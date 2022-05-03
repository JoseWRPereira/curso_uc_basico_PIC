#include "config.h"
#include <xc.h>
#include "delay.h"
#include "lcd.h"

char str[] = "                ";
void main( void )
{
    lcd_init();
    initEUSART( 9600 );
    str[0] = 'S';
    lcd_print(0,0,str);
    while( 1 )
    {

    }
}