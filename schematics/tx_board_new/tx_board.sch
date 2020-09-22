EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title "Digital  Repeater TX Board"
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 "Author: DB9MAT Mathis, SO3ALG Nikoloz, SP5WWP Wojciech"
Comment4 "M17 Open Source Digital  Repeater"
$EndDescr
Text GLabel 9950 5400 0    50   Input ~ 10
TX
$Comp
L tx_board-rescue:C_Small-device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C320
U 1 1 5E0C71B9
P 10850 5400
F 0 "C320" V 10621 5400 50  0000 C CNN
F 1 "1000p" V 10712 5400 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 10850 5400 50  0001 C CNN
F 3 "~" H 10850 5400 50  0001 C CNN
F 4 "50" H 10850 5400 50  0001 C CNN "Voltage"
F 5 "C0G" H 10850 5400 50  0001 C CNN "TempCoef"
F 6 "5" H 10850 5400 50  0001 C CNN "Tolerance"
	1    10850 5400
	0    1    1    0   
$EndComp
$Comp
L tx_board-rescue:C_Small-device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C321
U 1 1 5E0C7CC9
P 11050 5600
F 0 "C321" H 10958 5554 50  0000 R CNN
F 1 "9p1" H 10958 5645 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 11050 5600 50  0001 C CNN
F 3 "~" H 11050 5600 50  0001 C CNN
F 4 "50" H 11050 5600 50  0001 C CNN "Voltage"
F 5 "5" H 11050 5600 50  0001 C CNN "Tolerance"
F 6 "C0G" H 11050 5600 50  0001 C CNN "TempCoef"
	1    11050 5600
	1    0    0    1   
$EndComp
Wire Wire Line
	10950 5400 11050 5400
Wire Wire Line
	11050 5400 11050 5500
Wire Wire Line
	11050 5700 11050 5800
$Comp
L power:GND #PWR0329
U 1 1 5E0D6EF6
P 11050 5800
F 0 "#PWR0329" H 11050 5550 50  0001 C CNN
F 1 "GND" H 11055 5627 50  0000 C CNN
F 2 "" H 11050 5800 50  0001 C CNN
F 3 "" H 11050 5800 50  0001 C CNN
	1    11050 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	12250 5600 12250 5800
Connection ~ 11750 5400
Wire Wire Line
	11750 5400 12100 5400
Wire Wire Line
	11750 5700 11750 5800
$Comp
L power:GND #PWR0330
U 1 1 5E0DA916
P 11750 5800
F 0 "#PWR0330" H 11750 5550 50  0001 C CNN
F 1 "GND" H 11755 5627 50  0000 C CNN
F 2 "" H 11750 5800 50  0001 C CNN
F 3 "" H 11750 5800 50  0001 C CNN
	1    11750 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	11750 5400 11750 5500
$Comp
L tx_board-rescue:C_Small-device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C322
U 1 1 5E0D325A
P 11750 5600
F 0 "C322" H 11658 5554 50  0000 R CNN
F 1 "9p1" H 11658 5645 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 11750 5600 50  0001 C CNN
F 3 "~" H 11750 5600 50  0001 C CNN
F 4 "50" H 11750 5600 50  0001 C CNN "Voltage"
F 5 "5" H 11750 5600 50  0001 C CNN "Tolerance"
F 6 "C0G" H 11750 5600 50  0001 C CNN "TempCoef"
	1    11750 5600
	-1   0    0    1   
$EndComp
$Comp
L tx_board-rescue:L_Small-device-Mainboard-rescue-rx_board-rescue-rx_board-rescue L305
U 1 1 5E0C8A95
P 11400 5400
F 0 "L305" V 11585 5400 50  0000 C CNN
F 1 "15nH" V 11494 5400 50  0000 C CNN
F 2 "Inductor_SMD:L_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 11400 5400 50  0001 C CNN
F 3 "~" H 11400 5400 50  0001 C CNN
	1    11400 5400
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0331
U 1 1 5E0B0FD9
P 12250 5800
F 0 "#PWR0331" H 12250 5550 50  0001 C CNN
F 1 "GND" H 12255 5627 50  0000 C CNN
F 2 "" H 12250 5800 50  0001 C CNN
F 3 "" H 12250 5800 50  0001 C CNN
	1    12250 5800
	1    0    0    -1  
$EndComp
$Comp
L tx_board-rescue:Conn_Coaxial-conn-Mainboard-rescue-rx_board-rescue-rx_board-rescue J301
U 1 1 5E0AD389
P 12250 5400
F 0 "J301" H 12350 5375 50  0000 L CNN
F 1 "Out" H 12350 5284 50  0000 L CNN
F 2 "Connector_Coaxial:SMA_Samtec_SMA-J-P-X-ST-EM1_EdgeMount" H 12250 5400 50  0001 C CNN
F 3 "" H 12250 5400 50  0001 C CNN
	1    12250 5400
	1    0    0    -1  
$EndComp
Connection ~ 11050 5400
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C316
U 1 1 5E28B5A1
P 7050 5950
F 0 "C316" V 7000 6050 39  0000 C CNN
F 1 "100n" V 7100 6100 39  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7050 5950 50  0001 C CNN
F 3 "~" H 7050 5950 50  0001 C CNN
F 4 "50" H 7050 5950 50  0001 C CNN "Voltage"
F 5 "10" H 7050 5950 50  0001 C CNN "Tolerance"
F 6 "X7R" H 7050 5950 50  0001 C CNN "TempCoef"
	1    7050 5950
	0    1    1    0   
$EndComp
Wire Wire Line
	6800 5950 6950 5950
Wire Wire Line
	8050 5950 8050 6150
NoConn ~ 6800 6050
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C318
U 1 1 5E2A6268
P 8200 6050
F 0 "C318" H 8292 6096 50  0000 L CNN
F 1 "10n" H 8292 6005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8200 6050 50  0001 C CNN
F 3 "~" H 8200 6050 50  0001 C CNN
F 4 "10" H 8200 6050 50  0001 C CNN "Tolerance"
F 5 "50" H 8200 6050 50  0001 C CNN "Voltage"
F 6 "X7R" H 8200 6050 50  0001 C CNN "TempCoef"
	1    8200 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 5850 8200 5700
$Comp
L power:+3.3V #PWR0326
U 1 1 5E2B8E01
P 8200 5700
F 0 "#PWR0326" H 8200 5550 50  0001 C CNN
F 1 "+3.3V" H 8215 5873 50  0000 C CNN
F 2 "" H 8200 5700 50  0001 C CNN
F 3 "" H 8200 5700 50  0001 C CNN
	1    8200 5700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0327
U 1 1 5E2B97C5
P 8200 6250
F 0 "#PWR0327" H 8200 6000 50  0001 C CNN
F 1 "GND" H 8205 6077 50  0000 C CNN
F 2 "" H 8200 6250 50  0001 C CNN
F 3 "" H 8200 6250 50  0001 C CNN
	1    8200 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 6150 8200 6250
$Comp
L power:GND #PWR0325
U 1 1 5E2C3292
P 8050 6250
F 0 "#PWR0325" H 8050 6000 50  0001 C CNN
F 1 "GND" H 8055 6077 50  0000 C CNN
F 2 "" H 8050 6250 50  0001 C CNN
F 3 "" H 8050 6250 50  0001 C CNN
	1    8050 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 6150 8050 6250
Connection ~ 8050 6150
Text GLabel 7450 6250 2    50   Input ~ 10
ADF_SCLK
Text GLabel 7450 6350 2    50   Input ~ 10
ADF_SREAD
Text GLabel 7450 6450 2    50   Input ~ 10
ADF_SDATA
Text GLabel 7450 6550 2    50   Input ~ 10
ADF_SLE
Wire Wire Line
	8200 5850 8200 5950
Connection ~ 8200 5850
Wire Wire Line
	6300 7100 6300 7200
Wire Wire Line
	6300 7200 6400 7200
Text GLabel 6400 7200 2    50   Input ~ 10
ADF_CE
NoConn ~ 6200 7100
NoConn ~ 6000 7100
NoConn ~ 5900 7100
NoConn ~ 5700 7100
NoConn ~ 5600 7100
NoConn ~ 5500 7100
NoConn ~ 5400 7100
NoConn ~ 5300 7100
NoConn ~ 5200 7100
$Comp
L power:GND #PWR0320
U 1 1 5E3D9CF0
P 6100 7200
F 0 "#PWR0320" H 6100 6950 50  0001 C CNN
F 1 "GND" H 6105 7027 50  0000 C CNN
F 2 "" H 6100 7200 50  0001 C CNN
F 3 "" H 6100 7200 50  0001 C CNN
	1    6100 7200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0318
U 1 1 5E3DAB40
P 5800 7200
F 0 "#PWR0318" H 5800 6950 50  0001 C CNN
F 1 "GND" H 5805 7027 50  0000 C CNN
F 2 "" H 5800 7200 50  0001 C CNN
F 3 "" H 5800 7200 50  0001 C CNN
	1    5800 7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 7100 5800 7200
Wire Wire Line
	6100 7100 6100 7200
$Comp
L power:GND #PWR0322
U 1 1 5E3EEEBD
P 6900 7200
F 0 "#PWR0322" H 6900 6950 50  0001 C CNN
F 1 "GND" H 6905 7027 50  0000 C CNN
F 2 "" H 6900 7200 50  0001 C CNN
F 3 "" H 6900 7200 50  0001 C CNN
	1    6900 7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 6850 6900 6850
Wire Wire Line
	6900 6850 6900 7200
$Comp
L power:GND #PWR0315
U 1 1 5E3F9D6A
P 4550 7200
F 0 "#PWR0315" H 4550 6950 50  0001 C CNN
F 1 "GND" H 4555 7027 50  0000 C CNN
F 2 "" H 4550 7200 50  0001 C CNN
F 3 "" H 4550 7200 50  0001 C CNN
	1    4550 7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 6550 4550 6550
Wire Wire Line
	4550 6550 4550 7200
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C309
U 1 1 5E406A00
P 4250 6850
F 0 "C309" H 4342 6896 50  0000 L CNN
F 1 "100n" H 4342 6805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4250 6850 50  0001 C CNN
F 3 "~" H 4250 6850 50  0001 C CNN
F 4 "50" H 4250 6850 50  0001 C CNN "Voltage"
F 5 "10" H 4250 6850 50  0001 C CNN "Tolerance"
F 6 "X7R" H 4250 6850 50  0001 C CNN "TempCoef"
	1    4250 6850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0313
U 1 1 5E407D99
P 4250 7200
F 0 "#PWR0313" H 4250 6950 50  0001 C CNN
F 1 "GND" H 4255 7027 50  0000 C CNN
F 2 "" H 4250 7200 50  0001 C CNN
F 3 "" H 4250 7200 50  0001 C CNN
	1    4250 7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 6950 4250 7200
Wire Wire Line
	4250 6750 4250 6450
$Comp
L tx_board-rescue:R_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue R304
U 1 1 5E41DD9F
P 3950 6850
F 0 "R304" H 4009 6896 50  0000 L CNN
F 1 "3k6" H 4009 6805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3950 6850 50  0001 C CNN
F 3 "~" H 3950 6850 50  0001 C CNN
F 4 "0.125" H 3950 6850 50  0001 C CNN "Power"
F 5 "5" H 3950 6850 50  0001 C CNN "Tolerance"
	1    3950 6850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0312
U 1 1 5E41EF62
P 3950 7200
F 0 "#PWR0312" H 3950 6950 50  0001 C CNN
F 1 "GND" H 3955 7027 50  0000 C CNN
F 2 "" H 3950 7200 50  0001 C CNN
F 3 "" H 3950 7200 50  0001 C CNN
	1    3950 7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 6950 3950 7200
Wire Wire Line
	3950 6750 3950 6350
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C304
U 1 1 5E435E4D
P 3650 6850
F 0 "C304" H 3742 6896 50  0000 L CNN
F 1 "10n" H 3742 6805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3650 6850 50  0001 C CNN
F 3 "~" H 3650 6850 50  0001 C CNN
F 4 "10" H 3650 6850 50  0001 C CNN "Tolerance"
F 5 "50" H 3650 6850 50  0001 C CNN "Voltage"
F 6 "X7R" H 3650 6850 50  0001 C CNN "TempCoef"
	1    3650 6850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0308
U 1 1 5E44277E
P 3650 7200
F 0 "#PWR0308" H 3650 6950 50  0001 C CNN
F 1 "GND" H 3655 7027 50  0000 C CNN
F 2 "" H 3650 7200 50  0001 C CNN
F 3 "" H 3650 7200 50  0001 C CNN
	1    3650 7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 6950 3650 7200
$Comp
L tx_board-rescue:R_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue R302
U 1 1 5E45AB33
P 3350 6850
F 0 "R302" H 3409 6896 50  0000 L CNN
F 1 "1k1" H 3409 6805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3350 6850 50  0001 C CNN
F 3 "~" H 3350 6850 50  0001 C CNN
F 4 "0.125" H 3350 6850 50  0001 C CNN "Power"
F 5 "5" H 3350 6850 50  0001 C CNN "Tolerance"
	1    3350 6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 6150 3350 6750
$Comp
L power:GND #PWR0304
U 1 1 5E467878
P 3350 7200
F 0 "#PWR0304" H 3350 6950 50  0001 C CNN
F 1 "GND" H 3355 7027 50  0000 C CNN
F 2 "" H 3350 7200 50  0001 C CNN
F 3 "" H 3350 7200 50  0001 C CNN
	1    3350 7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 6950 3350 7200
Wire Wire Line
	4250 6450 4650 6450
Wire Wire Line
	3950 6350 4650 6350
Wire Wire Line
	3650 6250 4650 6250
Wire Wire Line
	3650 6250 3650 6750
Wire Wire Line
	3350 6150 4650 6150
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C302
U 1 1 5E565560
P 2800 5750
F 0 "C302" H 2700 5650 50  0000 C CNN
F 1 "10p" H 2700 5850 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2800 5750 50  0001 C CNN
F 3 "~" H 2800 5750 50  0001 C CNN
F 4 "50" H 2800 5750 50  0001 C CNN "Voltage"
F 5 "C0G" H 2800 5750 50  0001 C CNN "TempCoef"
F 6 "5" H 2800 5750 50  0001 C CNN "Tolerance"
	1    2800 5750
	0    -1   1    0   
$EndComp
Wire Wire Line
	2900 5750 3050 5750
Wire Wire Line
	4650 5850 4550 5850
$Comp
L power:GND #PWR0314
U 1 1 5E581A0F
P 4550 5850
F 0 "#PWR0314" H 4550 5600 50  0001 C CNN
F 1 "GND" V 4555 5722 50  0000 R CNN
F 2 "" H 4550 5850 50  0001 C CNN
F 3 "" H 4550 5850 50  0001 C CNN
	1    4550 5850
	0    1    1    0   
$EndComp
$Comp
L tx_board-rescue:L_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue L301
U 1 1 5E5822DB
P 3050 5550
F 0 "L301" V 3000 5500 50  0000 L CNN
F 1 "15n" V 3150 5500 50  0000 L CNN
F 2 "Inductor_SMD:L_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3050 5550 50  0001 C CNN
F 3 "~" H 3050 5550 50  0001 C CNN
	1    3050 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 5650 3050 5750
Connection ~ 3050 5750
Wire Wire Line
	3050 5750 4650 5750
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C301
U 1 1 5E58FDA7
P 2700 5050
F 0 "C301" H 2792 5096 50  0000 L CNN
F 1 "220p" H 2792 5005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2700 5050 50  0001 C CNN
F 3 "~" H 2700 5050 50  0001 C CNN
F 4 "50" H 2700 5050 50  0001 C CNN "Voltage"
F 5 "C0G" H 2700 5050 50  0001 C CNN "TempCoef"
F 6 "5" H 2700 5050 50  0001 C CNN "Tolerance"
	1    2700 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0301
U 1 1 5E590ACA
P 2700 5250
F 0 "#PWR0301" H 2700 5000 50  0001 C CNN
F 1 "GND" H 2705 5077 50  0000 C CNN
F 2 "" H 2700 5250 50  0001 C CNN
F 3 "" H 2700 5250 50  0001 C CNN
	1    2700 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 5150 2700 5250
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C303
U 1 1 5E5ACCE9
P 3400 5050
F 0 "C303" H 3492 5096 50  0000 L CNN
F 1 "10n" H 3492 5005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3400 5050 50  0001 C CNN
F 3 "~" H 3400 5050 50  0001 C CNN
F 4 "10" H 3400 5050 50  0001 C CNN "Tolerance"
F 5 "50" H 3400 5050 50  0001 C CNN "Voltage"
F 6 "X7R" H 3400 5050 50  0001 C CNN "TempCoef"
	1    3400 5050
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0305
U 1 1 5E5AD1CD
P 3400 5250
F 0 "#PWR0305" H 3400 5000 50  0001 C CNN
F 1 "GND" H 3405 5077 50  0000 C CNN
F 2 "" H 3400 5250 50  0001 C CNN
F 3 "" H 3400 5250 50  0001 C CNN
	1    3400 5250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3400 5150 3400 5250
Wire Wire Line
	3400 4950 3400 4850
Wire Wire Line
	3400 4850 3050 4850
Wire Wire Line
	2700 4850 2700 4950
Wire Wire Line
	2700 4850 3050 4850
Wire Wire Line
	3050 4850 3050 5450
Wire Wire Line
	3050 4850 3050 4750
Connection ~ 3050 4850
$Comp
L power:+3.3V #PWR0302
U 1 1 5E5E64EC
P 3050 4750
F 0 "#PWR0302" H 3050 4600 50  0001 C CNN
F 1 "+3.3V" H 3065 4923 50  0000 C CNN
F 2 "" H 3050 4750 50  0001 C CNN
F 3 "" H 3050 4750 50  0001 C CNN
	1    3050 4750
	1    0    0    -1  
$EndComp
Text GLabel 2600 5750 0    50   Input ~ 10
TX
Wire Wire Line
	2600 5750 2700 5750
$Comp
L power:+3.3V #PWR0307
U 1 1 5E606987
P 3650 4950
F 0 "#PWR0307" H 3650 4800 50  0001 C CNN
F 1 "+3.3V" H 3665 5123 50  0000 C CNN
F 2 "" H 3650 4950 50  0001 C CNN
F 3 "" H 3650 4950 50  0001 C CNN
	1    3650 4950
	1    0    0    -1  
$EndComp
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C307
U 1 1 5E606EE2
P 3950 5250
F 0 "C307" H 4042 5296 50  0000 L CNN
F 1 "10n" H 4042 5205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3950 5250 50  0001 C CNN
F 3 "~" H 3950 5250 50  0001 C CNN
F 4 "10" H 3950 5250 50  0001 C CNN "Tolerance"
F 5 "50" H 3950 5250 50  0001 C CNN "Voltage"
F 6 "X7R" H 3950 5250 50  0001 C CNN "TempCoef"
	1    3950 5250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0311
U 1 1 5E606EEC
P 3950 5450
F 0 "#PWR0311" H 3950 5200 50  0001 C CNN
F 1 "GND" H 3955 5277 50  0000 C CNN
F 2 "" H 3950 5450 50  0001 C CNN
F 3 "" H 3950 5450 50  0001 C CNN
	1    3950 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 5350 3950 5450
$Comp
L power:+3.3V #PWR0310
U 1 1 5E6175EC
P 3950 4950
F 0 "#PWR0310" H 3950 4800 50  0001 C CNN
F 1 "+3.3V" H 3965 5123 50  0000 C CNN
F 2 "" H 3950 4950 50  0001 C CNN
F 3 "" H 3950 4950 50  0001 C CNN
	1    3950 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 5650 4250 5650
Wire Wire Line
	4650 5450 4550 5450
$Comp
L tx_board-rescue:R_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue R305
U 1 1 5E657124
P 4150 4350
F 0 "R305" V 3954 4350 50  0000 C CNN
F 1 "3R9" V 4045 4350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4150 4350 50  0001 C CNN
F 3 "~" H 4150 4350 50  0001 C CNN
F 4 "0.125" H 4150 4350 50  0001 C CNN "Power"
F 5 "5" H 4150 4350 50  0001 C CNN "Tolerance"
	1    4150 4350
	0    1    1    0   
$EndComp
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C306
U 1 1 5E65807F
P 3850 4350
F 0 "C306" V 3621 4350 50  0000 C CNN
F 1 "100n" V 3712 4350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3850 4350 50  0001 C CNN
F 3 "~" H 3850 4350 50  0001 C CNN
F 4 "50" H 3850 4350 50  0001 C CNN "Voltage"
F 5 "10" H 3850 4350 50  0001 C CNN "Tolerance"
F 6 "X7R" H 3850 4350 50  0001 C CNN "TempCoef"
	1    3850 4350
	0    1    1    0   
$EndComp
Wire Wire Line
	3950 4350 4050 4350
$Comp
L power:GND #PWR0306
U 1 1 5E669C8F
P 3650 4450
F 0 "#PWR0306" H 3650 4200 50  0001 C CNN
F 1 "GND" H 3655 4277 50  0000 C CNN
F 2 "" H 3650 4450 50  0001 C CNN
F 3 "" H 3650 4450 50  0001 C CNN
	1    3650 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 4350 3650 4350
Wire Wire Line
	3650 4350 3650 4450
Wire Wire Line
	5300 4850 5300 4750
Wire Wire Line
	5300 4750 5500 4750
Wire Wire Line
	5500 4750 5500 4850
Wire Wire Line
	5300 4750 4700 4750
Wire Wire Line
	4700 4750 4700 4850
Connection ~ 5300 4750
$Comp
L power:GND #PWR0316
U 1 1 5E69DFD9
P 4700 4850
F 0 "#PWR0316" H 4700 4600 50  0001 C CNN
F 1 "GND" H 4705 4677 50  0000 C CNN
F 2 "" H 4700 4850 50  0001 C CNN
F 3 "" H 4700 4850 50  0001 C CNN
	1    4700 4850
	1    0    0    -1  
$EndComp
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C311
U 1 1 5E69E757
P 5000 4350
F 0 "C311" V 4771 4350 50  0000 C CNN
F 1 "22n" V 4862 4350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5000 4350 50  0001 C CNN
F 3 "~" H 5000 4350 50  0001 C CNN
F 4 "50" H 5000 4350 50  0001 C CNN "Voltage"
F 5 "X7R" H 5000 4350 50  0001 C CNN "TempCoef"
F 6 "10" H 5000 4350 50  0001 C CNN "Tolerance"
	1    5000 4350
	0    1    1    0   
$EndComp
Wire Wire Line
	3950 5150 3950 5050
Wire Wire Line
	3950 5050 4250 5050
Wire Wire Line
	4250 5050 4250 5650
Wire Wire Line
	3950 4950 3950 5050
Connection ~ 3950 5050
Connection ~ 3650 6250
Wire Wire Line
	5100 4350 5200 4350
Wire Wire Line
	5200 4350 5200 4850
Wire Wire Line
	4250 4350 4450 4350
Wire Wire Line
	4450 4350 4450 5550
Connection ~ 4450 4350
Wire Wire Line
	4450 4350 4900 4350
$Comp
L tx_board-rescue:R_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue R308
U 1 1 5E7B0720
P 5000 3300
F 0 "R308" H 5059 3346 50  0000 L CNN
F 1 "560" H 5059 3255 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5000 3300 50  0001 C CNN
F 3 "~" H 5000 3300 50  0001 C CNN
F 4 "0.125" H 5000 3300 50  0001 C CNN "Power"
F 5 "5" H 5000 3300 50  0001 C CNN "Tolerance"
	1    5000 3300
	1    0    0    -1  
$EndComp
$Comp
L tx_board-rescue:R_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue R309
U 1 1 5E7B09A5
P 5300 3300
F 0 "R309" H 5359 3346 50  0000 L CNN
F 1 "270" H 5359 3255 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5300 3300 50  0001 C CNN
F 3 "~" H 5300 3300 50  0001 C CNN
F 4 "0.125" H 5300 3300 50  0001 C CNN "Power"
F 5 "5" H 5300 3300 50  0001 C CNN "Tolerance"
	1    5300 3300
	1    0    0    -1  
$EndComp
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C313
U 1 1 5E7B0D8A
P 5600 3300
F 0 "C313" H 5650 3400 50  0000 L CNN
F 1 "1n" H 5650 3200 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5600 3300 50  0001 C CNN
F 3 "~" H 5600 3300 50  0001 C CNN
F 4 "50" H 5600 3300 50  0001 C CNN "Voltage"
F 5 "X7R" H 5600 3300 50  0001 C CNN "TempCoef"
F 6 "10" H 5600 3300 50  0001 C CNN "Tolerance"
	1    5600 3300
	1    0    0    -1  
$EndComp
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C310
U 1 1 5E7B1D9F
P 5000 3700
F 0 "C310" H 5092 3746 50  0000 L CNN
F 1 "470p" H 5092 3655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5000 3700 50  0001 C CNN
F 3 "~" H 5000 3700 50  0001 C CNN
F 4 "50" H 5000 3700 50  0001 C CNN "Voltage"
F 5 "C0G" H 5000 3700 50  0001 C CNN "TempCoef"
F 6 "5" H 5000 3700 50  0001 C CNN "Tolerance"
	1    5000 3700
	1    0    0    -1  
$EndComp
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C312
U 1 1 5E7B3173
P 5300 3700
F 0 "C312" H 5392 3746 50  0000 L CNN
F 1 "15n" H 5392 3655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5300 3700 50  0001 C CNN
F 3 "~" H 5300 3700 50  0001 C CNN
F 4 "50" H 5300 3700 50  0001 C CNN "Voltage"
F 5 "X7R" H 5300 3700 50  0001 C CNN "TempCoef"
F 6 "10" H 5300 3700 50  0001 C CNN "Tolerance"
	1    5300 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 3400 5300 3600
Wire Wire Line
	5000 3800 5000 3900
Wire Wire Line
	5000 3900 5300 3900
Wire Wire Line
	5300 3900 5300 3800
Wire Wire Line
	5300 3900 5600 3900
Wire Wire Line
	5600 3900 5600 3400
Connection ~ 5300 3900
Wire Wire Line
	5300 3900 5300 4000
Wire Wire Line
	5800 4850 5800 3500
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C315
U 1 1 5E88DD91
P 6550 4750
F 0 "C315" V 6321 4750 50  0000 C CNN
F 1 "100n" V 6412 4750 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6550 4750 50  0001 C CNN
F 3 "~" H 6550 4750 50  0001 C CNN
F 4 "50" H 6550 4750 50  0001 C CNN "Voltage"
F 5 "10" H 6550 4750 50  0001 C CNN "Tolerance"
F 6 "X7R" H 6550 4750 50  0001 C CNN "TempCoef"
	1    6550 4750
	0    -1   1    0   
$EndComp
$Comp
L power:GND #PWR0321
U 1 1 5E88DD9B
P 6750 4850
F 0 "#PWR0321" H 6750 4600 50  0001 C CNN
F 1 "GND" H 6755 4677 50  0000 C CNN
F 2 "" H 6750 4850 50  0001 C CNN
F 3 "" H 6750 4850 50  0001 C CNN
	1    6750 4850
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6650 4750 6750 4750
Wire Wire Line
	6750 4750 6750 4850
Wire Wire Line
	5900 4850 5900 4750
Wire Wire Line
	5900 4750 6450 4750
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C314
U 1 1 5E8CFCCF
P 6550 4350
F 0 "C314" V 6321 4350 50  0000 C CNN
F 1 "10n" V 6412 4350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6550 4350 50  0001 C CNN
F 3 "~" H 6550 4350 50  0001 C CNN
F 4 "10" H 6550 4350 50  0001 C CNN "Tolerance"
F 5 "50" H 6550 4350 50  0001 C CNN "Voltage"
F 6 "X7R" H 6550 4350 50  0001 C CNN "TempCoef"
	1    6550 4350
	0    -1   1    0   
$EndComp
Wire Wire Line
	5700 4850 5700 4350
Wire Wire Line
	5700 4350 6000 4350
Wire Wire Line
	6000 4850 6000 4350
Connection ~ 6000 4350
Wire Wire Line
	6000 4350 6450 4350
Wire Wire Line
	6650 4350 6750 4350
Wire Wire Line
	6750 4350 6750 4750
Connection ~ 6750 4750
Wire Wire Line
	6000 4350 6000 4250
$Comp
L power:+3.3V #PWR0319
U 1 1 5E940DC5
P 6000 4250
F 0 "#PWR0319" H 6000 4100 50  0001 C CNN
F 1 "+3.3V" H 6015 4423 50  0000 C CNN
F 2 "" H 6000 4250 50  0001 C CNN
F 3 "" H 6000 4250 50  0001 C CNN
	1    6000 4250
	1    0    0    -1  
$EndComp
$Comp
L tx_board-rescue:L_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue L303
U 1 1 5EA553CC
P 10150 5400
F 0 "L303" V 10335 5400 50  0000 C CNN
F 1 "20n" V 10244 5400 50  0000 C CNN
F 2 "Inductor_SMD:L_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 10150 5400 50  0001 C CNN
F 3 "~" H 10150 5400 50  0001 C CNN
	1    10150 5400
	0    -1   -1   0   
$EndComp
$Comp
L tx_board-rescue:L_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue L304
U 1 1 5EA567ED
P 10550 5400
F 0 "L304" V 10735 5400 50  0000 C CNN
F 1 "22n" V 10644 5400 50  0000 C CNN
F 2 "Inductor_SMD:L_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 10550 5400 50  0001 C CNN
F 3 "~" H 10550 5400 50  0001 C CNN
	1    10550 5400
	0    -1   -1   0   
$EndComp
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C319
U 1 1 5EA5722F
P 10350 5600
F 0 "C319" H 10442 5646 50  0000 L CNN
F 1 "6p8" H 10442 5555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 10350 5600 50  0001 C CNN
F 3 "~" H 10350 5600 50  0001 C CNN
F 4 "50" H 10350 5600 50  0001 C CNN "Voltage"
F 5 "C0G" H 10350 5600 50  0001 C CNN "TempCoef"
F 6 "5" H 10350 5600 50  0001 C CNN "Tolerance"
	1    10350 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	10250 5400 10350 5400
Wire Wire Line
	10350 5400 10350 5500
Connection ~ 10350 5400
Wire Wire Line
	10350 5400 10450 5400
Wire Wire Line
	9950 5400 10050 5400
Wire Wire Line
	10650 5400 10750 5400
Wire Wire Line
	6800 5850 8200 5850
Text GLabel 7600 5750 2    50   Output ~ 10
ADF_SWD
$Comp
L tx_board-rescue:R_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue R307
U 1 1 5E39EE3B
P 4750 3500
F 0 "R307" V 4554 3500 50  0000 C CNN
F 1 "100" V 4645 3500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4750 3500 50  0001 C CNN
F 3 "~" H 4750 3500 50  0001 C CNN
F 4 "0.125" H 4750 3500 50  0001 C CNN "Power"
F 5 "5" H 4750 3500 50  0001 C CNN "Tolerance"
	1    4750 3500
	0    1    1    0   
$EndComp
$Comp
L tx_board-rescue:R_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue R306
U 1 1 5E39F1EF
P 4300 3500
F 0 "R306" V 4104 3500 50  0000 C CNN
F 1 "47k" V 4195 3500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4300 3500 50  0001 C CNN
F 3 "~" H 4300 3500 50  0001 C CNN
F 4 "0.125" H 4300 3500 50  0001 C CNN "Power"
F 5 "5" H 4300 3500 50  0001 C CNN "Tolerance"
	1    4300 3500
	0    1    1    0   
$EndComp
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C308
U 1 1 5E39F459
P 4000 3500
F 0 "C308" V 3771 3500 50  0000 C CNN
F 1 "100n" V 3862 3500 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4000 3500 50  0001 C CNN
F 3 "~" H 4000 3500 50  0001 C CNN
F 4 "50" H 4000 3500 50  0001 C CNN "Voltage"
F 5 "10" H 4000 3500 50  0001 C CNN "Tolerance"
F 6 "X7R" H 4000 3500 50  0001 C CNN "TempCoef"
	1    4000 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	5000 3400 5000 3500
Wire Wire Line
	4400 3500 4550 3500
Wire Wire Line
	4550 3500 4550 4000
Connection ~ 4550 3500
Wire Wire Line
	4550 3500 4650 3500
Wire Wire Line
	4450 5550 4650 5550
Wire Wire Line
	4850 3500 5000 3500
Connection ~ 5000 3500
Wire Wire Line
	5000 3500 5000 3600
Wire Wire Line
	4200 3500 4100 3500
Text GLabel 3100 3500 0    50   Input ~ 10
FM_MOD
Text Notes 4900 2900 2    50   ~ 0
Voltage at this point should be 0.2-2V
Wire Notes Line
	4900 3450 4900 2900
Wire Notes Line
	4900 2900 3400 2900
$Comp
L tx_board-rescue:TestPoint_Probe-Connector-Mainboard-rescue-rx_board-rescue-rx_board-rescue TP302
U 1 1 5E4B8F5F
P 5000 3500
F 0 "TP302" H 5153 3601 50  0000 L CNN
F 1 "TestPoint_Probe" H 5153 3510 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 5200 3500 50  0001 C CNN
F 3 "~" H 5200 3500 50  0001 C CNN
	1    5000 3500
	1    0    0    -1  
$EndComp
$Comp
L tx_board-rescue:TestPoint_Probe-Connector-Mainboard-rescue-rx_board-rescue-rx_board-rescue TP301
U 1 1 5E4BA4A8
P 4550 4000
F 0 "TP301" H 4703 4101 50  0000 L CNN
F 1 "TestPoint_Probe" H 4703 4010 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 4750 4000 50  0001 C CNN
F 3 "~" H 4750 4000 50  0001 C CNN
	1    4550 4000
	1    0    0    -1  
$EndComp
Connection ~ 4550 4000
Wire Wire Line
	4550 4000 4550 5450
$Comp
L tx_board-rescue:TestPoint_Probe-Connector-Mainboard-rescue-rx_board-rescue-rx_board-rescue TP303
U 1 1 5E4BB697
P 5800 3500
F 0 "TP303" H 5953 3601 50  0000 L CNN
F 1 "TestPoint_Probe" H 5953 3510 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 6000 3500 50  0001 C CNN
F 3 "~" H 6000 3500 50  0001 C CNN
	1    5800 3500
	1    0    0    -1  
$EndComp
$Comp
L tx_board-rescue:R_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue R301
U 1 1 5E462A64
P 3200 3650
F 0 "R301" V 3004 3650 50  0000 C CNN
F 1 "22k" V 3095 3650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3200 3650 50  0001 C CNN
F 3 "~" H 3200 3650 50  0001 C CNN
F 4 "0.125" H 3200 3650 50  0001 C CNN "Power"
F 5 "5" H 3200 3650 50  0001 C CNN "Tolerance"
	1    3200 3650
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0317
U 1 1 5E8261D5
P 5300 4000
F 0 "#PWR0317" H 5300 3750 50  0001 C CNN
F 1 "GND" H 5305 3827 50  0000 C CNN
F 2 "" H 5300 4000 50  0001 C CNN
F 3 "" H 5300 4000 50  0001 C CNN
	1    5300 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0303
U 1 1 5E47AF06
P 3200 3850
F 0 "#PWR0303" H 3200 3600 50  0001 C CNN
F 1 "GND" H 3205 3677 50  0000 C CNN
F 2 "" H 3200 3850 50  0001 C CNN
F 3 "" H 3200 3850 50  0001 C CNN
	1    3200 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 3500 3200 3500
Wire Wire Line
	3200 3500 3200 3550
Wire Wire Line
	3200 3750 3200 3850
$Comp
L tx_board-rescue:R_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue R303
U 1 1 5E4AF468
P 3500 3500
F 0 "R303" V 3304 3500 50  0000 C CNN
F 1 "47k" V 3395 3500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3500 3500 50  0001 C CNN
F 3 "~" H 3500 3500 50  0001 C CNN
F 4 "0.125" H 3500 3500 50  0001 C CNN "Power"
F 5 "5" H 3500 3500 50  0001 C CNN "Tolerance"
	1    3500 3500
	0    -1   -1   0   
$EndComp
$Comp
L tx_board-rescue:C_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C305
U 1 1 5E4AF96C
P 3700 3650
F 0 "C305" V 3471 3650 50  0000 C CNN
F 1 "2n2" V 3562 3650 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3700 3650 50  0001 C CNN
F 3 "~" H 3700 3650 50  0001 C CNN
F 4 "50" H 3700 3650 50  0001 C CNN "Voltage"
F 5 "5" H 3700 3650 50  0001 C CNN "Tolerance"
F 6 "X7R" H 3700 3650 50  0001 C CNN "TempCoef"
	1    3700 3650
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0309
U 1 1 5E4C885A
P 3700 3850
F 0 "#PWR0309" H 3700 3600 50  0001 C CNN
F 1 "GND" H 3705 3677 50  0000 C CNN
F 2 "" H 3700 3850 50  0001 C CNN
F 3 "" H 3700 3850 50  0001 C CNN
	1    3700 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 3750 3700 3850
Wire Wire Line
	3700 3550 3700 3500
Connection ~ 3700 3500
Wire Wire Line
	3700 3500 3900 3500
Wire Wire Line
	3400 3500 3200 3500
Connection ~ 3200 3500
Wire Wire Line
	3600 3500 3700 3500
Text GLabel 7600 5450 2    50   Input ~ 10
SPI2_SCK
Text GLabel 7600 5550 2    50   Input ~ 10
SPI2_MISO
Text GLabel 7600 5650 2    50   Input ~ 10
SPI2_MOSI
$Comp
L tx_board-rescue:L_Small-Device-Mainboard-rescue-rx_board-rescue-rx_board-rescue L302
U 1 1 5E528AE0
P 5500 4600
F 0 "L302" V 5450 4550 50  0000 L CNN
F 1 "DNP" V 5600 4550 50  0000 L CNN
F 2 "Inductor_SMD:L_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5500 4600 50  0001 C CNN
F 3 "~" H 5500 4600 50  0001 C CNN
	1    5500 4600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5600 4600 5600 4850
Wire Wire Line
	5400 4600 5400 4850
$Comp
L tx_board-rescue:C_Small-device-Mainboard-rescue-rx_board-rescue-rx_board-rescue C?
U 1 1 5E56F3D1
P 7900 7000
AR Path="/5DEDCA32/5E56F3D1" Ref="C?"  Part="1" 
AR Path="/5DF0E505/5E56F3D1" Ref="C?"  Part="1" 
AR Path="/5E56F3D1" Ref="C317"  Part="1" 
F 0 "C317" H 7992 7046 50  0000 L CNN
F 1 "22u/TA" H 7992 6955 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-3216-18_Kemet-A_Pad1.58x1.35mm_HandSolder" H 7900 7000 50  0001 C CNN
F 3 "~" H 7900 7000 50  0001 C CNN
F 4 "TAJA226K006RNJV" H 7900 7000 50  0001 C CNN "Partno"
F 5 "10" H 7900 7000 50  0001 C CNN "Tolerance"
F 6 "10" H 7900 7000 50  0001 C CNN "Voltage"
F 7 "TANTAL" H 7900 7000 50  0001 C CNN "TempCoef"
	1    7900 7000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 6800 7900 6900
Wire Wire Line
	7900 7200 7900 7100
$Comp
L power:+3.3V #PWR0323
U 1 1 5E5897DB
P 7900 6800
F 0 "#PWR0323" H 7900 6650 50  0001 C CNN
F 1 "+3.3V" H 7915 6973 50  0000 C CNN
F 2 "" H 7900 6800 50  0001 C CNN
F 3 "" H 7900 6800 50  0001 C CNN
	1    7900 6800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0324
U 1 1 5E589C85
P 7900 7200
F 0 "#PWR0324" H 7900 6950 50  0001 C CNN
F 1 "GND" H 7905 7027 50  0000 C CNN
F 2 "" H 7900 7200 50  0001 C CNN
F 3 "" H 7900 7200 50  0001 C CNN
	1    7900 7200
	1    0    0    -1  
$EndComp
Text GLabel 7600 5350 2    50   Output ~ 10
ADF_MUXOUT
$Comp
L tx_board-rescue:ADF7021-adf7021-rx_board-rescue-rx_board-rescue U301
U 1 1 5E245F16
P 5650 6000
F 0 "U301" H 5650 6050 49  0000 C CNN
F 1 "ADF7021" H 5650 5950 49  0000 C CNN
F 2 "Package_CSP:LFCSP-48-1EP_7x7mm_P0.5mm_EP4.1x4.1mm_ThermalVias" H 5450 5750 49  0001 C CNN
F 3 "" H 5450 5750 49  0001 C CNN
	1    5650 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 4850 6300 4650
Wire Wire Line
	6300 4650 6850 4650
$Comp
L Device:R_Pack04 RN302
U 1 1 5E711FA8
P 7200 5550
F 0 "RN302" V 6783 5550 50  0000 C CNN
F 1 "4 x 1k ISOLATED" V 6874 5550 50  0000 C CNN
F 2 "Resistor_SMD:R_Array_Concave_4x0603" V 7475 5550 50  0001 C CNN
F 3 "~" H 7200 5550 50  0001 C CNN
F 4 "5" H 7200 5550 50  0001 C CNN "Tolerance"
	1    7200 5550
	0    1    1    0   
$EndComp
Wire Wire Line
	6800 5750 7600 5750
Wire Wire Line
	7400 5650 7600 5650
Wire Wire Line
	7600 5550 7400 5550
Wire Wire Line
	7400 5450 7600 5450
Wire Wire Line
	7600 5350 7400 5350
Wire Wire Line
	6850 5350 7000 5350
Wire Wire Line
	6850 4650 6850 5350
Wire Wire Line
	7000 5450 6800 5450
Wire Wire Line
	7000 5550 6800 5550
Wire Wire Line
	7000 5650 6800 5650
$Comp
L Device:R_Pack04 RN301
U 1 1 5E8F8B20
P 7150 6450
F 0 "RN301" V 7350 6450 50  0000 C CNN
F 1 "4 x 1k ISOLATED" V 7450 6450 50  0000 C CNN
F 2 "Resistor_SMD:R_Array_Concave_4x0603" V 7425 6450 50  0001 C CNN
F 3 "~" H 7150 6450 50  0001 C CNN
F 4 "5" H 7150 6450 50  0001 C CNN "Tolerance"
	1    7150 6450
	0    1    1    0   
$EndComp
Wire Wire Line
	7150 5950 8050 5950
Wire Wire Line
	6800 6150 8050 6150
Wire Wire Line
	6800 6250 6950 6250
Wire Wire Line
	6800 6350 6950 6350
Wire Wire Line
	6800 6450 6950 6450
Wire Wire Line
	6800 6550 6950 6550
Wire Wire Line
	7350 6250 7450 6250
Wire Wire Line
	7450 6350 7350 6350
Wire Wire Line
	7350 6450 7450 6450
Wire Wire Line
	7350 6550 7450 6550
NoConn ~ 4650 6050
NoConn ~ 4650 5950
Wire Wire Line
	6200 3850 6200 4850
Text GLabel 7600 3850 2    50   Input ~ 10
EXT_OSC2_IN
$Comp
L power:GND #PWR0328
U 1 1 5EA584A1
P 10350 5800
F 0 "#PWR0328" H 10350 5550 50  0001 C CNN
F 1 "GND" H 10355 5627 50  0000 C CNN
F 2 "" H 10350 5800 50  0001 C CNN
F 3 "" H 10350 5800 50  0001 C CNN
	1    10350 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 2750 5300 2750
Wire Wire Line
	5800 2750 5800 3500
Wire Wire Line
	5000 2750 5000 3200
Connection ~ 5800 3500
Wire Wire Line
	5300 3200 5300 2750
Connection ~ 5300 2750
Wire Wire Line
	5300 2750 5600 2750
Wire Wire Line
	5600 3200 5600 2750
Connection ~ 5600 2750
Wire Wire Line
	5600 2750 5800 2750
Wire Wire Line
	11050 5400 11300 5400
Wire Wire Line
	11500 5400 11750 5400
Wire Wire Line
	10350 5700 10350 5800
Wire Wire Line
	3650 4950 3650 6250
Wire Wire Line
	6200 3850 7600 3850
NoConn ~ 6100 4850
Text GLabel 7200 8550 3    50   Input ~ 0
ADF_SLE
Text GLabel 7300 8550 3    50   Input ~ 0
ADF_SDATA
Text GLabel 7400 8550 3    50   Input ~ 0
ADF_SREAD
Text GLabel 7500 8550 3    50   Input ~ 0
ADF_SCLK
Text GLabel 7600 8550 3    50   Input ~ 0
ADF_SWD
Text GLabel 7700 8550 3    50   Input ~ 0
SPI2_MOSI
Text GLabel 7800 8550 3    50   Input ~ 0
SPI2_MISO
Text GLabel 7900 8550 3    50   Input ~ 0
SPI2_SCK
Text GLabel 8000 8550 3    50   Input ~ 0
ADF_MUXOUT
Text GLabel 8200 8050 1    50   Input ~ 0
EXT_OSC2_IN
Text GLabel 7100 8550 3    50   Input ~ 0
ADF_CE
Wire Wire Line
	7800 8050 7800 7950
$Comp
L power:GND #PWR09
U 1 1 5F5CB5E7
P 7800 7950
F 0 "#PWR09" H 7800 7700 50  0001 C CNN
F 1 "GND" H 7805 7777 50  0000 C CNN
F 2 "" H 7800 7950 50  0001 C CNN
F 3 "" H 7800 7950 50  0001 C CNN
	1    7800 7950
	-1   0    0    1   
$EndComp
Wire Wire Line
	7400 8050 7400 7950
$Comp
L power:GND #PWR07
U 1 1 5F5D7938
P 7400 7950
F 0 "#PWR07" H 7400 7700 50  0001 C CNN
F 1 "GND" H 7405 7777 50  0000 C CNN
F 2 "" H 7400 7950 50  0001 C CNN
F 3 "" H 7400 7950 50  0001 C CNN
	1    7400 7950
	-1   0    0    1   
$EndComp
Wire Wire Line
	7200 8050 7200 7950
$Comp
L power:GND #PWR05
U 1 1 5F5DDB86
P 7200 7950
F 0 "#PWR05" H 7200 7700 50  0001 C CNN
F 1 "GND" H 7205 7777 50  0000 C CNN
F 2 "" H 7200 7950 50  0001 C CNN
F 3 "" H 7200 7950 50  0001 C CNN
	1    7200 7950
	-1   0    0    1   
$EndComp
Wire Wire Line
	8100 8050 8100 7950
$Comp
L power:GND #PWR011
U 1 1 5F5FE8B3
P 8100 7950
F 0 "#PWR011" H 8100 7700 50  0001 C CNN
F 1 "GND" H 8105 7777 50  0000 C CNN
F 2 "" H 8100 7950 50  0001 C CNN
F 3 "" H 8100 7950 50  0001 C CNN
	1    8100 7950
	-1   0    0    1   
$EndComp
Wire Wire Line
	8300 8050 8300 7950
$Comp
L power:GND #PWR013
U 1 1 5F604F03
P 8300 7950
F 0 "#PWR013" H 8300 7700 50  0001 C CNN
F 1 "GND" H 8305 7777 50  0000 C CNN
F 2 "" H 8300 7950 50  0001 C CNN
F 3 "" H 8300 7950 50  0001 C CNN
	1    8300 7950
	-1   0    0    1   
$EndComp
Wire Wire Line
	8100 8550 8100 8650
$Comp
L power:GND #PWR012
U 1 1 5F61E8F6
P 8100 8650
F 0 "#PWR012" H 8100 8400 50  0001 C CNN
F 1 "GND" H 8105 8477 50  0000 C CNN
F 2 "" H 8100 8650 50  0001 C CNN
F 3 "" H 8100 8650 50  0001 C CNN
	1    8100 8650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 8550 8300 8650
$Comp
L power:GND #PWR014
U 1 1 5F625506
P 8300 8650
F 0 "#PWR014" H 8300 8400 50  0001 C CNN
F 1 "GND" H 8305 8477 50  0000 C CNN
F 2 "" H 8300 8650 50  0001 C CNN
F 3 "" H 8300 8650 50  0001 C CNN
	1    8300 8650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 8050 8250 8050
Wire Wire Line
	8250 8050 8250 8550
Wire Wire Line
	8250 8550 8200 8550
Wire Wire Line
	7000 8050 7000 7950
$Comp
L power:GND #PWR01
U 1 1 5F63C3C4
P 7000 7950
F 0 "#PWR01" H 7000 7700 50  0001 C CNN
F 1 "GND" H 7005 7777 50  0000 C CNN
F 2 "" H 7000 7950 50  0001 C CNN
F 3 "" H 7000 7950 50  0001 C CNN
	1    7000 7950
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR03
U 1 1 5F64B16D
P 7300 7950
F 0 "#PWR03" H 7300 7800 50  0001 C CNN
F 1 "+3.3V" H 7315 8123 50  0000 C CNN
F 2 "" H 7300 7950 50  0001 C CNN
F 3 "" H 7300 7950 50  0001 C CNN
	1    7300 7950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 7950 7300 8050
$Comp
L Connector_Generic:Conn_02x14_Odd_Even J1
U 1 1 5F6643F7
P 7600 8350
F 0 "J1" V 7604 9030 50  0000 L CNN
F 1 "Conn_02x14_Odd_Even" V 7695 9030 50  0000 L CNN
F 2 "edge_contact:edge_2x14pin" H 7600 8350 50  0001 C CNN
F 3 "~" H 7600 8350 50  0001 C CNN
	1    7600 8350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7100 8050 7100 8550
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 5F5F1835
P 9850 2200
F 0 "H1" H 9950 2249 50  0000 L CNN
F 1 "Würt_LGA_Shielding" H 9950 2158 50  0000 L CNN
F 2 "lib:WE_36103205_SMD" H 9850 2200 50  0001 C CNN
F 3 "~" H 9850 2200 50  0001 C CNN
	1    9850 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR017
U 1 1 5F5F2F75
P 9850 2350
F 0 "#PWR017" H 9850 2100 50  0001 C CNN
F 1 "GND" H 9855 2177 50  0000 C CNN
F 2 "" H 9850 2350 50  0001 C CNN
F 3 "" H 9850 2350 50  0001 C CNN
	1    9850 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9850 2300 9850 2350
$Comp
L power:GND #PWR016
U 1 1 5F5FAC6F
P 9500 2250
F 0 "#PWR016" H 9500 2000 50  0001 C CNN
F 1 "GND" H 9505 2077 50  0000 C CNN
F 2 "" H 9500 2250 50  0001 C CNN
F 3 "" H 9500 2250 50  0001 C CNN
	1    9500 2250
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG02
U 1 1 5F602B7C
P 9500 2200
F 0 "#FLG02" H 9500 2275 50  0001 C CNN
F 1 "PWR_FLAG" H 9500 2373 50  0000 C CNN
F 2 "" H 9500 2200 50  0001 C CNN
F 3 "~" H 9500 2200 50  0001 C CNN
	1    9500 2200
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR015
U 1 1 5F603595
P 9050 2250
F 0 "#PWR015" H 9050 2100 50  0001 C CNN
F 1 "+3.3V" H 9065 2423 50  0000 C CNN
F 2 "" H 9050 2250 50  0001 C CNN
F 3 "" H 9050 2250 50  0001 C CNN
	1    9050 2250
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG01
U 1 1 5F60B0F9
P 9050 2200
F 0 "#FLG01" H 9050 2275 50  0001 C CNN
F 1 "PWR_FLAG" H 9050 2373 50  0000 C CNN
F 2 "" H 9050 2200 50  0001 C CNN
F 3 "~" H 9050 2200 50  0001 C CNN
	1    9050 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 2200 9050 2250
Wire Wire Line
	9500 2200 9500 2250
$EndSCHEMATC
