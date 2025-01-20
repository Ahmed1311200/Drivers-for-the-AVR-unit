#include "STEPPER_MOTOR_DRIVER.h"
#include "dio_public.h"  // Assuming you have a DIO driver for GPIO control

// Stepper motor step sequence for forward and backward movement
static uint8 step_sequence_forward[] = MOTOR_STEP_SEQUENCE_FORWARD;
static uint8 step_sequence_backward[] = MOTOR_STEP_SEQUENCE_BACKWARD;

void StepperMotor_Init(void)
{
    // Initialize the 4 pins as outputs for the stepper motor control
    dio_pin_init(DIO_PORTA, MOTOR_PIN_1, DIO_PIN_MODE_OUTPUT);
    dio_pin_init(DIO_PORTA, MOTOR_PIN_2, DIO_PIN_MODE_OUTPUT);
    dio_pin_init(DIO_PORTA, MOTOR_PIN_3, DIO_PIN_MODE_OUTPUT);
    dio_pin_init(DIO_PORTA, MOTOR_PIN_4, DIO_PIN_MODE_OUTPUT);
}

void StepperMotor_Step(uint8 direction, uint8 steps, uint16 delay_ms)
{
    uint8 i, step_index;

    // Loop for the number of steps
    for(i = 0; i < steps; i++)
    {
        if(direction == MOTOR_DIRECTION_FORWARD)
        {
            // Move forward
            for(step_index = 0; step_index < 8; step_index++)
            {
                dio_port_write(DIO_PORTA, step_sequence_forward[step_index]);
                delay_ms_func(delay_ms);
            }
        }
        else
        {
            // Move backward
            for(step_index = 0; step_index < 8; step_index++)
            {
                dio_port_write(DIO_PORTA, step_sequence_backward[step_index]);
                delay_ms_func(delay_ms);
            }
        }
    }
}

// Delay function (simple for simulation)
void delay_ms_func(uint16 delay)
{
    volatile uint32 i;
    for(i = 0; i < (delay * 1000); i++)
    {
        // Just a dummy loop for delay (assuming 1 ms delay)
    }
}
