#include <xc.h>
#include "delay.h"

void pwm_init( void )
{
    TRISCbits.TRISC2 = 1; // CCP1
    TRISCbits.TRISC1 = 1; // CCP2

    PR2 = 100;

    CCP1CONbits.CCP1M = 0x0;
    CCP2CONbits.CCP2M = 0xF;
    CCPR1L = 0;
    CCPR2L = 0;
    CCP1CONbits.DC1B0 = 0;
    CCP1CONbits.DC1B1 = 0;
    CCP2CONbits.DC2B0 = 0;
    CCP2CONbits.DC2B1 = 0;

    TMR2 = 0;
    PIR1bits.TMR2IF  = 0;
    T2CONbits.T2CKPS = 0; // Prescaler  1:1
    T2CONbits.TOUTPS = 0; // Postscaler 1:1
    T2CONbits.TMR2ON = 1;
    while( !PIR1bits.TMR2IF )
        ;
    TRISCbits.TRISC2 = 0; // CCP1
    TRISCbits.TRISC1 = 0; // CCP2
}

void pwm_setDutyCycle(char dc )
{
   CCPR1L = dc;
   CCPR2L = dc;
}

