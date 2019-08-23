#include<stdio.h>
#include<wiringPi.h>

#define FAN_IA 4
#define FAN_IB 5

// rotate left 2sec
static void Left_2_second(){
  digitalWrite(FAN_IA, HIGH);
  digitalWrite(FAN_IB, LOW);
  delay(2000);
}

// rotate right 2sec
static void Right_2_second(){
  digitalWrite(FAN_IA, LOW);
  digitalWrite(FAN_IB, HIGH);
  delay(2000);
}

// stop and wait 2sec
static void Wait_2_second(){
  digitalWrite(FAN_IA, LOW);
  digitalWrite(FAN_IB, LOW);
  delay(2000);
}

int main()
{
  if (wiringPiSetup() == -1) { return -1; }

  pinMode(FAN_IA, OUTPUT);
  pinMode(FAN_IB, OUTPUT);

  while(1){
    Left_2_second();
    Wait_2_second();
    Right_2_second();
    Wait_2_second();
  }

  return 0;
}
