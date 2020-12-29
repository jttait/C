#include <stdbool.h>
#include <stdio.h>
#include "sol.h"

int main()
{
   char s1[MAXLINE];
   char s2[MAXLINE];

   printf("\nEnter first string: ");
   getline2(s1, MAXLINE);
   printf("Enter second string: ");
   getline2(s2, MAXLINE);

   squeeze(s1, s2);

   printf("Resulting string: %s\n", s1);

   return 0;
}
