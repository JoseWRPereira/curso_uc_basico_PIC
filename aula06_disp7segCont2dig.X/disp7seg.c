/*
 * File:   disp7seg.c
 * Author: josewrpereira
 *
 * Created on 4 de Outubro de 2021, 22:17
 */


#include <xc.h>

#define QTD_DIGITOS         2
#define BASE                10

#define DISP7SEG_BUS( x )   PORTB = x
#define HAB_DEZENA( x )     PORTDbits.RD3 = x
#define HAB_UNIDADE( x )    PORTDbits.RD2 = x

unsigned char digito = 0;

const char disp7seg_digitos[16] = 
{   0xFC, 0x60, 0xDA, 0xF2, 
    0x66, 0xB6, 0xBE, 0xE0, 
    0xFE, 0xF6, 0xEE, 0x3E, 
    0x9C, 0x7A, 0x9E, 0x8E
};

void disp7seg_init( void )
{
    ANSELH = 0;
    TRISB = 0;
    PORTB = 0;
    TRISDbits.TRISD3 = 0;
    TRISDbits.TRISD2 = 0;
}

void disp7seg( unsigned char num )
{
    switch( digito )
    {
        case 0: // Unidade
                HAB_DEZENA( 0 );
                DISP7SEG_BUS( disp7seg_digitos[num % BASE] );
                HAB_UNIDADE( 1 );
                break;

        case 1: // Dezena
                HAB_UNIDADE( 0 );
                DISP7SEG_BUS( disp7seg_digitos[(num / BASE) % BASE] );
                HAB_DEZENA( 1 );
                break;
    }
    digito = ++digito % QTD_DIGITOS;

}
