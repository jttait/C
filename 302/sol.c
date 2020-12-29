/*
 * Exercise 3-1. Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside). Write a version with only
 * one test inside the loop and measure the difference in runtime.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "sol.h"

void escape(char s[], char t[])
{
   char u[MAXLINE];
   int i = 0;
   int j = 0;

   while (s[i] != '\0') {
      switch(s[i]) {
         case '\t':
            u[j++] = '\\';
            u[j++] = 't';
            break;
         case '\n':
            u[j++] = '\\';
            u[j++] = 'n';
            break;
         default:
            u[j++] = s[i];
            break;
      }
      i++;
   }  
   copy(t, u);
}

void deescape(char t[], char s[])
{
   char u[MAXLINE];
   int i = 0;
   int j = 0;

   while (t[i] != '\0') {
      switch(t[i]) {
         case '\\':
            switch(t[i+1]) {
               case 't':
                  u[j++] = '\t';
                  i += 2;
                  break;
               case 'n':
                  u[j++] = '\n';
                  i += 2;
                  break;
               default:
                  u[j++] = t[i++];
                  break;
            }
         default:
            u[j++] = t[i++];
            break;
      }
   }
   copy(s, u);
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
