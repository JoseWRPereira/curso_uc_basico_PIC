#include <xc.h>
#include "adc.h"

void adc_init( void )
{
    ANSELbits.ANS0 = 1;
    ANSELbits.ANS1 = 1;
    ANSELbits.ANS2 = 1;
    ANSELbits.ANS3 = 1;
    ADCON0bits.ADCS = FOSC_DIV_2;
    ADCON1bits.VCFG0 = ADC_VREF_VDD;
    ADCON1bits.VCFG1 = ADC_VREF_VSS;
    ADCON1bits.ADFM = ADC_FORMAT_RIGHT;
    ADCON0bits.ADON = 1;
}

unsigned int adc_read( unsigned char chs )
{
    unsigned int ADC_value = 0;
    ADCON0bits.CHS = chs<4 ? chs : 0;
    ADCON0bits.GO = 1;
    while( ADCON0bits.GO )
        ;
    ADC_value = ADRESH;
    ADC_value <<= 8;
    ADC_value += ADRESL;
    return( ADC_value );
}