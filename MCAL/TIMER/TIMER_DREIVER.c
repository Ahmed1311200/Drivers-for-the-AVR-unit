
#include "TIMER_DREIVER.h"
#include "STD_TYPE.h"
#include "STD_MACRO.h"

void Timer0_InitCTC(void)
{
    // Configure OCR0: the value to compare with
    OCR0 = 78; // To achieve a tick of 10 milliseconds
    
    // Set timer mode as Compare Match (CTC mode)
    SET_BIT(TCCR0, WGM01);
    CLR_BIT(TCCR0, WGM00);
    
    // Configure clock prescaler: clk/1024
    SET_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS02);
    
    // Enable global interrupts
    sei();
    
    // Enable Timer0 interrupt for compare match
    SET_BIT(TIMSK, OCIE0);
}

void Timer0_Stop(void)
{
    // Disable the clock to stop the counter
    CLR_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS02);
}

void Timer0_InitFastPWM(void)
{
    // Configure OCR0: the value to compare with for PWM
    OCR0 = 128; // Initial duty cycle (50%)
    
    // Set timer mode for Fast PWM
    SET_BIT(TCCR0, WGM00); 
    SET_BIT(TCCR0, WGM01);
    
    // Enable global interrupts
    sei();
    
    // Set non-inverting mode for PWM
    SET_BIT(TCCR0, COM01); 
    
    // Enable Timer0 interrupt for overflow
    SET_BIT(TIMSK, TOIE0);
    
    // Configure clock prescaler: clk/1024
    SET_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS02);
}

void Timer0_SetDutyCycle(float duty)
{
    // Set the OCR0 depending on the duty cycle percentage
    OCR0 = (duty / 100) * 256;
}
