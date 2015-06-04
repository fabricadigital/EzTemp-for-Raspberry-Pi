/*******************************************************************************
* File Name: Thermistor.c
* Version 1.20
*
* Description:
*  This file provides the source code to the API for the ThermistorCalc
*  Component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Thermistor.h"


/*******************************************************************************
* Function Name: Thermistor_GetResistance
********************************************************************************
*
* Summary:
*  The digital values of the voltages across the reference resistor and the
*  thermistor are passed to this function as parameters. The function returns
*  the resistance, based on the voltage values.
*
* Parameters:
*  vReference: the voltage across the reference resistor;
*  vThermistor: the voltage across the thermistor.
*  The ratio of these two voltages is used by this function. Therefore, the
*  units for both parameters must be the same.
*
* Return:
*  The return value is the resistance across the thermistor. The value returned
*  is the resistance in Ohms.
*
*******************************************************************************/
uint32 Thermistor_GetResistance(int16 vReference, int16 vThermistor)
                                      
{
    int32 resT;
    int16 temp;

    /* Calculate thermistor resistance from the voltages */
    resT = Thermistor_REF_RESISTOR * ((int32)vThermistor);
    if (vReference < 0)
    {
        temp = -vReference;
        temp = (int16)((uint16)((uint16)temp >> 1u));
        temp = -temp;
    }
    else
    {
        temp = (int16)((uint16)((uint16)vReference >> 1u));
    }
    resT += temp;
    resT /= vReference;

    /* The ordering of Reference resistor value is specifically designed to keep the result from overflowing */
    return ((uint32)((uint32)resT << Thermistor_REF_RES_SHIFT));
}


/*******************************************************************************
* Function Name: Thermistor_GetTemperature
********************************************************************************
*
* Summary:
*  The value of the thermistor resistance is passed to this function as a
*  parameter. The function returns the temperature, based on the resistance
*  value. The method used to calculate the temperature is dependent on whether
*  Equation or LUT was selected in the Customizer.
*
* Parameters:
*  resT: the resistance across the thermistor in Ohms.
*
* Return:
*  The return value is the temperature in 1/100ths of degrees C. For example,
*  the return value is 2345, when the actual temperature is 23.45 degrees C.
*
*******************************************************************************/
int16 Thermistor_GetTemperature(uint32 resT) 
{
    int16 tempTR;
    static const uint32 CYCODE Thermistor_LUT[] = { 21916u, 21834u, 21753u, 21672u, 21592u, 21512u, 21432u, 21352u, 21273u,
 21194u, 21116u, 21038u, 20960u, 20882u, 20805u, 20728u, 20652u, 20575u, 20499u, 20424u, 20348u, 20273u, 20199u, 20124u,
 20050u, 19977u, 19903u, 19830u, 19757u, 19685u, 19612u, 19541u, 19469u, 19398u, 19327u, 19256u, 19185u, 19115u, 19045u,
 18976u, 18907u, 18838u, 18769u, 18700u, 18632u, 18564u, 18497u, 18429u, 18362u, 18296u, 18229u, 18163u, 18097u, 18031u,
 17966u, 17901u, 17836u, 17771u, 17707u, 17643u, 17579u, 17516u, 17452u, 17389u, 17327u, 17264u, 17202u, 17140u, 17078u,
 17017u, 16955u, 16894u, 16834u, 16773u, 16713u, 16653u, 16593u, 16534u, 16474u, 16415u, 16356u, 16298u, 16240u, 16181u,
 16124u, 16066u, 16009u, 15951u, 15895u, 15838u, 15781u, 15725u, 15669u, 15613u, 15558u, 15503u, 15447u, 15393u, 15338u,
 15283u, 15229u, 15175u, 15121u, 15068u, 15014u, 14961u, 14908u, 14856u, 14803u, 14751u, 14699u, 14647u, 14595u, 14544u,
 14493u, 14441u, 14391u, 14340u, 14290u, 14239u, 14189u, 14139u, 14090u, 14040u, 13991u, 13942u, 13893u, 13844u, 13796u,
 13748u, 13700u, 13652u, 13604u, 13557u, 13509u, 13462u, 13415u, 13368u, 13322u, 13275u, 13229u, 13183u, 13137u, 13092u,
 13046u, 13001u, 12956u, 12911u, 12866u, 12821u, 12777u, 12733u, 12689u, 12645u, 12601u, 12557u, 12514u, 12471u, 12428u,
 12385u, 12342u, 12300u, 12257u, 12215u, 12173u, 12131u, 12089u, 12048u, 12006u, 11965u, 11924u, 11883u, 11842u, 11802u,
 11761u, 11721u, 11681u, 11641u, 11601u, 11562u, 11522u, 11483u, 11443u, 11404u, 11366u, 11327u, 11288u, 11250u, 11211u,
 11173u, 11135u, 11097u, 11060u, 11022u, 10985u, 10948u, 10910u, 10873u, 10837u, 10800u, 10763u, 10727u, 10691u, 10655u,
 10619u, 10583u, 10547u, 10511u, 10476u, 10441u, 10405u, 10370u, 10335u, 10301u, 10266u, 10232u, 10197u, 10163u, 10129u,
 10095u, 10061u, 10027u, 9994u, 9960u, 9927u, 9894u, 9861u, 9828u, 9795u, 9762u, 9729u, 9697u, 9665u, 9632u, 9600u,
 9568u, 9536u, 9505u, 9473u, 9442u, 9410u, 9379u, 9348u, 9317u, 9286u, 9255u, 9225u, 9194u, 9164u, 9133u, 9103u, 9073u,
 9043u, 9013u, 8983u, 8954u, 8924u, 8895u, 8865u, 8836u, 8807u, 8778u, 8749u, 8720u, 8692u, 8663u, 8635u, 8606u, 8578u,
 8550u, 8522u, 8494u, 8466u, 8439u, 8411u, 8384u, 8356u, 8329u, 8302u, 8275u, 8248u, 8221u, 8194u, 8167u, 8141u, 8114u,
 8088u, 8061u, 8035u, 8009u, 7983u, 7957u, 7931u, 7906u, 7880u, 7854u, 7829u, 7804u, 7778u, 7753u, 7728u, 7703u, 7678u,
 7654u, 7629u, 7604u, 7580u, 7555u, 7531u, 7507u, 7483u, 7459u, 7435u, 7411u, 7387u, 7363u, 7340u, 7316u, 7293u, 7269u,
 7246u, 7223u, 7200u, 7177u, 7154u, 7131u, 7108u, 7085u, 7063u, 7040u, 7018u, 6995u, 6973u, 6951u, 6929u, 6907u, 6885u,
 6863u, 6841u, 6819u, 6798u, 6776u, 6755u, 6733u, 6712u, 6691u, 6669u, 6648u, 6627u, 6606u, 6585u, 6565u, 6544u, 6523u,
 6503u, 6482u, 6462u, 6441u, 6421u, 6401u, 6381u, 6361u, 6341u, 6321u, 6301u, 6281u, 6261u, 6242u, 6222u, 6203u, 6183u,
 6164u, 6145u, 6125u, 6106u, 6087u, 6068u, 6049u, 6030u, 6012u, 5993u, 5974u, 5955u, 5937u, 5918u, 5900u, 5882u, 5863u,
 5845u, 5827u, 5809u, 5791u, 5773u, 5755u, 5737u, 5720u, 5702u, 5684u, 5667u, 5649u, 5632u, 5614u, 5597u, 5580u, 5562u,
 5545u, 5528u, 5511u, 5494u, 5477u, 5460u, 5444u, 5427u, 5410u, 5394u, 5377u, 5361u, 5344u, 5328u, 5311u, 5295u, 5279u,
 5263u, 5247u, 5231u, 5215u, 5199u, 5183u, 5167u, 5151u, 5136u, 5120u, 5104u, 5089u, 5073u, 5058u, 5042u, 5027u, 5012u,
 4997u, 4981u, 4966u, 4951u, 4936u, 4921u, 4906u, 4892u, 4877u, 4862u, 4847u, 4833u, 4818u, 4804u, 4789u, 4775u, 4760u,
 4746u, 4732u, 4717u, 4703u, 4689u, 4675u, 4661u, 4647u, 4633u, 4619u, 4605u, 4591u, 4577u, 4564u, 4550u, 4536u, 4523u,
 4509u, 4496u, 4482u, 4469u, 4456u, 4442u, 4429u, 4416u, 4403u, 4390u, 4377u, 4364u, 4351u, 4338u, 4325u, 4312u, 4299u,
 4286u, 4274u, 4261u, 4248u, 4236u, 4223u, 4211u, 4198u, 4186u, 4173u, 4161u };


    #if (Thermistor_IMPLEMENTATION == Thermistor_EQUATION_METHOD)

        float32 stEqn;
        float32 logrT;

        /* Calculate thermistor resistance from the voltages */
        #if(!CY_PSOC3)
            logrT = (float32)log((float64)resT);
        #else
            logrT = log((float32)resT);
        #endif  /* (!CY_PSOC3) */

        /* Calculate temperature from the resistance of thermistor using Steinhart-Hart Equation */
        #if(!CY_PSOC3)
            stEqn = (float32)(Thermistor_THA + (Thermistor_THB * logrT) + 
                             (Thermistor_THC * pow((float64)logrT, (float32)3)));
        #else
            stEqn = (float32)(Thermistor_THA + (Thermistor_THB * logrT) + 
                             (Thermistor_THC * pow(logrT, (float32)3)));
        #endif  /* (!CY_PSOC3) */

        tempTR = (int16)((float32)((((1.0 / stEqn) - Thermistor_K2C) * (float32)Thermistor_SCALE) + 0.5));

    #else /* Thermistor_IMPLEMENTATION == Thermistor_LUT_METHOD */

        uint16 mid;
        uint16 first = 0u;
        uint16 last = Thermistor_LUT_SIZE - 1u;

        /* Calculate temperature from the resistance of thermistor by using the LUT */
        while (first < last)
        {
            mid = (first + last) >> 1u;

            if ((0u == mid) || ((Thermistor_LUT_SIZE - 1u) == mid) || (resT == Thermistor_LUT[mid]))
            {
                last = mid;
                break;
            }
            else if (Thermistor_LUT[mid] > resT)
            {
                first = mid + 1u;
            }
            else /* (Thermistor_LUT[mid] < resT) */
            {
                last = mid - 1u;
            }
        }

        /* Calculation the closest entry in the LUT */
        if ((Thermistor_LUT[last] > resT) && (last < (Thermistor_LUT_SIZE - 1u)) &&
           ((Thermistor_LUT[last] - resT) > (resT - Thermistor_LUT[last + 1u])))
        {
            last++;
        }
        else if ((Thermistor_LUT[last] < resT) && (last > 0u) &&
                ((Thermistor_LUT[last - 1u] - resT) < (resT - Thermistor_LUT[last])))
        {
            last--;
        }
        else
        {
            /* Closest entry in the LUT already found */
        }

        tempTR = Thermistor_MIN_TEMP + (int16)((uint16)(last * Thermistor_ACCURACY));

    #endif /* (Thermistor_IMPLEMENTATION == Thermistor_EQUATION_METHOD) */

    return (tempTR);
}


/* [] END OF FILE */
