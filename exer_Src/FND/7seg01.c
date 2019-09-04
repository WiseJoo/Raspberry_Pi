#include<stdio.h>
#include<wiringPi.h>

// GPIO define section
#define A 13    // GPIO. 13(physical. 21)
#define B 14    // GPIO. 14(physical. 23)
#define C 4     // GPIO. 4 (physical. 16)
#define D 5     // GPIO. 5 (physical. 18)
#define E 21    // GPIO. 21(physical. 29)
#define F 22    // GPIO. 22(physical. 31)
#define G 23    // GPIO. 23(physical. 33)

unsigned char SEGMENTS[7] = {A, B, C, D, E, F, G};
unsigned char NUMBER[10][7] = {
    {0 , 0, 0, 0, 0, 0, 1},     // 0
    {1 , 0, 0, 1, 1, 1, 1},     // 1
    {0 , 0, 1, 0, 0, 1, 0},     // 2
    {0 , 0, 0, 0, 1, 1, 0},     // 3
    {1 , 0, 0, 1, 1, 0, 0},     // 4
    {0 , 1, 0, 0, 1, 0, 0},     // 5
    {0 , 1, 0, 0, 0, 0, 0},     // 6
    {0 , 0, 0, 1, 1, 1, 1},     // 7
    {0 , 0, 0, 0, 0, 0, 0},     // 8
    {0 , 0, 0, 0, 1, 0, 0}      // 9
};

int main()
{
    if(wiringPiSetup() == -1){return 1;}

    for(char i = 0; i < 7; i++){
        pinMode(SEGMENTS[i], OUTPUT);
    }

    while(1){
        for(char i = 0; i < 10; i++){
            for(char j = 0; j < 7; j++){
                digitalWrite(SEGMENTS[j], NUMBER[i][j]);
            }
            delay(500);
        }
    }
}