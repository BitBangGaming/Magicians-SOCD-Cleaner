/* Includes */
#include "direction.h"

/* Function Definitions */

// Setting Outputs
void DirectionPressLeft(uint8_t tempOrientation)
{
	// Press left on correct pin (OEM controller dependent)
	if(tempOrientation == 0)
	{
		// G  R  L  U  D on JST connector
		PORTD &= ~(1 << DIRECTION_SW2_CLEAN);
	}
	else if(tempOrientation == 1)
	{
		// G  L  R  D  U on JST connector
		PORTD &= ~(1 << DIRECTION_SW1_CLEAN);
		
	}
	else if(tempOrientation == 2)
	{
		// G  R  U  L  D on JST connector
		PORTD &= ~(1 << DIRECTION_SW4_CLEAN);
	}
	else
	{
		// Future orientation...do nothing for now
	}
	DirectionPressLeftLed();
}

void DirectionReleaseLeft(uint8_t tempOrientation)
{
	// Release left on correct pin (OEM controller dependent)
	if(tempOrientation == 0)
	{
		// G  R  L  U  D on JST connector
		PORTD |= (1 << DIRECTION_SW2_CLEAN);
	}
	else if(tempOrientation == 1)
	{
		// G  L  R  D  U on JST connector
		PORTD |= (1 << DIRECTION_SW1_CLEAN);
	}
	else if(tempOrientation == 2)
	{
		// G  R  U  L  D on JST connector
		PORTD |= (1 << DIRECTION_SW4_CLEAN);
	}
	else
	{
		// Future orientation...do nothing for now
	}
	DirectionReleaseLeftLed();
}

void DirectionPressRight(uint8_t tempOrientation)
{
	// Press right on correct pin (OEM controller dependent)
	if(tempOrientation == 0)
	{
		// G  R  L  U  D on JST connector
		PORTD &= ~(1 << DIRECTION_SW1_CLEAN);
	}
	else if(tempOrientation == 1)
	{
		// G  L  R  D  U on JST connector
		PORTD &= ~(1 << DIRECTION_SW2_CLEAN);
		
	}
	else if(tempOrientation == 2)
	{
		// G  R  U  L  D on JST connector
		PORTD &= ~(1 << DIRECTION_SW1_CLEAN);
	}
	else
	{
		// Future orientation...do nothing for now
	}
	DirectionPressRightLed();
}

void DirectionReleaseRight(uint8_t tempOrientation)
{
	// Release right on correct pin (OEM controller dependent)
	if(tempOrientation == 0)
	{
		// G  R  L  U  D on JST connector
		PORTD |= (1 << DIRECTION_SW1_CLEAN);
	}
	else if(tempOrientation == 1)
	{
		// G  L  R  D  U on JST connector
		PORTD |= (1 << DIRECTION_SW2_CLEAN);
	}
	else if(tempOrientation == 2)
	{
		// G  R  U  L  D on JST connector
		PORTD |= (1 << DIRECTION_SW1_CLEAN);
	}
	else
	{
		// Future orientation...do nothing for now
	}
	DirectionReleaseRightLed();
}

void DirectionPressDown(uint8_t tempOrientation)
{
	// Press down on correct pin (OEM controller dependent)
	if(tempOrientation == 0)
	{
		// G  R  L  U  D on JST connector
		PORTD &= ~(1 << DIRECTION_SW4_CLEAN);
	}
	else if(tempOrientation == 1)
	{
		// G  L  R  D  U on JST connector
		PORTD &= ~(1 << DIRECTION_SW3_CLEAN);
	}
	else if(tempOrientation == 2)
	{
		// G  R  U  L  D on JST connector
		PORTD &= ~(1 << DIRECTION_SW4_CLEAN);
	}
	else
	{
		// Future orientation...do nothing for now
	}
	DirectionPressDownLed();
}

void DirectionReleaseDown(uint8_t tempOrientation)
{
	// Release down on correct pin (OEM controller dependent)
	if(tempOrientation == 0)
	{
		// G  R  L  U  D on JST connector
		PORTD |= (1 << DIRECTION_SW4_CLEAN);
	}
	else if(tempOrientation == 1)
	{
		// G  L  R  D  U on JST connector
		PORTD |= (1 << DIRECTION_SW3_CLEAN);
	}
	else if(tempOrientation == 2)
	{
		// G  R  U  L  D on JST connector
		PORTD |= (1 << DIRECTION_SW4_CLEAN);
	}
	else
	{
		// Future orientation...do nothing for now
	}
	DirectionReleaseDownLed();
}

void DirectionPressUp(uint8_t tempOrientation)
{
	// Press up on correct pin (OEM controller dependent)
	if(tempOrientation == 0)
	{
		// G  R  L  U  D on JST connector
		PORTD &= ~(1 << DIRECTION_SW3_CLEAN);
	}
	else if(tempOrientation == 1)
	{
		// G  L  R  D  U on JST connector
		PORTD &= ~(1 << DIRECTION_SW4_CLEAN);
		
	}
	else if(tempOrientation == 2)
	{
		// G  R  U  L  D on JST connector
		PORTD &= ~(1 << DIRECTION_SW4_CLEAN);
	}
	else
	{
		// Future orientation...do nothing for now
	}
	DirectionPressUpLed();
}

void DirectionReleaseUp(uint8_t tempOrientation)
{
	// Release left on correct pin (OEM controller dependent)
	if(tempOrientation == 0)
	{
		// G  R  L  U  D on JST connector
		PORTD |= (1 << DIRECTION_SW3_CLEAN);
	}
	else if(tempOrientation == 1)
	{
		// G  L  R  D  U on JST connector
		PORTD |= (1 << DIRECTION_SW4_CLEAN);
		
	}
	else if(tempOrientation == 2)
	{
		// G  R  U  L  D on JST connector
		PORTD |= (1 << DIRECTION_SW2_CLEAN);
	}
	else
	{
		// Future orientation...do nothing for now
	}
	DirectionReleaseUpLed();
}

// LED Outputs
void DirectionPressRightLed()
{
	PORTD &= ~(1 << DIRECTION_RIGHT_LED);
}

void DirectionReleaseRightLed()
{
	PORTD |= (1 << DIRECTION_RIGHT_LED);
}

void DirectionPressLeftLed()
{
	PORTB &= ~(1 << DIRECTION_LEFT_LED);
}

void DirectionReleaseLeftLed()
{
	PORTB |= (1 << DIRECTION_LEFT_LED);
}

void DirectionPressDownLed()
{
	PORTB &= ~(1 << DIRECTION_DOWN_LED);
}

void DirectionReleaseDownLed()
{
	PORTB |= (1 << DIRECTION_DOWN_LED);
}

void DirectionPressUpLed()
{
	PORTB &= ~(1 << DIRECTION_UP_LED);
}

void DirectionReleaseUpLed()
{
	PORTB |= (1 << DIRECTION_UP_LED);
}

// Reading Inputs
uint8_t DirectionGetLeftState()
{
	return (PINB & (1 << DIRECTION_LEFT_BUTTON));
}

uint8_t DirectionGetRightState()
{
	return (PINB & (1 << DIRECTION_RIGHT_BUTTON));
}

uint8_t DirectionGetUpState()
{
	return (PINB & (1 << DIRECTION_UP_BUTTON));
}

uint8_t DirectionGetDownState()
{
	return (PINB & (1 << DIRECTION_DOWN_BUTTON));
}