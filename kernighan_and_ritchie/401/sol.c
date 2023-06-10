/*
 * Exercise 4-1. Write the function strrindex(s,t), which returns the position
 * of the rightmost occurrence of t in s, or -1 if there is none.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "sol.h"

int strrindex(char s[], char t[])
{
   int i, j, k;
   int result = -1;
   for (i = 0; s[i] != '\0'; i++) {
      for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
         ;
      }
      if (k > 0 && t[k] == '\0') {
         result = i;
      }
   }
   return result;
}

int getline2(char s[], int lim)
{
   int c, i; for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; i++) {
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
