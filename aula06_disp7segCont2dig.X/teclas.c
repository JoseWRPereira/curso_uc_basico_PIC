/*
 * File:   teclas.c
 * Author: josewrpereira
 *
 * Created on 4 de Outubro de 2021, 22:34
 */


#include <xc.h>

#define TECLA_INC       !PORTDbits.RD1
#define TECLA_DEC       !PORTDbits.RD0

void teclas_init( void )
{
    TRISDbits.TRISD0 = 1;
    TRISDbits.TRISD1 = 1;
}

char tecla_inc_ant = 0;
char tecla_incrementar( void )
{
    return( TECLA_INC );
}
char tecla_incrementar_borda_subida( void )
{
    if( !tecla_inc_ant && TECLA_INC )
    {
        tecla_inc_ant = TECLA_INC;
        return( 1 );
    }
    else
    {
        tecla_inc_ant = TECLA_INC;
        return( 0 );
    }
}
char tecla_incrementar_borda_descida( void )
{
    if( tecla_inc_ant && !TECLA_INC )
    {
        tecla_inc_ant = TECLA_INC;
        return( 1 );
    }
    else
    {
        tecla_inc_ant = TECLA_INC;
        return( 0 );
    }
}

char tecla_dec_ant = 0;
char tecla_decrementar( void )
{
    return( TECLA_DEC );
}
char tecla_decrementar_borda_subida( void )
{
    if( !tecla_dec_ant && TECLA_DEC )
    {
        tecla_dec_ant = TECLA_DEC;
        return( 1 );
    }
    else
    {
        tecla_dec_ant = TECLA_DEC;
        return( 0 );
    }
}
char tecla_decrementar_borda_descida( void )
{
    if( tecla_dec_ant && !TECLA_DEC )
    {
        tecla_dec_ant = TECLA_DEC;
        return( 1 );
    }
    else
    {
        tecla_dec_ant = TECLA_DEC;
        return( 0 );
    }
}
