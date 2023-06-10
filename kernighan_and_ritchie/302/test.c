#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "sol.h"

int main()
{
   char s[MAXLINE];
   char t[MAXLINE];

   /* escape */

   strcpy(s, "\t");
   escape(s,t);
   assert(strcmp(t, "\\t") == 0);

   strcpy(s, "\n");
   escape(s,t);
   assert(strcmp(t, "\\n") == 0);

   strcpy(s, "hello\tworld\n");
   escape(s,t);
   assert(strcmp(t, "hello\\tworld\\n") == 0);

   strcpy(s, "\thello\t\t\tworld\n");
   escape(s,t);
   assert(strcmp(t, "\\thello\\t\\t\\tworld\\n") == 0);

   /* deescape */

   strcpy(t, "\\t");
   deescape(t, s);
   assert(strcmp(s, "\t") == 0);

   strcpy(t, "\\n");
   deescape(t, s);
   assert(strcmp(s, "\n") == 0);

   strcpy(t, "hello\\tworld\\n");
   deescape(t, s);
   assert(strcmp(s, "hello\tworld\n") == 0);

   strcpy(t, "\\thello\\t\\t\\tworld\\n");
   deescape(t, s);
   assert(strcmp(s, "\thello\t\t\tworld\n") == 0);

   printf("All tests passed.\n");

   return 0;
}
