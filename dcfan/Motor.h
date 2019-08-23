#include<stdio.h>

// wPi.4
#define FAN_IA 4

// weak wind
static void Weak(){
  softPwmWrite(FAN_IA, 333);
  printf("Weak wind\n");
  delay(5000);
}

// medium wind
static void Medium(){
  softPwmWrite(FAN_IA, 666);
  printf("Medium wind\n");
  delay(5000);
}

// string wind
static void Strong(){
  softPwmWrite(FAN_IA, 1000);
  printf("Strong wind\n");
  delay(5000);
}

static void Stop(){
  softPwmWrite(FAN_IA, 0);
  printf("Stop\n");
}
