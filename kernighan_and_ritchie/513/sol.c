/*
 * Exercise 5-13. Write the program tail, which prints the last n lines of its
 * input. By default, n is 10, let us say, but it can be changed by an optional
 * argument, so that
 *      tail -n
 * prints the last n lines. The program should behave rationally no matter how
 * unreasonable the input or the value of n. Write the program so that it makes
 * the best use of available storage; lines should be stored as in the sorting
 * program of Section 5.6, not in a two-dimensional array of fixed size.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "sol.h"

#define ALLOCSIZE 10000
#define MAXLEN 1000
#define MAXLINES 5000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
char *lineptr[MAXLINES];

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
   if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
      allocp = p;
   }
}

int readlines(char *lineptr[], int maxlines)
{
   int len, nlines;
   char *p, line[MAXLEN];
   nlines = 0;
   while ((len = getline2(line, MAXLEN)) > 0) {
      if (nlines >= maxlines || (p = alloc(len)) == NULL) {
         return -1;
      }
      else {
         line[len-1] = '\0';
         strcpy(p, line);
         lineptr[nlines++] = p;
      }
   }
   return nlines;
}

void writelines(char *lineptr[], int nlines)
{
   int i;
   for (i = 0; i < nlines; i++)
      printf("%s\n", lineptr[i]);
}

void tail(char *lineptr[], int n, int nlines)
{
   int i;
   if (n > nlines) {
      writelines(lineptr, nlines);
   }
   else {
      for (i = nlines - n; i < nlines; i++)
         printf("%s\n", lineptr[i]);
   }
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
