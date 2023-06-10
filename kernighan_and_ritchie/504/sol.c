/*
 * Exercise 5-3. Write the function strend(s,t), which returns 1 if the string t
 * occurs at the end of the string s and zero otherwise.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "sol.h"

int strend(char* s, char* t)
{
   char *sbegin = s;
   char *tbegin = t;

   while(*s++);
   while(*t++);

   *s--;
   *t--;

   while (s >= sbegin && t >= tbegin) {
      if (*s != *t) {
         return 0;
      }
      else {
         *s--;
         *t--;
      }
   }
   return 1;
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
