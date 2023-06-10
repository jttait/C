#include <stdio.h>
#include "sol.h"

int main()
{
   int i, len;
   int num_output_lines = 0;
   char line[MAXLINE];
   char lines[MAXLINES][MAXLINE];

   while ((len = getline2(line, MAXLINE)) > 0) {
      int newlen = remove_trailing_whitespace_and_newline(line);
      if (newlen > 0) {
         copy(lines[num_output_lines], line);
         num_output_lines++;
      }
   }
   if (num_output_lines > 0) {
      printf("Output lines: \n");
      for (i = 0; i < num_output_lines; i++) {
         printf("%s\n", lines[i]);
      }
   }
   return 0;
}


