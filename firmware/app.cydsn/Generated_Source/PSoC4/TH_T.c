/*******************************************************************************
* File Name: TH_T.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "TH_T.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        TH_T_PC =   (TH_T_PC & \
                                (uint32)(~(uint32)(TH_T_DRIVE_MODE_IND_MASK << (TH_T_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (TH_T_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: TH_T_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void TH_T_Write(uint8 value) 
{
    uint8 drVal = (uint8)(TH_T_DR & (uint8)(~TH_T_MASK));
    drVal = (drVal | ((uint8)(value << TH_T_SHIFT) & TH_T_MASK));
    TH_T_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: TH_T_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  TH_T_DM_STRONG     Strong Drive 
*  TH_T_DM_OD_HI      Open Drain, Drives High 
*  TH_T_DM_OD_LO      Open Drain, Drives Low 
*  TH_T_DM_RES_UP     Resistive Pull Up 
*  TH_T_DM_RES_DWN    Resistive Pull Down 
*  TH_T_DM_RES_UPDWN  Resistive Pull Up/Down 
*  TH_T_DM_DIG_HIZ    High Impedance Digital 
*  TH_T_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void TH_T_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(TH_T__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: TH_T_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro TH_T_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 TH_T_Read(void) 
{
    return (uint8)((TH_T_PS & TH_T_MASK) >> TH_T_SHIFT);
}


/*******************************************************************************
* Function Name: TH_T_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 TH_T_ReadDataReg(void) 
{
    return (uint8)((TH_T_DR & TH_T_MASK) >> TH_T_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(TH_T_INTSTAT) 

    /*******************************************************************************
    * Function Name: TH_T_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 TH_T_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(TH_T_INTSTAT & TH_T_MASK);
		TH_T_INTSTAT = maskedStatus;
        return maskedStatus >> TH_T_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
