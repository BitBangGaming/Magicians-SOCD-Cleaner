/* Includes */
#include "modeswitches.h"

/* Function Definitions */

// Reading Inputs
uint8_t ModeSwitchesReadDip5Sw1()
{
	return (PINC & (1 << MODESWITCHES_DIP5_SW1));
}

uint8_t ModeSwitchesReadDip5Sw2()
{
	return (PINC & (1 << MODESWITCHES_DIP5_SW2));
}

uint8_t ModeSwitchesReadDip5Sw3()
{
	return (PINC & (1 << MODESWITCHES_DIP5_SW3));
}

uint8_t ModeSwitchesReadDip5Sw4()
{
	return (PINC & (1 << MODESWITCHES_DIP5_SW4));
}

uint8_t ModeSwitchesReadDip5Sw5()
{
	return (PINC & (1 << MODESWITCHES_DIP5_SW5));
}

uint8_t ModeSwitchesReadDip2Sw1()
{
	return (PIND & (1 << MODESWITCHES_DIP2_SW1));
}

uint8_t ModeSwitchesReadDip2Sw2()
{
	return (PIND & (1 << MODESWITCHES_DIP2_SW2));
}

uint8_t ModeSwitchesReadRemoteButton()
{
	return (PINB & (1 << MODESWITCHES_PRESET_BUTTON));
}

// Mode Decision
uint8_t ModeSwitchesX()
{	
	uint8_t modeCode = 0;
	if ( (ModeSwitchesReadDip5Sw1() > 0) && (ModeSwitchesReadDip5Sw2() > 0) )
	{
		// Mode code for cleaner x neutral
		modeCode = 0;
	}
	else if ( (ModeSwitchesReadDip5Sw1() > 0) && (ModeSwitchesReadDip5Sw2() == 0) )
	{
		// Mode code for cleaner x left
		modeCode = 1;
	}
	else if ( (ModeSwitchesReadDip5Sw1() == 0) && (ModeSwitchesReadDip5Sw2() > 0) )
	{
		// Mode code for cleaner x right
		modeCode = 2;
	}
	else
	{
		// Mode code for cleaner x last input
		modeCode = 3;
	}
	
	return modeCode;
}

uint8_t ModeSwitchesY()
{
	uint8_t modeCode = 0;
	if ( (ModeSwitchesReadDip5Sw3() > 0) && (ModeSwitchesReadDip5Sw4() > 0) )
	{
		// Mode code for cleaner y neutral
		modeCode = 0;
	}
	else if ( (ModeSwitchesReadDip5Sw3() > 0) && (ModeSwitchesReadDip5Sw4() == 0) )
	{
		// Mode code for cleaner y down
		modeCode = 1;
	}
	else if ( (ModeSwitchesReadDip5Sw3() == 0) && (ModeSwitchesReadDip5Sw4() > 0) )
	{
		// Mode code for cleaner y up
		modeCode = 2;
	}
	else
	{
		// Mode code for cleaner y last input
		modeCode = 3;
	}
	
	return modeCode;
}

uint8_t ModeSwitchesRemote()
{
	// Decide mode based on preset choosing button
	uint8_t modeCode = 0;
	if ( (ModeSwitchesReadDip5Sw5() > 0) )
	{
		// Mode code for dip selection
		modeCode = 0;
	}
	else
	{
		// Mode code for remote button selection
		modeCode = 1;
	}
	return modeCode;
}

uint8_t ModeSwitchesOrientation()
{
	// Decide mode for default OEM controller
	uint8_t modeCode = 0;
	if ( (ModeSwitchesReadDip2Sw1() > 0) && (ModeSwitchesReadDip2Sw2() > 0) )
	{
		// Mode code for G  R  L  U  D on JST connector
		modeCode = 0;
	}
	else if ( (ModeSwitchesReadDip2Sw1() > 0) && (ModeSwitchesReadDip2Sw2() == 0) )
	{
		// Mode code for G  L  R  D  U on JST connector
		modeCode = 1;
	}
	else if ( (ModeSwitchesReadDip2Sw1() == 0) && (ModeSwitchesReadDip2Sw2() > 0) )
	{
		// Mode code for G  R  U  L  D on JST connector
		modeCode = 2;
	}
	else
	{
		// Mode code for future orientation
		modeCode = 3;
	}
	
	return modeCode;
}