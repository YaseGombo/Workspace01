/*******************************************************************************
* File Name: Counter_Hall_PM.c  
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

#include "Counter_Hall.h"

static Counter_Hall_backupStruct Counter_Hall_backup;


/*******************************************************************************
* Function Name: Counter_Hall_SaveConfig
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
*  Counter_Hall_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Counter_Hall_SaveConfig(void) 
{
    #if (!Counter_Hall_UsingFixedFunction)

        Counter_Hall_backup.CounterUdb = Counter_Hall_ReadCounter();

        #if(!Counter_Hall_ControlRegRemoved)
            Counter_Hall_backup.CounterControlRegister = Counter_Hall_ReadControlRegister();
        #endif /* (!Counter_Hall_ControlRegRemoved) */

    #endif /* (!Counter_Hall_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_Hall_RestoreConfig
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
*  Counter_Hall_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_Hall_RestoreConfig(void) 
{      
    #if (!Counter_Hall_UsingFixedFunction)

       Counter_Hall_WriteCounter(Counter_Hall_backup.CounterUdb);

        #if(!Counter_Hall_ControlRegRemoved)
            Counter_Hall_WriteControlRegister(Counter_Hall_backup.CounterControlRegister);
        #endif /* (!Counter_Hall_ControlRegRemoved) */

    #endif /* (!Counter_Hall_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_Hall_Sleep
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
*  Counter_Hall_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Counter_Hall_Sleep(void) 
{
    #if(!Counter_Hall_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Counter_Hall_CTRL_ENABLE == (Counter_Hall_CONTROL & Counter_Hall_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Counter_Hall_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Counter_Hall_backup.CounterEnableState = 0u;
        }
    #else
        Counter_Hall_backup.CounterEnableState = 1u;
        if(Counter_Hall_backup.CounterEnableState != 0u)
        {
            Counter_Hall_backup.CounterEnableState = 0u;
        }
    #endif /* (!Counter_Hall_ControlRegRemoved) */
    
    Counter_Hall_Stop();
    Counter_Hall_SaveConfig();
}


/*******************************************************************************
* Function Name: Counter_Hall_Wakeup
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
*  Counter_Hall_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_Hall_Wakeup(void) 
{
    Counter_Hall_RestoreConfig();
    #if(!Counter_Hall_ControlRegRemoved)
        if(Counter_Hall_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Counter_Hall_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Counter_Hall_ControlRegRemoved) */
    
}


/* [] END OF FILE */
