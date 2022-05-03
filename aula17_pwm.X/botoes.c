#include <xc.h>

void botoes_init( void )
{
    TRISDbits.TRISD0 = 1;
    TRISDbits.TRISD1 = 1;
}

unsigned char b0( void )
{
    return( !PORTDbits.RD0 );
}

unsigned char b1( void )
{
    return( !PORTDbits.RD1 );
}
