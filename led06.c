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

  while(1)
    {
        digitalWrite(LEDRED, HIGH);
        digitalWrite(LEDGRE, HIGH);
        digitalWrite(LEDYEL, HIGH);
        delay(250);

        digitalWrite(LEDRED, LOW);
        digitalWrite(LEDGRE, LOW);
        digitalWrite(LEDYEL, LOW);
        delay(250);
    }

  return 0;
}
