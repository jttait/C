/*
 * Exercise 2-5. Write the function any(s1,s2), which returns the first location
 * in the stirng s1 where any character from the string s2 occurs or -1 if s1
 * contains no characters from s2. (The standard library function strpbrk does
 * the same job but returns a pointer to the location).
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "sol.h"

int any(char s1[], char s2[])
{
   int i, j;

   for (i = 0; s1[i] != '\0'; i++) {
      for (j = 0; s2[j] != '\0'; j++) {
         if (s2[j] == s1[i]) {
            return i;
         }
      }
   }
   return -1;
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
