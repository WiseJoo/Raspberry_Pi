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
      printf("ALL LED OFF...\n");

      delay(500);
      
      digitalWrite(LEDRED, HIGH);
      printf("LED RED ON...\n");

      delay(500);

      digitalWrite(LEDRED, LOW);
      printf("LED RED OFF...\n");

      delay(500);

      digitalWrite(LEDGRE, HIGH);
      printf("LED GRE ON...\n");

      delay(500);

      digitalWrite(LEDGRE, LOW);
      printf("LED GRE OFF...\n");

      delay(500);

      digitalWrite(LEDYEL, HIGH);
      printf("LED YEL ON...\n");

      delay(500);

      digitalWrite(LEDYEL, LOW);
      printf("LED YEL OFF...\n");

      delay(500);
      
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDGRE, HIGH);
      digitalWrite(LEDYEL, HIGH);
      printf("All LED ON...\n");
      
      delay(500);
    }

  return 0;
}
