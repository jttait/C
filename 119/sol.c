/*
 * Exercise 1-19. Write a function reverse(s) that reverses the character
 * stirng s. Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>
#include "sol.h"

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
