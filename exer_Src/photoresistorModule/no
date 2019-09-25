#include <stdio.h>
#include <wiringPi.h>
#include <time.h>

#define LIGHT 10 // wPi. 10, BCM. 8, Physical. 24(Connected to DOUT)
#define LED 0 // wPi. 0, BCM. 17, Physical. 11
int timestamp(void){
  time_t time_now;
  struct tm *tm;
  time(&time_now);
  tm = localtime(&time_now);
  return (printf("%d-%02d-%02d %02d:%02d:%02d ",
		 tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
		 tm->tm_hour, tm->tm_min, tm->tm_sec));
}

int main(void)
{
  if(wiringPiSetup() == -1){return 1;}
  pinMode(LIGHT, INPUT);
  pinMode(LED, OUTPUT);
  while(1){
    timestamp();

    if(digitalRead(LIGHT) == HIGH){
      digitalWrite(LED, LOW);
      printf("Dark\n");
    }else {
      digitalWrite(LED, HIGH);
      printf("Light\n");
    }
    delay(1000);
  }
  return 0;
}
  
