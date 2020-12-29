#include <stdbool.h>
#include <stdio.h>
#include "sol.h"

int main()
{
   char line[MAXLINE];
   int len;

   printf("\nEnter a hexadecimal string: ");
   while ((len = getline2(line, MAXLINE)) > 0) {
      printf("Number in decimal: %ld", htoi(line));
      printf("\nEnter a hexadecimal string: ");
   }

   return 0;
}
