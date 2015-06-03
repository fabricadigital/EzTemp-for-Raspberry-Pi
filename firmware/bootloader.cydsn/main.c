/*

The MIT License (MIT)

Copyright (c) 2014 CAIMANICS (hola@caimanics.com)
Author: Pablo Bacho (pablo.bacho@caimanics.com)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include <project.h>

int main()
{
    /* Short-circuit EN and VDD to start bootloader */
    EN_Write(0);
    
    if(EN_Read() != 0u) {
        Bootloader_SET_RUN_TYPE(Bootloader_START_BTLDR);
    } else {
        Bootloader_SET_RUN_TYPE(Bootloader_START_APP);
    }
    
    Bootloader_Start();
}

/**
* SCB UART bootloader code by Arachnid:
* https://gist.github.com/Arachnid/8069083
*/

void CyBtldrCommStart(void) {
    UART_Start();
}
 
void CyBtldrCommStop (void) {
    UART_Stop();
}
 
void CyBtldrCommReset(void) {
    UART_SpiUartClearRxBuffer();
    UART_SpiUartClearTxBuffer();
}
 
cystatus CyBtldrCommWrite(uint8* buffer, uint16 size, uint16* count, uint8 timeOut) {
    for(*count = 0; *count < size; (*count)++) {
        UART_UartPutChar(buffer[*count]);
    }
    
    return CYRET_SUCCESS;
}
 
cystatus CyBtldrCommRead (uint8* buffer, uint16 size, uint16* count, uint8 timeOut) {
    int timeoutUs = timeOut * 10000;
    cystatus status = CYRET_TIMEOUT;
    *count = 0;
    
    while(*count < size && timeoutUs >= 0) {
        if(UART_SpiUartGetRxBufferSize() > 0) {
            buffer[(*count)++] = UART_UartGetByte();
            // Switch to byte-to-byte timeout and mark as success
            timeoutUs = 10000; //10mS
            status = CYRET_SUCCESS;
        } else {
            CyDelayUs(10);
            timeoutUs -= 10;
        }
    }
    return status;
}

/* [] END OF FILE */
