/*
 * Exercise 2-1. Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 */

#include <stdio.h>

#define MAXLINE 1000

int main()
{
   int i;
   int lim;
   char c;
   char s[MAXLINE];

   lim = MAXLINE;

   for (i = 0; i < lim-1; ++i) {
      if ((c = getchar()) != '\n') {
         if (c != EOF) {
            s[i] = c;
         }
      }
   }

   printf("%s\n", s);

   return 0;
}
