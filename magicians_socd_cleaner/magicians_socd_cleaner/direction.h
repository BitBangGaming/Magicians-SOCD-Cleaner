/* Header Guard */
#ifndef DIRECTION_H_    
#define DIRECTION_H_

/* Includes */
#include <avr/io.h>
#include <avr/eeprom.h>

/* Macros */
// Output Pins
#define DIRECTION_SW1_CLEAN PD3
#define DIRECTION_SW2_CLEAN PD4
#define DIRECTION_SW3_CLEAN PD5
#define DIRECTION_SW4_CLEAN PD6
#define DIRECTION_RIGHT_LED PD0
#define DIRECTION_LEFT_LED  PB4
#define DIRECTION_DOWN_LED  PB5
#define DIRECTION_UP_LED    PB6

// Input Pins
#define DIRECTION_RIGHT_BUTTON PINB0
#define DIRECTION_LEFT_BUTTON  PINB1
#define DIRECTION_DOWN_BUTTON  PINB2
#define DIRECTION_UP_BUTTON    PINB3

/* Variables */
static uint8_t invertModeCode;

/* Function Declarations */
// Setting Outputs
void DirectionPressLeft(uint8_t);
void DirectionReleaseLeft(uint8_t);
void DirectionPressRight(uint8_t);
void DirectionReleaseRight(uint8_t);
void DirectionPressDown(uint8_t);
void DirectionReleaseDown(uint8_t);
void DirectionPressUp(uint8_t);
void DirectionReleaseUp(uint8_t);

// LED Outputs
void DirectionPressLeftLed();
void DirectionReleaseLeftLed();
void DirectionPressRightLed();
void DirectionReleaseRightLed();
void DirectionPressDownLed();
void DirectionReleaseDownLed();
void DirectionPressUpLed();
void DirectionReleaseUpLed();

// Reading Inputs
uint8_t DirectionGetLeftState(void);
uint8_t DirectionGetRightState(void);
uint8_t DirectionGetUpState(void);
uint8_t DirectionGetDownState(void);

#endif // DIRECTION_H_
