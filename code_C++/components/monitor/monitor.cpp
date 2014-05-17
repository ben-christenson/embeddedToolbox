#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monitor.h"

#define TRUE               1
#define FALSE              0



/* --------------------------------------------------- */
monitor::monitor()
{
}

monitor::~monitor()
{
}

void monitor::Execute(void)
{
   #if 1
   int ch;
   struct command *cmd;

   /* Get next char */
   ch = getc(stdin);
   if(ch)
   {
      /* Add char to buffer */
      rawCmdBuf[bufIdx++] = ch;

      /* Return hit? */
      if( ch == 0x0A )
      {
         /* Account for a hit on return only */
         if( bufIdx > 1 )
         {
            rawCmdBuf[bufIdx] = 0x00;
            xargc=0;

            /* Parse command line input into tokens */
            xargv[xargc++] = strtok(rawCmdBuf, " \n");
            while( (xargv[xargc] = strtok(NULL, " \n")) != NULL )
            {
               xargc++;
               if( xargc >= MAX_ARG_COUNT )
               {
                  printf("error: argument limit of %d exceeded\n", MAX_ARG_COUNT );
                  break;
               }
            }

            /* Look for command and call it */
            if( (cmd = llistSearch( xargv[0] )) != NULL )
            {
               cmd->func( xargc, xargv );
            }
            else
            {
               printf( "error: command %s not found\n", xargv[0] );
            }
         }
         updatePrompt();
         bufIdx=0;
      }
   }
   #endif
}


/* --------------------------------------------------- */
void monitor::Init( void )
{
   #if 0
   /* Init command list with first command */
   sprintf( cmdHead.cmdS, "help" );
   cmdHead.func  = &help;
   cmdHead.xhelp = NULL;
   cmdHead.next  = NULL;

   /* Register some functions */
   if( cmdRegister( "mm",   &mm,   &mm_xhelp ) == -1 )
      printf( "error: failed to register <mm> cmd" );

   if( cmdRegister( "md",   &md,   &md_xhelp ) == -1 )
      printf( "error: failed to register <md> cmd" );

   /* Set first prompt */
   updatePrompt();
#endif
}


/* --------------------------------------------------- */
void monitor::help( int xargc, char * xargv[] )
{
   #if 0
   struct command * cmd;

   /* Help for specific command? */
   if( xargc > 1 )
   {
      /* Search for command */
      if( (cmd = llistSearch( xargv[1])) != NULL )
      {
         /* Does command have extended help? */
         if( cmd->xhelp )
         {
            cmd->xhelp();
         }
         else
         {
            printf("error: no extended help for %s\n", xargv[1] );
         }
      }
      else
      {
         printf("error: command %s not found\n", xargv[1] );
      }
   }
   else
   {
      printf("\n------------------------------------\n");

      /* Print list */
      for( cmd = &cmdHead; cmd != NULL; cmd = cmd->next )
      {
         printf( "  %c%s\n", ((cmd->xhelp == NULL) ? ' ' : '*') , cmd->cmdS );
      }

      printf("\n------------------------------------\n");
   }
   #endif
}


/* --------------------------------------------------- */
void monitor::updatePrompt( void )
{
   printf( "\nmon> " );
}


/* --------------------------------------------------- */
int monitor::cmdRegister( char * newCmd,
                 void (*newFunc)( int, char ** ),
                 void (*newHelp)(void) )
{
   #if 0
   struct command * tmpCmd;

   tmpCmd = (struct command *)malloc(sizeof(struct command));
   if( tmpCmd == NULL )
   {
      printf("error: failed to malloc memory for cmd structure\n");
      return(-1);
   }

   sprintf(tmpCmd->cmdS, "%s", newCmd);
   tmpCmd->func  = newFunc;
   tmpCmd->xhelp = newHelp;
   llistInsertEnd( tmpCmd );
   #endif
   return(0);
}


/* --------------------------------------------------- */
struct command * monitor::llistSearch( char * cmdName )
{
   #if 0
   struct command * cmd;

   /* Go through list */
   for( cmd = &cmdHead; cmd != NULL; cmd = cmd->next )
   {
      /* Compare search name to command name */
      if( strncmp( cmd->cmdS, cmdName, strlen(cmd->cmdS)) == 0 )
      {
         return(cmd);
      }
   }
   #endif
   return(NULL);
}

#if 0
/* --------------------------------------------------- */
void monitor::llistInsertEnd( struct monitor::command * newCmd )
{
   #if 0
   struct command * cmd;

   /* Go to last entry */
   for( cmd = &cmdHead; cmd->next != NULL; cmd = cmd->next );

   /* Add new entry */
   cmd->next = newCmd;
   #endif
}
#endif

/* --------------------------------------------------- */
void monitor::printBuf( char * buf, int count )
{
   int i=0;
   int idx=0;
   char tmpBuf[256];

   while( i < count )
   {
      /* Add 1 char to buffer */
      idx += sprintf(&tmpBuf[idx], "0x%2.2x ", *buf++ );
      i++;

      /* Print 8 chars per line */
      if( i%8 == 0 )
      {
         printf("%s\n", tmpBuf );
         idx=0;
      }
   }

   /* Catch any straglers */
   if(idx!=0)
      printf("%s\n", tmpBuf );
}


/* --------------------------------------------------- */
void monitor::mm( int xargc, char * xargv[] )
{
   #if 0
   unsigned char *address = NULL;
   unsigned int  val;

   if( xargc != 3 )
   {
      printf( "error: bad or missing arguments\n" );
      return;
   }

   /* Get address */
   address = (char *)strtoul(xargv[1],NULL,0);

   /* Get value */
   val = strtoul(xargv[2],NULL,0);

   //*address = val;
   printf( "address=%p value=%d\n", address, *address);
#endif
}


/* --------------------------------------------------- */
void monitor::mm_xhelp( void )
{
   printf("md: memory modify\n" );
   printf("usage: mx 0x12345678 <value>\n" );
}


/* --------------------------------------------------- */
void monitor::md( int xargc, char * xargv[] )
{
   unsigned int address = 0;
   unsigned int length  = 1;

   if( xargc < 2 )
   {
      printf( "error: bad or missing arguments\n" );
      return;
   }

   /* Get address */
   address = strtoul(xargv[1],NULL,0);

   /* Get length if passed in */
   if( xargc == 3 )
   {
      length = strtoul(xargv[2],NULL,0);
   }

   printf( "address=%ld length=%d", address, length );
   //printBuf( (char *)address, length );
}


/* --------------------------------------------------- */
void monitor::md_xhelp( void )
{
   printf("md: memory dump\n" );
   printf("usage: mx 0x12345678 [count]\n" );
}
