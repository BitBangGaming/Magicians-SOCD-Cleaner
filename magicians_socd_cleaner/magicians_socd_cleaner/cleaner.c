/* Includes */
#include "cleaner.h"

/* Function Definitions */
// Cleaners
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
	switch (CleanerXAxisState)
	{
		case NEUTRAL_X:
			if ( (tempLeftState == 0) )
			{
				DirectionPressLeft(ModeSwitchesOrientation());
				CleanerXAxisState = LEFT;
			}
			else if ( (tempRightState == 0) )
			{
				DirectionPressRight(ModeSwitchesOrientation());
				CleanerXAxisState = RIGHT;
			}
			else
			{
				DirectionReleaseLeft(ModeSwitchesOrientation());
				DirectionReleaseRight(ModeSwitchesOrientation());
				CleanerXAxisState = NEUTRAL_X;
			}
		break;
		
		case LEFT:
			if ( (tempLeftState > 0) )
			{
				DirectionReleaseLeft(ModeSwitchesOrientation());
				CleanerXAxisState = NEUTRAL_X;
			}
			else if ( (tempRightState == 0) )
			{
				DirectionReleaseLeft(ModeSwitchesOrientation());
				DirectionPressRight(ModeSwitchesOrientation());
				CleanerXAxisState = LEFT_LOST;
			}
			else
			{
				DirectionReleaseRight(ModeSwitchesOrientation());
				DirectionPressLeft(ModeSwitchesOrientation());
				CleanerXAxisState = LEFT;
			}
			break;
		
		case LEFT_LOST:
			if ( (tempLeftState > 0) )
			{
				DirectionReleaseLeft(ModeSwitchesOrientation());
				DirectionPressRight(ModeSwitchesOrientation());
				CleanerXAxisState = RIGHT;
			}
			else if ( (tempRightState > 0) )
			{
				DirectionReleaseRight(ModeSwitchesOrientation());
				DirectionPressLeft(ModeSwitchesOrientation());
				CleanerXAxisState = LEFT;
			}
			else
			{
				DirectionReleaseLeft(ModeSwitchesOrientation());
				DirectionPressRight(ModeSwitchesOrientation());
				CleanerXAxisState = LEFT_LOST;
			}
			break;
		
		case RIGHT:
			if ( (tempRightState > 0) )
			{
				DirectionReleaseRight(ModeSwitchesOrientation());
				CleanerXAxisState = NEUTRAL_X;
			}
			else if ( (tempLeftState == 0) )
			{
				DirectionReleaseRight(ModeSwitchesOrientation());
				DirectionPressLeft(ModeSwitchesOrientation());
				CleanerXAxisState = RIGHT_LOST;
			}
			else
			{
				DirectionReleaseLeft(ModeSwitchesOrientation());
				DirectionPressRight(ModeSwitchesOrientation());
				CleanerXAxisState = RIGHT;
			}
			break;
		
		case RIGHT_LOST:
			if ( (tempRightState > 0) )
			{
				DirectionReleaseRight(ModeSwitchesOrientation());
				DirectionPressLeft(ModeSwitchesOrientation());
				CleanerXAxisState = LEFT;
			}
			else if ( (tempLeftState > 0) )
			{
				DirectionReleaseLeft(ModeSwitchesOrientation());
				DirectionPressRight(ModeSwitchesOrientation());
				CleanerXAxisState = RIGHT;
			}
			else
			{
				DirectionReleaseRight(ModeSwitchesOrientation());
				DirectionPressLeft(ModeSwitchesOrientation());
				CleanerXAxisState = RIGHT_LOST;
			}
			break;
		
		default:
			break;
	}
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
	// Left and Right = Last Input
	switch (CleanerYAxisState)
	{
		case NEUTRAL_Y:
			if ( (tempDownState == 0) )
			{
				DirectionPressDown(ModeSwitchesOrientation());
				CleanerYAxisState = DOWN;
			}
			else if ( (tempUpState == 0) )
			{
				DirectionPressUp(ModeSwitchesOrientation());
				CleanerYAxisState = UP;
			}
			else
			{
				DirectionReleaseDown(ModeSwitchesOrientation());
				DirectionReleaseUp(ModeSwitchesOrientation());
				CleanerYAxisState = NEUTRAL_Y;
			}
			break;
		
		case DOWN:
			if ( (tempDownState > 0) )
			{
				DirectionReleaseDown(ModeSwitchesOrientation());
				CleanerYAxisState = NEUTRAL_Y;
			}
			else if ( (tempUpState == 0) )
			{
				DirectionReleaseDown(ModeSwitchesOrientation());
				DirectionPressUp(ModeSwitchesOrientation());
				CleanerYAxisState = DOWN_LOST;
			}
			else
			{
				DirectionReleaseUp(ModeSwitchesOrientation());
				DirectionPressDown(ModeSwitchesOrientation());
				CleanerYAxisState = DOWN;
			}
			break;
		
		case DOWN_LOST:
			if ( (tempDownState > 0) )
			{
				DirectionReleaseDown(ModeSwitchesOrientation());
				DirectionPressUp(ModeSwitchesOrientation());
				CleanerYAxisState = UP;
			}
			else if ( (tempUpState > 0) )
			{
				DirectionReleaseUp(ModeSwitchesOrientation());
				DirectionPressDown(ModeSwitchesOrientation());
				CleanerYAxisState = DOWN;
			}
			else
			{
				DirectionReleaseDown(ModeSwitchesOrientation());
				DirectionPressUp(ModeSwitchesOrientation());
				CleanerYAxisState = DOWN_LOST;
			}
			break;
		
		case UP:
			if ( (tempUpState > 0) )
			{
				DirectionReleaseUp(ModeSwitchesOrientation());
				CleanerYAxisState = NEUTRAL_Y;
			}
			else if ( (tempDownState == 0) )
			{
				DirectionReleaseUp(ModeSwitchesOrientation());
				DirectionPressDown(ModeSwitchesOrientation());
				CleanerYAxisState = UP_LOST;
			}
			else
			{
				DirectionReleaseDown(ModeSwitchesOrientation());
				DirectionPressUp(ModeSwitchesOrientation());
				CleanerYAxisState = UP;
			}
			break;
		
		case UP_LOST:
			if ( (tempUpState > 0) )
			{
				DirectionReleaseUp(ModeSwitchesOrientation());
				DirectionPressDown(ModeSwitchesOrientation());
				CleanerYAxisState = DOWN;
			}
			else if ( (tempDownState > 0) )
			{
				DirectionReleaseDown(ModeSwitchesOrientation());
				DirectionPressUp(ModeSwitchesOrientation());
				CleanerYAxisState = UP;
			}
			else
			{
				DirectionReleaseUp(ModeSwitchesOrientation());
				DirectionPressDown(ModeSwitchesOrientation());
				CleanerYAxisState = UP_LOST;
			}
			break;
		
		default:
			break;
	}
}

void CleanerTetris(uint8_t tempDownState, uint8_t tempUpState, uint8_t tempLeftState, uint8_t tempRightState)
{
	switch (CleanerDirectionState)
	{
		//-----------------------------------------------------------------
		case NEUTRAL_TETRIS:
		if ( (tempDownState == 0) )
		{
			DirectionPressDown(ModeSwitchesOrientation());
			CleanerDirectionState = DOWN_TETRIS;
		}
		else if ( (tempUpState == 0) )
		{
			DirectionPressUp(ModeSwitchesOrientation());
			CleanerDirectionState = UP_TETRIS;
		}
		else if ( (tempLeftState == 0) )
		{
			DirectionPressLeft(ModeSwitchesOrientation());
			CleanerDirectionState = LEFT_TETRIS;
		}
		else if ( (tempRightState == 0) )
		{
			DirectionPressRight(ModeSwitchesOrientation());
			CleanerDirectionState = RIGHT_TETRIS;
		}
		else
		{
			// leave outputs as they were when entering state
		}
		break;
		//-----------------------------------------------------------------
		case LEFT_TETRIS:
		//if ( (tempLeftState + tempRightState + tempDownState + tempUpState) > 2 )
		//{
			if ( (tempLeftState > 0) && (tempRightState > 0) && (tempDownState > 0) && (tempUpState > 0) )
			{
				DirectionReleaseLeft(ModeSwitchesOrientation());
				DirectionReleaseRight(ModeSwitchesOrientation());
				DirectionReleaseDown(ModeSwitchesOrientation());
				DirectionReleaseUp(ModeSwitchesOrientation());
				CleanerDirectionState = NEUTRAL_TETRIS;
			}
			else if ( (tempRightState == 0) )
			{
				DirectionReleaseLeft(ModeSwitchesOrientation());
				DirectionPressRight(ModeSwitchesOrientation());
				CleanerDirectionState = LEFT_LOST_TETRIS;
			}
			else if ( (tempUpState == 0) )
			{
				DirectionReleaseLeft(ModeSwitchesOrientation());
				DirectionPressUp(ModeSwitchesOrientation());
				CleanerDirectionState = LEFT_LOST_TETRIS;
			}
			else if ( (tempDownState == 0) )
			{
				DirectionReleaseLeft(ModeSwitchesOrientation());
				DirectionPressDown(ModeSwitchesOrientation());
				CleanerDirectionState = LEFT_LOST_TETRIS;
			}
			else
			{
				// leave outputs as they were when entering state
			}
		//}
		break;
		//-----------------------------------------------------------------
		case LEFT_LOST_TETRIS:
		if ( (tempLeftState == 0) && (tempRightState > 0) && (tempDownState > 0) && (tempUpState > 0) )
		{
			DirectionReleaseRight(ModeSwitchesOrientation());
			DirectionReleaseDown(ModeSwitchesOrientation());
			DirectionReleaseUp(ModeSwitchesOrientation());
			DirectionPressLeft(ModeSwitchesOrientation());
			CleanerDirectionState = LEFT_TETRIS;
		}
		else if ( (tempRightState == 0) )
		{
			CleanerDirectionState = RIGHT_TETRIS;
			while( (DirectionGetLeftState() == 0) && (DirectionGetRightState() == 0) ){}
		}
		else if ( (tempDownState == 0) )
		{
			CleanerDirectionState = DOWN_TETRIS;
			while( (DirectionGetLeftState() == 0) && (DirectionGetDownState() == 0) ){}
		}
		else if ( (tempUpState == 0) )
		{
			CleanerDirectionState = UP_TETRIS;
			while( (DirectionGetLeftState() == 0) && (DirectionGetUpState() == 0) ){}
		}
		else
		{
			// leave outputs as they were when entering state
		}
		break;
		//-----------------------------------------------------------------
		case RIGHT_TETRIS:
		//if ( (tempLeftState + tempRightState + tempDownState + tempUpState) > 2 )
		//{
			if ( (tempLeftState > 0) && (tempRightState > 0) && (tempDownState > 0) && (tempUpState > 0) )
			{
				DirectionReleaseLeft(ModeSwitchesOrientation());
				DirectionReleaseRight(ModeSwitchesOrientation());
				DirectionReleaseDown(ModeSwitchesOrientation());
				DirectionReleaseUp(ModeSwitchesOrientation());
				CleanerDirectionState = NEUTRAL_TETRIS;
			}
			else if ( (tempLeftState == 0) )
			{
				DirectionReleaseRight(ModeSwitchesOrientation());
				DirectionPressLeft(ModeSwitchesOrientation());
				CleanerDirectionState = RIGHT_LOST_TETRIS;
			}
			else if ( (tempUpState == 0) )
			{
				DirectionReleaseRight(ModeSwitchesOrientation());
				DirectionPressUp(ModeSwitchesOrientation());
				CleanerDirectionState = RIGHT_LOST_TETRIS;
			}
			else if ( (tempDownState == 0) )
			{
				DirectionReleaseRight(ModeSwitchesOrientation());
				DirectionPressDown(ModeSwitchesOrientation());
				CleanerDirectionState = RIGHT_LOST_TETRIS;
			}
			else
			{
				// leave outputs as they were when entering state
			}
		//}
		break;
		//-----------------------------------------------------------------
		case RIGHT_LOST_TETRIS:
		if ( (tempLeftState > 0) && (tempRightState == 0) && (tempDownState > 0) && (tempUpState > 0) )
		{
			DirectionReleaseLeft(ModeSwitchesOrientation());
			DirectionReleaseDown(ModeSwitchesOrientation());
			DirectionReleaseUp(ModeSwitchesOrientation());
			DirectionPressRight(ModeSwitchesOrientation());
			CleanerDirectionState = RIGHT_TETRIS;
		}
		else if ( (tempLeftState == 0) )
		{
			CleanerDirectionState = LEFT_TETRIS;
			while( (DirectionGetRightState() == 0) && (DirectionGetLeftState() == 0) ){}
		}
		else if ( (tempDownState == 0) )
		{
			CleanerDirectionState = DOWN_TETRIS;
			while( (DirectionGetRightState() == 0) && (DirectionGetDownState() == 0) ){}
		}
		else if ( (tempUpState == 0) )
		{
			CleanerDirectionState = UP_TETRIS;
			while( (DirectionGetRightState() == 0) && (DirectionGetUpState() == 0) ){}
		}
		else
		{
			// leave outputs as they were when entering state
		}
		break;
		//-----------------------------------------------------------------
		case DOWN_TETRIS:
		//if ( (tempLeftState + tempRightState + tempDownState + tempUpState) > 2 )
		//{
			if ( (tempLeftState > 0) && (tempRightState > 0) && (tempDownState > 0) && (tempUpState > 0) )
			{
				DirectionReleaseLeft(ModeSwitchesOrientation());
				DirectionReleaseRight(ModeSwitchesOrientation());
				DirectionReleaseDown(ModeSwitchesOrientation());
				DirectionReleaseUp(ModeSwitchesOrientation());
				CleanerDirectionState = NEUTRAL_TETRIS;
			}
			else if ( (tempRightState == 0) )
			{
				DirectionReleaseDown(ModeSwitchesOrientation());
				DirectionPressRight(ModeSwitchesOrientation());
				CleanerDirectionState = DOWN_LOST_TETRIS;
			}
			else if ( (tempUpState == 0) )
			{
				DirectionReleaseDown(ModeSwitchesOrientation());
				DirectionPressUp(ModeSwitchesOrientation());
				CleanerDirectionState = DOWN_LOST_TETRIS;
			}
			else if ( (tempLeftState == 0) )
			{
				DirectionReleaseDown(ModeSwitchesOrientation());
				DirectionPressLeft(ModeSwitchesOrientation());
				CleanerDirectionState = DOWN_LOST_TETRIS;
			}
			else
			{
				// leave outputs as they were when entering state
			}
		//}
		break;
		//-----------------------------------------------------------------
		case DOWN_LOST_TETRIS:
		if ( (tempLeftState > 0) && (tempRightState > 0) && (tempDownState == 0) && (tempUpState > 0) )
		{
			DirectionReleaseRight(ModeSwitchesOrientation());
			DirectionReleaseLeft(ModeSwitchesOrientation());
			DirectionReleaseUp(ModeSwitchesOrientation());
			DirectionPressDown(ModeSwitchesOrientation());
			CleanerDirectionState = DOWN_TETRIS;
		}
		else if ( (tempRightState == 0) )
		{
			CleanerDirectionState = RIGHT_TETRIS;
			while( (DirectionGetDownState() == 0) && (DirectionGetRightState() == 0) ){}
		}
		else if ( (tempLeftState == 0) )
		{
			CleanerDirectionState = LEFT_TETRIS;
			while( (DirectionGetDownState() == 0) && (DirectionGetLeftState() == 0) ){}
		}
		else if ( (tempUpState == 0) )
		{
			CleanerDirectionState = UP_TETRIS;
			while( (DirectionGetDownState() == 0) && (DirectionGetUpState() == 0) ){}
		}
		else
		{
			// leave outputs as they were when entering state
		}
		break;
		//-----------------------------------------------------------------
		case UP_TETRIS:
		//if ( (tempLeftState + tempRightState + tempDownState + tempUpState) > 2 )
		//{
			if ( (tempLeftState > 0) && (tempRightState > 0) && (tempDownState > 0) && (tempUpState > 0) )
			{
				DirectionReleaseLeft(ModeSwitchesOrientation());
				DirectionReleaseRight(ModeSwitchesOrientation());
				DirectionReleaseDown(ModeSwitchesOrientation());
				DirectionReleaseUp(ModeSwitchesOrientation());
				CleanerDirectionState = NEUTRAL_TETRIS;
			}
			else if ( (tempRightState == 0) )
			{
				DirectionReleaseUp(ModeSwitchesOrientation());
				DirectionPressRight(ModeSwitchesOrientation());
				CleanerDirectionState = UP_LOST_TETRIS;
			}
			else if ( (tempLeftState == 0) )
			{
				DirectionReleaseUp(ModeSwitchesOrientation());
				DirectionPressLeft(ModeSwitchesOrientation());
				CleanerDirectionState = UP_LOST_TETRIS;
			}
			else if ( (tempDownState == 0) )
			{
				DirectionReleaseUp(ModeSwitchesOrientation());
				DirectionPressDown(ModeSwitchesOrientation());
				CleanerDirectionState = UP_LOST_TETRIS;
			}
			else
			{
				// leave outputs as they were when entering state
			}
		//}
		break;
		//-----------------------------------------------------------------
		case UP_LOST_TETRIS:
		if ( (tempLeftState > 0) && (tempRightState > 0) && (tempDownState > 0) && (tempUpState == 0) )
		{
			DirectionReleaseRight(ModeSwitchesOrientation());
			DirectionReleaseDown(ModeSwitchesOrientation());
			DirectionReleaseUp(ModeSwitchesOrientation());
			DirectionPressLeft(ModeSwitchesOrientation());
			CleanerDirectionState = UP_TETRIS;
		}
		else if ( (tempRightState == 0) )
		{
			CleanerDirectionState = RIGHT_TETRIS;
			while( (DirectionGetUpState() == 0) && (DirectionGetRightState() == 0) ){}
		}
		else if ( (tempDownState == 0) )
		{
			CleanerDirectionState = DOWN_TETRIS;
			while( (DirectionGetUpState() == 0) && (DirectionGetDownState() == 0) ){}
		}
		else if ( (tempLeftState == 0) )
		{
			CleanerDirectionState = LEFT_TETRIS;
			while( (DirectionGetUpState() == 0) && (DirectionGetLeftState() == 0) ){}
		}
		else
		{
			// leave outputs as they were when entering state
		}
		break;
	}
}

void CleanerCustom0(uint8_t tempDownState, uint8_t tempUpState, uint8_t tempLeftState, uint8_t tempRightState)
{
	if( (tempLeftState == 0) && (tempDownState == 0) && (tempRightState == 0) )
	{
		// SACD clean to Down
		DirectionReleaseLeft(ModeSwitchesOrientation());
		DirectionReleaseRight(ModeSwitchesOrientation());
		DirectionPressDown(ModeSwitchesOrientation());
		DirectionReleaseUp(ModeSwitchesOrientation());
	}
	else if( (tempDownState == 0) && (tempRightState == 0) && (tempUpState == 0) )
	{
		// SACD clean to Right
		DirectionReleaseLeft(ModeSwitchesOrientation());
		DirectionPressRight(ModeSwitchesOrientation());
		DirectionReleaseDown(ModeSwitchesOrientation());
		DirectionReleaseUp(ModeSwitchesOrientation());
	}
	else if( (tempRightState == 0) && (tempUpState == 0) && (tempLeftState == 0) )
	{
		// SACD clean to Up
		DirectionReleaseLeft(ModeSwitchesOrientation());
		DirectionReleaseRight(ModeSwitchesOrientation());
		DirectionReleaseDown(ModeSwitchesOrientation());
		DirectionPressUp(ModeSwitchesOrientation());
	}
	else if( (tempUpState == 0) && (tempLeftState == 0) && (tempDownState == 0) )
	{
		// SACD clean to Left
		DirectionPressLeft(ModeSwitchesOrientation());
		DirectionReleaseRight(ModeSwitchesOrientation());
		DirectionReleaseDown(ModeSwitchesOrientation());
		DirectionReleaseUp(ModeSwitchesOrientation());
	}
	else
	{	
		// SOCD Clean Left and Right = Last Input
		switch (CleanerXAxisState)
		{
			case NEUTRAL_X:
				if ( (tempLeftState == 0) )
				{
					DirectionPressLeft(ModeSwitchesOrientation());
					CleanerXAxisState = LEFT;
				}
				else if ( (tempRightState == 0) )
				{
					DirectionPressRight(ModeSwitchesOrientation());
					CleanerXAxisState = RIGHT;
				}
				else
				{
					DirectionReleaseLeft(ModeSwitchesOrientation());
					DirectionReleaseRight(ModeSwitchesOrientation());
					CleanerXAxisState = NEUTRAL_X;
				}
				break;
		
			case LEFT:
				if ( (tempLeftState > 0) )
				{
					DirectionReleaseLeft(ModeSwitchesOrientation());
					CleanerXAxisState = NEUTRAL_X;
				}
				else if ( (tempRightState == 0) )
				{
					DirectionReleaseLeft(ModeSwitchesOrientation());
					DirectionPressRight(ModeSwitchesOrientation());
					CleanerXAxisState = LEFT_LOST;
				}
				else
				{
					DirectionReleaseRight(ModeSwitchesOrientation());
					DirectionPressLeft(ModeSwitchesOrientation());
					CleanerXAxisState = LEFT;
				}
				break;
		
			case LEFT_LOST:
				if ( (tempLeftState > 0) )
				{
					DirectionReleaseLeft(ModeSwitchesOrientation());
					DirectionPressRight(ModeSwitchesOrientation());
					CleanerXAxisState = RIGHT;
				}
				else if ( (tempRightState > 0) )
				{
					DirectionReleaseRight(ModeSwitchesOrientation());
					DirectionPressLeft(ModeSwitchesOrientation());
					CleanerXAxisState = LEFT;
				}
				else
				{
					DirectionReleaseLeft(ModeSwitchesOrientation());
					DirectionPressRight(ModeSwitchesOrientation());
					CleanerXAxisState = LEFT_LOST;
				}
				break;
		
			case RIGHT:
				if ( (tempRightState > 0) )
				{
					DirectionReleaseRight(ModeSwitchesOrientation());
					CleanerXAxisState = NEUTRAL_X;
				}
				else if ( (tempLeftState == 0) )
				{
					DirectionReleaseRight(ModeSwitchesOrientation());
					DirectionPressLeft(ModeSwitchesOrientation());
					CleanerXAxisState = RIGHT_LOST;
				}
				else
				{
					DirectionReleaseLeft(ModeSwitchesOrientation());
					DirectionPressRight(ModeSwitchesOrientation());
					CleanerXAxisState = RIGHT;
				}
				break;
		
			case RIGHT_LOST:
				if ( (tempRightState > 0) )
				{
					DirectionReleaseRight(ModeSwitchesOrientation());
					DirectionPressLeft(ModeSwitchesOrientation());
					CleanerXAxisState = LEFT;
				}
				else if ( (tempLeftState > 0) )
				{
					DirectionReleaseLeft(ModeSwitchesOrientation());
					DirectionPressRight(ModeSwitchesOrientation());
					CleanerXAxisState = RIGHT;
				}
				else
				{
					DirectionReleaseRight(ModeSwitchesOrientation());
					DirectionPressLeft(ModeSwitchesOrientation());
					CleanerXAxisState = RIGHT_LOST;
				}
				break;
		
				default:
				break;
		}
		
		// Left and Right = Last Input
		switch (CleanerYAxisState)
		{
			case NEUTRAL_Y:
				if ( (tempDownState == 0) )
				{
					DirectionPressDown(ModeSwitchesOrientation());
					CleanerYAxisState = DOWN;
				}
				else if ( (tempUpState == 0) )
				{
					DirectionPressUp(ModeSwitchesOrientation());
					CleanerYAxisState = UP;
				}
				else
				{
					DirectionReleaseDown(ModeSwitchesOrientation());
					DirectionReleaseUp(ModeSwitchesOrientation());
					CleanerYAxisState = NEUTRAL_Y;
				}
			break;
			
			case DOWN:
				if ( (tempDownState > 0) )
				{
					DirectionReleaseDown(ModeSwitchesOrientation());
					CleanerYAxisState = NEUTRAL_Y;
				}
				else if ( (tempUpState == 0) )
				{
					DirectionReleaseDown(ModeSwitchesOrientation());
					DirectionPressUp(ModeSwitchesOrientation());
					CleanerYAxisState = DOWN_LOST;
				}
				else
				{
					DirectionReleaseUp(ModeSwitchesOrientation());
					DirectionPressDown(ModeSwitchesOrientation());
					CleanerYAxisState = DOWN;
				}
			break;
			
			case DOWN_LOST:
				if ( (tempDownState > 0) )
				{
					DirectionReleaseDown(ModeSwitchesOrientation());
					DirectionPressUp(ModeSwitchesOrientation());
					CleanerYAxisState = UP;
				}
				else if ( (tempUpState > 0) )
				{
					DirectionReleaseUp(ModeSwitchesOrientation());
					DirectionPressDown(ModeSwitchesOrientation());
					CleanerYAxisState = DOWN;
				}
				else
				{
					DirectionReleaseDown(ModeSwitchesOrientation());
					DirectionPressUp(ModeSwitchesOrientation());
					CleanerYAxisState = DOWN_LOST;
				}
			break;
			
			case UP:
				if ( (tempUpState > 0) )
				{
					DirectionReleaseUp(ModeSwitchesOrientation());
					CleanerYAxisState = NEUTRAL_Y;
				}
				else if ( (tempDownState == 0) )
				{
					DirectionReleaseUp(ModeSwitchesOrientation());
					DirectionPressDown(ModeSwitchesOrientation());
					CleanerYAxisState = UP_LOST;
				}
				else
				{
					DirectionReleaseDown(ModeSwitchesOrientation());
					DirectionPressUp(ModeSwitchesOrientation());
					CleanerYAxisState = UP;
				}
			break;
			
			case UP_LOST:
				if ( (tempUpState > 0) )
				{
					DirectionReleaseUp(ModeSwitchesOrientation());
					DirectionPressDown(ModeSwitchesOrientation());
					CleanerYAxisState = DOWN;
				}
				else if ( (tempDownState > 0) )
				{
					DirectionReleaseDown(ModeSwitchesOrientation());
					DirectionPressUp(ModeSwitchesOrientation());
					CleanerYAxisState = UP;
				}
				else
				{
					DirectionReleaseUp(ModeSwitchesOrientation());
					DirectionPressDown(ModeSwitchesOrientation());
					CleanerYAxisState = UP_LOST;
				}
			break;
			
			default:
			break;
		}
	}
}

void CleanerDetectThreeReleasedButtons()
{

	while(1)
	{

	}
}