#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h> //ソフトウェア方式pwm
#define led 2

int main(void){
    int pwmRange = 100;
    int initialValue = 0;
    int i;
    
    wiringPiSetupGpio();
    pinMode(led, OUTPUT);
    softPwmCreate(led, initialValue, pwmRange);

    while(1){
        for(i = 0; i < 100; i++){
            softPwmWrite(led, i);
            delay(50);
        }
    }
}

