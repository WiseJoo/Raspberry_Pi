//include standard input/output header & wiringPi header
#include<stdio.h>
#include<wiringPi.h>

//CAR side traffic light & Passenger side traffic light define
#define CAR_GRE 0
#define CAR_RED 2
#define CAR_YEL 3
#define PMAIN_GRE 1
#define PSUB_GRE 4
#define PRED 5

//define traffic light delay value
#define D7 7000
#define D4 4000
#define D2 2000
#define D1 1000
#define D_5 500

//traffic light test value
#define TEST 10000

int main()
{
    //Attempt wiringPiSetup, if fail return -1 
    if(wiringPiSetup() == -1)
    {
    printf("setup wiringPi failed!");
    return 1;
    }

    pinMode(CAR_GRE, OUTPUT);
    pinMode(CAR_RED, OUTPUT);
    pinMode(CAR_YEL, OUTPUT);
    pinMode(PMAIN_GRE, OUTPUT);
    pinMode(PSUB_GRE, OUTPUT);
    pinMode(PRED, OUTPUT);
/*
    |CAR_GRE|CAR_RED|CAR_YEL|||||PMAIN_GRE|PSUB_GRE|PRED
From now on above traffic lights represented like this ===> |OFF|OFF|OFF|||OFF|OFF|OFF|
*/

    //All LED off. 
    //|OFF|OFF|OFF|||OFF|OFF|OFF|
    digitalWrite(CAR_GRE, LOW);
    digitalWrite(CAR_RED, LOW);
    digitalWrite(CAR_YEL, LOW);
    digitalWrite(PMAIN_GRE, LOW);
    digitalWrite(PSUB_GRE, LOW);
    digitalWrite(PRED, LOW);



  while(1)
    {
        //1st sequence.
        //|CAR_GRE|OFF|OFF|||OFF|OFF|PRED|
        digitalWrite(CAR_YEL, LOW);
        digitalWrite(CAR_RED, LOW);
        digitalWrite(CAR_GRE, HIGH);
        digitalWrite(PRED, HIGH);
        delay(D7);

        //2nd sequence.
        //|CAR_GRE|OFF|CAR_YEL|||OFF|OFF|PRED
        digitalWrite(CAR_YEL, HIGH);
        delay(D2);

        //3rd sequence.
        //|OFF|CAR_RED|OFF|||OFF|OFF|PRED
        digitalWrite(CAR_GRE, LOW);
        digitalWrite(CAR_YEL, LOW);
        digitalWrite(CAR_RED, HIGH);
        delay(D1);

        //4th sequence.
        //|OFF|CAR_RED|OFF|||PMAIN_GRE|PSUB_GRE|OFF|
        digitalWrite(PRED, LOW);
        digitalWrite(PMAIN_GRE, HIGH);
        digitalWrite(PSUB_GRE, HIGH);
        delay(D4);
        for(int i = 0; i < 4; i++){
            delay(D_5);
            digitalWrite(PSUB_GRE, LOW);
            delay(D_5);
            digitalWrite(PSUB_GRE, HIGH);
        }

        //5th sequence.
        //|OFF|CAR_RED|OFF|||OFF|OFF|PRED|
        digitalWrite(PMAIN_GRE, LOW);
        digitalWrite(PSUB_GRE, LOW);
        digitalWrite(PRED, HIGH);
        delay(D1);


        //6th sequence.
        //|OFF|CAR_RED|CAR_YEL|||OFF|OFF|PRED|
        digitalWrite(CAR_YEL, HIGH);
        delay(D1);
    }

  return 0;
}
