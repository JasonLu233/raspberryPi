#!/usr/bin/python3
import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

trig = 40
echo = 32



GPIO.setup(trig,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(echo,GPIO.IN)


def _callback_u (a):
    print('callback pin 32 changed %f' %time.time())
    t1=time.time()
    

def _callback_d (a):
    print('callback pin 32 changed %f' %time.time())
    t2=time.time()
    
    
#GPIO.add_event_detect(echo,GPIO.RISING,callback=_callback_u)
#GPIO.add_event_detect(echo,GPIO.FALLING,callback=_callback_d)
#GPIO.add_event_callback(echo,,_32_callback)

def test():
    GPIO.output(trig,1)
    time.sleep(0.000012)
    GPIO.output(trig,0)
    
    while not GPIO.input(echo):
        pass
    t1 = time.time()
    #print('time t1 %f' %t1)
    while GPIO.input(echo):
        #print(GPIO.input(echo))
        pass
    t2 = time.time()
    #print('time t2 %f' %t2)
    return (t2-t1)*340/2

try :
    while True:
        print ('Distance: %f m' %test())
        time.sleep(3)
except KeyboardInterrupt:
    GPIO.cleanup()

#GPIO.output(40,GPIO.LOW)
#time.sleep(1)
#GPIO.output(40,GPIO.HIGH)
#time.sleep(1)
#GPIO.cleanup()	
