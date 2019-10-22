import RPi.GPIO as GPIO
import time

from w1thermsensor import W1ThermSensor
from smbus2 import SMBus
from mcp3208 import MCP3208

#Consts
T_SENSOR_1="000009a5e43c"
T_SENSOR_2="000009a60a09"
PCF_CTRL = 0x21
PCF_DATA = 0x20

#CTRL
OE_1  = 0
OE_2  = 1
OE_3  = 2
CLK_EN= 3
CLR   = 4
LATCH = 5
FAN_R = 6
FAN_L = 7

#----------------------------------------------------------------------------
def GetRPM(fan):
	if fan == 0:
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(0<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(0<<CLK_EN)|(1<<FAN_L)
		i2c.write_byte(PCF_CTRL, val)
		
		time.sleep(1)
		
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)|(0<<FAN_L)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)|(1<<LATCH)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)|(0<<LATCH)
		i2c.write_byte(PCF_CTRL, val)
		
		time.sleep(0.001)
		val=(0<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		r_1=i2c.read_byte(PCF_DATA)
		time.sleep(0.001)
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		
		val=(1<<OE_1)|(0<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		r_2=i2c.read_byte(PCF_DATA)
		time.sleep(0.001)
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		
		val=(1<<OE_1)|(1<<OE_2)|(0<<OE_3)|(1<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		r_3=i2c.read_byte(PCF_DATA)
		time.sleep(0.001)
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
	else:
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(0<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(0<<CLK_EN)|(1<<FAN_R)
		i2c.write_byte(PCF_CTRL, val)
		
		time.sleep(1)
		
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)|(0<<FAN_R)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)|(1<<LATCH)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)|(0<<LATCH)
		i2c.write_byte(PCF_CTRL, val)
		
		time.sleep(0.001)
		val=(0<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		r_1=i2c.read_byte(PCF_DATA)
		time.sleep(0.001)
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		
		val=(1<<OE_1)|(0<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		r_2=i2c.read_byte(PCF_DATA)
		time.sleep(0.001)
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		
		val=(1<<OE_1)|(1<<OE_2)|(0<<OE_3)|(1<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		r_3=i2c.read_byte(PCF_DATA)
		time.sleep(0.001)
		val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)
		i2c.write_byte(PCF_CTRL, val)
		time.sleep(0.001)
		
	return (r_1|(r_2<<8)|(r_3<<16))*15

#----------------------------------------------------------------------------
i2c = SMBus(1)
adc = MCP3208()

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(12, GPIO.OUT)
GPIO.setup(18, GPIO.OUT)
 
fan_L = GPIO.PWM(12, 500)
fan_R = GPIO.PWM(18, 500)
fan_L.start(20)
fan_R.start(20)

val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(0<<CLR)|(1<<CLK_EN)
i2c.write_byte(PCF_CTRL, val)
val=(1<<OE_1)|(1<<OE_2)|(1<<OE_3)|(1<<CLR)|(1<<CLK_EN)
i2c.write_byte(PCF_CTRL, val)

while True:
	sensor = W1ThermSensor(W1ThermSensor.THERM_SENSOR_DS18B20, T_SENSOR_1)
	temp_1 = sensor.get_temperature()
	sensor = W1ThermSensor(W1ThermSensor.THERM_SENSOR_DS18B20, T_SENSOR_2)
	temp_2 = sensor.get_temperature()

	left_fan=GetRPM(0)
	right_fan=GetRPM(1)
	
	u_psu=0
	u_bat=0
	for i in range(1000):
		u_psu+=adc.read(0)
		u_bat+=adc.read(1)
	u_psu/=1000.0
	u_bat/=1000.0
	u_psu*=14.46/1576.5
	u_bat*=14.46/1576.5 #might need to change coeffs
	
	#overwrite
	with open('/var/www/html/vals.txt', 'r') as file:
		data = file.readlines()
		data[0] = str(temp_1) + '\n'
		data[1] = str(temp_2) + '\n'
		data[2] = '20\n'
		data[3] = '20\n'
		data[4] = str(u_bat) + '\n'
		data[5] = str(u_psu) + '\n'		
		data[6] = str(left_fan) + '\n'
		data[7] = str(right_fan) + '\n'

		with open('/var/www/html/vals.txt', 'w') as file:
			file.writelines(data)

	#print("L=%dRPM, R=%dRPM" % (GetRPM(0), GetRPM(1)))

	#fan_L.ChangeDutyCycle(75)
	#fan_R.ChangeDutyCycle(75)

	#print("T_1=%.2f T_2=%.2f" % (temp_1, temp_2))
	
	#time.sleep(1)