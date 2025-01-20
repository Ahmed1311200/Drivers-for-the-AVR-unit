#include "UART_DREIVER.h"

#include <string.h>
#include <stddef.h>
#include "STD_TYPE.h"
#define TX_BUFFER_SIZE  100



static uart_config_t uart_config;

static void uart_apply_baudrate(void);

static uint32_t tx_index = 0;
static uint32_t tx_total = 0;
static uint8_t tx_buffer[TX_BUFFER_SIZE];
static void (*tx_complete)(void);


int8_t uart_init(const uart_config_t* config)
{
    int8_t retval = 0;
    uint8_t temp = 0;
    
    memcpy(&uart_config, config, sizeof(uart_config_t));
    
    uart_apply_baudrate();
    
    if(config->parity == UART_PARITY_EVEN)
    {
        temp |= (1 << 5);
    }
    else if(config->parity == UART_PARITY_ODD)
    {
        temp |= (1 << 5) | (1 << 4);
    }
    
    if(config->stop_bits == UART_STOP_BITS_2)
    {
        temp |= (1 << 3);
    }
    
    temp |= (1 << 2) | (1 << 1);
    
    *UCSRC = (1 << 7) | temp;
    
    *SREG |= 0x80;
    
    return retval;
}

int8_t uart_tx(const uint8_t* tx_data, uint32_t len)
{
    int8_t retval = 0;
    
    if(tx_data == NULL)
    {
        retval = -1;
    }
    else if(uart_config.mode == UART_RX_ONLY)
    {
        retval = -1;
    }
    else
    {
        *UCSRB |= (1 << 3);
        
        for(uint32_t index = 0; index < len; index++)
        {
            
            while((*UCSRA & (1 << 5)) == 0);
            *UDR = tx_data[index];
        }
        
        while((*UCSRA & (1 << 6)) == 0);
        
        *UCSRB &= ~(1 << 3);
    }
    
    return retval;
}

int8_t uart_rx(uint8_t* rx_data, uint32_t len)
{
    int8_t retval = 0;
    
    if(rx_data == NULL)
    {
        retval = -1;
    }
    else if(uart_config.mode == UART_TX_ONLY)
    {
        retval = -1;
    }
    else
    {
        *UCSRB |= (1 << 4);
        
        for(uint32_t index = 0; index < len; index++)
        {
           
            while((*UCSRA & (1 << 7)) == 0);
            rx_data[index] = *UDR;
        }
        
        *UCSRB &= ~(1 << 4);
    }
    
    return retval;
}

uint32_t uart_write(const uint8_t* tx_data, uint32_t len, void (*callback) (void))
{
    uint32_t retval = 0;
    
    if(tx_data == NULL)
    {
        retval = -1;
    }
    else if(uart_config.mode == UART_RX_ONLY)
    {
        retval = -1;
    }
    else
    {
        tx_total = (len > TX_BUFFER_SIZE) ? TX_BUFFER_SIZE : len;
        tx_index = 0;
        memcpy(tx_buffer, tx_data, tx_total);
        
        *UCSRB |= (1 << 3);
        
        *UCSRB |= (1 << 6) | (1 << 5);
        
        tx_complete = callback;
        
        retval = tx_total;
    }
    
    return retval;
}

static void uart_apply_baudrate(void)
{
    uint16_t ubbr;
    
    *UCSRA |= 0x02;
    
    ubbr = uart_config.f_cpu / (8 * uart_config.baudrate) - 1;
    
    *UBBRL = ubbr;
    *UBBRH = ubbr >> 8;
}

void __vector_14(void) __attribute__((signal));
void __vector_14(void)
{
    *UDR = tx_buffer[tx_index];
    
    if(tx_index < tx_total - 1)
    {
        tx_index++;
    }
    else
    {
         *UCSRB &= ~(1 << 5);
    }
}

void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
    *UCSRB &= ~(1 << 6);
    
    if(tx_complete != NULL)
    {
        tx_complete();
    }
}