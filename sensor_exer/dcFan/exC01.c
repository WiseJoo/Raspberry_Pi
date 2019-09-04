#include<wiringPi.h>
#include<softPwm.h>
#include<stdio.h>
#include"Motor.h"

int main()
{
  if(wiringPiSetup()) { return -1; }

  softPwmCreate(FAN_IA, 0, 1000);

  printf("Fan control manual. select mode.\n");
  printf("q -- stop\n");
  printf("w -- weak\n");
  printf("m -- medium\n");
  printf("s -- strong\n");

  while(1){
    switch(getchar())
      {
      case 'q':
	Stop();
	printf("select complete.\n\n\n\n");
	break;
      case 'w':
	Weak();        // weak wind 5sec
	printf("select complete.\n\n\n\n");
	break;
      case 'm':
	Medium();      // medium wind 5sec
	printf("select complete.\n\n\n\n");
	break;
      case 's':
	Strong();      // strong wind 5sec
	printf("select complete.\n\n\n\n");
	break;
      }
  }

  return 0;
}

