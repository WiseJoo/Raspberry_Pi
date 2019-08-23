import RPi.GPIO as GPIO
import time

FAN_IA = 23 # BCM. 23, Physical. 16
FAN_IB = 24 # BCM. 24, Physical. 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(FAN_IA, GPIO.OUT)
GPIO.setup(FAN_IB, GPIO.OUT)

# rotate left 2sec
def Left_2sec():
    GPIO.output(FAN_IA,True)
    GPIO.output(FAN_IB,False)
    time.sleep(2)
# rotate right 2sec
def Right_2sec():
    GPIO.output(FAN_IA,False)
    GPIO.output(FAN_IB,True)
    time.sleep(2)
# rotate left 2sec
def Wait_2sec():
    GPIO.output(FAN_IA,False)
    GPIO.output(FAN_IB,False)
    time.sleep(2)

if __name__== "__main__" :
    try :
        while True :
            Left_2sec()
            Wait_2sec()
            Right_2sec()
            Wait_2sec()

    except :
        GPIO.cleanup()
        print("end")
