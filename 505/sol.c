/*
 * Exercise 5-5. Write versions of the library functions strncpy, strncat, and
 * strncmp, which operate on at most the first n characters of their argument
 * stirngs. For example, strncpy(s,t,n) copies at most n characters of to to s.
 * Full descriptions are in Appendix B.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "sol.h"

void strncpy2(char *s, char *t, int n)
{
   while (n > 0 && *t != '\0') {
      *s++ = *t++;
      n--;
   }
   *s = '\0';
}

void strncat2(char *s, char *t, int n)
{
   while (*s++);
   *s--;
   while (n > 0 && *t != '\0') {
      *s++ = *t++;
      n--;
   }
   *s = '\0';
}

int strncmp2(char *s, char *t, int n)
{
   for ( ; *s == *t; s++, t++) {
      if (*s == '\0' || n <= 1) {
         return 0;
      }
      n--;
   }
   return *s - *t;
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
