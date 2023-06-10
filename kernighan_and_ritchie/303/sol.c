/*
 * Exercise 3-3. Write a function expand(s1, s2) that expands shorthand
 * notations like a-z in the string s1 into the equivalent complete list
 * abc...xyz in s2. Allow for letters of either case and digits, and be prepared
 * to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or
 * trailing - is taken literally.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "sol.h"

int writeRange(char s[], int j, int start, int end);
char findEndLower(char s[], int* i);
char findEndUpper(char s[], int* i);
char findEndDigits(char s[], int* i);

void expand(char s1[], char s2[])
{
   char start;
   char end;
   int i = 0;
   int j = 0;
   while (s1[i] != '\0') {
      if(islower(s1[i])) {
         start = s1[i++]; 
         end = findEndLower(s1, &i);
         j = writeRange(s2, j, start, end);
      }
      else if (isupper(s1[i])) {
         start = s1[i++];
         end = findEndUpper(s1, &i);
         j = writeRange(s2, j, start, end);
      }
      else if (isdigit(s1[i])) {
         start = s1[i++];
         end = findEndDigits(s1, &i);
         j = writeRange(s2, j, start, end);
      }
      else if (s1[i] == '-') {
         if (islower(s1[i+1])) {
            start = 'a';
            end = findEndLower(s1, &i);
            j = writeRange(s2, j, start, end);
         }
         else if (isupper(s1[i+1])) {
            start = 'A';
            end = findEndUpper(s1, &i);
            j = writeRange(s2, j, start, end);
         }
         else if (isdigit(s1[i+1])) {
            start = '0';
            end = findEndDigits(s1, &i);
            j = writeRange(s2, j, start, end);
         }
      }
   }
   s2[j] = '\0';
}

char findEndLower(char s[], int* i)
{
   char end = 'z';
   while (s[*i] != '\0' && s[(*i)++] == '-')
      if (islower(s[*i]))
         end = s[(*i)++];
      else
         end = 'z';
   return end;
}

char findEndUpper(char s[], int* i)
{
   char end = 'Z';
   while (s[*i] != '\0' && s[(*i)++] == '-')
      if (isupper(s[*i]))
         end = s[(*i)++];
      else
         end = 'Z';
   return end;
}

char findEndDigits(char s[], int* i)
{
   char end = '9';
   while (s[*i] != '\0' && s[(*i)++] == '-')
      if (isdigit(s[*i]))
         end = s[(*i)++];
      else
         end = '9';
   return end;
}

int writeRange(char s[], int j, int start, int end)
{
   char c;
   for (c = start; c <= end; c++)
      s[j++] = c;
   return j;
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
