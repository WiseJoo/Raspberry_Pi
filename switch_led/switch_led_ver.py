import RPi.GPIO as GPIO
# GPIO control module

SWITCH = 18
# wPi. 1(GPIO. 1), BCM. 18, Physical-Pin. 12
LED = 23
# wPi. 4(GPIO. 4), BCM. 23, Physical-Pin. 16
GPIO.setmode(GPIO.BCM)                  # BCM mode set
GPIO.setup(LED, GPIO.OUT)               # LED OUTPUT set
GPIO.setup(SWITCH, GPIO.IN, pull_up_down = GPIO.PUD_DOWN)
# SWITCH INPUT set, PULL_DOWN resist set

try :                                   # normal operation state
    while True :                        # infinite loop
        if GPIO.input(SWITCH) == 1:     # when switch pressed
            GPIO.output(LED, True)      # LED on
        else :                          # when switch un pressed
            GPIO.output(LED, False)     # LED OFF

except :                                # when exit
    GPIO.cleanup()                      # GPIO reset
    print("end")
