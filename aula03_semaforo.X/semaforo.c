/*
 * File:   semaforo.c
 * Author: josewrpereira
 *
 * Created on 09 September 2021, 22:42
 */

#include <xc.h>
#include "semaforo.h"
#include "delay.h"

void semaforo_init( void )
{
        // Configuração dos pinos
    TRISDbits.TRISD7 = 0;   // Saída: Vermelho veículos
    TRISDbits.TRISD6 = 0;   // Saída: Amarelo veículos
    TRISDbits.TRISD5 = 0;   // Saída: Verde veículos
    TRISDbits.TRISD3 = 0;   // Saída: Vermelho pedestre
    TRISDbits.TRISD2 = 0;   // Saída: Verde pedestre
    TRISDbits.TRISD0 = 1;   // Entrada: Botão pedestre
    
        // Inicialização do estado dos LEDs
    PORTDbits.RD7 = 0;
    PORTDbits.RD6 = 0;
    PORTDbits.RD5 = 0;
    PORTDbits.RD3 = 0;
    PORTDbits.RD2 = 0;
}

char botao_pedestre( void )
{
    return( PORTDbits.RD0 );
}


void semaforo_veiculo_verde( void )
{
    PORTDbits.RD7 = 0;
    PORTDbits.RD6 = 0;
    PORTDbits.RD5 = 1;
}
void semaforo_veiculo_amarelo( void )
{
    PORTDbits.RD7 = 0;
    PORTDbits.RD5 = 0;
    PORTDbits.RD6 = 1;
}
void semaforo_veiculo_vermelho( void )
{
    PORTDbits.RD5 = 0;
    PORTDbits.RD6 = 0;
    PORTDbits.RD7 = 1;
}

void semaforo_pedestre_verde( void )
{
    PORTDbits.RD3 = 0;
    PORTDbits.RD2 = 1;
}
void semaforo_pedestre_vermelho( void )
{
    PORTDbits.RD2 = 0;
    PORTDbits.RD3 = 1;
}
void semaforo_pedestre_vermelho_pisca( void )
{
    PORTDbits.RD3 = 1;
    delay(500);
    PORTDbits.RD3 = 0;
    delay(500);
}