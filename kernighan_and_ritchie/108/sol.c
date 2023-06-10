/*
 * Exercise 1-8. Write a program to count blanks, tabs, and newlines.
 */

#include <stdio.h>

int main()
{
   int num_blank, num_tab, num_newline;
   char c;

   num_blank = num_tab = num_newline = 0;
   
   while ((c = getchar()) != EOF) {
      if (c == ' ')
         ++num_blank;
      else if (c == '\t')
         ++num_tab;
      else if (c == '\n')
         ++num_newline;
   }
   printf("\nNumber of blanks: %d\n", num_blank);
   printf("Number of tabs: %d\n", num_tab);
   printf("Number of newlines: %d\n", num_newline);
   return 0;
}
