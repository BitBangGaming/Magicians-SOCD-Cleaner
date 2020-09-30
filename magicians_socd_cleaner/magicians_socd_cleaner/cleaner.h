/* Header Guard */
#ifndef CLEANER_H_
#define CLEANER_H_

/* Includes */
#include <avr/io.h>
#include "direction.h"
#include "modeswitches.h"

/* Macros */
// X axis states
#define NEUTRAL_X  0
#define LEFT	   1
#define LEFT_LOST  2
#define RIGHT	   3
#define RIGHT_LOST 4

// Y axis states
#define NEUTRAL_Y  0
#define DOWN	   1
#define DOWN_LOST  2
#define UP		   3
#define UP_LOST	   4

/* Variables */
// State trackers
static uint8_t CleanerXAxisState;
static uint8_t CleanerYAxisState;

/* Function Declarations */
// SOCD Cleaners
void CleanerXNeutral(uint8_t, uint8_t);
void CleanerXLeft(uint8_t, uint8_t);
void CleanerXRight(uint8_t, uint8_t);
void CleanerXLastInput(uint8_t, uint8_t);
void CleanerYNeutral(uint8_t, uint8_t);
void CleanerYDown(uint8_t, uint8_t);
void CleanerYUp(uint8_t, uint8_t);
void CleanerYLastInput(uint8_t, uint8_t);

#endif // CLEANER_H_