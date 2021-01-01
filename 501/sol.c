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

int getch(void);
void ungetch(int);

int getint(int *pn)
{
   int c, sign;

   while (isspace(c = getch()))
      ;
   if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
      ungetch(c);
      return 0;
   }

   sign = (c == '-') ? -1 : 1;

   if (c == '+' || c == '-') {
      c = getch();
      if (!isdigit(c)) {
         ungetch(c);
         return 0;
      }
   }
      

   for (*pn = 0; isdigit(c); c = getch())
      *pn = 10 * *pn + (c - '0');
   *pn *= sign;
   if (c != EOF)
      ungetch(c);

   return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
   if (bufp >= BUFSIZE)
      printf("ungetch: too many characters\n");
   else
      buf[bufp++] = c;
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
