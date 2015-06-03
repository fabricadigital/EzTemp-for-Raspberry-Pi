/*******************************************************************************
* File Name: VSSREF.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_VSSREF_H) /* Pins VSSREF_H */
#define CY_PINS_VSSREF_H

#include "cytypes.h"
#include "cyfitter.h"
#include "VSSREF_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    VSSREF_Write(uint8 value) ;
void    VSSREF_SetDriveMode(uint8 mode) ;
uint8   VSSREF_ReadDataReg(void) ;
uint8   VSSREF_Read(void) ;
uint8   VSSREF_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define VSSREF_DRIVE_MODE_BITS        (3)
#define VSSREF_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - VSSREF_DRIVE_MODE_BITS))

#define VSSREF_DM_ALG_HIZ         (0x00u)
#define VSSREF_DM_DIG_HIZ         (0x01u)
#define VSSREF_DM_RES_UP          (0x02u)
#define VSSREF_DM_RES_DWN         (0x03u)
#define VSSREF_DM_OD_LO           (0x04u)
#define VSSREF_DM_OD_HI           (0x05u)
#define VSSREF_DM_STRONG          (0x06u)
#define VSSREF_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define VSSREF_MASK               VSSREF__MASK
#define VSSREF_SHIFT              VSSREF__SHIFT
#define VSSREF_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VSSREF_PS                     (* (reg32 *) VSSREF__PS)
/* Port Configuration */
#define VSSREF_PC                     (* (reg32 *) VSSREF__PC)
/* Data Register */
#define VSSREF_DR                     (* (reg32 *) VSSREF__DR)
/* Input Buffer Disable Override */
#define VSSREF_INP_DIS                (* (reg32 *) VSSREF__PC2)


#if defined(VSSREF__INTSTAT)  /* Interrupt Registers */

    #define VSSREF_INTSTAT                (* (reg32 *) VSSREF__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define VSSREF_DRIVE_MODE_SHIFT       (0x00u)
#define VSSREF_DRIVE_MODE_MASK        (0x07u << VSSREF_DRIVE_MODE_SHIFT)


#endif /* End Pins VSSREF_H */


/* [] END OF FILE */
