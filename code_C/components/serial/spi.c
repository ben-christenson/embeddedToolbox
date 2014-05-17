//*****************************************************************************
//  Copyright(c)
//
//  Description:
//
//*****************************************************************************
#include "uart.h"

enum
{
   UART_IDLE,
   UART_TX,
   UART_COMPLETE,
   UART_ERROR,
}
UART_TX_STATUS;
static UART_TX_STATUS tx_status = UART_IDLE;

// How many bytes can we load at once into chip buffer
#define UART_TX_BUFFER_DEPTH 1

// How big is our receive buffer in memory
#define RX_BUFFER_DEPTH 32
static uint8 rx_buffer[RX_BUFFER_DEPTH];

// How big is our transmit buffer in memory
#define TX_BUFFER_DEPTH 32
static uint8 tx_buffer[TX_BUFFER_DEPTH];

void UART_init( UART_CFG * cfg )
{
   // set Baud
   // Set stop
   // Set parity
   // Clear RX buffer
   // Clear TX buffer
   // Enable RX interrupt
}


uint8 UART_peak()
{
   // Return next byte in queue but doesn't remove it from queue
}

uint8 UART_getbyte()
{
   // Make sure there is data in RX buffer
   // Copy 1 byte and adjust buffer pointer
   return(0);
}

uint8 UART_putbyte( uint8 byte )
{
   // Make sure we are not in an TX cycle
   if( tx_status == UART_IDLE )
   {
      // Shove right into chip TX buffer

      // Return bytes sent
      return(1);
   }
   return(0);
}

void UART_put( uint8 * msg, uint32 length )
{
   // Make sure length doesn't exceed buffer size
   // Make sure we have buffer space
   // Copy date to buffer
   // Start TX cycle
}

uint32 UART_get( uint8 * buffer, uint16 max, uint8 eom )
{
   uint8 * byte = null;
   uint32 i = 0;

   // While we haven't reached max bytes and end of msg char
   // copy bytes into remote buffer
   while( (i++ < max) && (byte != eom) )
   {
      *buffer++ = *byte++
   }

   // Return how many bytes we copied
   return i;
}

void UART_isr()
{
   // Was this an RX interrupt

   // Was this a TX empty interrupt
   
   // Was this some error interrupt
}
