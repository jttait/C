/*
 * Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and delete entirely blank lines.
 */

#include <stdio.h>
#include "sol.h"

int remove_trailing_whitespace_and_newline(char s[])
{
   int len = 0;
   while (s[len] != '\0') {
      len++;
   }

   len--; /*skip sentinel */
   while (len > 0 && (s[len] == '\t' || s[len] == ' ' || s[len] == '\n')) {
      s[len--] = '\0';
   }
   if (s[len] == '\t' || s[len] == ' ' || s[len] == '\n')
      return 0;
   else 
      return ++len;
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
