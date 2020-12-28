/*
 * Exercise 1-12. Write a program that prints its input one word per line.
 */

#include <stdio.h>
#include <stdbool.h>

int main()
{
   char c;
   bool inword = false;

   while ((c = getchar()) != EOF) {
      if (c == ' ' && inword) {
         putchar('\n');
         inword = false;
      }
      else if (c != ' ') {
         putchar(c);
         inword = true;
      }
   }
   return 0;
}
