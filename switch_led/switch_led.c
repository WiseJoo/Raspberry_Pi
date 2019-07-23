#include<stdio.h>
#include<wiringPi.h>

#define SWITCH 1
// wPi. 1(GPIO. 1), BCM. 18, Physical-Pin. 12
#define LED 4
// wPi. 4(GPIO. 4), BCM. 23, Physical-Pin. 16


int main(){
  if(wiringPiSetup() == -1){
      // can't load wiringPi
      printf("setup wiringPi failed!\n");
      // error log print
      return 1;
      // abnormal exit
    }

    pinMode(SWITCH, INPUT);
    //SWITCH as input device
    pinMode(SWITCH, PUD_DOWN);		//set pulldown resist
    pinMode(LED, OUTPUT);		//LED as output device

    for(;;){				// infinite loop
      if(digitalRead(SWITCH) == 1){	// when SWITCH pressed
	digitalWrite(LED, HIGH);	// LED turn on
      } else{
	// when SWITCH un pressed
	digitalWrite(LED, LOW);		// LED turn off
      }
    }
    return 0;
}
  
