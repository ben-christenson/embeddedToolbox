#ifndef SIMPLE_DB_H
#define SIMPLE_DB_H

#define DB_STR_LEN 16

enum
{
   KEY_FLOAT_NAME,
   KEY_INT_NAME,
   KEY_STRING_NAME,
}
SDB_KEY;

typedef union
{
   float db_float;
   int db_int;
   char db_string[DB_STR_LEN];
}
SDB_VALUE;

#endif
