#include "config.h"
#include <xc.h>
#include "delay.h"
#include "lcd.h"
#include "teclado.h"

void main( void )
{
    unsigned char string[] = "Tecla:          ";
    
    lcd_init();
    teclado_init();

    while( 1 )
    {   
        string[7] = teclado();
        lcd_print(0,0, string );
    }
}
