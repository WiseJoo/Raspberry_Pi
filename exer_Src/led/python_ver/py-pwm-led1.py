import RPi.GPIO as GPIO

LED = 18
# wPi. 1(GPIO. 1), BCM. 18, Physical-Pin. 12

GPIO.setmode(GPIO.BCM)
#set BCM mode

GPIO.setwarnings(False)

GPIO.setup(LED, GPIO.OUT)
#set LED OUTPUT

pwm = GPIO.PWM(LED, 100)
# GPIO.PWM(BCM No, Frequency(Hz))
pwm.start(0)
# Duty Cycle = 0%

try :
    while True :
        pwm.ChangeDutyCycle(50)
        #ChangeDutyCycle(0 ~ 100)

except :
    pwm.stop()
    GPIO.cleanup()
