#ifndef LED_H_
#define LED_H_

#include "dio_public.h"
#include "STD_TYPE.h"

/*
	Function Name        : LED_Init
	Function Returns     : void
	Function Arguments   : uint8 portname,uint8 pinnumber
	Function Description : Initialize the pin as an output pin to connect the LED.
*/
void LED_Init(uint8 portname, uint8 pinnumber);

/*
	Function Name        : LED_TurnOn
	Function Returns     : void
	Function Arguments   : uint8 portname,uint8 pinnumber
	Function Description : Turn on the LED connected to the given pin and port.
*/
void LED_TurnOn(uint8 portname, uint8 pinnumber);

/*
	Function Name        : LED_TurnOff
	Function Returns     : void
	Function Arguments   : uint8 portname,uint8 pinnumber
	Function Description : Turn off the LED connected to the given pin and port.
*/
void LED_TurnOff(uint8 portname, uint8 pinnumber);

/*
	Function Name        : LED_Toggle
	Function Returns     : void
	Function Arguments   : uint8 portname,uint8 pinnumber
	Function Description : Toggle the LED connected to the given pin and port.
*/
void LED_Toggle(uint8 portname, uint8 pinnumber);

/*
	Function Name        : LED_ReadStatus
	Function Returns     : uint8
	Function Arguments   : uint8 portname,uint8 pinnumber
	Function Description : Returns 0 if the LED connected to the given port and pin is off or return 1 if it is on.
*/
uint8 LED_ReadStatus(uint8 portname, uint8 pinnumber);

#endif /* LED_H_ */
