import RPi.GPIO as GPIO
import time
#delay function module

LED = 18
# wPi. 1(GPIO. 1), BCM. 18, Physical-Pin. 12

GPIO.setmode(GPIO.BCM)
#set BCM mode
GPIO.setup(LED, GPIO.OUT)
#set LED OUTPUT

pwm = GPIO.PWM(LED, 100)
# GPIO.PWM(BCM No, Frequency(Hz))
pwm.start(0)
# Duty Cycle = 0%

for value in range(0,1024):
    pwm.ChangeDutyCycle(value / 10.23)
    #ChangeDutyCycle(0 ~ 100)
    time.sleep(0.005)
    
pwm.stop()
GPIO.cleanup()
