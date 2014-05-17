//*****************************************************************************
//  Copyright(c)
//
//  Description:
//
//*****************************************************************************
#ifndef LED_H
#define LED_H

#include "config.h" 
#include "datatypes.h" 
#include "returncodes.h"

// If you have no user interface or logging you can blink critical errors
// so someone can figure out why this system failed.
enum
{
   LED_CODE_ERROR,         // Details for user manual here?
   LED_CODE_NO_USE = 11,   // Easily confused as 1 blink
}
LED_BLINK_CODE;

// Update to match colors of LEDs in your system
enum
{
   LED_RED,
   LED_GREEN,
   LED_YELLOW
}
LED_COLOR;

// Signal action and handle active high/low in code
enum
{
   LED_ON,
   LED_OFF
}
LED_STATE;

// Give LEDs a name so it's easy to follow the code
enum
{
   LED_HEARTBEAT,
   LED_SOME_ACTIVITY,
   LED_WHATEVER
}
LED_ID;

void LED_init();
void LED_heartbeat();
void LED_errorBlink( LED_BLINK_CODE code );
void LED_set( LED_ID led, LED_STATE state, LED_COLOR color );

#endif
