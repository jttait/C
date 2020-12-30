/*
 * Exercise 3-2. Write a function escape(s,t) that converts characters like
 * newline and tab into visible escape sequences like \n and \t as it copies the
 * string t to s. Use a switch. Write a function for the other directoin as
 * well, converting escape sequences into the real characters.
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
   while (s[*i] != '\0' && s[(*i)++] == '-') {
      if (islower(s[*i])) {
         end = s[(*i)++];
      }
      else {
         end = 'z';
      }
   }
   return end;
}

char findEndUpper(char s[], int* i)
{
   char end = 'Z';
   while (s[*i] != '\0' && s[(*i)++] == '-') {
      if (isupper(s[*i])) {
         end = s[(*i)++];
      }
      else {
         end = 'Z';
      }
   }
   return end;
}

char findEndDigits(char s[], int* i)
{
   char end = '9';
   while (s[*i] != '\0' && s[(*i)++] == '-') {
      if (isdigit(s[*i])) {
         end = s[(*i)++];
      }
      else {
         end = '9';
      }
   }
   return end;
}

int writeRange(char s[], int j, int start, int end)
{
   char c;
   for (c = start; c <= end; c++) {
      s[j++] = c;
   }
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
