#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sol.h"

int main(int argc, char **argv)
{
   int len, m, n, i;
   int tabs[100];
   char line[MAXLINE];
   char *program, *marg, *narg;

   program = argv[1];
   marg = argv[2];
   narg = argv[3];

   m = atoi(marg);
   n = atoi(narg);

   tabs[0] = m;
   for (i = 1; i < 100; i++) {
      m += n;
      tabs[i] = m;
   }

   if (strcmp(program, "entab") == 0) {
      while ((len = getline2(line, MAXLINE)) > 0) {
         entab(line, tabs);
         printf("%s", line);
      }
   }
   else if (strcmp(program, "detab") == 0) {
      while ((len = getline2(line, MAXLINE)) > 0) {
         entab(line, tabs);
         printf("%s", line);
      }
   }
   else {
      printf("Usage ./run entab -m +n or ./run detab -m +n\n");
   }

   return 0;
}
