/*******************************************************************************
* File Name: Counter_32_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Counter_32.h"

static Counter_32_backupStruct Counter_32_backup;


/*******************************************************************************
* Function Name: Counter_32_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Counter_32_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Counter_32_SaveConfig(void) 
{
    #if (!Counter_32_UsingFixedFunction)

        Counter_32_backup.CounterUdb = Counter_32_ReadCounter();

        #if(!Counter_32_ControlRegRemoved)
            Counter_32_backup.CounterControlRegister = Counter_32_ReadControlRegister();
        #endif /* (!Counter_32_ControlRegRemoved) */

    #endif /* (!Counter_32_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_32_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Counter_32_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_32_RestoreConfig(void) 
{      
    #if (!Counter_32_UsingFixedFunction)

       Counter_32_WriteCounter(Counter_32_backup.CounterUdb);

        #if(!Counter_32_ControlRegRemoved)
            Counter_32_WriteControlRegister(Counter_32_backup.CounterControlRegister);
        #endif /* (!Counter_32_ControlRegRemoved) */

    #endif /* (!Counter_32_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_32_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Counter_32_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Counter_32_Sleep(void) 
{
    #if(!Counter_32_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Counter_32_CTRL_ENABLE == (Counter_32_CONTROL & Counter_32_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Counter_32_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Counter_32_backup.CounterEnableState = 0u;
        }
    #else
        Counter_32_backup.CounterEnableState = 1u;
        if(Counter_32_backup.CounterEnableState != 0u)
        {
            Counter_32_backup.CounterEnableState = 0u;
        }
    #endif /* (!Counter_32_ControlRegRemoved) */
    
    Counter_32_Stop();
    Counter_32_SaveConfig();
}


/*******************************************************************************
* Function Name: Counter_32_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Counter_32_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_32_Wakeup(void) 
{
    Counter_32_RestoreConfig();
    #if(!Counter_32_ControlRegRemoved)
        if(Counter_32_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Counter_32_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Counter_32_ControlRegRemoved) */
    
}


/* [] END OF FILE */
