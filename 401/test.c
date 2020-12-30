#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "sol.h"

int main()
{
   char s[MAXLINE];
   char t[MAXLINE];

   strcpy(s, "hello world world");
   strcpy(t, "wor");
   assert(strrindex(s, t) == 12);

   strcpy(s, "cat bat fat");
   strcpy(t, "at");
   assert(strrindex(s, t) == 9);

   printf("All tests passed.\n");

   return 0;
}
