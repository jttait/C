/*
 * Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
 * bits that begin at position p set to the rightmost n bits of y, leaving the
 * other bits unchanged.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "sol.h"

unsigned setbits(unsigned x, int p, int n, int y)
{
   unsigned xmask, ymask;

   ymask = ymask & 0; /* set all bits to 0 */
   ymask = ymask | ~(~0 << n); /* set rightmost n bits with 1 */
   y = y & ymask; /* set all but rightmost n bits to 0 */

   xmask = ~(xmask & 0); /* set all bits to 1 */
   xmask = xmask & (~0 << n); /* set rightmost n bits to 0 */
   xmask = xmask << p; /* shift left, fills rightmost (p-1) bits with 0 */
   xmask = xmask | ~(~0 << p); /* fill 1s back into rightmost (p-1) bits */
   x = x & xmask; /* set n bits at position p to 0 */

   return x | (y << p);
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
