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

   strcpy(t, "hello, world");
   strncpy2(s, t, 2);
   assert(strcmp(s, "he") == 0);

   strcpy(t, "hello, world");
   strncpy2(s, t, 4);
   assert(strcmp(s, "hell") == 0);

   strcpy(t, "hello, world");
   strncpy2(s, t, 99);
   assert(strcmp(s, "hello, world") == 0);

   strcpy(s, "hello, ");
   strcpy(t, "world");
   strncat2(s, t, 2);
   assert(strcmp(s, "hello, wo") == 0);

   strcpy(s, "hello, ");
   strcpy(t, "world");
   strncat2(s, t, 10);
   assert(strcmp(s, "hello, world") == 0);

   strcpy(s, "hello");
   strcpy(t, "hello");
   assert(strncmp2(s, t, 2) == 0);

   strcpy(s, "hello");
   strcpy(t, "helot");
   assert(strncmp2(s, t, 3) == 0);

   strcpy(s, "hello");
   strcpy(t, "helot");
   assert(strncmp2(s, t, 10) == -3);

   strcpy(s, "hello");
   strcpy(t, "helot");
   assert(strncmp2(s, t, 5) == -3);

   printf("All tests passed.\n");

   return 0;
}
