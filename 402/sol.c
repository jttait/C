/*
 * Exercise 4-2. Extend atof to handle scientific notation of the form
 *     123.45e-6
 * where a floating-point number may be followed by e or E and an optionally
 * signed exponent.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "sol.h"

double atof2(char s[])
{
   double val, power, result;
   int i, sign, exp, expSign;
   for (i = 0; isspace(s[i]); i++)
      ;
   sign = (s[i] == '-') ? -1 : 1;
   if (s[i] == '+' || s[i] == '-')
      i++;
   for (val = 0.0; isdigit(s[i]); i++)
      val = 10.0 * val + (s[i] - '0');
   if (s[i] == '.')
      i++;
   for (power = 1.0; isdigit(s[i]); i++) {
      val = 10.0 * val + (s[i] - '0');
      power *= 10.0;
   }
   
   if (s[i] == 'e' || s[i] == 'E')
      i++;
   expSign = (s[i] == '-') ? -1 : 1;
   if (s[i] == '+' || s[i] == '-')
      i++;
   for (exp = 0; isdigit(s[i]); i++) {
      exp = 10 * exp + (s[i] - '0');
   }

   result = sign * val / power;

   if (exp)
      result *= pow(10, expSign * exp);

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
