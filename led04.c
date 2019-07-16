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
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDGRE, LOW);
      printf("LED RED ON, LED GREEN OFF...\n");
      printf("You can't cross...\n");

      delay(3000);

      for(int i = 0; i < 5; i++){
	digitalWrite(LEDYEL, HIGH);
	delay(500);
	digitalWrite(LEDYEL, LOW);
	delay(500);
      }

      digitalWrite(LEDRED, LOW);
      digitalWrite(LEDGRE, HIGH);
      printf("LED RED OFF, LED GREEN ON...\n");
      printf("You can cross...\n");
      
      delay(3000);

      for(int i = 0; i < 5; i++){
	digitalWrite(LEDYEL, HIGH);
	delay(500);
	digitalWrite(LEDYEL, LOW);
	delay(500);
      }      
    }

  return 0;
}
