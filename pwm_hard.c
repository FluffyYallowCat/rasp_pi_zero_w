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
    pwmSetClock(1000);
    pwmSetRange(100);
    pwmSetMode(PWM_MODE_MS);
    pwmWrite(18, 50);
    softPwmCreate(led, initialValue, pwmRange);
}

