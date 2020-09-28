/* Header Guard */
#ifndef CLEANER_H_
#define CLEANER_H_

/* Includes */
#include <avr/io.h>
#include "direction.h"
#include "modeswitches.h"

/* Macros */
// None

/* Variables */
// None

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