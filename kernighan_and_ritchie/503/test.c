#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "sol.h"


int main()
{
   char s[MAXLINE];
   char t[MAXLINE];

   strcpy(s, "hello, ");
   strcpy(t, "world");
   strcat2(s, t);
   assert(strcmp(s, "hello, world") == 0);

   strcpy(s, "1, 2, 3, ");
   strcpy(t, "4, 5, 6.");
   strcat2(s, t);
   assert(strcmp(s, "1, 2, 3, 4, 5, 6.") == 0);

   printf("All tests passed.\n");

   return 0;
}
