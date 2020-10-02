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
	// Trying out another commit
	// Setup I/O	
	MainInitialize();
	
	// Main program loop
    while(1) 
    {
		// Go and clean
		MainGoClean();		
	}
	return(0);
}

static void MainGoClean()
{
	uint8_t remoteMode = ModeSwitchesRemote();
	
	if(remoteMode == 0)
	{
		MainCleanerX(DirectionGetLeftState(), DirectionGetRightState());
		MainCleanerY(DirectionGetDownState(), DirectionGetUpState());
	}
	else
	{
		MainCleanerRemote(DirectionGetLeftState(), DirectionGetRightState(), DirectionGetDownState(), DirectionGetUpState());
	}
}

static void MainCleanerX(uint8_t tempLeftState, uint8_t tempRightState)
{
	// Grab cleaner from local dip switches
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

static void MainCleanerY(uint8_t tempDownState, uint8_t tempUpState)
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

static void MainCleanerRemote(uint8_t tempLeftState, uint8_t tempRightState, uint8_t tempDownState, uint8_t tempUpState)
{
	switch (remoteModeCode)
	{
		case REMOTE_MODE_0:
			CleanerXNeutral(tempLeftState, tempRightState);
			CleanerYNeutral(tempDownState, tempUpState);
			break;
		
		case REMOTE_MODE_1:
			CleanerXNeutral(tempLeftState, tempRightState);
			CleanerYDown(tempDownState, tempUpState);
			break;
		
		case REMOTE_MODE_2:
			CleanerXNeutral(tempLeftState, tempRightState);
			CleanerYUp(tempDownState, tempUpState);
			break;
		
		case REMOTE_MODE_3:
			CleanerXNeutral(tempLeftState, tempRightState);
			CleanerYLastInput(tempDownState, tempUpState);
			break;
		
		case REMOTE_MODE_4:
			CleanerXLeft(tempLeftState, tempRightState);
			CleanerYNeutral(tempDownState, tempUpState);
			break;
		
		case REMOTE_MODE_5:
			CleanerXLeft(tempLeftState, tempRightState);
			CleanerYDown(tempDownState, tempUpState);
			break;
		
		case REMOTE_MODE_6:
			CleanerXLeft(tempLeftState, tempRightState);
			CleanerYUp(tempDownState, tempUpState);
			break;
		
		case REMOTE_MODE_7:
			CleanerXLeft(tempLeftState, tempRightState);
			CleanerYLastInput(tempDownState, tempUpState);
			break;
		
		case REMOTE_MODE_8:
			CleanerXRight(tempLeftState, tempRightState);
			CleanerYNeutral(tempDownState, tempUpState);
			break;
		
		case REMOTE_MODE_9:
			CleanerXRight(tempLeftState, tempRightState);
			CleanerYDown(tempDownState, tempUpState);
			break;
		
		case REMOTE_MODE_10:
			CleanerXRight(tempLeftState, tempRightState);
			CleanerYUp(tempDownState, tempUpState);
			break;
		
		case REMOTE_MODE_11:
			CleanerXRight(tempLeftState, tempRightState);
			CleanerYLastInput(tempDownState, tempUpState);
			break;
		
		case REMOTE_MODE_12:
			CleanerXLastInput(tempLeftState, tempRightState);
			CleanerYNeutral(tempDownState, tempUpState);
			break;
		
		case REMOTE_MODE_13:
			CleanerXLastInput(tempLeftState, tempRightState);
			CleanerYDown(tempDownState, tempUpState);
			break;
		
		case REMOTE_MODE_14:
			CleanerXLastInput(tempLeftState, tempRightState);
			CleanerYUp(tempDownState, tempUpState);
			break;
		
		case REMOTE_MODE_15:
			CleanerXLastInput(tempLeftState, tempRightState);
			CleanerYLastInput(tempDownState, tempUpState);
			break;
	}
}

static void MainInitialize()
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

	// Default button positions
	DirectionReleaseLeft(0);
	DirectionReleaseRight(0);
	DirectionReleaseDown(0);
	DirectionReleaseUp(0);
	
	// Default remote mode code
	remoteModeCode = 0;
}