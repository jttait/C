/*
 * Exercise 1-20. Write a program detab that replaces tabs in the input with the
 * proper number of blanks to space the next tab stop. Assume a fixed set of tab
 * stops, say every n columns. Should n be a variable or a symbolic parameter?
 */

#include <stdio.h>
#include "sol.h"

#define N 8

int getline2(char line[], int maxline);
void copy(char to[], char from[]);
void replace_tabs(char s[]);
int spaces_to_next_tabstop(int column, int tab_spacing);

int spaces_to_next_tabstop(int column, int tab_spacing)
{
   if ((column % tab_spacing) == 0) {
      return tab_spacing;
   }
   return tab_spacing - (column % tab_spacing);
}

void replace_tabs(char s[])
{
   char detabbed[MAXLINE];
   int stringcounter = 0;
   int columncounter = 0;

   while (s[stringcounter] != '\0') {
      if (s[stringcounter] == '\t') {
         int spaces = spaces_to_next_tabstop(columncounter, N);
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
