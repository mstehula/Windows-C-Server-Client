#include <stdio.h>
#include "server.h"

int main(int argc, char * argv[])
// -
// Func: This is the main thread for the client executable
// Args: Any command line arugments for the clinet to observe
// Retn: Errors, if any. Else, will return a 0
// -
{
  if(argc == 1)
  // No arguments
  {

  }
  else
  // More than one arguments
  {
    for(; argc > 0; argc--)
    //Loop through all arguments
    {

    }
  }

  int server_id = start_server();

  stop_server(server_id);

  return(0);
}
