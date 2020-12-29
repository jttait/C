/*
 * Exercise 2-7. Write a function invert (x,p,n) that returns x with the n bits
 * that begin at position p inverted (i.e., 1 changed to 0 and vice versa),
 * leaving the others unchanged.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "sol.h"

unsigned invert(unsigned x, int p, int n)
{
   unsigned mask;
   unsigned inverted;

   inverted = x >> p; /* shift the n bits to the rightmost */
   inverted = ~inverted; /* invert all bits */
   mask = mask & 0; /* set all bits to 0 */
   mask = mask | ~(~0 << n); /* set rightmost n bits to n */
   inverted = inverted & mask; /* zero all other bits except the n bits */
   inverted = inverted << p; /* shift the n bits back to their position */

   mask = ~(mask & 0); /* set all bits to 1 */
   mask = mask & (~0 << n); /* set rightmost n bits to 0 */
   mask = mask << p; /* shift left, fills rightmost (p-1) bits with 0 */
   mask = mask | ~(~0 << p); /* fill 1s back into rightmost (p-1) bits */
   x = x & mask; /* set n bits at position p to 0 */

   return x | inverted;
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
