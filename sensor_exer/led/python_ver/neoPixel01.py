# LED1 : DATA IN
# LED2 : 5V+
# LED3 : GND
# LED4 : DATA OUT

import neopixel
import time
import sys


LED_COUNT       = 5             # number of LED 
LED_PIN         = 18            # BCM 18(Physical 12) (if BCM 10(Physical 19) then use SPI)
LED_BRIGHTNESS  = 255           # 0 ~ 255. if your led do not well shining blue color then gradually lower this value.
LED_CHANNEL     = 0             # if this value 0 then you can connect BCM 18(Physical 12), 1 then you can connect BCM 13, 19, 41, 45, 53 

def SetColor(strip, num, color, milli_sec) :
    for i in range(milli_sec) :
        strip.setPixelColor(num, color)
        strip.show()
        time.sleep(0.001)
strip = neopixel.Adafruit_NeoPixel(LED_COUNT, LED_PIN, 800000, 10, False, LED_BRIGHTNESS, LED_CHANNEL)
strip.begin()


def OneByOne() :
    for i in range(LED_COUNT) :
        if i % 3 == 1 :
            for j in range(256) :   # Blue to RED
                SetColor(strip, i, neopixel.Color(j, 0, 255 - j), 1)
            for j in range(256) :   # RED to GREEN
                SetColor(strip, i, neopixel.Color(255 - j, j, 0), 1)
            for j in range(256) :   # Green to Blue
                SetColor(strip, i, neopixel.Color(0, 255 - j, j), 1)

        if i % 3 == 2 :
            for j in range(256) :   # RED to GREEN
                SetColor(strip, i, neopixel.Color(255 - j, j, 0), 1)
            for j in range(256) :   # Green to Blue
                SetColor(strip, i, neopixel.Color(0, 255 - j, j), 1)
            for j in range(256) :   # Blue to RED
                SetColor(strip, i, neopixel.Color(j, 0, 255 - j), 1)

        if i % 3 == 0 :
            for j in range(256) :   # Green to Blue
                SetColor(strip, i, neopixel.Color(0, 255 - j, j), 1)
            for j in range(256) :   # Blue to RED
                SetColor(strip, i, neopixel.Color(j, 0, 255 - j), 1)
            for j in range(256) :   # RED to GREEN
                SetColor(strip, i, neopixel.Color(255 - j, j, 0), 1)


def All() :
    for j in range(256) :
        for i in range(LED_COUNT):
            if i % 3 == 1:  # Blue ~ Red
                SetColor(strip, i, neopixel.Color(j, 0, 255 - j), 1)
            if i % 3 == 2:  # Red ~ Green
                SetColor(strip, i, neopixel.Color(255 - j, j, 0), 1)
            if i % 3 == 0:  # Green ~ Blue
                SetColor(strip, i, neopixel.Color(0, 255 - j, j), j)
    for j in range(256) :
        for i in range(LED_COUNT):
            if i % 3 == 1:  # Red ~ Green
                SetColor(strip, i, neopixel.Color(255 - j, j, 0), 1)
            if i % 3 == 2:  # Green ~ Blue
                SetColor(strip, i, neopixel.Color(0, 255 - j, j), 1)
            if i % 3 == 0:  # Blue ~ Red
                SetColor(strip, i, neopixel.Color(j, 0, 255 - j), 1)
    for j in range(256) :
        for i in range(LED_COUNT):
            if i % 3 == 1:  # Green ~ Blue
                SetColor(strip, i, neopixel.Color(0, 255 - j, j), 1)
            if i % 3 == 2:  # Blue ~ Red
                SetColor(strip, i, neopixel.Color(j, 0, 255 - j), 1)
            if i % 3 == 0:  # Red ~ Green
                SetColor(strip, i, neopixel.Color(255 - j, j, 0), 1)


try :
    print("when press 'Ctrl-C' then exit this program.")

    while True:
        All()

        for i in range(LED_COUNT) :
            SetColor(strip, i, neopixel.Color(0,0,0), 1)

        OneByOne()

except :
    print("\nyou press 'Ctrl-C'. program will be exited")

    for i in range(LED_COUNT) :
        SetColor(strip, i, neopixel.Color(0, 0, 0), 1)

    sys.exit(0)