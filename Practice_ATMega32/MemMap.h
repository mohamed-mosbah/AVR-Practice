/*
 * MemMap.h
 *
 * Created: 24/04/2022 19:15:49
 *  Author: Mohamed
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

/*************************************************************************************/
/* DIO Registers */

#define		PORTA		(*(volatile unsigned char*)0x3B)
#define		DDRA		(*(volatile unsigned char*)0x3A)
#define		PINA		(*(volatile unsigned char*)0x39)

#define		PORTB		(*(volatile unsigned char*)0x38)
#define		DDRB		(*(volatile unsigned char*)0x37)
#define		PINB		(*(volatile unsigned char*)0x36)

#define		PORTC		(*(volatile unsigned char*)0x35)
#define		DDRC		(*(volatile unsigned char*)0x34)
#define		PINC		(*(volatile unsigned char*)0x33)

#define		PORTD		(*(volatile unsigned char*)0x32)
#define		DDRD		(*(volatile unsigned char*)0x31)
#define		PIND		(*(volatile unsigned char*)0x30)


/*************************************************************************************/
/* ADC Registers */

#define		ADMUX		(*(volatile unsigned char*)0x27)
#define		REFS1		7
#define		REFS0		6
#define		ADLAR		5

#define		ADCSRA		(*(volatile unsigned char*)0x26)
#define		ADEN		7
#define		ADSC		6
#define		ADH			(*(volatile unsigned char*)0x25)
#define		ADL			(*(volatile unsigned char*)0x24)
#define		ADC			(*(volatile unsigned short*)0x24)

/*************************************************************************************/
/*External Interrupt */
#define MCUCSR   (*(volatile unsigned char*)0x54)
#define ISC2 6

#define MCUCR   (*(volatile unsigned char*)0x55)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define GICR     (*(volatile unsigned char*)0x5B)
#define INT1 7
#define INT0 6
#define INT2 5

#define GIFR    (*(volatile unsigned char*)0x5A)
#define INTF1 7
#define INTF0 6
#define INTF2 5

/*interrupt functions*/

# define sei()  __asm__ __volatile__ ("sei" ::)
# define cli()  __asm__ __volatile__ ("cli" ::)
# define reti()  __asm__ __volatile__ ("reti" ::)
# define ret()  __asm__ __volatile__ ("ret" ::)

#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)

/*************************************************************************************/
/* Interrupt vectors */

/* External Interrupt Request 0 */
#define INT0_vect			__vector_1
/* External Interrupt Request 1 */
#define INT1_vect			__vector_2
/* External Interrupt Request 2 */
#define INT2_vect			__vector_3




#endif /* MEMMAP_H_ */