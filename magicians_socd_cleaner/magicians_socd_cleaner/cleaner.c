/* Includes */
#include "cleaner.h"

/* Function Definitions */
// SOCD Cleaners
void CleanerXNeutral(uint8_t tempLeftState, uint8_t tempRightState)
{
	// Left and Right = Neutral
	if ( (tempLeftState == 0) && (tempRightState == 0) )
	{
		DirectionReleaseLeft(ModeSwitchesOrientation());
		DirectionReleaseRight(ModeSwitchesOrientation());
	}
	else if ( (tempLeftState == 0) && (tempRightState > 0) )
	{
		DirectionPressLeft(ModeSwitchesOrientation());
		DirectionReleaseRight(ModeSwitchesOrientation());
	}
	else if ( (tempLeftState > 0) && (tempRightState == 0) )
	{
		DirectionReleaseLeft(ModeSwitchesOrientation());
		DirectionPressRight(ModeSwitchesOrientation());
	}
	else
	{
		DirectionReleaseLeft(ModeSwitchesOrientation());
		DirectionReleaseRight(ModeSwitchesOrientation());
	}
}

void CleanerXLeft(uint8_t tempLeftState, uint8_t tempRightState)
{
	// Left and Right = Left
	if ( (tempLeftState == 0) && (tempRightState == 0) )
	{
		DirectionPressLeft(ModeSwitchesOrientation());
		DirectionReleaseRight(ModeSwitchesOrientation());
	}
	else if ( (tempLeftState == 0) && (tempRightState > 0) )
	{
		DirectionPressLeft(ModeSwitchesOrientation());
		DirectionReleaseRight(ModeSwitchesOrientation());
	}
	else if ( (tempLeftState > 0) && (tempRightState == 0) )
	{
		DirectionReleaseLeft(ModeSwitchesOrientation());
		DirectionPressRight(ModeSwitchesOrientation());
	}
	else
	{
		DirectionReleaseLeft(ModeSwitchesOrientation());
		DirectionReleaseRight(ModeSwitchesOrientation());
	}
}

void CleanerXRight(uint8_t tempLeftState, uint8_t tempRightState)
{
	// Left and Right = Right
	if ( (tempLeftState == 0) && (tempRightState == 0) )
	{
		DirectionReleaseLeft(ModeSwitchesOrientation());
		DirectionPressRight(ModeSwitchesOrientation());
	}
	else if ( (tempLeftState == 0) && (tempRightState > 0) )
	{
		DirectionPressLeft(ModeSwitchesOrientation());
		DirectionReleaseRight(ModeSwitchesOrientation());
	}
	else if ( (tempLeftState > 0) && (tempRightState == 0) )
	{
		DirectionReleaseLeft(ModeSwitchesOrientation());
		DirectionPressRight(ModeSwitchesOrientation());
	}
	else
	{
		DirectionReleaseLeft(ModeSwitchesOrientation());
		DirectionReleaseRight(ModeSwitchesOrientation());
	}
}

void CleanerXLastInput(uint8_t tempLeftState, uint8_t tempRightState)
{
	// Left and Right = Last Input
	// Nothing yet
}

void CleanerYNeutral(uint8_t tempDownState, uint8_t tempUpState)
{
	// Down and Up = Neutral
	if ( (tempDownState == 0) && (tempUpState == 0) )
	{
		DirectionReleaseDown(ModeSwitchesOrientation());
		DirectionReleaseUp(ModeSwitchesOrientation());
	}
	else if ( (tempDownState == 0) && (tempUpState > 0) )
	{
		DirectionPressDown(ModeSwitchesOrientation());
		DirectionReleaseUp(ModeSwitchesOrientation());
	}
	else if ( (tempDownState > 0) && (tempUpState == 0) )
	{
		DirectionReleaseDown(ModeSwitchesOrientation());
		DirectionPressUp(ModeSwitchesOrientation());
	}
	else
	{
		DirectionReleaseDown(ModeSwitchesOrientation());
		DirectionReleaseUp(ModeSwitchesOrientation());
	}
}

void CleanerYDown(uint8_t tempDownState, uint8_t tempUpState)
{
	// Down and Up = Down
	if ( (tempDownState == 0) && (tempUpState == 0) )
	{
		DirectionPressDown(ModeSwitchesOrientation());
		DirectionReleaseUp(ModeSwitchesOrientation());
	}
	else if ( (tempDownState == 0) && (tempUpState > 0) )
	{
		DirectionPressDown(ModeSwitchesOrientation());
		DirectionReleaseUp(ModeSwitchesOrientation());
	}
	else if ( (tempDownState > 0) && (tempUpState == 0) )
	{
		DirectionReleaseDown(ModeSwitchesOrientation());
		DirectionPressUp(ModeSwitchesOrientation());
	}
	else
	{
		DirectionReleaseDown(ModeSwitchesOrientation());
		DirectionReleaseUp(ModeSwitchesOrientation());
	}
}

void CleanerYUp(uint8_t tempDownState, uint8_t tempUpState)
{
	// Down and Up = Up
	if ( (tempDownState == 0) && (tempUpState == 0) )
	{
		DirectionReleaseDown(ModeSwitchesOrientation());
		DirectionPressUp(ModeSwitchesOrientation());
	}
	else if ( (tempDownState == 0) && (tempUpState > 0) )
	{
		DirectionPressDown(ModeSwitchesOrientation());
		DirectionReleaseUp(ModeSwitchesOrientation());
	}
	else if ( (tempDownState > 0) && (tempUpState == 0) )
	{
		DirectionReleaseDown(ModeSwitchesOrientation());
		DirectionPressUp(ModeSwitchesOrientation());
	}
	else
	{
		DirectionReleaseDown(ModeSwitchesOrientation());
		DirectionReleaseUp(ModeSwitchesOrientation());
	}
}

void CleanerYLastInput(uint8_t tempDownState, uint8_t tempUpState)
{
	// Down and Up = Last Input
	// Nothing yet
}