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

  //reset LED. all LED off
  digitalWrite(LEDRED, LOW);
  digitalWrite(LEDGRE, LOW);
  digitalWrite(LEDYEL, LOW);
  
  while(1)
    {
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDGRE, LOW);
      printf("LED RED ON, LED GREEN OFF...\n");
      printf("You can't cross...\n");

      delay(3000);

      printf("The signal changes soon...\n");
      for(int i = 0; i < 5; i++){
	digitalWrite(LEDYEL, HIGH);
	delay(250);
	digitalWrite(LEDYEL, LOW);
	delay(250);
      }

      digitalWrite(LEDRED, LOW);
      digitalWrite(LEDGRE, HIGH);
      printf("LED RED OFF, LED GREEN ON...\n");
      printf("You can cross...\n");
      
      delay(3000);

      printf("The signal changes soon...\n");
      for(int i = 0; i < 5; i++){
	digitalWrite(LEDYEL, HIGH);
	delay(250);
	digitalWrite(LEDYEL, LOW);
	delay(250);
      }      
    }

  return 0;
}
