/*
 * Exercise 2-4. Write the function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into its equivalent
 * integer value. The allowable digits are 0 through 9, a through f, and A
 * through F.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "sol.h"

long htoi(char s[])
{
   int i;
   int exponent = 0;
   long total = 0;
   for (i = strlen(s) - 1; i >= 0; i--) {
      if (i == 1 && (s[i] == 'x' || s[i] == 'X'))
         ;
      else if (i == 0 && s[i] == '0')
         ;
      else if (s[i] >= '0' && s[i] <= '9')
         total += (s[i] - '0') * pow(16, exponent++);
      else if (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f')
         total += (tolower(s[i]) - 'a' + 10) * pow(16, exponent++);
      else
         return -1;
   }
   return total; 
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
