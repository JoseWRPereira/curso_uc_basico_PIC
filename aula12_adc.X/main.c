#include "config.h"
#include <xc.h>
#include "delay.h"
#include "lcd.h"
#include "adc.h"

void main( void )
{
    lcd_init();
    adc_init();
    lcd_print(0,0,"ADC: ");
    lcd_num(0, 5, adc_read(0), 5 );
    lcd_num(0,10, adc_read(1), 5 );
    lcd_num(1, 5, adc_read(2), 5 );
    lcd_num(1,10, adc_read(3), 5 );
    while( 1 )
    {
    }
}