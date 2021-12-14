#include <xc.h>
#include "lcd.h"
#include "delay.h"

//****************** Interface com PORTs/Pinos
#define LCD_BUS         PORTD
#define LCD_EN          PORTBbits.RB0
#define LCD_RS          PORTBbits.RB1
#define LCD_ROWS        2
#define LCD_COLS        16



//****************** Definicao de Comandos ao LCD 
#define LCD_CLEAR_DISPLAY           0x01

#define LCD_RETURN_HOME             0x02

#define LCD_ENTRY_MODE_SET          0x04
#define LCD_EMS_CURSOR_RIGHT        0x02
#define LCD_EMS_CURSOR_LEFT         0x00
#define LCD_EMS_SHIFT_DISPLAY       0x01

#define LCD_DISPLAY_CONTROL         0x08
#define LCD_DC_DISPLAY_ON           0x04
#define LCD_DC_DISPLAY_OFF          0x00
#define LCD_DC_CURSOR_ON            0x02
#define LCD_DC_CURSOR_OFF           0x00
#define LCD_DC_BLINK_ON             0x01
#define LCD_DC_BLINK_OFF            0x00

#define LCD_CURSOR_SHIFT            0x10
#define LCD_CS_LEFT                 0x00
#define LCD_CS_RIGHT                0x04

#define LCD_DISPLAY_SHIFT           0x10
#define LCD_DS_LEFT                 0x08
#define LCD_DS_RIGHt                0x0C

#define LCD_FUNCTION_SET            0x20
#define LCD_FS_DATA_LENGTH_8        0x10
#define LCD_FS_DATA_LENGTH_4        0x00
#define LCD_FS_LINE_NUMBER_1        0x00
#define LCD_FS_LINE_NUMBER_2        0x08
#define LCD_FS_DOTS_FORMAT_5x8      0x00
#define LCD_FS_DOTS_FORMAT_5x11     0x04

#define LCD_SET_CGRAM_ADDRS( adrs ) (0x40+(adrs & 0x3F))

#define LCD_SET_DDRAM_ADDRS( adrs ) (0x80+(adrs & 0x7F))
#define LCD_ADDR_LINE_0             0x00
#define LCD_ADDR_LINE_1             0x40



//**************************************************************
// Envia uma instrução para o display (Instruction Register)
void LCD_instReg( unsigned char i )
{
    LCD_RS = 0;
    LCD_BUS = i;
    LCD_EN = 0;

    if( i == LCD_CLEAR_DISPLAY || i == LCD_RETURN_HOME )
        __delay_ms( 2 );
    else
        __delay_us( 40 );

    LCD_EN = 1;
}



//**************************************************************
// Envia um caractere para o display (Data Register))
void LCD_dataReg( unsigned char d )
{
    LCD_RS = 1;
    LCD_BUS = d;
    LCD_EN = 0;
    __delay_us( 40 );
    LCD_EN = 1;
}



//**************************************************************
// Posicionar o cursor na coordenada: (linha, coluna)
void LCD_lincol( unsigned char lin, unsigned char col)
{
    LCD_instReg( LCD_SET_DDRAM_ADDRS( (LCD_ADDR_LINE_1 * lin) + (col + LCD_ADDR_LINE_0) ) );
}



//**************************************************************
// Inicializa os pinos conectados ao display e em seguida
// o proprio display
void LCD_init( void )
{
    delay(100);
    TRISDbits.TRISD0 = 0;   // D0
    TRISDbits.TRISD1 = 0;   // D1
    TRISDbits.TRISD2 = 0;   // D2
    TRISDbits.TRISD3 = 0;   // D3
    TRISDbits.TRISD4 = 0;   // R4
    TRISDbits.TRISD5 = 0;   // D5
    TRISDbits.TRISD6 = 0;   // D6
    TRISDbits.TRISD7 = 0;   // D7
    ANSELHbits.ANS12 = 0;   // ANALOG DISABLE (EN)
    ANSELHbits.ANS10 = 0;   // ANALOG DISABLE (RS)
    TRISBbits.TRISB0 = 0;   // EN
    TRISBbits.TRISB1 = 0;   // RS

    delay(100);
    LCD_EN = 1;
    LCD_instReg( LCD_FUNCTION_SET|LCD_FS_DATA_LENGTH_8|LCD_FS_LINE_NUMBER_2 );
    LCD_instReg( LCD_DISPLAY_CONTROL|LCD_DC_DISPLAY_ON|LCD_DC_CURSOR_OFF|LCD_DC_BLINK_OFF );
    LCD_instReg( LCD_CLEAR_DISPLAY );
    LCD_instReg( LCD_RETURN_HOME );
    delay(100);
}



//**************************************************************
// Apaga todos os caracteres no display
void LCD_clr( void )
{
    LCD_instReg(LCD_CLEAR_DISPLAY);
}



//**************************************************************
// Escreve uma string na (linha,coluna) do display
// Uso: 
//      LCD_print(0,0,"string");
//
void LCD_print( unsigned char lin, unsigned char col, const char * str )
{
    char pos = col;
    LCD_lincol( lin, col );

    while( *str )
    {
        LCD_dataReg( *str );
        ++str;
        ++pos;
    }
}


//**************************************************************
// Escreve um número inteiro no display
// Uso: 
//      LCD_num( 0, 0, var, 3 );
//
// Obs: O 3 significa o número de espaços usados no display para 
// a impressão da variavel var.
//
void LCD_num(  unsigned char lin, unsigned char col,
                    int num, unsigned char tam )
{
    int div;
    unsigned char size;
    char sinal; // 0:+ 1:-
   
    sinal = num < 0;
    if( sinal )
        num = (~num) + 1;

    LCD_lincol(lin, col);
   
    div=10000;
    size = 5;
    while( div >= 1 )
    {
        if( num/div == 0 )
            --size;
        else
            break;
        div/=10;
    }

    while( tam > (size+sinal) && tam > 1 )
    {
        LCD_dataReg(' ');
        --tam;
    }  

    if( sinal )
        LCD_dataReg('-');
 
    do
    {
        LCD_dataReg( (unsigned char)(num / div) + '0' );
        num = num % div;
        div/=10;
    }
    while( div >= 1 );
}
