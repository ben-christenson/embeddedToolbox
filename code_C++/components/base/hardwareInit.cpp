/*
* Copyright (c) 2013 Ben Christenson
*
* Permission is hereby granted, free of charge, to any person
* obtaining a copy of this software and associated documentation
* files (the "Software"), to deal in the Software without
* restriction, including without limitation the rights to use,
* copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following
* conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
* OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
* HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*
*/
#include "config.h" 
#include "datatypes.h" 
#include "returncodes.h" 
#include "hardwareInit.h"

#define foo "some long string"

RETURN_CODES HW_init()
{
   #ifdef DEBUG_MONITOR
   // Register debug monitor command(s)
   dbgMon_register_cmd( "hw", SDB_dbg_cmd, SDB_dbg_help );
   #endif
   return RC_OK;
}

#ifdef
void HW_dbg_help()
{
}

void HW_dbg_cmd()
{
}
#endif
