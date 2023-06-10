/*
 * Exercise 5-6. Rewrite appropriate programs from earlier chapters and
 * exercises with pointers instead of array indexing. Good possibilities include
 * getline (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3,
 * and 4), reverse (Chapter 3), and strindex and getop (Chapter 4).
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "sol.h"

int getline2(char s[], int lim)
{
   int c, i; for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; i++) {
      *(s+i) = c;
   }
   if (c == '\n') {
      *(s+i) = c;
      ++i;
   }
   *(s+i) = '\0';
   return i;
}

int atoi2(char *s)
{
   int n = 0;
   while (*s >= '0' && *s <= '9') {
      n = 10 * n + (*s - '0');
      s++;
   }

   return n;
}

void itoa2(int n, char *s)
{
   int sign;
   char *sbegin = s;
   if ((sign = n) < 0)
      n = -n;
   do {
      *s++ = n % 10 + '0';
   } while ((n /= 10) > 0);
   if (sign < 0)
      *s++ = '-';
   *s = '\0';
   reverse2(sbegin);
}

void reverse2(char *s)
{
   char c;
   char *i = s;
   char *j = s + strlen(s) - 1;

   while (i < j) {
      c = *i;
      *i = *j;
      *j = c;
      i++;
      j--;
   }
}

int strindex2(char *s, char *t)
{
   char *i = s;
   char *k = t;
   char *j;

   while (*i != '\0') {
      j = i;
      k = t;
      while (*j != '\0' && *j == *k) {
         j++;
         k++;
      }
      if (k != t && *k == '\0') {
         return i - s;
      }
      i++;
   }
   return -1;
}
