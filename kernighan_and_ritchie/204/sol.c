/*
 * Exercise 2-4. Write an alternate version of squeeze(s1, s2) that deletes each
 * character in s1 that matches any character in s2.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "sol.h"

void squeeze(char s1[], char s2[])
{
   int i = 0;
   int j = 0;
   int k = 0;
   bool s2contains;
   char s3[MAXLINE];
   while (s1[i] != '\0') {
      j = 0;
      s2contains = false;
      while (s2[j] != '\0') {
         if (s2[j++] == s1[i]) {
            s2contains = true;
         }
      }
      if (!s2contains) {
         s3[k++] = s1[i];
      }
      i++;
   }
   s3[k] = '\0';
   copy(s1, s3); 
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
