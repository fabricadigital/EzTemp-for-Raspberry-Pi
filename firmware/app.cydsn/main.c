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

#define _VERSION_       0x0002u

struct REF {
    int16 vss;
    int16 vdd;
} REF;

struct T {
    int16 C;
    int16 F;
} T;

struct RH {
    int16 humidity;
} RH;

struct EXT {
    int16 counts;
} EXT;


void read() {
    ADC_Wakeup();
    Opamp_Wakeup();
    AMux_Start();
    
    EN_Write(1);
    
    CyDelay(70);
    
    /* VSS REF */
    AMux_Next();
    
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    ADC_StopConvert();
    
    REF.vss = ADC_GetResult16(0);
    ADC_SetOffset(0, REF.vss);
    
    /* VDD */
    AMux_Next();
    
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    ADC_StopConvert();
    
    REF.vdd = ADC_GetResult16(0) << 1;
    
    /* Thermistor */
    AMux_Next();
    
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    ADC_StopConvert();
    
    T.C = Thermistor_GetTemperature(Thermistor_GetResistance(REF.vdd - ADC_GetResult16(0), ADC_GetResult16(0))) / 10;
    T.F = ((T.C * 9) /5) + 320;
    
    /* Relative humidity */
    AMux_Next();
    
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    ADC_StopConvert();
    
    RH.humidity = (ADC_GetResult16(0) * 1000) / REF.vdd;
    
    /* External signal */
    AMux_Next();
    
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    ADC_StopConvert();
    
    EXT.counts = ADC_GetResult16(0);

    EN_Write(0);
    
    AMux_Stop();
    ADC_Sleep();
    Opamp_Sleep();
}

int main()
{
    uint8 cmd, checksum, txbyte;
    
    UART_Start();
    ADC_Start();
    Opamp_Start();
    
    ADC_Sleep();
    Opamp_Sleep();
        
    for(;;)
    {   
        UART_SpiUartClearRxBuffer();
        while(UART_SpiUartGetRxBufferSize() == 0u);
        cmd = UART_UartGetByte();
        
        checksum = 0xFF;
        
        read();
        
        checksum -= cmd;
        UART_UartPutChar(cmd); // Echo back
        
        switch(cmd) {
            case 'c': // Temperature in Celsius
                txbyte = T.C/10;
                checksum -= txbyte;
                UART_UartPutChar(txbyte);
            break;
            case 'd': // Temperature in Celsius .1
                txbyte = T.C >> 8;
                checksum -= txbyte;
                UART_UartPutChar(txbyte);
                txbyte = T.C;
                checksum -= txbyte;
                UART_UartPutChar(txbyte);
            break;
            case 'f':
                txbyte = T.F/10;
                checksum -= txbyte;
                UART_UartPutChar(txbyte);
            break;
            case 'g':
                txbyte = T.F >> 8;
                checksum -= txbyte;
                UART_UartPutChar(txbyte);
                txbyte = T.F;
                checksum -= txbyte;
                UART_UartPutChar(txbyte);
            break;
            case 'h':
                txbyte = RH.humidity /10;
                checksum -= txbyte;
                UART_UartPutChar(txbyte);
            break;
            case 'i':
                txbyte = RH.humidity >> 8;
                checksum -= txbyte;
                UART_UartPutChar(txbyte);
                txbyte = RH.humidity;
                checksum -= txbyte;
                UART_UartPutChar(txbyte);
            break;
            case 'x':
                txbyte = EXT.counts >> 8;
                checksum -= txbyte;
                UART_UartPutChar(txbyte);
                txbyte = EXT.counts;
                checksum -= txbyte;
                UART_UartPutChar(txbyte);
            break;
            case 'v':
                txbyte = _VERSION_ >> 8;
                checksum -= txbyte;
                UART_UartPutChar(txbyte);
                txbyte = _VERSION_;
                checksum -= txbyte;
                UART_UartPutChar(txbyte);
            break;
            default:
                
            break;
        }
        
        UART_UartPutChar(checksum);
    }
}

/* [] END OF FILE */
