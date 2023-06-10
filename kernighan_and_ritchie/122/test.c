#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "sol.h"

int main()
{
   char teststring[MAXLINE];

   strcpy(teststring, "mary had a little lamb its fleece as white as snow");
   fold_line(teststring, 10);
   assert(strcmp(teststring, "mary had a\nlittle\nlamb its\nfleece as\nwhite as\nsnow") == 0);

   printf("All tests passed.\n");

   return 0;
}
