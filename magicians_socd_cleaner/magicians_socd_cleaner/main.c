/* Includes */
#include <avr/io.h>
#include "direction.h"
#include "modeswitches.h"
#include "cleaner.h"
#include "main.h"
#define F_CPU 1000000UL
#include <util/delay.h>

int main(void)
{	
	// Testing out some changes in github
	// Setup I/O	
	MainInitialize();
	
	// Main program loop
    while(1) 
    {
		// Clean x axis
		MainCleanerX(DirectionGetLeftState(), DirectionGetRightState());
		// Note: 
		// Would like to implement local and remote mode by doing: MainCleanerX(DirectionGetLeftState(), DirectionGetRightState(), ModeSwitchesRemote());
		// Or something like that!
		
		// Clean y axis
		MainCleanerY(DirectionGetDownState(), DirectionGetUpState());
		// Would like to implement local and remote mode by doing: MainCleanerX(DirectionGetDownState(), DirectionGetUpState(), ModeSwitchesRemote());
		// Or something like that!
	}
	return(0);
}

void MainCleanerX(uint8_t tempLeftState, uint8_t tempRightState)
{
	// Cleaning for x axis
	if(ModeSwitchesX() == 0)
	{
		CleanerXNeutral(tempLeftState, tempRightState);
	}
	else if(ModeSwitchesX() == 1)
	{
		CleanerXLeft(tempLeftState, tempRightState);
	}
	else if(ModeSwitchesX() == 2)
	{
		CleanerXRight(tempLeftState, tempRightState);
	}
	else
	{
		CleanerXLastInput(tempLeftState, tempRightState);
	}
}

void MainCleanerY(uint8_t tempDownState, uint8_t tempUpState)
{
	// Cleaning for y axis
	if(ModeSwitchesY() == 0)
	{
		CleanerYNeutral(tempDownState, tempUpState);
	}
	else if(ModeSwitchesY() == 1)
	{
		CleanerYDown(tempDownState, tempUpState);
	}
	else if(ModeSwitchesY() == 2)
	{
		CleanerYUp(tempDownState, tempUpState);
	}
	else
	{
		CleanerYLastInput(tempDownState, tempUpState);
	}
}

void MainInitialize()
{
	// Set all ports to be configured as inputs
	DDRB = 0b00000000;
	DDRC = 0b00000000;
	DDRD = 0b00000000;

	// Disable all internal pull-up resistors
	PORTB = 0b00000000;
	PORTC = 0b00000000;
	PORTD = 0b00000000;

	// Enable necessary internal pull-up resistors
	PORTB |= (1 << MAIN_RIGHT_BUTTON_PULLUP);
	PORTB |= (1 << MAIN_LEFT_BUTTON_PULLUP);
	PORTB |= (1 << MAIN_DOWN_BUTTON_PULLUP);
	PORTB |= (1 << MAIN_UP_BUTTON_PULLUP);
	PORTC |= (1 << MAIN_DIP5_SW1_PULLUP);
	PORTC |= (1 << MAIN_DIP5_SW2_PULLUP);
	PORTC |= (1 << MAIN_DIP5_SW3_PULLUP);
	PORTC |= (1 << MAIN_DIP5_SW4_PULLUP);
	PORTC |= (1 << MAIN_DIP5_SW5_PULLUP);
	PORTD |= (1 << MAIN_DIP2_SW1_PULLUP);
	PORTD |= (1 << MAIN_DIP2_SW2_PULLUP);
	PORTB |= (1 << MAIN_PRESET_BUTTON_PULLUP);

	// Set specific port bits to be configured as outputs
	DDRD = DDRD | (1 << DIRECTION_SW1_CLEAN);
	DDRD = DDRD | (1 << DIRECTION_SW2_CLEAN);
	DDRD = DDRD | (1 << DIRECTION_SW3_CLEAN);
	DDRD = DDRD | (1 << DIRECTION_SW4_CLEAN);

	// Default Button Positions
	DirectionReleaseLeft(0);
	DirectionReleaseRight(0);
	DirectionReleaseDown(0);
	DirectionReleaseUp(0);
}