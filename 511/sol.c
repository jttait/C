/*
 * Exercise 1-21. Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops for each detab. When either a tab or a single blank would suffice
 * to reach a tab stop, which should be given preference?
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "sol.h"

#define MAXLINE 1000
#define TABSTOP 8

int spaces_to_next_tabstop(int column, int tab_spacing)
{
   if ((column % tab_spacing) == 0) {
      return tab_spacing;
   }
   return tab_spacing - (column % tab_spacing);
}

void replace_spaces_with_tabs(char s[])
{
   char entabbed[MAXLINE];
   int j = 0;
   int i = 0;
   int k;

   while (s[i] != '\0') {
      if (s[i] == ' ') {
         int dist_to_tabstop = spaces_to_next_tabstop(i, TABSTOP);
         int all_spaces = 1;
         for (k = 0; k < dist_to_tabstop && s[i+k] != '\0'; k++) {
            if (s[i+k] != ' ') {
               all_spaces = 0;
            }
         }
         if (all_spaces == 1) {
            entabbed[j++] = '\t';
            i = i + dist_to_tabstop;
         }
         else {
            entabbed[j++] = s[i];
            i++;
         }
      }
      else {
         entabbed[j++] = s[i];
         i++;
      }
   }
   entabbed[j] = '\0';
   copy(s, entabbed);
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
