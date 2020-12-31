#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "sol.h"

#define TOLERANCE 0.001

int main()
{
   char s[MAXLINE];
   int i;

   i = 0;
   strcpy(s, "hello");
   reverse(s, &i);
   assert(strcmp(s, "olleh") == 0);

   i = 0;
   strcpy(s, "hello world");
   reverse(s, &i);
   assert(strcmp(s, "dlrow olleh") == 0);

   printf("All tests passed.\n");

   return 0;
}
