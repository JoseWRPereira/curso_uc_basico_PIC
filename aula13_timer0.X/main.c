#include "config.h"
#include <xc.h>
#include "lcd.h"
#include "timer0.h"

// #define COUNTER
//#define DELAY

void main( void )
{
    lcd_init();

#ifdef COUNTER

    lcd_print(0,0,"Count0");
    counter0_start();
    while( 1 )
    {
        lcd_num(0,7, counter0(), 3 );
    }

#else

    unsigned int div = 0;
    unsigned int u1seg = 0;

#ifndef DELAY

    lcd_print(0,0,"Timer0");
    timer0_start(PS_RATE_1_256,190);

    while( 1 )
    {
        if( timer0_end() )
        {
            timer0_start(PS_RATE_1_256,190);
            div = ++div % 20;
            if( !div )
            {
                ++u1seg;
                lcd_num(0,7, u1seg, 5 );
            }
        }
    }
#else
    lcd_print(0,0,"Timer0_delay");
    while( 1 )
    {
        timer0_delay_ms( 1000 );
        lcd_num(1,10, u1seg++, 3 );
    }
#endif
#endif
}