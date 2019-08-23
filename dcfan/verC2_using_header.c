#include<wiringPi.h>
#include<softPwm.h>
#include<stdio.h>
#include"Motor.h"

int main()
{
  if(wiringPiSetup()) { return -1; }

  softPwmCreate(FAN_IA, 0, 1000);

  while(1){
    Weak();        // weak wind 5sec
    Medium();      // medium wind 5sec
    Strong();      // strong wind 5sec
  }

  return 0;
}

