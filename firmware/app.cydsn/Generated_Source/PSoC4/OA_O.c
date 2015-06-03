/*******************************************************************************
* File Name: OA_O.c  
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
#include "OA_O.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        OA_O_PC =   (OA_O_PC & \
                                (uint32)(~(uint32)(OA_O_DRIVE_MODE_IND_MASK << (OA_O_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (OA_O_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: OA_O_Write
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
void OA_O_Write(uint8 value) 
{
    uint8 drVal = (uint8)(OA_O_DR & (uint8)(~OA_O_MASK));
    drVal = (drVal | ((uint8)(value << OA_O_SHIFT) & OA_O_MASK));
    OA_O_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: OA_O_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  OA_O_DM_STRONG     Strong Drive 
*  OA_O_DM_OD_HI      Open Drain, Drives High 
*  OA_O_DM_OD_LO      Open Drain, Drives Low 
*  OA_O_DM_RES_UP     Resistive Pull Up 
*  OA_O_DM_RES_DWN    Resistive Pull Down 
*  OA_O_DM_RES_UPDWN  Resistive Pull Up/Down 
*  OA_O_DM_DIG_HIZ    High Impedance Digital 
*  OA_O_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void OA_O_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(OA_O__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: OA_O_Read
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
*  Macro OA_O_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 OA_O_Read(void) 
{
    return (uint8)((OA_O_PS & OA_O_MASK) >> OA_O_SHIFT);
}


/*******************************************************************************
* Function Name: OA_O_ReadDataReg
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
uint8 OA_O_ReadDataReg(void) 
{
    return (uint8)((OA_O_DR & OA_O_MASK) >> OA_O_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(OA_O_INTSTAT) 

    /*******************************************************************************
    * Function Name: OA_O_ClearInterrupt
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
    uint8 OA_O_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(OA_O_INTSTAT & OA_O_MASK);
		OA_O_INTSTAT = maskedStatus;
        return maskedStatus >> OA_O_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
