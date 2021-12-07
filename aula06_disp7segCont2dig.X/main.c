/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 4 de Outubro de 2021, 22:14
 */

#include "config.h"
#include <xc.h>
#include "disp7seg.h"
#include "teclas.h"
#include "delay.h"

void main(void)
{
    char i = 0;
    disp7seg_init();
    teclas_init();
    while( 1 )
    {
        disp7seg(i);
        if( tecla_incrementar_borda_subida() && i < 15 )
            i++;
        if( tecla_decrementar_borda_descida() && i > 0 )
            i--;
        delay(5);
    }
}
