/*
 * Exercise 4-13. Write a recursive version of the function reverse(s), which
 * reverses a string s in place.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "sol.h"

void reverse(char s[], int* i)
{
   char first = s[*i];

   if (s[*i] != '\0') {
      (*i)++;
      reverse(s, i);
   }
   else {
      *i = 0;
   }

   if (first != '\0') {
      s[*i] = first;
      (*i)++;
   }
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
