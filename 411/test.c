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

   rpn();

   printf("All tests passed.\n");

   return 0;
}
