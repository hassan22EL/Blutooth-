/*
 * File:   test.c
 * Author: Hassan
 *
 * Created on 21 ?????, 2018, 07:16 ?
 */


#include <xc.h>

#include "Bultooth.h"
#include "../inulde/EUSART.X/EUSART.h"
#define LED RB0

void main(void) {
    LED=0;
    TRISBbits.TRISB0 = 0;
   char get_value;
    Blutooth_INIT();
    Blutooth_load_String("Blutooth Ready");
    boradcast_Blutooth();
    Blutooth_load_String("press 1 to turn on LED");
    boradcast_Blutooth();
    Blutooth_load_String("press 0 to turn off LED ");
    boradcast_Blutooth();
    while (1) {
        get_value = ReadChar_Blutooth();
        if (get_value == '0') {
            LED = 0;
            Blutooth_load_String("Load Turn OFF");
            boradcast_Blutooth();
        } else if (get_value == '1') {
            LED = 1;
            Blutooth_load_String("LED Turn ON");
            boradcast_Blutooth();
        }

    }
}
