#include "LED_DRIVER.h"
#include "dio_public.h"

/*
	Function Name        : LED_Init
	Function Returns     : void
	Function Arguments   : uint8 portname,uint8 pinnumber
	Function Description : Initialize the pin as an output pin to connect the LED.
*/
void LED_Init(uint8 portname, uint8 pinnumber)
{
    /* Initialize the pin as output */
    dio_pin_init(portname, pinnumber, DIO_PIN_MODE_OUTPUT);
}

/*
	Function Name        : LED_TurnOn
	Function Returns     : void
	Function Arguments   : uint8 portname,uint8 pinnumber
	Function Description : Turn on the LED connected to the given pin and port.
*/
void LED_TurnOn(uint8 portname, uint8 pinnumber)
{
    dio_pin_write(portname, pinnumber, 1);  // Set the pin to high
}

/*
	Function Name        : LED_TurnOff
	Function Returns     : void
	Function Arguments   : uint8 portname,uint8 pinnumber
	Function Description : Turn off the LED connected to the given pin and port.
*/
void LED_TurnOff(uint8 portname, uint8 pinnumber)
{
    dio_pin_write(portname, pinnumber, 0);  // Set the pin to low
}

/*
	Function Name        : LED_Toggle
	Function Returns     : void
	Function Arguments   : uint8 portname,uint8 pinnumber
	Function Description : Toggle the LED connected to the given pin and port.
*/
void LED_Toggle(uint8 portname, uint8 pinnumber)
{
    dio_pin_toggle(portname, pinnumber);  // Toggle the pin state
}

/*
	Function Name        : LED_ReadStatus
	Function Returns     : uint8
	Function Arguments   : uint8 portname,uint8 pinnumber
	Function Description : Returns 0 if the LED connected to the given port and pin is off or return 1 if it is on.
*/
uint8 LED_ReadStatus(uint8 portname, uint8 pinnumber)
{
    dio_level_t pin_level;
    dio_pin_read(portname, pinnumber, &pin_level);
    return pin_level;  // Return the pin status (0 or 1)
}
