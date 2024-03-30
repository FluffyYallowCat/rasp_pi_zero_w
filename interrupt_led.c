#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define led0 2
#define led1 3
#define sw0 14
#define sw1 17

/*プロトタイプ宣言*/
void int_sw0(void); //sw0の割り込み関数
void int_sw1(void); //sw1の割り込み関数

int main(void){
    wiringPiSetupGpio(); //BCMのGPIO番号を使用
    pinMode(led0, OUTPUT);
    pinMode(led1, OUTPUT);
    pinMode(sw0, INPUT);
    pullUpDnControl(sw0, PUD_DOWN);
    pinMode(sw1, INPUT);
    pullUpDnControl(sw1, PUD_DOWN);

    //sw0の立ち上がりで割り込み発生
    wiringPiISR(sw0, INT_EDGE_RISING, (void*)int_sw0);
    //sw1の立ち上がりで割り込み発生
    wiringPiISR(sw1, INT_EDGE_RISING, (void*)int_sw1);
    for(;;){ //ledを0.5s間隔で点滅
        digitalWrite(led0, 1);
        delay(500);
        digitalWrite(led0, 0);
        delay(500);
    }
    return EXIT_SUCCESS;
}

void int_sw0(void){
    digitalWrite(led1, 1);
}

void int_sw1(void){
    digitalWrite(led1, 0);
}