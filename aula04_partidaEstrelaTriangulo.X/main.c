/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 30 de Setembro de 2021, 22:24
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "contatores.h"

void main(void)
{
    contatores_init();
    
    while( 1 )
    {
        if( s1() )
        {
            partida();
            delay( 3000 );
            estrela_triangulo();
        }
        if( s0() )
        {
            parada();
        }
    }
}
