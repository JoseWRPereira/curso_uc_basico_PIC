#include "config.h"
#include <xc.h>
#include "lcd.h"


void main( void )
{
    lcd_init();
    lcd_print(0,0,"Timer0");
    while( 1 )
    {

    }
}