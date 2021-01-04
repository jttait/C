#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "sol.h"

int main()
{
   char testline[MAXLINE];
   int tabs[100];

   tabs[0] = 8; tabs[1] = 16; tabs[2] = 24;
   assert(spaces_to_next_tabstop(0, tabs) == 8);
   assert(spaces_to_next_tabstop(1, tabs) == 7);
   assert(spaces_to_next_tabstop(2, tabs) == 6);
   assert(spaces_to_next_tabstop(3, tabs) == 5);
   assert(spaces_to_next_tabstop(4, tabs) == 4);
   assert(spaces_to_next_tabstop(5, tabs) == 3);
   assert(spaces_to_next_tabstop(6, tabs) == 2);
   assert(spaces_to_next_tabstop(7, tabs) == 1);
   assert(spaces_to_next_tabstop(8, tabs) == 8);
   assert(spaces_to_next_tabstop(9, tabs) == 7);

   strcpy(testline, "hello world");
   tabs[0] = 8; tabs[1] = 16; tabs[2] = 24; tabs[3] = 32;
   entab(testline, tabs);
   assert(strcmp(testline, "hello world") == 0);

   strcpy(testline, "hello         world");
   tabs[0] = 8; tabs[1] = 16; tabs[2] = 24; tabs[3] = 32;
   entab(testline, tabs);
   assert(strcmp(testline, "hello\t      world") == 0);

   strcpy(testline, "hello         world");
   tabs[0] = 4; tabs[1] = 8; tabs[2] = 12; tabs[3] = 16;
   entab(testline, tabs);
   assert(strcmp(testline, "hello\t\t  world") == 0);
   
   tabs[0] = 8; tabs[1] = 16; tabs[2] = 24; tabs[3] = 32;
   strcpy(testline, "hello\tworld");
   detab(testline, tabs);
   assert(strcmp(testline, "hello   world") == 0);
   
   strcpy(testline, "hello\t\tworld");
   detab(testline, tabs);
   assert(strcmp(testline, "hello           world") == 0);

   tabs[0] = 4; tabs[1] = 8; tabs[2] = 12; tabs[3] = 16;
   strcpy(testline, "hello\t\tworld");
   detab(testline, tabs);
   assert(strcmp(testline, "hello       world") == 0);

   printf("All tests passed.\n");

   return 0;
}
