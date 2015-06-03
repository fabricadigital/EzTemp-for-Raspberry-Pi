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
    static const uint32 CYCODE Thermistor_LUT[] = { 68237u, 67907u, 67578u, 67251u, 66926u, 66603u, 66282u, 65962u, 65644u,
 65328u, 65013u, 64700u, 64389u, 64080u, 63772u, 63466u, 63161u, 62858u, 62557u, 62257u, 61959u, 61663u, 61368u, 61075u,
 60784u, 60494u, 60205u, 59918u, 59633u, 59349u, 59066u, 58786u, 58506u, 58228u, 57952u, 57677u, 57404u, 57132u, 56861u,
 56592u, 56325u, 56058u, 55794u, 55530u, 55268u, 55008u, 54749u, 54491u, 54234u, 53979u, 53725u, 53473u, 53222u, 52972u,
 52724u, 52477u, 52231u, 51986u, 51743u, 51501u, 51261u, 51021u, 50783u, 50546u, 50311u, 50076u, 49843u, 49611u, 49380u,
 49151u, 48923u, 48696u, 48470u, 48245u, 48021u, 47799u, 47578u, 47358u, 47139u, 46921u, 46704u, 46489u, 46274u, 46061u,
 45849u, 45638u, 45428u, 45219u, 45011u, 44804u, 44599u, 44394u, 44191u, 43988u, 43787u, 43586u, 43387u, 43189u, 42991u,
 42795u, 42600u, 42405u, 42212u, 42020u, 41829u, 41638u, 41449u, 41261u, 41073u, 40887u, 40701u, 40517u, 40333u, 40151u,
 39969u, 39788u, 39608u, 39429u, 39251u, 39074u, 38898u, 38723u, 38548u, 38375u, 38202u, 38030u, 37859u, 37689u, 37520u,
 37352u, 37184u, 37018u, 36852u, 36687u, 36523u, 36360u, 36197u, 36036u, 35875u, 35715u, 35556u, 35397u, 35240u, 35083u,
 34927u, 34772u, 34617u, 34464u, 34311u, 34159u, 34007u, 33857u, 33707u, 33558u, 33409u, 33262u, 33115u, 32969u, 32823u,
 32679u, 32535u, 32391u, 32249u, 32107u, 31966u, 31826u, 31686u, 31547u, 31409u, 31271u, 31134u, 30998u, 30862u, 30727u,
 30593u, 30459u, 30326u, 30194u, 30062u, 29931u, 29801u, 29671u, 29542u, 29414u, 29286u, 29159u, 29032u, 28907u, 28781u,
 28657u, 28532u, 28409u, 28286u, 28164u, 28042u, 27921u, 27801u, 27681u, 27562u, 27443u, 27325u, 27207u, 27090u, 26974u,
 26858u, 26743u, 26628u, 26514u, 26400u, 26287u, 26175u, 26063u, 25951u, 25840u, 25730u, 25620u, 25511u, 25402u, 25294u,
 25186u, 25079u, 24973u, 24866u, 24761u, 24656u, 24551u, 24447u, 24343u, 24240u, 24138u, 24036u, 23934u, 23833u, 23732u,
 23632u, 23532u, 23433u, 23334u, 23236u, 23138u, 23041u, 22944u, 22848u, 22752u, 22656u, 22561u, 22466u, 22372u, 22279u,
 22185u, 22093u, 22000u, 21908u, 21817u, 21726u, 21635u, 21545u, 21455u, 21366u, 21277u, 21189u, 21100u, 21013u, 20926u,
 20839u, 20752u, 20666u, 20581u, 20495u, 20411u, 20326u, 20242u, 20159u, 20075u, 19993u, 19910u, 19828u, 19746u, 19665u,
 19584u, 19504u, 19423u, 19344u, 19264u, 19185u, 19107u, 19028u, 18950u, 18873u, 18796u, 18719u, 18642u, 18566u, 18490u,
 18415u, 18340u, 18265u, 18191u, 18117u, 18043u, 17970u, 17896u, 17824u, 17751u, 17679u, 17608u, 17536u, 17465u, 17395u,
 17324u, 17254u, 17185u, 17115u, 17046u, 16977u, 16909u, 16841u, 16773u, 16705u, 16638u, 16571u, 16505u, 16438u, 16372u,
 16307u, 16241u, 16176u, 16112u, 16047u, 15983u, 15919u, 15855u, 15792u, 15729u, 15666u, 15604u, 15542u, 15480u, 15418u,
 15357u, 15296u, 15235u, 15174u, 15114u, 15054u, 14995u, 14935u, 14876u, 14817u, 14759u, 14700u, 14642u, 14584u, 14527u,
 14469u, 14412u, 14356u, 14299u, 14243u, 14187u, 14131u, 14075u, 14020u, 13965u, 13910u, 13856u, 13801u, 13747u, 13694u,
 13640u, 13587u, 13534u, 13481u, 13428u, 13376u, 13324u, 13272u, 13220u, 13168u, 13117u, 13066u, 13015u, 12965u, 12915u,
 12864u, 12815u, 12765u, 12715u, 12666u, 12617u, 12568u, 12520u, 12472u, 12423u, 12375u, 12328u, 12280u, 12233u, 12186u,
 12139u, 12092u, 12046u, 11999u, 11953u, 11908u, 11862u, 11816u, 11771u, 11726u, 11681u, 11637u, 11592u, 11548u, 11504u,
 11460u, 11416u, 11373u, 11329u, 11286u, 11243u, 11200u, 11158u, 11115u, 11073u, 11031u, 10989u, 10948u, 10906u, 10865u,
 10824u, 10783u, 10742u, 10701u, 10661u, 10621u, 10581u, 10541u, 10501u, 10462u, 10422u, 10383u, 10344u, 10305u, 10266u,
 10228u, 10189u, 10151u, 10113u, 10075u, 10038u, 10000u, 9963u, 9925u, 9888u, 9851u, 9815u, 9778u, 9742u, 9705u, 9669u,
 9633u, 9597u, 9562u, 9526u, 9491u, 9456u, 9420u, 9386u, 9351u, 9316u, 9282u, 9247u, 9213u, 9179u, 9145u, 9111u, 9078u,
 9044u, 9011u, 8978u, 8945u, 8912u, 8879u, 8846u, 8814u, 8782u, 8749u, 8717u, 8685u, 8653u, 8622u, 8590u, 8559u, 8528u,
 8496u, 8465u, 8434u, 8404u, 8373u, 8343u, 8312u, 8282u, 8252u, 8222u, 8192u, 8162u, 8132u, 8103u, 8074u, 8044u, 8015u,
 7986u, 7957u, 7929u, 7900u, 7871u, 7843u, 7815u, 7786u, 7758u, 7730u, 7703u, 7675u, 7647u, 7620u, 7592u, 7565u, 7538u,
 7511u, 7484u, 7457u, 7430u, 7404u, 7377u, 7351u, 7325u, 7299u, 7272u, 7247u, 7221u, 7195u, 7169u, 7144u, 7118u, 7093u,
 7068u, 7043u, 7018u, 6993u, 6968u, 6943u, 6919u, 6894u, 6870u, 6845u, 6821u, 6797u, 6773u, 6749u, 6725u, 6702u, 6678u,
 6655u, 6631u, 6608u, 6585u, 6561u, 6538u, 6515u, 6492u, 6470u, 6447u, 6424u, 6402u, 6380u, 6357u, 6335u, 6313u, 6291u,
 6269u, 6247u, 6225u, 6203u, 6182u, 6160u, 6139u, 6118u, 6096u, 6075u, 6054u, 6033u, 6012u, 5991u, 5970u, 5950u, 5929u,
 5909u, 5888u, 5868u, 5848u, 5827u, 5807u, 5787u, 5767u, 5747u, 5728u, 5708u, 5688u, 5669u, 5649u, 5630u, 5610u, 5591u,
 5572u, 5553u, 5534u, 5515u, 5496u, 5477u, 5459u, 5440u, 5421u, 5403u, 5384u, 5366u, 5348u, 5330u, 5311u, 5293u, 5275u,
 5257u, 5240u, 5222u, 5204u, 5186u, 5169u, 5151u, 5134u, 5116u, 5099u, 5082u, 5065u, 5048u, 5031u, 5014u, 4997u, 4980u,
 4963u, 4946u, 4930u, 4913u, 4897u, 4880u, 4864u, 4847u, 4831u, 4815u, 4799u, 4783u, 4767u, 4751u, 4735u, 4719u, 4703u,
 4688u, 4672u, 4656u, 4641u, 4625u, 4610u, 4595u, 4579u, 4564u, 4549u, 4534u, 4519u, 4504u, 4489u, 4474u, 4459u, 4444u,
 4430u, 4415u, 4400u, 4386u, 4371u, 4357u, 4343u, 4328u, 4314u, 4300u, 4286u, 4272u, 4258u, 4244u, 4230u, 4216u, 4202u,
 4188u, 4174u, 4161u, 4147u, 4133u, 4120u, 4106u, 4093u, 4080u, 4066u, 4053u, 4040u, 4027u, 4014u, 4000u, 3987u, 3974u,
 3962u, 3949u, 3936u, 3923u, 3910u, 3898u, 3885u, 3872u, 3860u, 3847u, 3835u, 3823u, 3810u, 3798u, 3786u, 3773u, 3761u,
 3749u, 3737u, 3725u, 3713u, 3701u, 3689u, 3677u, 3665u, 3654u, 3642u, 3630u, 3619u, 3607u, 3596u, 3584u, 3573u, 3561u,
 3550u, 3538u, 3527u, 3516u, 3505u, 3493u, 3482u, 3471u, 3460u, 3449u, 3438u, 3427u, 3416u, 3406u, 3395u, 3384u, 3373u,
 3363u, 3352u, 3341u, 3331u, 3320u, 3310u, 3299u, 3289u, 3278u, 3268u, 3258u, 3248u, 3237u, 3227u, 3217u, 3207u, 3197u,
 3187u, 3177u, 3167u, 3157u, 3147u, 3137u, 3127u, 3117u, 3108u, 3098u, 3088u, 3079u, 3069u, 3059u, 3050u, 3040u, 3031u,
 3022u, 3012u, 3003u, 2993u, 2984u, 2975u, 2966u, 2956u, 2947u, 2938u, 2929u, 2920u, 2911u, 2902u, 2893u, 2884u, 2875u,
 2866u, 2857u, 2849u, 2840u, 2831u, 2822u, 2814u, 2805u, 2796u, 2788u, 2779u, 2771u, 2762u, 2754u, 2745u, 2737u, 2728u,
 2720u, 2712u, 2703u, 2695u, 2687u, 2679u, 2671u, 2662u, 2654u, 2646u, 2638u, 2630u, 2622u, 2614u, 2606u, 2598u, 2590u,
 2582u, 2575u, 2567u, 2559u, 2551u, 2544u, 2536u, 2528u, 2521u, 2513u, 2505u, 2498u, 2490u, 2483u, 2475u, 2468u, 2460u,
 2453u, 2446u, 2438u, 2431u, 2424u, 2416u, 2409u, 2402u, 2395u, 2387u, 2380u, 2373u, 2366u, 2359u, 2352u, 2345u, 2338u,
 2331u, 2324u, 2317u, 2310u, 2303u, 2296u, 2290u, 2283u, 2276u, 2269u, 2263u, 2256u, 2249u, 2242u, 2236u, 2229u, 2223u,
 2216u, 2209u, 2203u, 2196u, 2190u, 2183u, 2177u, 2171u, 2164u, 2158u, 2151u, 2145u, 2139u, 2133u, 2126u, 2120u, 2114u,
 2108u, 2101u, 2095u, 2089u, 2083u, 2077u, 2071u, 2065u, 2059u, 2053u, 2047u, 2041u, 2035u, 2029u, 2023u, 2017u, 2011u,
 2005u, 1999u, 1994u, 1988u, 1982u, 1976u, 1971u, 1965u, 1959u, 1954u, 1948u, 1942u, 1937u, 1931u, 1925u, 1920u, 1914u,
 1909u, 1903u, 1898u, 1892u, 1887u, 1881u, 1876u, 1871u, 1865u, 1860u, 1855u, 1849u, 1844u, 1839u, 1833u, 1828u, 1823u,
 1818u, 1812u, 1807u, 1802u, 1797u, 1792u, 1787u, 1782u, 1777u, 1772u, 1766u, 1761u, 1756u, 1751u, 1746u, 1741u, 1737u,
 1732u, 1727u, 1722u, 1717u, 1712u, 1707u, 1702u, 1698u, 1693u, 1688u, 1683u, 1678u, 1674u, 1669u };


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
