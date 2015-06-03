/*******************************************************************************
* File Name: EN.h  
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

#if !defined(CY_PINS_EN_H) /* Pins EN_H */
#define CY_PINS_EN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "EN_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    EN_Write(uint8 value) ;
void    EN_SetDriveMode(uint8 mode) ;
uint8   EN_ReadDataReg(void) ;
uint8   EN_Read(void) ;
uint8   EN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EN_DRIVE_MODE_BITS        (3)
#define EN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - EN_DRIVE_MODE_BITS))

#define EN_DM_ALG_HIZ         (0x00u)
#define EN_DM_DIG_HIZ         (0x01u)
#define EN_DM_RES_UP          (0x02u)
#define EN_DM_RES_DWN         (0x03u)
#define EN_DM_OD_LO           (0x04u)
#define EN_DM_OD_HI           (0x05u)
#define EN_DM_STRONG          (0x06u)
#define EN_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define EN_MASK               EN__MASK
#define EN_SHIFT              EN__SHIFT
#define EN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EN_PS                     (* (reg32 *) EN__PS)
/* Port Configuration */
#define EN_PC                     (* (reg32 *) EN__PC)
/* Data Register */
#define EN_DR                     (* (reg32 *) EN__DR)
/* Input Buffer Disable Override */
#define EN_INP_DIS                (* (reg32 *) EN__PC2)


#if defined(EN__INTSTAT)  /* Interrupt Registers */

    #define EN_INTSTAT                (* (reg32 *) EN__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define EN_DRIVE_MODE_SHIFT       (0x00u)
#define EN_DRIVE_MODE_MASK        (0x07u << EN_DRIVE_MODE_SHIFT)


#endif /* End Pins EN_H */


/* [] END OF FILE */
