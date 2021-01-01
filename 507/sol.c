/*
 * Exercise 5-6. Rewrite readlines to store lines in an array supplied by main,
 * rather than calling alloc to maintain storage. How much faster is the
 * program?
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "sol.h"

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
   if (allocbuf + ALLOCSIZE - allocp >= n) {
      allocp += n;
      return allocp - n;
   }
   else {
      return 0;
   }
}

void afree(char *p)
{
   if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
      allocp = p;
}

int getline2(char s[], int lim)
{
   int c, i; for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; i++) {
      *(s+i) = c;
   }
   if (c == '\n') {
      *(s+i) = c;
      ++i;
   }
   *(s+i) = '\0';
   return i;
}

int readlines(char *lineptr[], int maxlines)
{
   int len, nlines;
   char *p, line[MAXLEN];

   nlines = 0;
   while ((len = getline2(line, MAXLEN)) > 0)
      if (nlines >= maxlines || (p = alloc(len)) == NULL)
         return -1;
      else {
         line[len-1] = '\0';
         strcpy(p, line);
         lineptr[nlines++] = p;
      }
   return nlines;
}

int readlines507(char *lineptr[], int maxlines, char lines[MAXLINES][MAXLEN])
{
   int len, nlines;

   nlines = 0;
   while ((len = getline2(lines[nlines], MAXLEN)) > 0)
      if (nlines >= maxlines)
         return -1;
      else {
         lines[nlines][len-1] = '\0';
         lineptr[nlines] = lines[nlines];
         nlines++;
      }
   return nlines;
}


void writelines(char *lineptr[], int nlines)
{
   while (nlines-- > 0)
      printf("%s\n", *lineptr++);
}

void qsort2(char *v[], int left, int right)
{
   int i, last;
   if (left >= right)
      return;
   swap2(v, left, (left+right)/2);
   last = left;
   for (i = left+1; i <= right; i++)
      if (strcmp(v[i], v[left]) < 0)
         swap2(v, ++last, i);
   swap2(v, left, last);
   qsort2(v, left, last-1);
   qsort2(v, last+1, right);
}

void swap2(char *v[], int i, int j)
{
   char *temp;
   temp = v[i];
   v[i] = v[j];
   v[j] = temp;
}
