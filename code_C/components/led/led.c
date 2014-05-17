//*****************************************************************************
//  Copyright(c)
//
//  Description:
//
//*****************************************************************************
#include "led.h"

void LED_init()
{
   // Init hardware
   // Set starting state of each LED
   // Launch any interrupt sources
}


void LED_set( LED_ID led, LED_STATE state, LED_COLOR color )
{
   // Put calls here to HW driver for specific LEDs
   switch( led )
   {
      case LED_SOME_ACTIVITY:
      {
      }
      break;

      default:
      {
         // some error or assert?
      }
   }
}


// Should be called at periodic interval, perhaps a timer ISR
void LED_heartbeat()
{
   // Toggle LED
}


// This function will loop forever blinking some 
// critical error code on an LED
void LED_errorBlink( LED_BLINK_CODE code )
{
   while(1)
   {
      // Toggle LED ON or OFF
      // Account for single or double blink code
      // Kick watchdog
      // Wait <blink interval> before next toggle
   }
}
