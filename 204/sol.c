/*
 * Exercise 1-24. Write a program to check a C program for rudimentary syntax
 * errors like unbalanced parantheses, brackets, and braces. Don't forget about
 * quotes, both single and double, escape sequences and comments. (This program
 * is hard if you do it in full generality).
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "sol.h"

long htoi(char s[])
{
   int i = strlen(s) - 1;
   int exponent = 0;
   long total = 0;
   while (i >= 0) {
      if (s[i] == '1')
         total += 1 * pow(16, exponent++);
      else if (s[i] == '2')
         total += 2 * pow(16, exponent++);
      else if (s[i] == '3')
         total += 3 * pow(16, exponent++);
      else if (s[i] == '4')
         total += 4 * pow(16, exponent++);
      else if (s[i] == '5')
         total += 5 * pow(16, exponent++);
      else if (s[i] == '6')
         total += 6 * pow(16, exponent++);
      else if (s[i] == '7')
         total += 7 * pow(16, exponent++);
      else if (s[i] == '8')
         total += 8 * pow(16, exponent++);
      else if (s[i] == '9')
         total += 9 * pow(16, exponent++);
      else if (tolower(s[i]) == 'a')
         total += 10 * pow(16, exponent++);
      else if (tolower(s[i]) == 'b')
         total += 11 * pow(16, exponent++);
      else if (tolower(s[i]) == 'c')
         total += 12 * pow(16, exponent++);
      else if (tolower(s[i]) == 'd')
         total += 13 * pow(16, exponent++);
      else if (tolower(s[i]) == 'e')
         total += 14 * pow(16, exponent++);
      else if (tolower(s[i]) == 'f')
         total += 15 * pow(16, exponent++);
      i--;
   }
   return total; 
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
