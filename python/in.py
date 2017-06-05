#!/usr/bin/python3
import RPi.GPIO as io
import time


io.setmode(io.BOARD)
io.setwarnings(False)

io.setup(32,io.IN)
print(io.input(32))
#io.wait_for_edge(32,io.FALLING)
pin=32
def _32_callback (a):
    print('callback pin 32 changed %s' %a)
def _32_callback2 (a):
    print('callback2 pin 32 changed %s' %a)
    
io.add_event_detect(pin,io.BOTH,bouncetime=200)
io.add_event_callback(pin,_32_callback)
io.add_event_callback(pin,_32_callback2)
try :
    while True:
        '''if io.input(32)==0:
            print(io.input(32))      
            print('dddddd') '''
except KeyboardInterrupt:
    io.cleanup()


