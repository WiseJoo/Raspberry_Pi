#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

#define INFRARED 11
#define BUZZER 0
#define LED 1
#define SERVO 4

int main(){

  if(wiringPiSetup() == -1){ return -1; }

  pinMode(INFRARED, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  softPwmCreate(SERVO, 0, 200);
  for(;;){
    if (digitalRead(INFRARED) == HIGH){
      digitalWrite(BUZZER, HIGH);
      digitalWrite(LED, HIGH);
      softPwmWrite(SERVO, 24);
      printf("sense!\n");
    }else {
      digitalWrite(BUZZER, LOW);
      digitalWrite(LED, LOW);
      softPwmWrite(SERVO, 15);
      printf("nothing!\n");
    }
  }

  return 0;
}
