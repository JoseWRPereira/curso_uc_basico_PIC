/*
 * File:   contatores.c
 * Author: josewrpereira
 *
 * Created on 30 de Setembro de 2021, 22:26
 */


#include <xc.h>

void contatores_init( void )
{
    TRISDbits.TRISD7 = 0;       // K3
    TRISDbits.TRISD6 = 0;       // K2
    TRISDbits.TRISD5 = 0;       // K1
    TRISDbits.TRISD1 = 1;       // S1
    TRISDbits.TRISD0 = 1;       // S0
}


void k1( void )
{
    PORTDbits.RD5 = 1;
}
void k2( void )
{
    PORTDbits.RD7 = 0;
    PORTDbits.RD6 = 1;
}

void k3( void )
{
    PORTDbits.RD6 = 0;
    PORTDbits.RD7 = 1;
}


unsigned char s1( void )
{
    return( !PORTDbits.RD1 );
}
unsigned char s0( void )
{
    return( !PORTDbits.RD0 );
}



void partida( void )
{
    k3();
    k1();
}

void estrela_triangulo( void )
{
    k2();
    k1();
}

void parada( void )
{
    PORTDbits.RD7 = 0;
    PORTDbits.RD6 = 0;
    PORTDbits.RD5 = 0;
}
