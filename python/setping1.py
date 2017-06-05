#!/usr/bin/python3

import RPi.GPIO as gpio
import time
from array import *
import sys
'''arg1--方向 1-顺时针,0-逆时针
   arg2--角度  '''
way = int(sys.argv[1])
r = int(sys.argv[2])

angle = int((64/45)*r)

gpio.setmode(gpio.BOARD)
gpio.setwarnings(False)

arr = [0,1,2,3,4,5,6,7]

if way==1:
	arr.reverse()

t1 = 0.006
pins = [32,36,38,40]

pins8 = ([pins[0],pins[3]],
         pins[0],
         [pins[0],pins[1]],
         pins[1],
         [pins[1],pins[2]],
         pins[2],
         [pins[2],pins[3]],
         pins[3],
         [pins[3],pins[0]])

gpio.setup(pins,gpio.OUT)

try:
	for m in range(0,angle):
		for x in arr:
			time.sleep(t1)
			for i in range(0,8):
				if x == i:
					gpio.output(pins8[i],0)
					
				else:
					gpio.output(pins8[i],1)
			'''gpio.output(pins[x],1)
			time.sleep(t1)
			gpio.output(pins[x],0)
			time.sleep(t1)'''	

except KeyboardInterrupt:
	print('\nEXIT!')

finally:
	gpio.cleanup()

