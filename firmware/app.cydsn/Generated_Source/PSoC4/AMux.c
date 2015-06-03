/*******************************************************************************
* File Name: AMux.c
* Version 1.80
*
*  Description:
*    This file contains functions for the AMuxSeq.
*
*   Note:
*
*******************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "AMux.h"

uint8 AMux_initVar = 0u;


/*******************************************************************************
* Function Name: AMux_Start
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AMux_Start(void)
{
    AMux_DisconnectAll();
    AMux_initVar = 1u;
}


/*******************************************************************************
* Function Name: AMux_Init
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AMux_Init(void)
{
    AMux_DisconnectAll();
}


/*******************************************************************************
* Function Name: AMux_Stop
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AMux_Stop(void)
{
    AMux_DisconnectAll();
}

#if (AMux_MUXTYPE == AMux_MUX_DIFF)

/*******************************************************************************
* Function Name: AMux_Next
********************************************************************************
* Summary:
*  Disconnects the previous channel and connects the next one in the sequence.
*  When Next is called for the first time after Init, Start, Enable, Stop, or
*  DisconnectAll, it connects channel 0.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AMux_Next(void)
{
    AMux_CYAMUXSIDE_A_Next();
    AMux_CYAMUXSIDE_B_Next();
}


/*******************************************************************************
* Function Name: AMux_DisconnectAll
********************************************************************************
* Summary:
*  This function disconnects all channels. The next time Next is called, channel
*  0 will be connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AMux_DisconnectAll(void)
{
    AMux_CYAMUXSIDE_A_DisconnectAll();
    AMux_CYAMUXSIDE_B_DisconnectAll();
}


/*******************************************************************************
* Function Name: AMux_GetChannel
********************************************************************************
* Summary:
*  The currently connected channel is retuned. If no channel is connected
*  returns -1.
*
* Parameters:
*  void
*
* Return:
*  The current channel or -1.
*
*******************************************************************************/
int8 AMux_GetChannel(void)
{
    return AMux_CYAMUXSIDE_A_curChannel;
}

#else

/*******************************************************************************
* Function Name: AMux_GetChannel
********************************************************************************
* Summary:
*  The currently connected channel is retuned. If no channel is connected
*  returns -1.
*
* Parameters:
*  void
*
* Return:
*  The current channel or -1.
*
*******************************************************************************/
int8 AMux_GetChannel(void)
{
    return AMux_curChannel;
}

#endif


/* [] END OF FILE */
