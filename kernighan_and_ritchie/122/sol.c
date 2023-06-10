/*
 * Exercise 1-22. Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column.
 */

#include <stdio.h>
#include "sol.h"

void fold_line(char s[], int maxlength) {
   char folded_line[MAXLINE];
   int i = 0;
   int j = 0;
   int col = 0;
   while (s[i] != '\0') {
      if (s[i] == ' ' || s[i] == '\t') {
         int k = 1;
         int another_blank = 0;
         while (k+col <= maxlength) {
            if (s[i+k] == ' ' || s[i+k] == '\t' || s[i+k] == '\0') {
               another_blank = 1;
            }
            k++;
         }
         if (another_blank == 1) {
            folded_line[j++] = s[i++];
            col++;
         }
         else {
            folded_line[j++] = '\n';
            i++;
            col = 0;
         }
      }
      else if (col == maxlength) {
         folded_line[j++] = '-';
         folded_line[j++] = '\n';
         folded_line[j++] = s[i++];
         col = 0;
      }
      else {
         folded_line[j++] = s[i++];
         col++;
      }
   }
   folded_line[j] = '\0';
   copy(s, folded_line);
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
