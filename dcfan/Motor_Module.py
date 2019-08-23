import time

# rotate left 2sec
def Left_2sec(GPIO, FAN_IA, FAN_IB):
    GPIO.output(FAN_IA,True)
    GPIO.output(FAN_IB,False)
    time.sleep(2)
# rotate right 2sec
def Right_2sec(GPIO, FAN_IA, FAN_IB):
    GPIO.output(FAN_IA,False)
    GPIO.output(FAN_IB,True)
    time.sleep(2)
# rotate left 2sec
def Wait_2sec(GPIO, FAN_IA, FAN_IB):
    GPIO.output(FAN_IA,False)
    GPIO.output(FAN_IB,False)
    time.sleep(2)
