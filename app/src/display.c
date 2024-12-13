/********************** inclusions *******************************************/
#include "display.h"
#include "main.h"
#include <stdbool.h>

/********************** arm_book Defines *******************************/

// Functional states
#ifndef OFF
#define OFF    0
#endif
#ifndef ON
#define ON     (!OFF)
#endif

// Electrical states
#ifndef LOW
#define LOW    0
#endif
#ifndef HIGH
#define HIGH   (!LOW)
#endif

/********************** macros and definitions *******************************/
#define DISPLAY_IR_CLEAR_DISPLAY   0b00000001
#define DISPLAY_IR_ENTRY_MODE_SET  0b00000100
#define DISPLAY_IR_DISPLAY_CONTROL 0b00001000
#define DISPLAY_IR_FUNCTION_SET    0b00100000
#define DISPLAY_IR_SET_DDRAM_ADDR  0b10000000

#define DISPLAY_IR_ENTRY_MODE_SET_INCREMENT 0b00000010
#define DISPLAY_IR_ENTRY_MODE_SET_NO_SHIFT  0b00000000

#define DISPLAY_IR_DISPLAY_CONTROL_DISPLAY_ON  0b00000100
#define DISPLAY_IR_DISPLAY_CONTROL_DISPLAY_OFF 0b00000000
#define DISPLAY_IR_DISPLAY_CONTROL_CURSOR_OFF  0b00000000
#define DISPLAY_IR_DISPLAY_CONTROL_BLINK_OFF   0b00000000

#define DISPLAY_IR_FUNCTION_SET_8BITS    0b00010000
#define DISPLAY_IR_FUNCTION_SET_4BITS    0b00000000
#define DISPLAY_IR_FUNCTION_SET_2LINES   0b00001000
#define DISPLAY_IR_FUNCTION_SET_5x8DOTS  0b00000000

#define DISPLAY_20x4_LINE1_FIRST_CHARACTER_ADDRESS 0
#define DISPLAY_20x4_LINE2_FIRST_CHARACTER_ADDRESS 64
#define DISPLAY_20x4_LINE3_FIRST_CHARACTER_ADDRESS 20
#define DISPLAY_20x4_LINE4_FIRST_CHARACTER_ADDRESS 84

#define DISPLAY_RS_INSTRUCTION 0
#define DISPLAY_RS_DATA        1

#define DISPLAY_RW_WRITE 0

#define DISPLAY_PIN_RS  4
#define DISPLAY_PIN_RW  5
#define DISPLAY_PIN_EN  6
#define DISPLAY_PIN_D4 11
#define DISPLAY_PIN_D5 12
#define DISPLAY_PIN_D6 13
#define DISPLAY_PIN_D7 14


/********************** internal data declaration ****************************/

static display_t display;
static bool initial8BitCommunicationIsCompleted;

/********************** internal functions declaration ***********************/
static void displayPinWrite( uint8_t pinName, int value );
static void displayDataBusWrite( uint8_t dataByte );
static void displayCodeWrite( bool type, uint8_t dataBus );

/********************** internal data definition *****************************/
/********************** external data declaration ****************************/
/********************** external functions definition ************************/

void displayInit()
{
    display.connection = DISPLAY_CONNECTION_GPIO_4BITS;

    initial8BitCommunicationIsCompleted = false;

    HAL_Delay(50);

    displayCodeWrite( DISPLAY_RS_INSTRUCTION,
                      DISPLAY_IR_FUNCTION_SET |
                      DISPLAY_IR_FUNCTION_SET_8BITS );
    HAL_Delay(5);

    displayCodeWrite( DISPLAY_RS_INSTRUCTION,
                      DISPLAY_IR_FUNCTION_SET |
                      DISPLAY_IR_FUNCTION_SET_8BITS );
    HAL_Delay(1);

    displayCodeWrite( DISPLAY_RS_INSTRUCTION,
                      DISPLAY_IR_FUNCTION_SET |
                      DISPLAY_IR_FUNCTION_SET_8BITS );
    HAL_Delay(1);

	displayCodeWrite( DISPLAY_RS_INSTRUCTION,
					  DISPLAY_IR_FUNCTION_SET |
					  DISPLAY_IR_FUNCTION_SET_4BITS );
	HAL_Delay(1);

	initial8BitCommunicationIsCompleted = true;

	displayCodeWrite( DISPLAY_RS_INSTRUCTION,
					  DISPLAY_IR_FUNCTION_SET |
					  DISPLAY_IR_FUNCTION_SET_4BITS |
					  DISPLAY_IR_FUNCTION_SET_2LINES |
					  DISPLAY_IR_FUNCTION_SET_5x8DOTS );
	HAL_Delay(1);

    displayCodeWrite( DISPLAY_RS_INSTRUCTION,
                      DISPLAY_IR_DISPLAY_CONTROL |
                      DISPLAY_IR_DISPLAY_CONTROL_DISPLAY_OFF |
                      DISPLAY_IR_DISPLAY_CONTROL_CURSOR_OFF |
                      DISPLAY_IR_DISPLAY_CONTROL_BLINK_OFF );
    HAL_Delay(1);

    displayCodeWrite( DISPLAY_RS_INSTRUCTION,
                      DISPLAY_IR_CLEAR_DISPLAY );
    HAL_Delay(1);

    displayCodeWrite( DISPLAY_RS_INSTRUCTION,
                      DISPLAY_IR_ENTRY_MODE_SET |
                      DISPLAY_IR_ENTRY_MODE_SET_INCREMENT |
                      DISPLAY_IR_ENTRY_MODE_SET_NO_SHIFT );
    HAL_Delay(1);

    displayCodeWrite( DISPLAY_RS_INSTRUCTION,
                      DISPLAY_IR_DISPLAY_CONTROL |
                      DISPLAY_IR_DISPLAY_CONTROL_DISPLAY_ON |
                      DISPLAY_IR_DISPLAY_CONTROL_CURSOR_OFF |
                      DISPLAY_IR_DISPLAY_CONTROL_BLINK_OFF );
    HAL_Delay(1);
}

void displayCharPositionWrite( uint8_t charPositionX, uint8_t charPositionY )
{
    switch( charPositionY ) {
        case 0:
            displayCodeWrite( DISPLAY_RS_INSTRUCTION,
                              DISPLAY_IR_SET_DDRAM_ADDR |
                              ( DISPLAY_20x4_LINE1_FIRST_CHARACTER_ADDRESS +
                                charPositionX ) );
            HAL_Delay(1);
        break;

        case 1:
            displayCodeWrite( DISPLAY_RS_INSTRUCTION,
                              DISPLAY_IR_SET_DDRAM_ADDR |
                              ( DISPLAY_20x4_LINE2_FIRST_CHARACTER_ADDRESS +
                                charPositionX ) );
            HAL_Delay(1);
        break;

        case 2:
            displayCodeWrite( DISPLAY_RS_INSTRUCTION,
                              DISPLAY_IR_SET_DDRAM_ADDR |
                              ( DISPLAY_20x4_LINE3_FIRST_CHARACTER_ADDRESS +
                                charPositionX ) );
            HAL_Delay(1);
        break;

        case 3:
            displayCodeWrite( DISPLAY_RS_INSTRUCTION,
                              DISPLAY_IR_SET_DDRAM_ADDR |
                              ( DISPLAY_20x4_LINE4_FIRST_CHARACTER_ADDRESS +
                                charPositionX ) );
            HAL_Delay(1);
        break;
    }
}

void displayStringWrite( const char * str )
{
    while (*str) {
        displayCodeWrite(DISPLAY_RS_DATA, *str++);
    }
}

/********************** internal functions definition ************************/

static void displayCodeWrite( bool type, uint8_t dataBus) {
	if (type == DISPLAY_RS_INSTRUCTION)
		displayPinWrite( DISPLAY_PIN_RS, DISPLAY_RS_INSTRUCTION);
	else
		displayPinWrite( DISPLAY_PIN_RS, DISPLAY_RS_DATA);
	displayPinWrite( DISPLAY_PIN_RW, DISPLAY_RW_WRITE);
	displayDataBusWrite(dataBus);
}

static void displayPinWrite( uint8_t pinName, int value )
{
	switch( pinName ) {
		case DISPLAY_PIN_D4: HAL_GPIO_WritePin(D2_GPIO_Port,  D2_Pin,  value);   break;
		case DISPLAY_PIN_D5: HAL_GPIO_WritePin(D7_GPIO_Port,  D7_Pin,  value);   break;
		case DISPLAY_PIN_D6: HAL_GPIO_WritePin(D8_GPIO_Port,  D8_Pin,  value);   break;
		case DISPLAY_PIN_D7: HAL_GPIO_WritePin(D9_GPIO_Port,  D9_Pin, value);   break;
		case DISPLAY_PIN_RS: HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, value);   break;
		case DISPLAY_PIN_EN: HAL_GPIO_WritePin(D11_GPIO_Port, D11_Pin, value);   break;
		case DISPLAY_PIN_RW: break;
		default: break;
	}
}

static void displayDataBusWrite( uint8_t dataBus )
{
    displayPinWrite( DISPLAY_PIN_EN, OFF );
    displayPinWrite( DISPLAY_PIN_D7, dataBus & 0b10000000 );
    displayPinWrite( DISPLAY_PIN_D6, dataBus & 0b01000000 );
    displayPinWrite( DISPLAY_PIN_D5, dataBus & 0b00100000 );
    displayPinWrite( DISPLAY_PIN_D4, dataBus & 0b00010000 );

	if ( initial8BitCommunicationIsCompleted == true) {
		displayPinWrite( DISPLAY_PIN_EN, ON );
		HAL_Delay(1);
		displayPinWrite( DISPLAY_PIN_EN, OFF );
		HAL_Delay(1);
		displayPinWrite( DISPLAY_PIN_D7, dataBus & 0b00001000 );
		displayPinWrite( DISPLAY_PIN_D6, dataBus & 0b00000100 );
		displayPinWrite( DISPLAY_PIN_D5, dataBus & 0b00000010 );
		displayPinWrite( DISPLAY_PIN_D4, dataBus & 0b00000001 );
	}

    displayPinWrite( DISPLAY_PIN_EN, ON );
    HAL_Delay(1);
    displayPinWrite( DISPLAY_PIN_EN, OFF );
    HAL_Delay(1);
}
/********************** end of file ******************************************/

