#include <xc.h>
#include "teclado.h"


int num_original;
unsigned char teclaAnt;

void edit( int * ptr_edit, unsigned char tecla )
{
    if( !teclaAnt && tecla )
    {
        if( tecla >= '0' && tecla <= '9' )
        {
            *ptr_edit = ((*ptr_edit) * 10)+(tecla-'0');
        }
        if( tecla == '*' )
        {
            *ptr_edit = (*ptr_edit) / 10;
        }
    }
    teclaAnt = tecla;
}