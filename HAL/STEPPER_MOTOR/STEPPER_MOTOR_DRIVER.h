#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#include "STD_TYPE.h"  // Include the header for basic type definitions (e.g., uint8, uint16)

// Define Stepper Motor Pins (Assuming 4 pins)
#define MOTOR_PIN_1   0  // Pin 1
#define MOTOR_PIN_2   1  // Pin 2
#define MOTOR_PIN_3   2  // Pin 3
#define MOTOR_PIN_4   3  // Pin 4

// Define Motor Directions
#define MOTOR_DIRECTION_FORWARD  1  // Value 1 represents forward direction
#define MOTOR_DIRECTION_BACKWARD 0  // Value 0 represents backward direction

// Define the step sequence for the stepper motor
// This sequence is for a 4-wire stepper motor, with one step per movement
// The sequence can be adjusted if a different type of motor is used
#define MOTOR_STEP_SEQUENCE_FORWARD  {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09}  // Forward sequence
#define MOTOR_STEP_SEQUENCE_BACKWARD {0x08, 0x09, 0x04, 0x0C, 0x02, 0x06, 0x01, 0x03}  // Backward sequence

// Function to initialize the stepper motor
void StepperMotor_Init(void);

// Function to move the motor one step
// direction: Motor direction (forward or backward)
// steps: Number of steps to rotate
// delay_ms: Delay between steps in milliseconds
void StepperMotor_Step(uint8 direction, uint8 steps, uint16 delay_ms);

#endif /* STEPPER_MOTOR_H_ */
