import RPi.GPIO as GPIO
import Motor_Module as MOTOR

FAN_IA = 23 # BCM. 23, Physical. 16
FAN_IB = 24 # BCM. 24, Physical. 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(FAN_IA, GPIO.OUT)
GPIO.setup(FAN_IB, GPIO.OUT)

if __name__== "__main__" :
    try :
        while True :
            MOTOR.Left_2sec(GPIO, FAN_IA, FAN_IB)
            MOTOR.Wait_2sec(GPIO, FAN_IA, FAN_IB)
            MOTOR.Right_2sec(GPIO, FAN_IA, FAN_IB)
            MOTOR.Wait_2sec(GPIO, FAN_IA, FAN_IB)

    except :
        GPIO.cleanup()
        print("end")
