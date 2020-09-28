/* Header Guard */
#ifndef MAIN_H_
#define MAIN_H_

/* Includes */
// None

/* Macros */
#define MAIN_RIGHT_BUTTON_PULLUP  PB0
#define MAIN_LEFT_BUTTON_PULLUP   PB1
#define MAIN_DOWN_BUTTON_PULLUP   PB2
#define MAIN_UP_BUTTON_PULLUP     PB3
#define	MAIN_DIP5_SW1_PULLUP	  PC7
#define	MAIN_DIP5_SW2_PULLUP	  PC5
#define	MAIN_DIP5_SW3_PULLUP	  PC6
#define	MAIN_DIP5_SW4_PULLUP	  PC4
#define	MAIN_DIP5_SW5_PULLUP	  PC2
#define	MAIN_DIP2_SW1_PULLUP	  PD1
#define	MAIN_DIP2_SW2_PULLUP	  PD2
#define	MAIN_PRESET_BUTTON_PULLUP PB7

/* Variables */
uint8_t leftState = 0;
uint8_t rightState = 0;
uint8_t downState = 0;
uint8_t upState = 0;

/* Function Declarations */
// Main routine 
int main(void);

// Cleaning Selection Logic 
void MainCleanerX(uint8_t, uint8_t);
void MainCleanerY(uint8_t, uint8_t);

// Initialization
void MainInitialize(void);

#endif // MAIN_H_ 