#include "config.h" 
#include "version.h" 
#include "datatypes.h" 
#include "returncodes.h" 
#include "hardwareInit.h" 

int main (int argv, char ** argc)
{
  RETURNCODE rc = RC_FAIL;

  rc = HW_init(); 
}
