#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "sol.h"

int main()
{
   int len;
   char line[MAXLINE];

   while ((len = getline2(line, MAXLINE)) > 0) {
      printf("%s\n", line);
   }

   return 0;
}
