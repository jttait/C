#include <stdbool.h>
#include <stdio.h>
#include "sol.h"

int main()
{
   char s1[MAXLINE];
   char s2[MAXLINE];
   int location;

   printf("\nEnter first string: ");
   getline2(s1, MAXLINE);
   printf("Enter second string: ");
   getline2(s2, MAXLINE);

   location = any(s1, s2);

   printf("Index of first match: %d\n", location);

   return 0;
}
