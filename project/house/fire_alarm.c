#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>
#define LED 15
#define FlamPin 0
#define FAN_IA 4
#define SERVO 1
#define BUZZER 2

int main(void) {
	if(wiringPiSetup() == -1) {return 1;}
	
	pinMode(FlamPin, INPUT);
	pinMode(LED, OUTPUT);
	pinMode(FAN_IA, OUTPUT);
	pinMode(BUZZER, OUTPUT);
	softPwmCreate(SERVO, 0, 200);
	
	while(1) {
		if(digitalRead(FlamPin) == HIGH) {
			digitalWrite(LED, LOW);
			digitalWrite(FAN_IA, HIGH);
			digitalWrite(BUZZER, LOW);
			softPwmWrite(SERVO,24);
		}
		else if (digitalRead(FlamPin) == LOW) {
			digitalWrite(LED, HIGH);	
			digitalWrite(FAN_IA, LOW);
			digitalWrite(BUZZER, HIGH);
			softPwmWrite(SERVO,15);
		}
		delay(1000);
	}
	return 0;
}
