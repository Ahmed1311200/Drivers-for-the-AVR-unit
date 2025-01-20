

#ifndef STD_TYPE_H_
#define STD_TYPE_H_

typedef unsigned char uint8;
typedef signed char	  sint8;
typedef unsigned short uint16;
typedef signed short sint16;
typedef double float64;
typedef unsigned long uint32;
// Register Addresses (based on the microcontroller's datasheet)
#define ADMUX   (*(static volatile uint8_t*)0x27) // ADC Multiplexer Selection Register
#define ADCSRA  (*(static volatile uint8_t*)0x26) // ADC Control and Status Register A
#define ADCH    (*(static volatile uint8_t*)0x25) // ADC Data Register High Byte
#define ADCL    (*(static volatile uint8_t*)0x24) // ADC Data Register Low Byte

// Bit positions in ADMUX
#define REFS0   6
#define REFS1   7

// Bit positions in ADCSRA
#define ADEN    7
#define ADSC    6
#define ADIF    4
#define ADPS2   2
#define ADPS1   1

// PORTA Registers
#define PORTA  (*(static volatile uint8_t*)0x3B) // PORTA Data Register
#define DDRA   (*(static volatile uint8_t*)0x3A) // Data Direction Register for PORTA
#define PINA   (*(static volatile uint8_t*)0x39) // Input Pins for PORTA

// PORTB Registers
#define PORTB  (*(static volatile uint8_t*)0x38) // PORTB Data Register
#define DDRB   (*(static volatile uint8_t*)0x37) // Data Direction Register for PORTB
#define PINB   (*(static volatile uint8_t*)0x36) // Input Pins for PORTB

// PORTC Registers
#define PORTC  (*(static volatile uint8_t*)0x35) // PORTC Data Register
#define DDRC   (*(static volatile uint8_t*)0x34) // Data Direction Register for PORTC
#define PINC   (*(static volatile uint8_t*)0x33) // Input Pins for PORTC

// PORTD Registers
#define PORTD  (*(static volatile uint8_t*)0x32) // PORTD Data Register
#define DDRD   (*(static volatile uint8_t*)0x31) // Data Direction Register for PORTD
#define PIND   (*(static volatile uint8_t*)0x30) // Input Pins for PORTD

// TIMER REGISTER
#define TCCR0  (*(static volatile uint8_t*)0x53)
#define TCNT0  (*(static volatile uint8_t*)0x52)
#define OCR0   (*(static volatile uint8_t*)0x5C)

// Register for SREG (Status Register)
#define SREG   (*(static volatile uint8_t*)0x5F)

// Registers for UART (USART)
#define UDR    (*(static volatile uint8_t*)0x2C)
#define UCSRA  (*(static volatile uint8_t*)0x2B)
#define UCSRB  (*(static volatile uint8_t*)0x2A)
#define UCSRC  (*(static volatile uint8_t*)0x40)
#define UBBRH  (*(static volatile uint8_t*)0x40)
#define UBBRL  (*(static volatile uint8_t*)0x29)


#endif /* STD_TYPE_H_ */