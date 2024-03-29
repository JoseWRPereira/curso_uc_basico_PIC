#ifndef TIMER0_H
#define TIMER0_H

#define COUNTER0


#define PS_RATE_1_1     0xF
#define PS_RATE_1_2     0x0
#define PS_RATE_1_4     0x1
#define PS_RATE_1_8     0x2
#define PS_RATE_1_16    0x3
#define PS_RATE_1_32    0x4
#define PS_RATE_1_64    0x5
#define PS_RATE_1_128   0x6
#define PS_RATE_1_256   0x7


#ifdef COUNTER0
void counter0_start( void );
void counter0_reset( void );
int counter0( void );
#endif

#ifndef COUNTER0
void timer0_start( unsigned char prescaler, unsigned char count );
unsigned char timer0_count( void );
unsigned char timer0_end( void );
void timer0_delay_ms( unsigned int t );
#endif

#endif
