#include "dio_public.h"
#include "KEYPAD_DRIVER.h"


/* Define keypad row and column ports and pins */
#define KEYPAD_ROWS_PORT   DIO_PORTB  // Port for keypad rows
#define KEYPAD_COLS_PORT   DIO_PORTC  // Port for keypad columns

/* Row pin definitions */
#define KEYPAD_ROW1_PIN    0
#define KEYPAD_ROW2_PIN    1
#define KEYPAD_ROW3_PIN    2
#define KEYPAD_ROW4_PIN    3

/* Column pin definitions */
#define KEYPAD_COL1_PIN    4
#define KEYPAD_COL2_PIN    5
#define KEYPAD_COL3_PIN    6
#define KEYPAD_COL4_PIN    7

/* Keypad layout mapping rows and columns to their respective keys */
static const uint8_t keypad_layout[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

/*
    Function Name        : keypad_vInit
    Function Returns     : void
    Function Arguments   : void
    Function Description : Initializes the keypad by configuring row pins as input
                           with pull-up resistors and column pins as output set to high.
*/
void KEYPAD_Init(void)
{
    /* Configure each row pin as input with a pull-up resistor */
    dio_pin_init(KEYPAD_ROWS_PORT, KEYPAD_ROW1_PIN, DIO_PIN_MODE_INPUT_PU);
    dio_pin_init(KEYPAD_ROWS_PORT, KEYPAD_ROW2_PIN, DIO_PIN_MODE_INPUT_PU);
    dio_pin_init(KEYPAD_ROWS_PORT, KEYPAD_ROW3_PIN, DIO_PIN_MODE_INPUT_PU);
    dio_pin_init(KEYPAD_ROWS_PORT, KEYPAD_ROW4_PIN, DIO_PIN_MODE_INPUT_PU);
    
    /* Configure each column pin as output and set them high */
    dio_pin_init(KEYPAD_COLS_PORT, KEYPAD_COL1_PIN, DIO_PIN_MODE_OUTPUT);
    dio_pin_init(KEYPAD_COLS_PORT, KEYPAD_COL2_PIN, DIO_PIN_MODE_OUTPUT);
    dio_pin_init(KEYPAD_COLS_PORT, KEYPAD_COL3_PIN, DIO_PIN_MODE_OUTPUT);
    dio_pin_init(KEYPAD_COLS_PORT, KEYPAD_COL4_PIN, DIO_PIN_MODE_OUTPUT);
    
    /* Set all column pins to high */
    dio_pin_write(KEYPAD_COLS_PORT, KEYPAD_COL1_PIN, 1);
    dio_pin_write(KEYPAD_COLS_PORT, KEYPAD_COL2_PIN, 1);
    dio_pin_write(KEYPAD_COLS_PORT, KEYPAD_COL3_PIN, 1);
    dio_pin_write(KEYPAD_COLS_PORT, KEYPAD_COL4_PIN, 1);
}

/*
    Function Name        : keypad_u8check_press
    Function Returns     : uint8_t
    Function Arguments   : void
    Function Description : Checks which key (if any) is pressed on the keypad.
                           Returns the pressed key's character or NOT_PRESSED if no key is pressed.
*/
uint8_t KEYPAD_GetPressedKey(void)
{
    uint8_t row, col, key = KEYPAD_NO_KEY_PRESSED; // Initialize key as NOT_PRESSED
    dio_level_t row_state;               // Variable to store the row state (pressed/released)

    /* Iterate through all columns */
    for (col = 0; col < 4; col++)
    {
        /* Set the current column to LOW */
        dio_pin_write(KEYPAD_COLS_PORT, col + KEYPAD_COL1_PIN, 0);
        
        /* Check all rows in the current column */
        for (row = 0; row < 4; row++)
        {
            /* Read the state of the current row */
            dio_pin_read(KEYPAD_ROWS_PORT, row + KEYPAD_ROW1_PIN, &row_state);
            
            /* If the row pin is LOW, a key is pressed */
            if (row_state == 0)
            {
                key = keypad_layout[row][col]; // Get the corresponding key from the layout
                
                /* Wait until the key is released */
                while (row_state == 0)
                {
                    dio_pin_read(KEYPAD_ROWS_PORT, row + KEYPAD_ROW1_PIN, &row_state);
                }
                return key; // Return the pressed key
            }
        }
        
        /* Reset the current column back to HIGH */
        dio_pin_write(KEYPAD_COLS_PORT, col + KEYPAD_COL1_PIN, 1);
    }
    
    return key; // Return NOT_PRESSED if no key is detected
}
