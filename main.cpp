#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2);
void print (int slew1);
InterruptIn button(D5);
AnalogOut  aout(D7);
AnalogIn Ain(A0);
float i;
int startq;
int j;
void flip()
{
   startq = 1;
}

class Counter{
public:
   Counter(PinName pin1) : 
   _interrupt(pin1){ 
      _interrupt.rise(callback(this, &Counter::increment));
   }
   void increment() {
      _count++;
   }
   int read() {
      return _count;
   }
private:
   InterruptIn _interrupt;
   volatile int _count;
};
Counter counter(D3);
Counter counter1(D4);
/*int j;
int sample = 128;
float ADCdata[128];*/
int main()
{   
    int sum;
    int slew;
    //float slew = 1.0/2;
    int state = 0;
    float slewstart;
    button.rise(&flip);
    while(!startq) {
        sum = counter.read()-counter1.read();
        if (sum % 4 == 0) {
            slew = 8;
        } else if (sum % 4 ==1) {
            slew = 4;
        } else if (sum % 4 == 2) {
            slew = 2;
        } else if (sum % 4 == 3) {
            slew = 1;
        } else slew = 1;
        print(slew);
        ThisThread::sleep_for(2s);
        slewstart = 1.0 / slew;
    }

    while (startq) {
       /* for (i = 0.0; i < (0.08 - 0.08 * slew); i += (0.08 - 0.08 * slew) / 10) {
            aout = i / (0.08 - 0.08 * slew);
        }
        for (i = (0.08 - 0.08 * slew); i < (0.24 - 0.08 * slew); i += (0.08 - 0.08 * slew) / 10) {
            aout = 1.0;
        }
        for (i = (0.24 - 0.08 * slew); i < 0.24; i += (0.08 - 0.08 * slew) / 10) {
            aout = 1 - (i - (0.24 - 0.08 * slew)) / (0.08 - 0.08 * slew);
        }*/
        if (slew == 1) {
        for (i = 0.0; i < 0.08 ; i += 0.08 / 5) {
            aout = i / 0.08;
            wait_us(0.08/5);
        }
        for (i = 0.08; i < 0.24 - 0.08; i += 0.08 / 5) {
            aout = 1.0;
            wait_us(0.08/5);
        }
        //wait_us(0.08);
        for (i =0.16; i < 0.24; i += 0.08/ 5) {
            aout = 1 - (i - 0.16) / 0.08;
            wait_us(0.08 / 5.0);
        }
        }
        else {
        for (i = 0.0; i < (0.08 * slewstart); i += (0.08 - 0.08 * slewstart) / 4) {
            aout = i / (0.08 - 0.08 * slewstart);
            wait_us((0.08 - 0.08 * slewstart) / 4);
        }
        for (i = (0.08 * slewstart); i < (0.24 - 0.08 * slewstart); i += (0.08 - 0.08 * slewstart) / 4) {
            aout = 1.0;
        }
        for (i = (0.24 - 0.08 * slewstart); i < 0.24; i += (0.08 - 0.08 * slewstart) / 4) {
            aout = 1 - (i - (0.24 - 0.08 * slewstart)) / (0.08 - 0.08 * slewstart);
            wait_us((0.08 - 0.08 * slewstart) / 4);
        }
        }
        for (j = 0; j < 128; j++) {
            ADCdata[j] = Ain
        }

    }  
    /*for (i = 0.0, j = 0;Fre !=1 && j < 128 && i < 1.0/ Fre; j += 1, i +=1.0/128) {
        aout = i * Fre;
            ThisThread::sleep_for(1000ms/( 128 * Fre ));
            ADCdata[j] = Ain;
            printf("%f\r\n", ADCdata[j]); 
        }*/
}
void print (int slew1) {
    uLCD.cls();
    uLCD.background_color(WHITE);
    uLCD.color(BLUE);
    uLCD.text_width(3); //4X size text
    uLCD.text_height(3);
    uLCD.textbackground_color(WHITE);
    uLCD.printf("\n 1/%dslew\n", slew1);
}