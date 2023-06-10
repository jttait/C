#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "sol.h"

int main()
{
   char s1[MAXLINE];
   char s2[MAXLINE];

   strcpy(s1, "a-z");
   expand(s1, s2);
   assert(strcmp(s2, "abcdefghijklmnopqrstuvwxyz") == 0);

   strcpy(s1, "a-b-c");
   expand(s1, s2);
   assert(strcmp(s2, "abc") == 0);

   strcpy(s1, "a-");
   expand(s1, s2);
   assert(strcmp(s2, "abcdefghijklmnopqrstuvwxyz") == 0);

   strcpy(s1, "0-9");
   expand(s1, s2);
   assert(strcmp(s2, "0123456789") == 0);

   strcpy(s1, "0-1-2");
   expand(s1, s2);
   assert(strcmp(s2, "012") == 0);

   strcpy(s1, "0-");
   expand(s1, s2);
   assert(strcmp(s2, "0123456789") == 0);

   strcpy(s1, "A-Z");
   expand(s1, s2);
   assert(strcmp(s2, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0); 

   strcpy(s1, "A-B-C");
   expand(s1, s2);
   assert(strcmp(s2, "ABC") == 0);

   strcpy(s1, "A-");
   expand(s1, s2);
   assert(strcmp(s2, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0); 

   strcpy(s1, "-z");
   expand(s1, s2);
   assert(strcmp(s2, "abcdefghijklmnopqrstuvwxyz") == 0);

   strcpy(s1, "-k");
   expand(s1, s2);
   assert(strcmp(s2, "abcdefghijk") == 0);

   strcpy(s1, "-Z");
   expand(s1, s2);
   assert(strcmp(s2, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0); 

   strcpy(s1, "-K");
   expand(s1, s2);
   assert(strcmp(s2, "ABCDEFGHIJK") == 0); 

   strcpy(s1, "-9");
   expand(s1, s2);
   assert(strcmp(s2, "0123456789") == 0); 

   strcpy(s1, "-5");
   expand(s1, s2);
   assert(strcmp(s2, "012345") == 0); 

   printf("All tests passed.\n");

   return 0;
}
