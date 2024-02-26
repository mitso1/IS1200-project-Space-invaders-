


#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int getsw(void){
    int sw = (0xfe0 & PORTD) >> 8;
}

int getbtns(void){
    int btns = (0xe0 & PORTD) >> 5;   // 1110 0000
    return btns;
}

