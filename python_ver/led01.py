import RPi.GPIO as GPIO 			# GPIO control module
import time 						# time module

LED = 17
# wPi. 0(GPIO. 0), BCM. 17, Physical-Pin. 11

GPIO.setmode(GPIO.BCM)				# set BCM mode
GPIO.setup(LED, GPIO.OUT)			# OUTPUT setting

try :								# Normal operation
	while True :					# infinite loop
		GPIO.output(LED, False)		# LED turn off
		print("LED OFF...")			# "LED OFF..." print
		time.sleep(0.5)				# wait 0.5second

		GPIO.output(LED, True)		# LED turn on
		print("LED ON...")			# "LED ON..." print
		time.sleep(0.5)				# wait 0.5second

except :
	GPIO.cleanup()					# exit
	print("end")
