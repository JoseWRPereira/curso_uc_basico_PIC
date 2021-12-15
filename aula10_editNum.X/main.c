#include "config.h"
#include <xc.h>
#include "delay.h"
#include "lcd.h"
#include "teclado.h"
#include "editnum.h"

void main( void )
{
    unsigned char string[] = "Tecla:          ";
    int num = 0;
    lcd_init();
    teclado_init();

    while( 1 )
    {   
        string[7] = teclado();
        lcd_print(0,0, string );
        edit( &num, string[7] );
        lcd_num(1,0, num, 6 );
    }
}
