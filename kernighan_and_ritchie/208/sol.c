/*
 * Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
 * integer x rotated to the right by n bit positions.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "sol.h"

unsigned rightrot(unsigned x, int n)
{
   unsigned mask, rotated;
   mask = mask & 0; /* set all bits to 0 */
   mask = mask | ~(~0 << n); /* set rightmost n bits to 1 */
   rotated = x & mask;
   rotated = rotated << (32 - n);
    
   x = x >> n;

   return x | rotated;
}

int getline2(char s[], int lim)
{
   int c, i;
   for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; i++) {
      s[i] = c;
   }
   if (c == '\n') {
      s[i] = c;
      ++i;
   }
   s[i] = '\0';
   return i;
}

void copy(char to[], char from[])
{
   int i = 0;
   while ((to[i] = from[i]) != '\0') {
      ++i;
   }
}
