/* Header Guard */
#ifndef CLEANER_H_
#define CLEANER_H_

/* Includes */
#include <avr/io.h>
#include "direction.h"
#include "modeswitches.h"

/* Macros */
// X axis states for last input cleaner
#define NEUTRAL_X  0
#define LEFT	   1
#define LEFT_LOST  2
#define RIGHT	   3
#define RIGHT_LOST 4

// Y axis states for last input cleaner
#define NEUTRAL_Y  0
#define DOWN	   1
#define DOWN_LOST  2
#define UP		   3
#define UP_LOST	   4

// tetris cleaner
#define NEUTRAL_TETRIS    10
#define LEFT_TETRIS		  11
#define LEFT_LOST_TETRIS  12
#define RIGHT_TETRIS	  13
#define RIGHT_LOST_TETRIS 14
#define DOWN_TETRIS		  15
#define DOWN_LOST_TETRIS  16
#define UP_TETRIS		  17
#define UP_LOST_TETRIS	  18

/* Variables */
// State trackers for last input cleaner
static uint8_t CleanerXAxisState;
static uint8_t CleanerYAxisState;
static uint8_t CleanerDirectionState = NEUTRAL_TETRIS;

/* Function Declarations */
// Cleaners
void CleanerXNeutral(uint8_t, uint8_t);
void CleanerXLeft(uint8_t, uint8_t);
void CleanerXRight(uint8_t, uint8_t);
void CleanerXLastInput(uint8_t, uint8_t);
void CleanerYNeutral(uint8_t, uint8_t);
void CleanerYDown(uint8_t, uint8_t);
void CleanerYUp(uint8_t, uint8_t);
void CleanerYLastInput(uint8_t, uint8_t);
void CleanerTetris(uint8_t, uint8_t, uint8_t, uint8_t);
void CleanerCustom0(uint8_t, uint8_t, uint8_t, uint8_t);

// Helper functions
void CleanerDetectThreeReleasedButtons();

#endif // CLEANER_H_