#include<stdio.h>
#include<wiringPi.h>
#include<softPwm.h>

#define SERVO 1

int main(){
  char sel;

  if(wiringPiSetup() ==  -1 )
    return 0;

  softPwmCreate(SERVO, 0, 200);

  while(1)
 {
   softPwmWrite(SERVO, 5);//0
   delay(600);
   softPwmWrite(SERVO, 25);//90
   delay(600);
   softPwmWrite(SERVO, 50);//180
   delay(600);
   softPwmWrite(SERVO, 75);//270
   delay(600);
 }  	
  return 0;
}
