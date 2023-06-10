#include <stdio.h>
#include "sol.h"

int main()
{
   int len;
   char line[MAXLINE];

   while ((len = getline2(line, MAXLINE)) > 0) {
      replace_tabs(line);
      printf("%s", line);
   }
   return 0;
}
