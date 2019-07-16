#include<stdio.h>
#include<wiringPi.h>

#define LEDRED 3
#define LEDGRE 2
#define LEDYEL 0

int main()
{
  if(wiringPiSetup() == -1)
    {
      printf("setup wiringPi failed!");
      return 1;
    }

  pinMode(LEDRED, OUTPUT);
  pinMode(LEDGRE, OUTPUT);
  pinMode(LEDYEL, OUTPUT);
  while(1)
    {
      digitalWrite(LEDRED, LOW);
      digitalWrite(LEDGRE, LOW);
      digitalWrite(LEDYEL, LOW);
      printf("LED OFF...\n");

      delay(100);

      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDGRE, HIGH);
      digitalWrite(LEDYEL, HIGH);
      printf("LED ON...\n");

      delay(100);
    }

  return 0;
}
