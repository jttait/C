#include <assert.h>
#include <string.h>
#include "sol.h"

int main()
{
   char teststring[MAXLINE];

   strcpy(teststring, "hello world");
   reverse(teststring);
   assert(strcmp(teststring, "dlrow olleh") == 0);

   return 0;
}
