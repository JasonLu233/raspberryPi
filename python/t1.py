import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

GPIO.setup(40,GPIO.OUT)
for i in range(0,10):
	GPIO.output(40,GPIO.LOW)
	time.sleep(1)
	GPIO.output(40,GPIO.HIGH)
	time.sleep(1)
GPIO.cleanup()	
