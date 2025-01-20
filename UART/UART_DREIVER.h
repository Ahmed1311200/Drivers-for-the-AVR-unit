#ifndef __UART_H

#define __UART_H

#include <stdint.h>

typedef enum
{
    UART_PARITY_NONE,
    UART_PARITY_EVEN,
    UART_PARITY_ODD,
} uart_parity_t;

typedef enum
{
    UART_STOP_BITS_1,
    UART_STOP_BITS_2,
} uart_stop_bits_t;

typedef enum
{
    UART_TX_ONLY,
    UART_RX_ONLY,
    UART_TX_RX,
} uart_mode_t;

typedef struct
{
    uart_parity_t parity;
    uart_stop_bits_t stop_bits;
    uart_mode_t mode;
    uint32_t baudrate;
    uint32_t f_cpu;
} uart_config_t;

int8_t uart_init(const uart_config_t* config);

int8_t uart_tx(const uint8_t* tx_data, uint32_t len);
int8_t uart_rx(uint8_t* rx_data, uint32_t len);
uint32_t uart_write(const uint8_t* tx_data, uint32_t len, void (*callback) (void));

#endif