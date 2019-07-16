#include<stdio.h>
#include<wiringPi.h>

#define LED 0

int main()
{
  if(wiringPiSetup() == -1)
    {
      printf("setup wiringPi failed!");
      return 1;
    }

  pinMode(LED, OUTPUT);
  while(1)
    {
      digitalWrite(LED, LOW);
      printf("LED OFF...\n");

      delay(500);

      digitalWrite(LED, HIGH);
      printf("LED ON...\n");

      delay(500);
    }

  return 0;
}
