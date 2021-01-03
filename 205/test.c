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
   assert(any(s1, s2) == 0);

   strcpy(s1, "abcdefg");
   strcpy(s2, "hijklmn");
   assert(any(s1, s2) == -1);

   strcpy(s1, "abcabc");
   strcpy(s2, "cot");
   assert(any(s1, s2) == 2);

   printf("All tests passed.\n");

   return 0;
}
