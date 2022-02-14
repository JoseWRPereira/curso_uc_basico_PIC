#include <xc.h>

char EEPROM_read( unsigned char addr )
{
    EEADRH = 0;
    EEADR = addr;
    EECON1bits.EEPGD = 0;       // Accesses data memory
    EECON1bits.RD = 1;          // Initiates a memory read
    while( EECON1bits.RD )
        ;
    return( EEDAT );
}

void EEPROM_write( unsigned char addr, unsigned char data )
{
    INTCONbits.GIE = 0;
    EEADR = addr;
    EEDAT = data;
    EECON1bits.EEPGD = 0;       // Accesses data memory
    EECON1bits.WREN = 1;        // Allows write cycle
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;          // Initiates a write cycle
    while( EECON1bits.WR )
        ;
    EECON1bits.WREN = 0;
    INTCONbits.GIE = 1;
}