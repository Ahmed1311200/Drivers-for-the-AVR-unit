#ifndef TIMER_DRIVER_H
#define TIMER_DRIVER_H

#include <stdint.h>

/* Timer0 Initialization in CTC mode */
void Timer0_InitCTC(void);

/* Stop Timer0 */
void Timer0_Stop(void);

/* Timer0 Initialization in Fast PWM mode */
void Timer0_InitFastPWM(void);

/* Change the duty cycle of the PWM signal */
void Timer0_SetDutyCycle(float duty);

#endif // TIMER_DRIVER_H
