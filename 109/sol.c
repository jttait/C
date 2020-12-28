/*
 * Exercise 1-9. Write a program to copy its input to its output, replacing each
 * string of one or more blanks with a single blank.
 */

#include <stdio.h>
#include <stdbool.h>

int main()
{
   char c;
   bool blank = false;

   while ((c = getchar()) != EOF) {
      if (c == ' ' && !blank) {
         putchar(c);
         blank = true;
      }
      else if (c != ' ') {
         putchar(c);
         blank = false;
      }
   }
   return 0;
}
