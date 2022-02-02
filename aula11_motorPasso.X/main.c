#include "config.h"
#include <xc.h>
#include "delay.h"
#include "lcd.h"
#include "editnum.h"
#include "stepmotor.h"

void main( void )
{
    unsigned char tecla;
    int numpassos;
    lcd_init();
    teclado_init();
    stepmotor_init(400);

    lcd_print(0,0," Motor de passo ");
    while( 1 )
    {   
        tecla = teclado();
        edit( &numpassos, tecla, 'D', 'Z', 0, 10000 );
        lcd_print(1,0,"NumPassos: ");
        lcd_num(1,11, numpassos, 5 );
        if( tecla == '#' )
            stepmotor( numpassos, STEPS,  CW, FULL_STEP, 200 );

    }
}
