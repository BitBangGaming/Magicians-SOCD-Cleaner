/* Includes */
#include <avr/io.h>
#include "direction.h"
#include "modeswitches.h"
#include "cleaner.h"
#include "main.h"
#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/eeprom.h>

int main(void)
{	
	// Setup I/O	
	MainInitialize();
	
	// Main program loop
    while(1) 
    {
		// Go and clean
		//MainGoClean();	
		CleanerCustom0(DirectionGetDownState(), DirectionGetUpState(), DirectionGetLeftState(), DirectionGetRightState());	
		//CleanerTetris(DirectionGetDownState(), DirectionGetUpState(), DirectionGetLeftState(), DirectionGetRightState());	
	}
	return(0);
}

static void MainGoClean()
{
	if(bypassCleaner == 1)
	{
		// Bypass cleaner and copy inputs to outputs
		while(1)
		{
			if(DirectionGetLeftState() == 0)
			{
				DirectionPressLeft(ModeSwitchesOrientation());
			}
			else
			{
				DirectionReleaseLeft(ModeSwitchesOrientation());
			}
			
			if(DirectionGetRightState() == 0)
			{
				DirectionPressRight(ModeSwitchesOrientation());
			}
			else
			{
				DirectionReleaseRight(ModeSwitchesOrientation());
			}
						
			if(DirectionGetDownState() == 0)
			{
				DirectionPressDown(ModeSwitchesOrientation());
			}
			else
			{
				DirectionReleaseDown(ModeSwitchesOrientation());
			}
									
			if(DirectionGetUpState() == 0)
			{
				DirectionPressUp(ModeSwitchesOrientation());
			}
			else
			{
				DirectionReleaseUp(ModeSwitchesOrientation());
			}
		}
	}
	
	if(ModeSwitchesRemote() == 0)
	{
		
		MainCleanerX(DirectionGetLeftState(), DirectionGetRightState());
		MainCleanerY(DirectionGetDownState(), DirectionGetUpState());
	}
	else
	{
		MainCleanerRemote(DirectionGetLeftState(), DirectionGetRightState(), DirectionGetDownState(), DirectionGetUpState());
		MainUpdateProgramModeCounter();
		MainProgramModeChecker();
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

static void MainUpdateProgramModeCounter()
{
	// Update counter whenever timer ticks above 0.05 seconds
	if(TCNT1 >= 49999)
	{
		if(ModeSwitchesReadDip5Sw1() == 0)
		{
			// Update program mode counter only if all inputs are pressed
			if((DirectionGetLeftState() == 0) && (DirectionGetRightState() == 0) && (DirectionGetDownState() == 0) && (DirectionGetUpState() == 0))
			{
				programModeCounter++;
				TCNT1 = 0;
			}
			else
			{
				programModeCounter = 0;
			}
		}
		else
		{
			// Update program mode counter only if remote button is pressed
			if(ModeSwitchesReadRemoteButton() == 0)
			{
				programModeCounter++;
				TCNT1 = 0;
			}
			else
			{
				programModeCounter = 0;
			}
		}
		
	}
}

static void MainProgramModeChecker()
{
	// Determine if we should go into program mode after 5 seconds
	// In other words, 0.05 seconds have been counted 100 times
	if(programModeCounter > 100)
	{
		// Indicate you are in program mode
		MainTurnOnPresetLed();
		
		// Read the inputs every 50 milliseconds for the next 5 seconds to determine the new cleaning operation
		for(uint8_t i = 0; i < 100; i++)
		{
			MainUpdateRemoteModeCode(DirectionGetLeftState(), DirectionGetRightState(), DirectionGetDownState(), DirectionGetUpState());
			_delay_ms(50);
		}
		
		// Task complete so reset the counter and turn off preset LED
		programModeCounter = 0;
		MainTurnOffPresetLed();
	}
}

static void MainUpdateRemoteModeCode(uint8_t tempLeftState, uint8_t tempRightState, uint8_t tempDownState, uint8_t tempUpState)
{
	if ( (tempLeftState == 0) && (tempRightState == 0) && (tempDownState == 0) && (tempUpState == 0) )
	{
		eeprom_update_byte (( uint8_t *) 46, REMOTE_MODE_0 );
	}
	else if ( (tempLeftState == 0) && (tempRightState == 0) && (tempDownState == 0) && (tempUpState > 0) )
	{
		eeprom_update_byte (( uint8_t *) 46, REMOTE_MODE_1 );
	}
	else if ( (tempLeftState == 0) && (tempRightState == 0) && (tempDownState > 0) && (tempUpState == 0) )
	{
		eeprom_update_byte (( uint8_t *) 46, REMOTE_MODE_2 );
	}
	else if ( (tempLeftState == 0) && (tempRightState == 0) && (tempDownState > 0) && (tempUpState > 0) )
	{
		eeprom_update_byte (( uint8_t *) 46, REMOTE_MODE_3 );
	}
	else if ( (tempLeftState == 0) && (tempRightState > 0) && (tempDownState == 0) && (tempUpState == 0) )
	{
		eeprom_update_byte (( uint8_t *) 46, REMOTE_MODE_4 );
	}
	else if ( (tempLeftState == 0) && (tempRightState > 0) && (tempDownState == 0) && (tempUpState > 0) )
	{
		eeprom_update_byte (( uint8_t *) 46, REMOTE_MODE_5 );
	}
	else if ( (tempLeftState == 0) && (tempRightState > 0) && (tempDownState > 0) && (tempUpState == 0) )
	{
		eeprom_update_byte (( uint8_t *) 46, REMOTE_MODE_6 );
	}
	else if ( (tempLeftState == 0) && (tempRightState > 0) && (tempDownState > 0) && (tempUpState > 0) )
	{
		eeprom_update_byte (( uint8_t *) 46, REMOTE_MODE_7 );
	}
	else if ( (tempLeftState > 0) && (tempRightState == 0) && (tempDownState == 0) && (tempUpState == 0) )
	{
		eeprom_update_byte (( uint8_t *) 46, REMOTE_MODE_8 );
	}
	else if ( (tempLeftState > 0) && (tempRightState == 0) && (tempDownState == 0) && (tempUpState > 0) )
	{
		eeprom_update_byte (( uint8_t *) 46, REMOTE_MODE_9 );
	}
	else if ( (tempLeftState > 0) && (tempRightState == 0) && (tempDownState > 0) && (tempUpState == 0) )
	{
		eeprom_update_byte (( uint8_t *) 46, REMOTE_MODE_10 );
	}
	else if ( (tempLeftState > 0) && (tempRightState == 0) && (tempDownState > 0) && (tempUpState > 0) )
	{
		eeprom_update_byte (( uint8_t *) 46, REMOTE_MODE_11 );
	}
	else if ( (tempLeftState > 0) && (tempRightState > 0) && (tempDownState == 0) && (tempUpState == 0) )
	{
		eeprom_update_byte (( uint8_t *) 46, REMOTE_MODE_12 );
	}
	else if ( (tempLeftState > 0) && (tempRightState > 0) && (tempDownState == 0) && (tempUpState > 0) )
	{
		eeprom_update_byte (( uint8_t *) 46, REMOTE_MODE_13 );
	}
	else if ( (tempLeftState > 0) && (tempRightState > 0) && (tempDownState > 0) && (tempUpState == 0) )
	{
		eeprom_update_byte (( uint8_t *) 46, REMOTE_MODE_14 );
	}
	else
	{
		eeprom_update_byte (( uint8_t *) 46, REMOTE_MODE_15 );
	}
	_delay_ms(5);
	remoteModeCode = eeprom_read_byte (( uint8_t *) 46);
}

static void MainTurnOnPresetLed()
{
	PORTD |= (1 << MAIN_PRESET_LED);
}

static void MainTurnOffPresetLed()
{
	PORTD &= ~(1 << MAIN_PRESET_LED);
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
	DDRD = DDRD | (1 << DIRECTION_RIGHT_LED);
	DDRB = DDRB | (1 << DIRECTION_LEFT_LED);
	DDRB = DDRB | (1 << DIRECTION_DOWN_LED);
	DDRB = DDRB | (1 << DIRECTION_UP_LED);
	DDRD = DDRD | (1 << MAIN_PRESET_LED);

	// Check to see if inversion of signals are requested
	if ( (DirectionGetRightState() == 0) && (DirectionGetDownState() == 0) )
	{
		if(eeprom_read_byte (( uint8_t *) 56) == COMMON_GROUND)
		{
			eeprom_update_byte (( uint8_t *) 56, COMMON_RAIL);
		}
		else
		{
			eeprom_update_byte (( uint8_t *) 56, COMMON_GROUND);
		}
	}
	
	// Check to see if we need to bypass the cleaner
	if ( (DirectionGetLeftState() == 0) && (DirectionGetUpState() == 0) )
	{
		bypassCleaner = 1;
	}
	else
	{
		bypassCleaner = 0;
	}
	
	DirectionReleaseLeftLed();
	DirectionReleaseRightLed();
	DirectionReleaseDownLed();
	DirectionReleaseUpLed();
	
	// Signal to show which signal inversion mode you are in
	if(eeprom_read_byte (( uint8_t *) 56) == COMMON_GROUND)
	{
		DirectionPressDownLed();
	}
	else
	{
		DirectionPressUpLed();
	}
	
	// Signal to show if you have bypassed the cleaner
	if(bypassCleaner == 0)
	{
		DirectionPressLeftLed();
	}
	else
	{
		DirectionPressRightLed();
	}
	
	// Hold all animation for two seconds then release
	_delay_ms(2000);
	DirectionReleaseLeftLed();
	DirectionReleaseRightLed();
	DirectionReleaseDownLed();
	DirectionReleaseUpLed();
	
	// Default button positions
	DirectionReleaseLeft(0);
	DirectionReleaseRight(0);
	DirectionReleaseDown(0);
	DirectionReleaseUp(0);
	
	// Read in saved remote mode code, but
	// default to REMOTE_MODE_1 if eeprom data is not in range
	uint8_t tempData = eeprom_read_byte (( uint8_t *) 46);
	if (tempData > 15)
	{
		remoteModeCode = REMOTE_MODE_0;
	}
	else
	{
		remoteModeCode = tempData;
	}
	
	// Set up the 16 bit timer to keep counting up
	TCCR1B |= (1 << CS10);
	
	// Default program mode counter
	programModeCounter = 0;

}