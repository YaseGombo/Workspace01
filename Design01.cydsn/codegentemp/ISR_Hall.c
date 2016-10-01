/*******************************************************************************
* File Name: ISR_Hall.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <ISR_Hall.h>
#include "cyapicallbacks.h"

#if !defined(ISR_Hall__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ISR_Hall_intc` */
#include "globalVariables.h"
#include "Counter_Hall.h"
#include "Status_Reg_Hall.h"
  
#ifdef DEBUG
#include <project.h>
#include <stdio.h>
#endif

#define PERIOD PERIOD_COUNTER_HALL
#define COMPARE COMPARE_COUNTER_HALL
/* `#END` */

#ifndef CYINT_IRQ_BASE
#define CYINT_IRQ_BASE      16
#endif /* CYINT_IRQ_BASE */
#ifndef CYINT_VECT_TABLE
#define CYINT_VECT_TABLE    ((cyisraddress **) CYREG_NVIC_VECT_OFFSET)
#endif /* CYINT_VECT_TABLE */

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: ISR_Hall_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it. This function disables the interrupt, 
*  sets the default interrupt vector, sets the priority from the value in the
*  Design Wide Resources Interrupt Editor, then enables the interrupt to the 
*  interrupt controller.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ISR_Hall_Start(void)
{
    /* For all we know the interrupt is active. */
    ISR_Hall_Disable();

    /* Set the ISR to point to the ISR_Hall Interrupt. */
    ISR_Hall_SetVector(&ISR_Hall_Interrupt);

    /* Set the priority. */
    ISR_Hall_SetPriority((uint8)ISR_Hall_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISR_Hall_Enable();
}


/*******************************************************************************
* Function Name: ISR_Hall_StartEx
********************************************************************************
*
* Summary:
*  Sets up the interrupt and enables it. This function disables the interrupt,
*  sets the interrupt vector based on the address passed in, sets the priority 
*  from the value in the Design Wide Resources Interrupt Editor, then enables 
*  the interrupt to the interrupt controller.
*  
*  When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*  used to provide consistent definition across compilers:
*  
*  Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*   Function prototype example:
*   CY_ISR_PROTO(MyISR);
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void ISR_Hall_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    ISR_Hall_Disable();

    /* Set the ISR to point to the ISR_Hall Interrupt. */
    ISR_Hall_SetVector(address);

    /* Set the priority. */
    ISR_Hall_SetPriority((uint8)ISR_Hall_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISR_Hall_Enable();
}


/*******************************************************************************
* Function Name: ISR_Hall_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ISR_Hall_Stop(void)
{
    /* Disable this interrupt. */
    ISR_Hall_Disable();

    /* Set the ISR to point to the passive one. */
    ISR_Hall_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: ISR_Hall_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for ISR_Hall.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(ISR_Hall_Interrupt)
{
    #ifdef ISR_Hall_INTERRUPT_INTERRUPT_CALLBACK
        ISR_Hall_Interrupt_InterruptCallback();
    #endif /* ISR_Hall_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START ISR_Hall_Interrupt` */

  uint16 time_new = (PERIOD - 1);
  uint16 capture = 0;
  uint8 status_isr = 0;
  
  uint8 temp_status_isr;
  while((temp_status_isr = Counter_Hall_ReadStatusRegister()) & Counter_Hall_STATUS_FIFONEMP){
    capture = Counter_Hall_ReadCapture();
    status_isr = temp_status_isr;
  }
  if((status_isr & Counter_Hall_STATUS_CAPTURE) && capture)  time_new = capture;

  // uint16 period = Counter_Hall_ReadPeriod();
  // uint16 compare = Counter_Hall_ReadCompare();
  /*
  uint8 status_isr = Counter_Hall_ReadStatusRegister();
  uint16 capture = Counter_Hall_ReadCapture();
  uint16 time_new = ((status_isr & Counter_Hall_STATUS_CAPTURE) && capture) ? capture : (PERIOD-1);
  */
    
  /*
  #ifdef DEBUG
    uint16 tmp_time = Counter_Hall_ReadCounter();
    if(tmp_time > capture) Control_Reg_Debug_Write(1);
    // else                   Control_Reg_Debug_Write(0);
    debugregs[0] = capture;
    debugregs[1] = tmp_time;
  #endif
  */
   
  uint8 hallState_new = Status_Reg_Hall_Read();
  int8 phase_new = table_phase[hallState_new];
  
  /// Update the history of states of the hall sensor
  int i;
  for(i = LENGTH_HIST-1; i != 0; i--){
    hallHist.phase[i] = hallHist.phase[i-1];
    hallHist.time[i] = hallHist.time[i-1];
  }
  hallHist.phase[0] = phase_new;
  hallHist.time[0] = time_new;
  
  /// Calculate angleParams
  if(hallHist.phase[0] > 5 || hallHist.phase[1] > 5 || hallHist.phase[2] > 5 || hallHist.phase[3] > 5){
    // Hall Sensors are not working
    status_error |= ERROR_HALL_SENSOR;
  } else if(hallHist.time[0] >= COMPARE || hallHist.time[1] >= COMPARE || hallHist.time[2] >= COMPARE || hallHist.time[3] >= COMPARE){
    // Motor rotation is very slow
    Set_angleParams_Center();
  } else {
    switch(pmodi((hallHist.phase[0] - hallHist.phase[1]), 6)){
    case 1:
      switch(pmodi((hallHist.phase[1] - hallHist.phase[2]), 6)){
      case 1:
        switch(pmodi((hallHist.phase[2] - hallHist.phase[3]), 6)){
        case 1:
          Set_angleParams_Forward();
          break;
        default:
          status_error |= ERROR_DIR_ROTATE;
          break;
        }
        break;
      default:
        status_error |= ERROR_DIR_ROTATE;
        break;
      }
      break;
    case 5:
      switch(pmodi((hallHist.phase[1] - hallHist.phase[2]), 6)){
      case 5:
        switch(pmodi((hallHist.phase[2] - hallHist.phase[3]), 6)){
        case 5:
          Set_angleParams_Backward();
          break;
        default:
          status_error |= ERROR_DIR_ROTATE;
          break;
        }
        break;
      default:
        status_error |= ERROR_DIR_ROTATE;
        break;
      }
      break;
    default:
      status_error |= ERROR_DIR_ROTATE;
      break;
    }
  }
  
  /*
  #ifdef DEBUG
  debugregs[0] = phase_new;
  debugregs[1] = time_new;
  debugregs[2] = status_error;
  debugregs[3] = status_isr;
  #endif
  */
  
    /* `#END` */
}


/*******************************************************************************
* Function Name: ISR_Hall_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ISR_Hall_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use ISR_Hall_StartEx instead.
* 
*   When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*   used to provide consistent definition across compilers:
*
*   Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*
*   Function prototype example:
*     CY_ISR_PROTO(MyISR);
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void ISR_Hall_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)ISR_Hall__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: ISR_Hall_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress ISR_Hall_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)ISR_Hall__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: ISR_Hall_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling ISR_Hall_Start or ISR_Hall_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after ISR_Hall_Start or ISR_Hall_StartEx has been called. 
*   To set the initial priority for the component, use the Design-Wide Resources
*   Interrupt Editor.
*
*   Note This API has no effect on Non-maskable interrupt NMI).
*
* Parameters:
*   priority: Priority of the interrupt, 0 being the highest priority
*             PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*             PSoC 4: Priority is from 0 to 3.
*
* Return:
*   None
*
*******************************************************************************/
void ISR_Hall_SetPriority(uint8 priority)
{
    *ISR_Hall_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: ISR_Hall_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt, 0 being the highest priority
*    PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*    PSoC 4: Priority is from 0 to 3.
*
*******************************************************************************/
uint8 ISR_Hall_GetPriority(void)
{
    uint8 priority;


    priority = *ISR_Hall_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: ISR_Hall_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt to the interrupt controller. Do not call this function
*   unless ISR_Start() has been called or the functionality of the ISR_Start() 
*   function, which sets the vector and the priority, has been called.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ISR_Hall_Enable(void)
{
    /* Enable the general interrupt. */
    *ISR_Hall_INTC_SET_EN = ISR_Hall__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_Hall_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 ISR_Hall_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*ISR_Hall_INTC_SET_EN & (uint32)ISR_Hall__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: ISR_Hall_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt in the interrupt controller.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ISR_Hall_Disable(void)
{
    /* Disable the general interrupt. */
    *ISR_Hall_INTC_CLR_EN = ISR_Hall__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_Hall_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
* Side Effects:
*   If interrupts are enabled and the interrupt is set up properly, the ISR is
*   entered (depending on the priority of this interrupt and other pending 
*   interrupts).
*
*******************************************************************************/
void ISR_Hall_SetPending(void)
{
    *ISR_Hall_INTC_SET_PD = ISR_Hall__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_Hall_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt in the interrupt controller.
*
*   Note Some interrupt sources are clear-on-read and require the block 
*   interrupt/status register to be read/cleared with the appropriate block API 
*   (GPIO, UART, and so on). Otherwise the ISR will continue to remain in 
*   pending state even though the interrupt itself is cleared using this API.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ISR_Hall_ClearPending(void)
{
    *ISR_Hall_INTC_CLR_PD = ISR_Hall__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
