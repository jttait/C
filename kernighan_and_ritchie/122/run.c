#include <stdio.h>
#include "sol.h"

int main()
{
   int len;
   char line[MAXLINE];

   while ((len = getline2(line, MAXLINE)) > 0) {
      if (len < MAXLENGTH) {
         printf("%s", line);
      }
      else {
         fold_line(line, MAXLENGTH);
         printf("%s", line);
      }
   }

   return 0;
}


