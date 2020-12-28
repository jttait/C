#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "sol.h"

int main()
{
   char teststring[MAXLINE];

   strcpy(teststring, "hello        ");
   remove_trailing_whitespace_and_newline(teststring);
   assert(strcmp(teststring, "hello") == 0);

   strcpy(teststring, "hello\t\t");
   remove_trailing_whitespace_and_newline(teststring);
   assert(strcmp(teststring, "hello") == 0);

   return 0;
}


