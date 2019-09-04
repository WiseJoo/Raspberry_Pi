#include<stdio.h>

// wPi.4
#define FAN_IA 4

// weak wind
static void Weak(){
  softPwmWrite(FAN_IA, 333);
  printf("Weak wind\n");
}

// medium wind
static void Medium(){
  softPwmWrite(FAN_IA, 666);
  printf("Medium wind\n");
}

// string wind
static void Strong(){
  softPwmWrite(FAN_IA, 1000);
  printf("Strong wind\n");
}

static void Stop(){
  softPwmWrite(FAN_IA, 0);
  printf("Stop\n");
}
