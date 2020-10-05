/* Header Guard */
#ifndef MAIN_H_
#define MAIN_H_

/* Includes */
// None

/* Macros */
// I/O
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

// Remote mode codes
#define	REMOTE_MODE_0  0
#define	REMOTE_MODE_1  1
#define	REMOTE_MODE_2  2
#define	REMOTE_MODE_3  3
#define	REMOTE_MODE_4  4
#define	REMOTE_MODE_5  5
#define	REMOTE_MODE_6  6
#define	REMOTE_MODE_7  7
#define	REMOTE_MODE_8  8
#define	REMOTE_MODE_9  9
#define	REMOTE_MODE_10 10
#define	REMOTE_MODE_11 11
#define	REMOTE_MODE_12 12
#define	REMOTE_MODE_13 13
#define	REMOTE_MODE_14 14
#define	REMOTE_MODE_15 15

/* Variables */
static uint8_t remoteModeCode;
static uint8_t programModeCounter;

/* Function Declarations */
// Main routine 
int main(void);

// Cleaning Selection Logic 
static void MainGoClean(void);
static void MainCleanerX(uint8_t, uint8_t);
static void MainCleanerY(uint8_t, uint8_t);
static void MainCleanerRemote(uint8_t, uint8_t, uint8_t, uint8_t);
static void MainUpdateProgramModeCounter(void);
static void MainProgramModeChecker(void);
static void MainUpdateRemoteModeCode(uint8_t, uint8_t, uint8_t, uint8_t);

// Initialization
static void MainInitialize(void);

#endif // MAIN_H_ 