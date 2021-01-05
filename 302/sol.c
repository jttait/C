/*
 * Exercise 3-2. Write a function escape(s,t) that converts characters like
 * newline and tab into visible escape sequences like \n and \t as it copies the
 * string t to s. Use a switch. Write a function for the other direction as
 * well, converting escape sequences into the real characters.
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
   u[j] = '\0';
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
            break;
         default:
            u[j++] = t[i++];
            break;
      }
   }
   u[j] = '\0';
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
