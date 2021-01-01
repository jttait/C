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
   int result;

   strcpy(s, "hello, world");
   strcpy(t, "world");
   result = strend(s, t);
   assert(result == 1);

   strcpy(s, "hello, world");
   strcpy(t, "world!");
   result = strend(s, t);
   assert(result == 0);

   printf("All tests passed.\n");

   return 0;
}
