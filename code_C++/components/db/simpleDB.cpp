//*****************************************************************************
//  Copyright(c)
//
//  Description:
//
//*****************************************************************************
#include "config.h" 
#include "datatypes.h" 
#include "returncodes.h"

typedef struct
{
}
DB_ENTRIES;

DB_ENTRIES db;


void SDB_init()
{
   // Clear resident copy of DB
   memset(db,0,sizeof(DB_ENTRIES));

   // Get copy from non-volatile storage

   // Verify CRC

   #ifdef DEBUG_MONITOR
   // Register debug monitor command(s)
   dbgMon_register_cmd( "db", SDB_dbg_cmd, SDB_dbg_help );
   #endif
}


void SDB_set( SDB_KEY key, SDB_VALUE value)
{
   // Get DB lock

   // Write value
   switch ( key )
   {
      case KEY_FLOAT_NAME:
      {
      }
      break;

      case KEY_INT_NAME:
      {
      }
      break;

      case KEY_STRING_NAME:
      {
      }
      break;

      default:
      {
      }
   };

   // Release lock
}


SDB_VALUE SDB_get( SDB_KEY key )
{
}


void SDB_write()
{
   // Calculate new CRC
   // Write to non-volatile storage
}


#ifdef DEBUG_MONITOR
void SDB_dbg_help()
{
}

void SDB_dbg_cmd()
{
}
#endif
