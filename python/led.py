#!/usr/bin/python3

import RPi.GPIO as gpio
import time
from array import *
import sys

t1 = float(sys.argv[1])

gpio.setmode(gpio.BOARD)
gpio.setwarnings(False)

arr = [0,1,2]
#t1 = 0.15
pins = [36,38,40]

gpio.setup(pins,gpio.OUT)

try:
	while True:
		for x in arr:
			gpio.output(pins[x],1)
			time.sleep(t1)
			gpio.output(pins[x],0)
			time.sleep(t1)	

except KeyboardInterrupt:
	print('EXIT!')

finally:
	gpio.cleanup()

