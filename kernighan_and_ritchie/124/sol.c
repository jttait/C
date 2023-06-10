/*
 * Exercise 1-24. Write a program to check a C program for rudimentary syntax
 * errors like unbalanced parantheses, brackets, and braces. Don't forget about
 * quotes, both single and double, escape sequences and comments. (This program
 * is hard if you do it in full generality).
 */

#include <stdbool.h>
#include <stdio.h>
#include "sol.h"

int updateBrackets(char s[], char opening, char closing, int counter)
{
   int i = 0;
   while (s[i] != '\0') {
      if (s[i] == opening)
         counter++;
      else if (s[i] == closing)
         counter--;
      i++;
   }
   return counter;
}

int updateQuotes(char s[], char quote, int counter)
{
   int i = 0;
   while (s[i] != '\0') {
      if (s[i] == quote)
         counter++;
      i++;
   }
   return counter;
}

int updateComments(char s[], int counter)
{
   int i = 0;
   while (s[i] != '\0') {
      if (s[i] == '*' && s[i-1] == '/')
         counter++;
      else if (s[i] == '/' && s[i-1] == '*')
         counter--;
      i++;
   }
   return counter;
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
