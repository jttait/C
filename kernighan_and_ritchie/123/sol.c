/*
 * Exercise 1-23. Write a program to remove all comments from a C program. Don't
 * forget to handle quoted strings and character constants properly. C comments
 * do not nest.
 */

#include <stdbool.h>
#include <stdio.h>
#include "sol.h"

bool remove_line_comments(char s[], bool incomment)
{
   int i, j;
   char updated[MAXLINE];

   i = j = 0;
   while (s[i] != '\0') {
      if (s[i] == '/' && s[i+1] == '*') {
         incomment = true;
         i++; i++;
      }
      else if (incomment && s[i] == '/' && s[i-1] == '*') {
         incomment = false;
         i++;
      }
      else if (!incomment) {
         updated[j] = s[i];
         i++; j++;
      }
      else {
         i++;
      }
   }
   updated[j] = '\0';
   copy(s, updated);
   return incomment;
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
