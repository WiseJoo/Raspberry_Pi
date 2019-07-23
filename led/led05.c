#include<stdio.h>
#include<wiringPi.h>

#define LEDRED 3
#define LEDGRE 2
#define LEDYEL 0

int main()
{
  int selector[3] = {0,2,3};
  int switcher = 0;
  
  if(wiringPiSetup() == -1)
    {
      printf("setup wiringPi failed!");
      return 1;
    }

  pinMode(LEDRED, OUTPUT);
  pinMode(LEDGRE, OUTPUT);
  pinMode(LEDYEL, OUTPUT);

  //reset LED. all LED off
  digitalWrite(LEDRED, LOW);
  digitalWrite(LEDGRE, LOW);
  digitalWrite(LEDYEL, LOW);

  	digitalWrite(selector[0], HIGH);
	delay(250);
	digitalWrite(selector[0], LOW);
	delay(250);

  while(1)
    {
      for(int i = 1; i < 3; i++){
	digitalWrite(selector[i], HIGH);
	delay(250);
	digitalWrite(selector[i], LOW);
	delay(250);
      }
      for(int i = 1; i > -1; i--){
	digitalWrite(selector[i], HIGH);
	delay(250);
	digitalWrite(selector[i], LOW);
	delay(250);
      }
    }

  return 0;
}
