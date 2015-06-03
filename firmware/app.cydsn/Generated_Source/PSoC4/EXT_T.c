/*******************************************************************************
* File Name: EXT_T.c  
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
#include "EXT_T.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        EXT_T_PC =   (EXT_T_PC & \
                                (uint32)(~(uint32)(EXT_T_DRIVE_MODE_IND_MASK << (EXT_T_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (EXT_T_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: EXT_T_Write
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
void EXT_T_Write(uint8 value) 
{
    uint8 drVal = (uint8)(EXT_T_DR & (uint8)(~EXT_T_MASK));
    drVal = (drVal | ((uint8)(value << EXT_T_SHIFT) & EXT_T_MASK));
    EXT_T_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: EXT_T_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  EXT_T_DM_STRONG     Strong Drive 
*  EXT_T_DM_OD_HI      Open Drain, Drives High 
*  EXT_T_DM_OD_LO      Open Drain, Drives Low 
*  EXT_T_DM_RES_UP     Resistive Pull Up 
*  EXT_T_DM_RES_DWN    Resistive Pull Down 
*  EXT_T_DM_RES_UPDWN  Resistive Pull Up/Down 
*  EXT_T_DM_DIG_HIZ    High Impedance Digital 
*  EXT_T_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void EXT_T_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(EXT_T__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: EXT_T_Read
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
*  Macro EXT_T_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 EXT_T_Read(void) 
{
    return (uint8)((EXT_T_PS & EXT_T_MASK) >> EXT_T_SHIFT);
}


/*******************************************************************************
* Function Name: EXT_T_ReadDataReg
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
uint8 EXT_T_ReadDataReg(void) 
{
    return (uint8)((EXT_T_DR & EXT_T_MASK) >> EXT_T_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(EXT_T_INTSTAT) 

    /*******************************************************************************
    * Function Name: EXT_T_ClearInterrupt
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
    uint8 EXT_T_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(EXT_T_INTSTAT & EXT_T_MASK);
		EXT_T_INTSTAT = maskedStatus;
        return maskedStatus >> EXT_T_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
