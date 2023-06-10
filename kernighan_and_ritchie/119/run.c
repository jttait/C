#include <stdio.h>
#include "sol.h"

int main()
{
   int len;
   char line[MAXLINE];

   while ((len = getline2(line, MAXLINE)) > 0) {
      reverse(line);
      printf("%s\n", line);
   }
   return 0;
}
