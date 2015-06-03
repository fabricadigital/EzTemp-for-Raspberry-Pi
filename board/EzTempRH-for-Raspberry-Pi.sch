EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:caimanics_cypress
LIBS:caimanics_honeywell
LIBS:EzTempRH-for-Raspberry-Pi-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "29 oct 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CY8C4100-28SSOP U1
U 1 1 53BBA7E6
P 2150 1850
F 0 "U1" H 1800 2650 60  0000 C CNN
F 1 "CY8C4100-28SSOP" V 2150 1850 60  0000 C CNN
F 2 "~" H 1700 2500 60  0000 C CNN
F 3 "~" H 1700 2500 60  0000 C CNN
	1    2150 1850
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 53BBA879
P 4300 1650
F 0 "C2" H 4300 1750 40  0000 L CNN
F 1 ".1uF" H 4306 1565 40  0000 L CNN
F 2 "~" H 4338 1500 30  0000 C CNN
F 3 "~" H 4300 1650 60  0000 C CNN
	1    4300 1650
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 53BBA888
P 4550 1650
F 0 "C3" H 4550 1750 40  0000 L CNN
F 1 "1uF" H 4556 1565 40  0000 L CNN
F 2 "~" H 4588 1500 30  0000 C CNN
F 3 "~" H 4550 1650 60  0000 C CNN
	1    4550 1650
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 53BBA8AE
P 4800 1650
F 0 "C4" H 4800 1750 40  0000 L CNN
F 1 ".1uF" H 4806 1565 40  0000 L CNN
F 2 "~" H 4838 1500 30  0000 C CNN
F 3 "~" H 4800 1650 60  0000 C CNN
	1    4800 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 1250 4300 1450
Wire Wire Line
	4550 1250 4550 1450
Wire Wire Line
	4800 1250 4800 1450
Wire Wire Line
	4300 1850 4300 1950
Wire Wire Line
	4800 1850 4800 1950
Connection ~ 4800 1950
Wire Wire Line
	4550 1850 4550 1950
Connection ~ 4550 1950
Text Label 4300 1250 3    60   ~ 0
Vddd
Text Label 4550 1250 3    60   ~ 0
Vccd
Text Label 5050 1950 2    60   ~ 0
Vss
Wire Wire Line
	3200 1200 2900 1200
Wire Wire Line
	3200 1400 2900 1400
$Comp
L R R3
U 1 1 53BBACA5
P 1600 6050
F 0 "R3" V 1680 6050 40  0000 C CNN
F 1 "10K" V 1607 6051 40  0000 C CNN
F 2 "~" V 1530 6050 30  0000 C CNN
F 3 "~" H 1600 6050 30  0000 C CNN
	1    1600 6050
	1    0    0    -1  
$EndComp
$Comp
L THERMISTOR TH1
U 1 1 53BBACB4
P 1600 6550
F 0 "TH1" V 1700 6600 50  0000 C CNN
F 1 "THERMISTOR" V 1500 6550 50  0000 C CNN
F 2 "~" H 1600 6550 60  0000 C CNN
F 3 "~" H 1600 6550 60  0000 C CNN
	1    1600 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 1600 1400 1600
Wire Wire Line
	1100 1700 1400 1700
Wire Wire Line
	1100 1800 1400 1800
Wire Wire Line
	1100 2400 1400 2400
Wire Wire Line
	1100 2500 1400 2500
Wire Wire Line
	3200 1500 2900 1500
Text Label 1100 1600 0    60   ~ 0
Vss
Text Label 1100 1700 0    60   ~ 0
VDD_T
Text Label 1100 1800 0    60   ~ 0
TH_T
Text Label 1100 1900 0    60   ~ 0
RH_T
Text Label 3200 2400 2    60   ~ 0
TX
Text Label 3200 2500 2    60   ~ 0
RX
NoConn ~ 1400 1300
NoConn ~ 1400 2200
NoConn ~ 1400 2300
NoConn ~ 2900 2300
NoConn ~ 2900 2200
Text Label 3200 1200 2    60   ~ 0
Vss
Text Label 3200 1300 2    60   ~ 0
Vddd
Text Label 3200 1400 2    60   ~ 0
Vccd
Text Label 3200 1500 2    60   ~ 0
XRES
Text Label 1100 2400 0    60   ~ 0
SWDIO
Text Label 1100 2500 0    60   ~ 0
SWDCK
Wire Wire Line
	1300 5750 1900 5750
Wire Wire Line
	1300 6850 1900 6850
Connection ~ 1600 6850
Text Label 1900 5750 2    60   ~ 0
EN
Text Label 1900 6300 2    60   ~ 0
TH_T
Connection ~ 1600 5750
Text Label 1900 6850 2    60   ~ 0
Vss
$Comp
L C C5
U 1 1 53BBBDB9
P 1300 6300
F 0 "C5" H 1300 6400 40  0000 L CNN
F 1 "C" H 1306 6215 40  0000 L CNN
F 2 "~" H 1338 6150 30  0000 C CNN
F 3 "~" H 1300 6300 60  0000 C CNN
	1    1300 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 5750 1300 6100
Wire Wire Line
	1300 6500 1300 6850
$Comp
L CONN_4 P1
U 1 1 53BBC032
P 4250 3050
F 0 "P1" V 4200 3050 50  0000 C CNN
F 1 "CONN_4" V 4300 3050 50  0000 C CNN
F 2 "" H 4250 3050 60  0000 C CNN
F 3 "" H 4250 3050 60  0000 C CNN
	1    4250 3050
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4900 2900 4600 2900
Wire Wire Line
	4900 3000 4600 3000
Wire Wire Line
	4900 3100 4600 3100
Wire Wire Line
	4900 3200 4600 3200
$Comp
L C C1
U 1 1 53BBC0FF
P 4050 1650
F 0 "C1" H 4050 1750 40  0000 L CNN
F 1 "1uF" H 4056 1565 40  0000 L CNN
F 2 "~" H 4088 1500 30  0000 C CNN
F 3 "~" H 4050 1650 60  0000 C CNN
	1    4050 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 1250 4050 1450
Wire Wire Line
	4050 1850 4050 1950
Connection ~ 4300 1950
Text Label 4050 1250 3    60   ~ 0
Vddd
$Comp
L CONN_5 P3
U 1 1 53BBC20A
P 4150 5650
F 0 "P3" V 4100 5650 50  0000 C CNN
F 1 "CONN_5" V 4200 5650 50  0000 C CNN
F 2 "" H 4150 5650 60  0000 C CNN
F 3 "" H 4150 5650 60  0000 C CNN
	1    4150 5650
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4900 5450 4550 5450
Wire Wire Line
	4900 5550 4550 5550
Wire Wire Line
	4900 5650 4550 5650
Wire Wire Line
	4900 5750 4550 5750
Wire Wire Line
	4900 5850 4550 5850
Text Label 4900 2900 2    60   ~ 0
Vddd
Text Label 4900 3200 2    60   ~ 0
Vss
Text Label 4900 3100 2    60   ~ 0
TX
Text Label 4900 3000 2    60   ~ 0
RX
Text Label 4900 5450 2    60   ~ 0
Vddd
Text Label 4900 5550 2    60   ~ 0
Vss
Text Label 4900 5650 2    60   ~ 0
XRES
Text Label 4900 5750 2    60   ~ 0
SWDCK
Text Label 4900 5850 2    60   ~ 0
SWDIO
$Comp
L HIH5030 U2
U 1 1 53BBD4DF
P 2450 6050
F 0 "U2" H 2650 5850 60  0000 C CNN
F 1 "HIH5030" H 2450 6450 60  0000 C CNN
F 2 "~" H 2450 6050 60  0000 C CNN
F 3 "~" H 2450 6050 60  0000 C CNN
	1    2450 6050
	1    0    0    -1  
$EndComp
Text Label 2950 6900 2    60   ~ 0
Vss
Text Label 2450 6700 1    60   ~ 0
RH_T
Text Label 2550 6700 1    60   ~ 0
EN
Wire Wire Line
	1100 2000 1400 2000
Wire Wire Line
	1100 2100 1400 2100
Text Label 1100 2000 0    60   ~ 0
EXT_T
Text Label 1100 2100 0    60   ~ 0
EN
Wire Wire Line
	3200 2400 2900 2400
Wire Wire Line
	3200 2500 2900 2500
Wire Wire Line
	3200 1300 2900 1300
Wire Wire Line
	4900 4250 4600 4250
Wire Wire Line
	4900 4350 4600 4350
Wire Wire Line
	4900 4450 4600 4450
Text Label 4900 4250 2    60   ~ 0
EN
Text Label 4900 4350 2    60   ~ 0
EXT_T
Text Label 4900 4450 2    60   ~ 0
Vss
Text Label 4900 4150 2    60   ~ 0
Vddd
Wire Wire Line
	4900 4150 4600 4150
$Comp
L C C6
U 1 1 54106932
P 2700 6650
F 0 "C6" H 2700 6750 40  0000 L CNN
F 1 "C" H 2706 6565 40  0000 L CNN
F 2 "~" H 2738 6500 30  0000 C CNN
F 3 "~" H 2700 6650 60  0000 C CNN
	1    2700 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 6300 1600 6300
Text Notes 4000 5250 0    60   ~ 0
Programmer header
Text Notes 4000 2650 0    60   ~ 0
Serial port to Raspberry Pi
Text Notes 4000 3950 0    60   ~ 0
External ADC signal
Text Notes 4000 1100 0    60   ~ 0
Bypass capacitors
Text Notes 1300 5500 0    60   ~ 0
Sensors
Wire Notes Line
	3800 2150 3800 900 
Wire Notes Line
	3800 3750 3800 4750
Wire Notes Line
	3800 4750 5200 4750
Wire Notes Line
	5200 4750 5200 3750
Wire Notes Line
	5200 3750 3800 3750
Wire Notes Line
	3800 2450 3800 3450
Wire Notes Line
	3800 3450 5500 3450
Wire Notes Line
	5500 3450 5500 2450
Wire Notes Line
	5500 2450 3800 2450
Wire Notes Line
	3800 5050 3800 6050
Wire Notes Line
	3800 6050 5200 6050
Wire Notes Line
	5200 6050 5200 5050
Wire Notes Line
	5200 5050 3800 5050
Text Notes 7400 7550 0    60   ~ 0
EzTemp&RH for Raspberry Pi
Text Notes 7100 7050 0    60   ~ 0
Copyright (c) 2014 - CAIMANICS (Pablo Bacho)\nPublished under the MIT License
Wire Wire Line
	2450 6700 2450 6400
Wire Wire Line
	1100 1900 1400 1900
Wire Wire Line
	1100 1400 1400 1400
Text Label 1100 1400 0    60   ~ 0
OA_O
Text Label 1100 1200 0    60   ~ 0
ADC_IN
Wire Wire Line
	1100 1500 1400 1500
Text Label 1100 1500 0    60   ~ 0
ADC_BY
Text Label 4800 1250 3    60   ~ 0
ADC_BY
$Comp
L CONN_4 P2
U 1 1 541A9AAC
P 4250 4300
F 0 "P2" V 4200 4300 50  0000 C CNN
F 1 "CONN_4" V 4300 4300 50  0000 C CNN
F 2 "" H 4250 4300 60  0000 C CNN
F 3 "" H 4250 4300 60  0000 C CNN
	1    4250 4300
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2550 6400 2550 6700
Wire Notes Line
	1100 5300 3150 5300
Wire Wire Line
	1600 5750 1600 5800
Wire Wire Line
	2350 6900 2950 6900
Wire Wire Line
	2700 6900 2700 6850
Wire Wire Line
	2350 6900 2350 6400
Connection ~ 2700 6900
Wire Wire Line
	2550 6400 2700 6400
Wire Wire Line
	2700 6400 2700 6450
Wire Wire Line
	1600 6850 1600 6800
$Comp
L R R1
U 1 1 541A9F12
P 1350 3950
F 0 "R1" V 1430 3950 40  0000 C CNN
F 1 "1.5K" V 1357 3951 40  0000 C CNN
F 2 "~" V 1280 3950 30  0000 C CNN
F 3 "~" H 1350 3950 30  0000 C CNN
	1    1350 3950
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 541A9F21
P 1350 4550
F 0 "R2" V 1430 4550 40  0000 C CNN
F 1 "680" V 1357 4551 40  0000 C CNN
F 2 "~" V 1280 4550 30  0000 C CNN
F 3 "~" H 1350 4550 30  0000 C CNN
	1    1350 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 3650 1350 3650
Wire Wire Line
	1350 3650 1350 3700
Wire Wire Line
	1350 4200 1350 4300
Wire Wire Line
	1350 4250 1750 4250
Connection ~ 1350 4250
Wire Wire Line
	1350 4800 1350 4850
Wire Wire Line
	1350 4850 1100 4850
Text Label 1100 4850 0    60   ~ 0
Vss
Text Label 1100 3650 0    60   ~ 0
OA_O
Text Label 1750 4250 2    60   ~ 0
ADC_IN
Text Notes 1000 3400 0    60   ~ 0
3.3v to 0-1.024v\nrange converter
Wire Notes Line
	800  3150 800  5050
Wire Notes Line
	800  5050 2000 5050
Wire Notes Line
	2000 5050 2000 3150
Wire Notes Line
	2000 3150 800  3150
Wire Wire Line
	4050 1950 5050 1950
Wire Notes Line
	3800 2150 5200 2150
Wire Notes Line
	5200 2150 5200 900 
Wire Notes Line
	5200 900  3800 900 
$Comp
L R R4
U 1 1 541AA4FB
P 2850 3950
F 0 "R4" V 2930 3950 40  0000 C CNN
F 1 "10K" V 2857 3951 40  0000 C CNN
F 2 "~" V 2780 3950 30  0000 C CNN
F 3 "~" H 2850 3950 30  0000 C CNN
	1    2850 3950
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 541AA501
P 2850 4550
F 0 "R5" V 2930 4550 40  0000 C CNN
F 1 "10K" V 2857 4551 40  0000 C CNN
F 2 "~" V 2780 4550 30  0000 C CNN
F 3 "~" H 2850 4550 30  0000 C CNN
	1    2850 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 3650 2850 3650
Wire Wire Line
	2850 3650 2850 3700
Wire Wire Line
	2850 4200 2850 4300
Wire Wire Line
	2850 4250 3250 4250
Connection ~ 2850 4250
Wire Wire Line
	2850 4800 2850 4850
Wire Wire Line
	2850 4850 2600 4850
Text Label 2600 4850 0    60   ~ 0
Vss
Text Label 2600 3650 0    60   ~ 0
EN
Text Label 3250 4250 2    60   ~ 0
VDD_T
Text Notes 2500 3400 0    60   ~ 0
Voltage sense
Wire Notes Line
	2300 3150 2300 5050
Wire Notes Line
	2300 5050 3500 5050
Wire Notes Line
	3500 5050 3500 3150
Wire Notes Line
	3500 3150 2300 3150
Wire Notes Line
	1100 5300 1100 7050
Wire Notes Line
	1100 7050 3150 7050
Wire Notes Line
	3150 7050 3150 5300
Wire Wire Line
	1100 1200 1400 1200
$Comp
L R R6
U 1 1 542174F8
P 4300 7050
F 0 "R6" V 4380 7050 40  0000 C CNN
F 1 "5.6k" V 4307 7051 40  0000 C CNN
F 2 "~" V 4230 7050 30  0000 C CNN
F 3 "~" H 4300 7050 30  0000 C CNN
	1    4300 7050
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 54217507
P 4600 7050
F 0 "R7" V 4680 7050 40  0000 C CNN
F 1 "5.6k" V 4607 7051 40  0000 C CNN
F 2 "~" V 4530 7050 30  0000 C CNN
F 3 "~" H 4600 7050 30  0000 C CNN
	1    4600 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 6700 4600 6800
Wire Wire Line
	4150 6700 4600 6700
Wire Wire Line
	4300 6700 4300 6800
Connection ~ 4300 6700
Wire Wire Line
	4300 7300 4300 7500
Wire Wire Line
	4600 7300 4600 7500
Text Label 4150 6700 0    60   ~ 0
Vddd
Text Label 4300 7500 1    60   ~ 0
TX
Text Label 4600 7500 1    60   ~ 0
RX
Text Notes 3950 6500 0    60   ~ 0
Optional I2C pull-up
Wire Notes Line
	3800 6300 5000 6300
Wire Notes Line
	5000 6300 5000 7650
Wire Notes Line
	5000 7650 3800 7650
Wire Notes Line
	3800 7650 3800 6300
$EndSCHEMATC
