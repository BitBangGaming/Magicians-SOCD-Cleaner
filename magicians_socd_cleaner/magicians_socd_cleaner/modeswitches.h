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
uint8_t ModeSwitchesReadDip5Sw1(void);
uint8_t ModeSwitchesReadDip5Sw2(void);
uint8_t ModeSwitchesReadDip5Sw3(void);
uint8_t ModeSwitchesReadDip5Sw4(void);
uint8_t ModeSwitchesReadDip5Sw5(void);
uint8_t ModeSwitchesReadDip2Sw1(void);
uint8_t ModeSwitchesReadDip2Sw2(void);
uint8_t ModeSwitchesReadRemoteButton(void);
uint8_t ModeSwitchesX(void);
uint8_t ModeSwitchesY(void);
uint8_t ModeSwitchesRemote(void);
uint8_t ModeSwitchesOrientation(void);

#endif // MODESWITCHES_H_ 