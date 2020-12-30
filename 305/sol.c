/*
 * Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into
 * a base b character representation in the string s. In particular,
 * itob(n,s,16) formats n as a hexadecimal integer in s.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "sol.h"

void reverse(char s[]);

void itob(int n, char s[], int b)
{
   int i;

   i = 0;
   do {
      int digit = n % b;
      if (digit < 9)
         s[i++] = digit + '0';
      else {
         s[i++] = digit - 10 + 'a';
      }
   } while ((n /= b) > 0);

   s[i] = '\0';
   reverse(s);
}

/* reverse is from 119 */
void reverse(char s[])
{
   char reversed[MAXLINE];
   int len = 0;
   int j = 0;

   while (s[len] != '\0')
      len++;
   len--; /* skip sentinel */
   if (s[len] == '\n')
      len--;
   while (len >= 0) {
      reversed[j++] = s[len--];
   }
   reversed[j] = '\0';
   copy(s, reversed);
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
