#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "sol.h"

int main()
{
   char s1[MAXLINE];
   char s2[MAXLINE];

   strcpy(s1, "abcdefg");
   strcpy(s2, "abcdef");
   squeeze(s1, s2);
   assert(strcmp(s1, "g") == 0);

   strcpy(s1, "abcdefg");
   strcpy(s2, "abcdefg");
   squeeze(s1, s2);
   assert(strcmp(s1, "") == 0);

   strcpy(s1, "hello");
   strcpy(s2, "world");
   squeeze(s1, s2);
   assert(strcmp(s1, "he") == 0);

   printf("All tests passed.\n");
   return 0;
}
