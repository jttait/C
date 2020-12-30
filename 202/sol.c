/*
 * Exercise 2-2. Write a loop equivalent to the for loop above without using &&
 * or ||.
 */

#include <stdio.h>

#define MAXLINE 1000

int main()
{
   int i;
   char c;
   char s[MAXLINE];
   int lim = MAXLINE;

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
