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
   int i;

   strcpy(s, "1234");
   i = atoi2(s);
   assert(i == 1234);

   itoa2(1234, s);
   assert(strcmp(s, "1234") == 0);

   strcpy(s, "hello");
   reverse2(s);
   assert(strcmp(s, "olleh") == 0);

   strcpy(s, "hello world");
   strcpy(t, "world");
   i = strindex2(s, t);
   assert(i == 6);

   strcpy(s, "hello world");
   strcpy(t, "rabbit");
   i = strindex2(s, t);
   assert(i == -1);

   printf("All tests passed.\n");

   return 0;
}
