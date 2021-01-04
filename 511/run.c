#include <stdio.h>
#include "sol.h"

int main(int argc, char **argv)
{
   int len;
   char line[MAXLINE];

   while ((len = getline2(line, MAXLINE)) > 0) {
      entab(line);
      printf("%s", line);
   }
   return 0;
}
