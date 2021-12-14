#include "config.h"
#include <xc.h>
#include "delay.h"
#include "lcd.h"

void main( void )
{
    unsigned int cont;
    LCD_init();
    LCD_print(0,0,"Contagem:       ");
    while( 1 )
    {
        LCD_num(0,10, cont, 3 );
        delay(1000);
        ++cont;
    }
}