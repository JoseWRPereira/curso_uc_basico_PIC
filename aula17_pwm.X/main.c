#include "config.h"
#include <xc.h>
#include "lcd.h"
#include "botoes.h"
#include "pwm.h"

void main( void )
{
    unsigned char dutycycle = 0;
    lcd_init();
    botoes_init();
    pwm_init();

    lcd_print(0,0,"PWM     %");
    lcd_num(0,4,dutycycle,3);

    while( 1 )
    {
        pwm_setDutyCycle(dutycycle);
        if( b0() )
        {
            if( dutycycle >= 10 )
                dutycycle -= 10;
            while( b0() )
                ;
            lcd_num(0,4,dutycycle,3);
        }

        if( b1() )
        {
            if( dutycycle < 100 )
                dutycycle += 10;
            while( b1() )
                ;
            lcd_num(0,4,dutycycle,3);
        }
    }
}