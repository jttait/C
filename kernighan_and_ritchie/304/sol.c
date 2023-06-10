/*
 * Exercise 3-4. In a two's complement number representation, our version of
 * itoa does not handle the largest negative number, that is, the value of n
 * equal to -(2^(wordsize-1)). Explain why not. Modify it to print the value
 * correctly, regardless of the machine on which it runs.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "sol.h"

void reverse(char s[]);

void itoa(int n, char s[])
{
   int i;
   bool negative = false;
   if (n < 0)
      negative = true;

   i = 0;
   do {
      s[i++] = abs(n % 10) + '0';
   } while (abs(n /= 10) > 0);

   if (negative)
      s[i++] = '-';

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
