/*
 * Exercise 5-12. Extend entab and detab to accept shorthand
 *      entab -m +n
 * to mean tab stops every n columns, starting at column m. Choose convenient
 * (for the user) default behaviour.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "sol.h"

#define MAXLINE 1000

int spaces_to_next_tabstop(int column, int tabs[])
{
   int nextTabstop;
   int i = 0;
   while (column > tabs[i]) {
      i++;
   }
   nextTabstop = tabs[i];
   if (nextTabstop - column == 0) {
      return tabs[i+1] - column;
   }
   else {
      return nextTabstop - column;
   }
}

void entab(char s[], int tabs[])
{
   char entabbed[MAXLINE];
   int j = 0;
   int i = 0;
   int k;

   while (s[i] != '\0') {
      if (s[i] == ' ') {
         int dist_to_tabstop = spaces_to_next_tabstop(i, tabs);
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

void detab(char s[], int tabs[])
{
   char detabbed[MAXLINE];
   int stringcounter = 0;
   int columncounter = 0;

   while (s[stringcounter] != '\0') {
      if (s[stringcounter] == '\t') {
         int spaces = spaces_to_next_tabstop(columncounter, tabs);
         while (spaces > 0) {
            detabbed[columncounter++] = ' ';
            spaces--;
         }
         stringcounter++;
      }
      else {
         detabbed[columncounter++] = s[stringcounter++];
      }
   }
   detabbed[columncounter] = '\0';
   copy(s, detabbed);
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
