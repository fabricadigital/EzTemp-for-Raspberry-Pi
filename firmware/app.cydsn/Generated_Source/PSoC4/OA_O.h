/*******************************************************************************
* File Name: OA_O.h  
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

#if !defined(CY_PINS_OA_O_H) /* Pins OA_O_H */
#define CY_PINS_OA_O_H

#include "cytypes.h"
#include "cyfitter.h"
#include "OA_O_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    OA_O_Write(uint8 value) ;
void    OA_O_SetDriveMode(uint8 mode) ;
uint8   OA_O_ReadDataReg(void) ;
uint8   OA_O_Read(void) ;
uint8   OA_O_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define OA_O_DRIVE_MODE_BITS        (3)
#define OA_O_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - OA_O_DRIVE_MODE_BITS))

#define OA_O_DM_ALG_HIZ         (0x00u)
#define OA_O_DM_DIG_HIZ         (0x01u)
#define OA_O_DM_RES_UP          (0x02u)
#define OA_O_DM_RES_DWN         (0x03u)
#define OA_O_DM_OD_LO           (0x04u)
#define OA_O_DM_OD_HI           (0x05u)
#define OA_O_DM_STRONG          (0x06u)
#define OA_O_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define OA_O_MASK               OA_O__MASK
#define OA_O_SHIFT              OA_O__SHIFT
#define OA_O_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define OA_O_PS                     (* (reg32 *) OA_O__PS)
/* Port Configuration */
#define OA_O_PC                     (* (reg32 *) OA_O__PC)
/* Data Register */
#define OA_O_DR                     (* (reg32 *) OA_O__DR)
/* Input Buffer Disable Override */
#define OA_O_INP_DIS                (* (reg32 *) OA_O__PC2)


#if defined(OA_O__INTSTAT)  /* Interrupt Registers */

    #define OA_O_INTSTAT                (* (reg32 *) OA_O__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define OA_O_DRIVE_MODE_SHIFT       (0x00u)
#define OA_O_DRIVE_MODE_MASK        (0x07u << OA_O_DRIVE_MODE_SHIFT)


#endif /* End Pins OA_O_H */


/* [] END OF FILE */
