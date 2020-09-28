#ifndef MODESWITCHES_H_
#define MODESWITCHES_H_

/* Includes */
#include <avr/io.h>

/* Macros */
// Input Pins
#define	MODESWITCHES_DIP5_SW1 PINC7
#define	MODESWITCHES_DIP5_SW2 PINC5
#define	MODESWITCHES_DIP5_SW3 PINC6
#define	MODESWITCHES_DIP5_SW4 PINC4
#define	MODESWITCHES_DIP5_SW5 PINC2

#define	MODESWITCHES_DIP2_SW1 PIND1
#define	MODESWITCHES_DIP2_SW2 PIND2

#define	MODESWITCHES_PRESET_BUTTON PINB7

/* Variables */
// None

/* Function Declarations */
// Mode
uint8_t ModeSwitchesX(void);
uint8_t ModeSwitchesY(void);
uint8_t ModeSwitchesRemote(void);
uint8_t ModeSwitchesOrientation(void);
uint8_t ModeSwitchesPresetEnable(void);

#endif // MODESWITCHES_H_ 