/*
* atmega16_GPIO.h
*  Author: da_unknown_developer
*
* Defines Macros for referring to GPIO Special function registers of atmega16.
*/

#ifdef MCU_SFRS_H_

#error some XXX_sfrs.h has been already included.

#endif

#ifndef ATMEGA16_SFRS_H_
#define ATMEGA16_SFRS_H_

#define MCU_SFRS_H_

#define SFR_OFFSET (0x20)
//Refers to memory mapped register
#define _MMIO_BYTE(ADDR) (*((volatile unsigned char*)(ADDR)))

#define _SFRIO8(ADDR) _MMIO_BYTE(ADDR + SFR_OFFSET)

//size of IO port (8 bits)
#define IO_PORT_SIZE 8

#define PIND    _SFRIO8(0x10)
#define PIND0   0
#define PIND1   1
#define PIND2   2
#define PIND3   3
#define PIND4   4
#define PIND5   5
#define PIND6   6
#define PIND7   7

#define DDRD    _SFRIO8(0x11)
#define DDD0    0
#define DDD1    1
#define DDD2    2
#define DDD3    3
#define DDD4    4
#define DDD5    5
#define DDD6    6
#define DDD7    7

#define PORTD   _SFRIO8(0x12)
#define PD0     0
#define PD1     1
#define PD2     2
#define PD3     3
#define PD4     4
#define PD5     5
#define PD6     6
#define PD7     7

#define PINC    _SFRIO8(0x13)
#define PINC0   0
#define PINC1   1
#define PINC2   2
#define PINC3   3
#define PINC4   4
#define PINC5   5
#define PINC6   6
#define PINC7   7

#define DDRC    _SFRIO8(0x14)
#define DDC0    0
#define DDC1    1
#define DDC2    2
#define DDC3    3
#define DDC4    4
#define DDC5    5
#define DDC6    6
#define DDC7    7

#define PORTC   _SFRIO8(0x15)
#define PC0     0
#define PC1     1
#define PC2     2
#define PC3     3
#define PC4     4
#define PC5     5
#define PC6     6
#define PC7     7

#define PINB    _SFRIO8(0x16)
#define PINB0   0
#define PINB1   1
#define PINB2   2
#define PINB3   3
#define PINB4   4
#define PINB5   5
#define PINB6   6
#define PINB7   7

#define DDRB    _SFRIO8(0x17)
#define DDB0    0
#define DDB1    1
#define DDB2    2
#define DDB3    3
#define DDB4    4
#define DDB5    5
#define DDB6    6
#define DDB7    7

#define PORTB   _SFRIO8(0x18)
#define PB0     0
#define PB1     1
#define PB2     2
#define PB3     3
#define PB4     4
#define PB5     5
#define PB6     6
#define PB7     7

#define PINA    _SFRIO8(0x19)
#define PINA0   0
#define PINA1   1
#define PINA2   2
#define PINA3   3
#define PINA4   4
#define PINA5   5
#define PINA6   6
#define PINA7   7

#define DDRA    _SFRIO8(0x1A)
#define DDA0    0
#define DDA1    1
#define DDA2    2
#define DDA3    3
#define DDA4    4
#define DDA5    5
#define DDA6    6
#define DDA7    7

#define PORTA   _SFRIO8(0x1B)
#define PA0     0
#define PA1     1
#define PA2     2
#define PA3     3
#define PA4     4
#define PA5     5
#define PA6     6
#define PA7     7


#define SFIOR _SFRIO8(0x30)

#define PUD 2

#endif /* ATMEGA16_SFRS_H_ */