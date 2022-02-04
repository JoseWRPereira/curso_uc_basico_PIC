#include "config.h"
#include <xc.h>
#include "lcd.h"
#include "delay.h"
#include "eeprom.h"


void main(void)
{
    char vetor[11] = "          ";
    char i;
    
    lcd_init();

    lcd_print(0,0,"Curta Eletronica");
    lcd_print(1,0,"          EEPROM");

    if( EEPROM_read(0) == 255 )
        for( i=0; i<10; i++ )
            EEPROM_write(i,i+'0' );
        
    for( i=0; i<10; i++ )
        vetor[i] = EEPROM_read(i);

    lcd_print(1,0, vetor );

    delay(5000);
    
    for( i=0; i<10; i++ )
       EEPROM_write(i,vetor[(i+1)%10] );

    for( i=0; i<10; i++ )
       vetor[i] = EEPROM_read(i);

    lcd_print(1,0, vetor );

    while( 1 )
    {
        
    }
}
