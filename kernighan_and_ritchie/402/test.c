#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "sol.h"

#define TOLERANCE 0.001

bool testAtof2(char s[], float result);

int main()
{
   char s[MAXLINE];

   strcpy(s, "123.0");
   assert(testAtof2(s, 123.0));

   strcpy(s, "123.45");
   assert(testAtof2(s, 123.45));

   strcpy(s, "-123");
   assert(testAtof2(s, -123.0));

   strcpy(s, "-123.45");
   assert(testAtof2(s, -123.45));

   strcpy(s, "123.45e6");
   assert(testAtof2(s, 123450000));

   strcpy(s, "123.45e-2");
   assert(testAtof2(s, 1.2345));

   printf("All tests passed.\n");

   return 0;
}

bool testAtof2(char s[], float result)
{
   return fabs(atof2(s) - result) < TOLERANCE;
}
