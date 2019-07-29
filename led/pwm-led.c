#include<stdio.h>
#include<wiringPi.h>
#include<softPwm.h>
// Software [Pulse Width Modulation] Module

#define LED 1
// wPi. 1(GPIO. 1), BCM. 18, Physical-Pin. 12

int main(){

  if(wiringPiSetup() == -1) return -1;

  softPwmCreate(LED, 0, 1023);
  //softPwmCreate(wPi no, init value, pwm range)

  for(;;){
    softPwmWrite(LED, 20);

  }
}
