import RPi.GPIO as GPIO
import time


A = 9       #BCM 9(physical. 21)
B = 11      #BCM 11(physical. 23)
C = 23      #BCM 23(physical. 16)
D = 24      #BCM 24(physical. 18)
E = 5       #BCM 5(physical. 29)
F = 6       #BCM 6(physical. 31)
G = 13      #BCM 13(physical. 33)

SEGMENTS = [A, B, C, D, E, F, G]
NUMBER = [
    [0,0,0,0,0,0,1],    #0
    [1,0,0,1,1,1,1],    #1
    [0,0,1,0,0,1,0],    #2
    [0,0,0,0,1,1,0],    #3
    [1,0,0,1,1,0,0],    #4
    [0,1,0,0,1,0,0],    #5
    [0,1,0,0,0,0,0],    #6
    [0,0,0,1,1,1,1],    #7
    [0,0,0,0,0,0,0],    #8
    [0,0,0,0,1,0,0]     #9   
]


GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

for i in range(7) :
    GPIO.setup(SEGMENTS[i], GPIO.OUT)

try :
    while True:
        for i in range(10) :
            for j in range(7) :
                GPIO.output(SEGMENTS[j], NUMBER[i][j])
            time.sleep(0.5)
except :
    GPIO.cleanup()
