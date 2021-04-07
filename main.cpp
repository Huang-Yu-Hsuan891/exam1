#include "mbed.h"
#include "uLCD_4DGL.h"

//uLCD_4DGL uLCD(D1, D0, D2);
DigitalIn up(D3);    // up
DigitalIn down(D4);    // down
DigitalIn sel(D5);    // select

AnalogOut  aout(D7);
//AnalogIn Ain(A0);
float i;

/*int j;
int sample = 128;
float ADCdata[128];*/
int main()
{   
    float slew = 1.0/2;
    /*while (1) {
        for (i = 0.0; i < (0.08 - 0.08 * slew); i += (0.08 - 0.08 * slew) / 10) {
            aout = i / (0.08 - 0.08 * slew);
        }
        for (i = (0.08 - 0.08 * slew); i < (0.24 - 0.08 * slew); i += (0.08 - 0.08 * slew) / 10) {
            aout = 1.0;
        }
        for (i = (0.24 - 0.08 * slew); i < 0.24; i += (0.08 - 0.08 * slew) / 10) {
            aout = 1 - (i - (0.24 - 0.08 * slew)) / (0.08 - 0.08 * slew);
        }
        */
    /*while (1) {
        for (i = 0.0; i < 0.08 ; i += 0.08 / 5) {
            aout = i / 0.08;
        }
        for (i = 0.08; i < 0.24 - 0.08; i += 0.08 / 5) {
            aout = 1.0;
        }
        for (i =0.16; i < 0.24; i += 0.08/ 5) {
            aout = 1 - (i - 0.16) / 0.08;
        }
    */    
    /* while (1) {
        for (i = 0.0; i < (0.08 * slew); i += (0.08 - 0.08 * slew) / 4) {
            aout = i / (0.08 - 0.08 * slew);
        }
        for (i = (0.08 * slew); i < (0.24 - 0.08 * slew); i += (0.08 - 0.08 * slew) / 4) {
            aout = 1.0;
        }
        for (i = (0.24 - 0.08 * slew); i < 0.24; i += (0.08 - 0.08 * slew) / 4) {
            aout = 1 - (i - (0.24 - 0.08 * slew)) / (0.08 - 0.08 * slew);
        } */   
    /*for (i = 0.0, j = 0;Fre !=1 && j < 128 && i < 1.0/ Fre; j += 1, i +=1.0/128) {
        aout = i * Fre;
            ThisThread::sleep_for(1000ms/( 128 * Fre ));
            ADCdata[j] = Ain;
            printf("%f\r\n", ADCdata[j]); 
        }*/
    }
}