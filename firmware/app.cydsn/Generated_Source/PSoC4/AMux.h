/*******************************************************************************
* File Name: AMux.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the AMuxSeq.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUXSEQ_AMux_H)
#define CY_AMUXSEQ_AMux_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define AMux_MUX_SINGLE 1
#define AMux_MUX_DIFF   2
#define AMux_MUXTYPE    1


/***************************************
*        Function Prototypes
***************************************/

void AMux_Start(void);
void AMux_Init(void);
void AMux_Stop(void);
#if (AMux_MUXTYPE == AMux_MUX_DIFF)
void AMux_Next(void);
void AMux_DisconnectAll(void);
#else
/* The Next and DisconnectAll functions are declared in cyfitter_cfg.h. */
/* void AMux_Next(void); */
/* void AMux_DisconnectAll(void); */
#endif
int8 AMux_GetChannel(void);


/***************************************
*           Global Variables
***************************************/

extern uint8 AMux_initVar;


/***************************************
*         Parameter Constants
***************************************/
#define AMux_CHANNELS 5


#endif /* CY_AMUXSEQ_AMux_H */


/* [] END OF FILE */
