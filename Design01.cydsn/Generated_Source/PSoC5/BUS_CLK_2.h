/*******************************************************************************
* File Name: BUS_CLK_2.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_BUS_CLK_2_H)
#define CY_CLOCK_BUS_CLK_2_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void BUS_CLK_2_Start(void) ;
void BUS_CLK_2_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void BUS_CLK_2_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void BUS_CLK_2_StandbyPower(uint8 state) ;
void BUS_CLK_2_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 BUS_CLK_2_GetDividerRegister(void) ;
void BUS_CLK_2_SetModeRegister(uint8 modeBitMask) ;
void BUS_CLK_2_ClearModeRegister(uint8 modeBitMask) ;
uint8 BUS_CLK_2_GetModeRegister(void) ;
void BUS_CLK_2_SetSourceRegister(uint8 clkSource) ;
uint8 BUS_CLK_2_GetSourceRegister(void) ;
#if defined(BUS_CLK_2__CFG3)
void BUS_CLK_2_SetPhaseRegister(uint8 clkPhase) ;
uint8 BUS_CLK_2_GetPhaseRegister(void) ;
#endif /* defined(BUS_CLK_2__CFG3) */

#define BUS_CLK_2_Enable()                       BUS_CLK_2_Start()
#define BUS_CLK_2_Disable()                      BUS_CLK_2_Stop()
#define BUS_CLK_2_SetDivider(clkDivider)         BUS_CLK_2_SetDividerRegister(clkDivider, 1u)
#define BUS_CLK_2_SetDividerValue(clkDivider)    BUS_CLK_2_SetDividerRegister((clkDivider) - 1u, 1u)
#define BUS_CLK_2_SetMode(clkMode)               BUS_CLK_2_SetModeRegister(clkMode)
#define BUS_CLK_2_SetSource(clkSource)           BUS_CLK_2_SetSourceRegister(clkSource)
#if defined(BUS_CLK_2__CFG3)
#define BUS_CLK_2_SetPhase(clkPhase)             BUS_CLK_2_SetPhaseRegister(clkPhase)
#define BUS_CLK_2_SetPhaseValue(clkPhase)        BUS_CLK_2_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(BUS_CLK_2__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define BUS_CLK_2_CLKEN              (* (reg8 *) BUS_CLK_2__PM_ACT_CFG)
#define BUS_CLK_2_CLKEN_PTR          ((reg8 *) BUS_CLK_2__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define BUS_CLK_2_CLKSTBY            (* (reg8 *) BUS_CLK_2__PM_STBY_CFG)
#define BUS_CLK_2_CLKSTBY_PTR        ((reg8 *) BUS_CLK_2__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define BUS_CLK_2_DIV_LSB            (* (reg8 *) BUS_CLK_2__CFG0)
#define BUS_CLK_2_DIV_LSB_PTR        ((reg8 *) BUS_CLK_2__CFG0)
#define BUS_CLK_2_DIV_PTR            ((reg16 *) BUS_CLK_2__CFG0)

/* Clock MSB divider configuration register. */
#define BUS_CLK_2_DIV_MSB            (* (reg8 *) BUS_CLK_2__CFG1)
#define BUS_CLK_2_DIV_MSB_PTR        ((reg8 *) BUS_CLK_2__CFG1)

/* Mode and source configuration register */
#define BUS_CLK_2_MOD_SRC            (* (reg8 *) BUS_CLK_2__CFG2)
#define BUS_CLK_2_MOD_SRC_PTR        ((reg8 *) BUS_CLK_2__CFG2)

#if defined(BUS_CLK_2__CFG3)
/* Analog clock phase configuration register */
#define BUS_CLK_2_PHASE              (* (reg8 *) BUS_CLK_2__CFG3)
#define BUS_CLK_2_PHASE_PTR          ((reg8 *) BUS_CLK_2__CFG3)
#endif /* defined(BUS_CLK_2__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define BUS_CLK_2_CLKEN_MASK         BUS_CLK_2__PM_ACT_MSK
#define BUS_CLK_2_CLKSTBY_MASK       BUS_CLK_2__PM_STBY_MSK

/* CFG2 field masks */
#define BUS_CLK_2_SRC_SEL_MSK        BUS_CLK_2__CFG2_SRC_SEL_MASK
#define BUS_CLK_2_MODE_MASK          (~(BUS_CLK_2_SRC_SEL_MSK))

#if defined(BUS_CLK_2__CFG3)
/* CFG3 phase mask */
#define BUS_CLK_2_PHASE_MASK         BUS_CLK_2__CFG3_PHASE_DLY_MASK
#endif /* defined(BUS_CLK_2__CFG3) */

#endif /* CY_CLOCK_BUS_CLK_2_H */


/* [] END OF FILE */
