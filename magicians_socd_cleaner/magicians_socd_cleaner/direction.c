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