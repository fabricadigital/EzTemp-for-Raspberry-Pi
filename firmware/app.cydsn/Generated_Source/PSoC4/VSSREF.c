/*******************************************************************************
* File Name: VSSREF.c  
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
#include "VSSREF.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        VSSREF_PC =   (VSSREF_PC & \
                                (uint32)(~(uint32)(VSSREF_DRIVE_MODE_IND_MASK << (VSSREF_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (VSSREF_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: VSSREF_Write
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
void VSSREF_Write(uint8 value) 
{
    uint8 drVal = (uint8)(VSSREF_DR & (uint8)(~VSSREF_MASK));
    drVal = (drVal | ((uint8)(value << VSSREF_SHIFT) & VSSREF_MASK));
    VSSREF_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: VSSREF_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  VSSREF_DM_STRONG     Strong Drive 
*  VSSREF_DM_OD_HI      Open Drain, Drives High 
*  VSSREF_DM_OD_LO      Open Drain, Drives Low 
*  VSSREF_DM_RES_UP     Resistive Pull Up 
*  VSSREF_DM_RES_DWN    Resistive Pull Down 
*  VSSREF_DM_RES_UPDWN  Resistive Pull Up/Down 
*  VSSREF_DM_DIG_HIZ    High Impedance Digital 
*  VSSREF_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void VSSREF_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(VSSREF__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: VSSREF_Read
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
*  Macro VSSREF_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 VSSREF_Read(void) 
{
    return (uint8)((VSSREF_PS & VSSREF_MASK) >> VSSREF_SHIFT);
}


/*******************************************************************************
* Function Name: VSSREF_ReadDataReg
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
uint8 VSSREF_ReadDataReg(void) 
{
    return (uint8)((VSSREF_DR & VSSREF_MASK) >> VSSREF_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(VSSREF_INTSTAT) 

    /*******************************************************************************
    * Function Name: VSSREF_ClearInterrupt
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
    uint8 VSSREF_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(VSSREF_INTSTAT & VSSREF_MASK);
		VSSREF_INTSTAT = maskedStatus;
        return maskedStatus >> VSSREF_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
