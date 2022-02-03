#include <xc.h>
#include "timer0.h"
#include "delay.h"

void counter0_start( void )
{
    TRISAbits.TRISA4 = 1;
    TMR0 = 0; 
    OPTION_REGbits.PSA = 1;
    OPTION_REGbits.T0SE = 0;
    OPTION_REGbits.T0CS = 1; 
}
void counter0_reset( void )
{
    TMR0 = 0;
}
int counter0( void )
{
    return( (int)TMR0 );
}


void timer0_start( unsigned char prescaler, unsigned char count )
{
    OPTION_REGbits.PSA = ((prescaler == PS_RATE_1_1) ? 1 : 0);
    OPTION_REGbits.PS = prescaler;
    OPTION_REGbits.T0CS = 0;
    TMR0 = 256 - count; 
    INTCONbits.T0IF = 0;
}
unsigned char timer0_count( void )
{
    return( TMR0 );
}
unsigned char timer0_end( void )
{
    return( INTCONbits.T0IF );
}


void timer0_delay_ms( unsigned int t )
{
    while( t )
    {
        timer0_start( PS_RATE_1_4, ((_XTAL_FREQ/1000)>>(PS_RATE_1_4+3L)) );
        while( !timer0_end() )
            ;
        --t;
    }
}