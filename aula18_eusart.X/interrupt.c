
#include <xc.h>
#include "eusart.h"

void __interrupt() isr(void)
{
    if( PIR1bits.RCIF )
    {
        RX_int(RCREG);
    }
}