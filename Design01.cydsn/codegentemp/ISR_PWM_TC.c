/*******************************************************************************
* File Name: ISR_PWM_TC.c  
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
#include <ISR_PWM_TC.h>
#include "cyapicallbacks.h"

#if !defined(ISR_PWM_TC__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ISR_PWM_TC_intc` */
#include "globalVariables.h"
#include "PWM_A.h" 
#include "PWM_B.h"
#include "PWM_C.h"
#ifdef DEBUG
#include <project.h>
#include <stdio.h>
#endif
#define MY_PWM_A_WRITECOMPARE(compare) (CY_SET_REG16(PWM_A_COMPARE1_LSB_PTR, compare))
#define MY_PWM_B_WRITECOMPARE(compare) (CY_SET_REG16(PWM_B_COMPARE1_LSB_PTR, compare))
#define MY_PWM_C_WRITECOMPARE(compare) (CY_SET_REG16(PWM_C_COMPARE1_LSB_PTR, compare))

#define DELAY_ONE_PULSE 32    // = (PRECISION_PWM * 2) / (PWM_CLK / CNT_HALL_CLK);
#define DELAY_ONE_A_HALF_PULSE 48
#define DELAY_A 1  // = round( 36 / (BUS_CLK / CNT_HALL_CLK) );
#define DELAY_B 1  // = round( 25 / (BUS_CLK / CNT_HALL_CLK) );
#define DELAY_C 1  // = round( 21 / (BUS_CLK / CNT_HALL_CLK) );

#define OFFSET_FIXEDPOINT 12
#define BIAS_FIXEDPOINT 0x1000L
#define OFFSET_KPPHI  16
#define BIAS_KPPHI  0x10000L
#define OFFSET_PWM 8  // = log2(PRECISION_PWM)

#define C_PPHI 12746
#define C_P_LPPHI 4357

volatile int32 thm0, wm0, am0;
volatile uint32 time_next;
volatile uint16 pwm_abc[3] = {0, 0, 0};
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
* Function Name: ISR_PWM_TC_Start
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
void ISR_PWM_TC_Start(void)
{
    /* For all we know the interrupt is active. */
    ISR_PWM_TC_Disable();

    /* Set the ISR to point to the ISR_PWM_TC Interrupt. */
    ISR_PWM_TC_SetVector(&ISR_PWM_TC_Interrupt);

    /* Set the priority. */
    ISR_PWM_TC_SetPriority((uint8)ISR_PWM_TC_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISR_PWM_TC_Enable();
}


/*******************************************************************************
* Function Name: ISR_PWM_TC_StartEx
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
void ISR_PWM_TC_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    ISR_PWM_TC_Disable();

    /* Set the ISR to point to the ISR_PWM_TC Interrupt. */
    ISR_PWM_TC_SetVector(address);

    /* Set the priority. */
    ISR_PWM_TC_SetPriority((uint8)ISR_PWM_TC_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISR_PWM_TC_Enable();
}


/*******************************************************************************
* Function Name: ISR_PWM_TC_Stop
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
void ISR_PWM_TC_Stop(void)
{
    /* Disable this interrupt. */
    ISR_PWM_TC_Disable();

    /* Set the ISR to point to the passive one. */
    ISR_PWM_TC_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: ISR_PWM_TC_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for ISR_PWM_TC.
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
CY_ISR(ISR_PWM_TC_Interrupt)
{
    #ifdef ISR_PWM_TC_INTERRUPT_INTERRUPT_CALLBACK
        ISR_PWM_TC_Interrupt_InterruptCallback();
    #endif /* ISR_PWM_TC_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START ISR_PWM_TC_Interrupt` */
  
  // about -48 cycles
  MY_PWM_A_WRITECOMPARE(pwm_abc[0]);  // PWM_A_WriteCompare(pwm_abc[0]);
  #ifdef DEBUG
  SysTick_Config(SYSTICK_MAXVAL);
  #endif
  // about -36 cycles
  MY_PWM_B_WRITECOMPARE(pwm_abc[1]);  // PWM_B_WriteCompare(pwm_abc[1]);
  // about -25 cycles
  MY_PWM_C_WRITECOMPARE(pwm_abc[2]);  // PWM_C_WriteCompare(pwm_abc[2]);
  // about -21 cycles
  
  if(angleParams.updated){
    #ifdef DEBUG
    SysCntVal = SYSTICK_MAXVAL - (SysTick->VAL); 
    asm("nop");
    #endif
    uint16 tmp_time = Counter_Hall_ReadCounter();
    
    thm0 = angleParams.thm0;
    wm0 = angleParams.wm0;
    am0 = angleParams.am0;
    
    // thm0 =  hallHist.phase[0] * THETA_60DEG;
    // wm0 = 0x4093L;
    // am0 = 0;
    angleParams.updated = 0;
    time_next = tmp_time + (DELAY_ONE_A_HALF_PULSE - DELAY_B);
    //time_next = 0;
  } else {
    if(time_next < (LONG_MAX / 2L)) time_next += DELAY_ONE_PULSE;
  }
  
  /* thm = thm0 + (wm0 * dt) / BIAS_OMEGA + (am0/2 * dt^2) / BIAS_ACC;
   *     = thm0 + (wm0 * dt) + (am0 * dt^2) / (2^21);   (21 = 16 + 5)
   * Split the division (/ (2^21)) into two operations (/ (2^16) and / (2^5)) to avoid overflow and rounding error.
   */ 
  // int32 thm = (((((am0 * time_next) >> 16) * time_next) >> 5)  // BIAS_ACC / 0x10000L * 2L = 0x20L
  //                + wm0 * time_next) + thm0;
  // int32 wm = ((am0 * time_next) >> BITs_BIAS_ACC) + wm0;
  int32 thm = (wm0 * time_next) + thm0;
  int32 wm = wm0;
  
  int thm_k = (int)(thm >> 18); // THTA_360DEG / LENGTH_TABLE = 2^18;
  int thm_k_abc[3] = {pmod32(thm_k, LENGTH_TABLE),
                         pmod32((thm_k - LENGTH_TABLEdiv3), LENGTH_TABLE),
                         pmod32((thm_k + LENGTH_TABLEdiv3), LENGTH_TABLE)};
  
  int32 wm2pphi = wm + ((C_PPHI * lambda) >>  OFFSET_FIXEDPOINT);
  int32 wm2p_Lpphi_lambda = ((wm + ((C_P_LPPHI * lambda) >> OFFSET_FIXEDPOINT)) * lambda) >> OFFSET_FIXEDPOINT;
  // PWM_A_ReadCounter() = ~0x79 here. (First cycle: 0xDE)
  
  int32 vpwm[3];
  int i;
  for(i = 0; i < 3; i++){
    vpwm[i] = (wm2pphi * table_pphi[thm_k_abc[i]] + wm2p_Lpphi_lambda * table_p_Lpphi[thm_k_abc[i]]) >> OFFSET_KPPHI;
  }
  // PWM_A_ReadCounter() = 0x97~0xB0 here. (First cycle: 0xA6)
 
  int32 vpwm_min = vpwm[0];
  if(vpwm_min > vpwm[1])  vpwm_min = vpwm[1];
  if(vpwm_min > vpwm[2])  vpwm_min = vpwm[2];
  
  for(i = 0; i < 3; i++){
    pwm_abc[i] = (inv_vbat * (vpwm[i] - vpwm_min)) >> (OFFSET_FIXEDPOINT - OFFSET_PWM + OFFSET_INVVBAT);
  }
  // PWM_A_ReadCounter() = 0xC0~0xCE here. (First cycle: 0x7A)
  /*
  volatile uint cnt = PWM_A_ReadCounter();
  asm("nop");
  */

  PWM_A_ReadStatusRegister();
  // SysCntVal = 0x166~0x179 here. (First cycle: 0x1E1)
  // SysCntVal = SYSTICK_MAXVAL - (SysTick->VAL); 
    /* `#END` */
}


/*******************************************************************************
* Function Name: ISR_PWM_TC_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ISR_PWM_TC_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use ISR_PWM_TC_StartEx instead.
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
void ISR_PWM_TC_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)ISR_PWM_TC__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: ISR_PWM_TC_GetVector
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
cyisraddress ISR_PWM_TC_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)ISR_PWM_TC__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: ISR_PWM_TC_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling ISR_PWM_TC_Start or ISR_PWM_TC_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after ISR_PWM_TC_Start or ISR_PWM_TC_StartEx has been called. 
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
void ISR_PWM_TC_SetPriority(uint8 priority)
{
    *ISR_PWM_TC_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: ISR_PWM_TC_GetPriority
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
uint8 ISR_PWM_TC_GetPriority(void)
{
    uint8 priority;


    priority = *ISR_PWM_TC_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: ISR_PWM_TC_Enable
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
void ISR_PWM_TC_Enable(void)
{
    /* Enable the general interrupt. */
    *ISR_PWM_TC_INTC_SET_EN = ISR_PWM_TC__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_PWM_TC_GetState
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
uint8 ISR_PWM_TC_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*ISR_PWM_TC_INTC_SET_EN & (uint32)ISR_PWM_TC__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: ISR_PWM_TC_Disable
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
void ISR_PWM_TC_Disable(void)
{
    /* Disable the general interrupt. */
    *ISR_PWM_TC_INTC_CLR_EN = ISR_PWM_TC__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_PWM_TC_SetPending
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
void ISR_PWM_TC_SetPending(void)
{
    *ISR_PWM_TC_INTC_SET_PD = ISR_PWM_TC__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_PWM_TC_ClearPending
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
void ISR_PWM_TC_ClearPending(void)
{
    *ISR_PWM_TC_INTC_CLR_PD = ISR_PWM_TC__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
