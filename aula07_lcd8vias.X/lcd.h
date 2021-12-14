#ifndef LCD_H
#define LCD_H

void LCD_init( void );
void LCD_clr( void );
void LCD_print( unsigned char lin, unsigned char col, const char * str );
void LCD_num(  unsigned char lin, unsigned char col,
                    int num, unsigned char tam );

#endif