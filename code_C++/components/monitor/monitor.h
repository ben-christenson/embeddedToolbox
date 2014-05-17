#ifndef MONITOR_H_INCLUDED
#define MONITOR_H_INCLUDED

const int CMD_BUF_SIZE = 512;
const int MAX_ARG_COUNT    =  16;
const int MAX_CMD_NAME_LEN =  32;

class monitor
{
	public:
		monitor();
		~monitor();
		void Execute(void);
		void Init( void );
		void md_xhelp( void );
      void md( int xargc, char * xargv[] );
      void mm_xhelp( void );
      void mm( int xargc, char * xargv[] );
      void help( int xargc, char * xargv[] );

	protected:

	private:
      void printBuf( char * buf, int count );
      void updatePrompt( void );
      //void llistInsertEnd( struct command * newCmd );
      struct command * llistSearch( char * cmdName );
      int cmdRegister( char * newCmd,
                 void (*newFunc)( int, char ** ),
                 void (*newHelp)(void) );
		bool runB;
      char rawCmdBuf[CMD_BUF_SIZE];
      char *xargv[MAX_ARG_COUNT];
      int  bufIdx;
      int  xargc;

      struct command
      {
         char cmdS[MAX_CMD_NAME_LEN];
         void (*func)( int, char ** );
         void (*xhelp)( void );
         struct command * next;
      } cmdHead;
};


#endif // MONITOR_H_INCLUDED
