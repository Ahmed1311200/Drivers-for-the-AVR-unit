#ifndef KEYPAD_DRIVER_H // Header guard to prevent multiple inclusions
#define KEYPAD_DRIVER_H

#include <stdint.h>  // Include standard integer types

/* 
 * Macro defining the value returned when no key is pressed.
 * This value is used as an indicator that no key press has been detected.
 */
#define KEYPAD_NO_KEY_PRESSED 0xFF

/*
 * Function Name        : KEYPAD_Init
 * Function Returns     : void
 * Function Arguments   : void
 * Function Description : 
 * This function initializes the keypad by setting up the row pins as inputs 
 * (with pull-up resistors enabled) and the column pins as outputs (initially set to high).
 */
void KEYPAD_Init(void);

/*
 * Function Name        : KEYPAD_GetPressedKey
 * Function Returns     : uint8_t
 * Function Arguments   : void
 * Function Description : 
 * This function scans the keypad to check if any key is pressed. If a key is detected, 
 * it returns the corresponding character based on the keypad layout. 
 * If no key is pressed, it returns the KEYPAD_NO_KEY_PRESSED value.
 */
uint8_t KEYPAD_GetPressedKey(void);

#endif /* KEYPAD_H_ */  // End of header guard
