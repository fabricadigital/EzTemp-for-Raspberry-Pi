/*******************************************************************************
* File Name: VBAT_T.h  
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

#if !defined(CY_PINS_VBAT_T_H) /* Pins VBAT_T_H */
#define CY_PINS_VBAT_T_H

#include "cytypes.h"
#include "cyfitter.h"
#include "VBAT_T_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    VBAT_T_Write(uint8 value) ;
void    VBAT_T_SetDriveMode(uint8 mode) ;
uint8   VBAT_T_ReadDataReg(void) ;
uint8   VBAT_T_Read(void) ;
uint8   VBAT_T_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define VBAT_T_DRIVE_MODE_BITS        (3)
#define VBAT_T_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - VBAT_T_DRIVE_MODE_BITS))

#define VBAT_T_DM_ALG_HIZ         (0x00u)
#define VBAT_T_DM_DIG_HIZ         (0x01u)
#define VBAT_T_DM_RES_UP          (0x02u)
#define VBAT_T_DM_RES_DWN         (0x03u)
#define VBAT_T_DM_OD_LO           (0x04u)
#define VBAT_T_DM_OD_HI           (0x05u)
#define VBAT_T_DM_STRONG          (0x06u)
#define VBAT_T_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define VBAT_T_MASK               VBAT_T__MASK
#define VBAT_T_SHIFT              VBAT_T__SHIFT
#define VBAT_T_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VBAT_T_PS                     (* (reg32 *) VBAT_T__PS)
/* Port Configuration */
#define VBAT_T_PC                     (* (reg32 *) VBAT_T__PC)
/* Data Register */
#define VBAT_T_DR                     (* (reg32 *) VBAT_T__DR)
/* Input Buffer Disable Override */
#define VBAT_T_INP_DIS                (* (reg32 *) VBAT_T__PC2)


#if defined(VBAT_T__INTSTAT)  /* Interrupt Registers */

    #define VBAT_T_INTSTAT                (* (reg32 *) VBAT_T__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define VBAT_T_DRIVE_MODE_SHIFT       (0x00u)
#define VBAT_T_DRIVE_MODE_MASK        (0x07u << VBAT_T_DRIVE_MODE_SHIFT)


#endif /* End Pins VBAT_T_H */


/* [] END OF FILE */
