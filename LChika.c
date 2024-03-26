#include <stdio.h> //入出力
#include <stdlib.h> //一般utility
#include <wiringPi.h> //wiringPi

#define LED     2

int main (void){
    int i;
    wiringPiSetupGpio();
    pinMode(LED, OUTPUT);

    for(i=0; i<10; i++){
        digitalWrite(LED, 1);
        delay(500);
        digitalWrite(LED, 0);
        delay(500);
    }

    return EXIT_SUCCESS;
}