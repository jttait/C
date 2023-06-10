int getline2(char s[], int lim);
void copy(char to[], char from[]);
void rpn(void);

#define MAXLINE 1000
#define MAXLINES 100

enum function {
   NUMBER=1000,
   PEEK=1001,
   SWAP=1002,
   DUPLICATE=1003,
   CLEAR=1004,
   SIN=1005,
   EXP=1006,
   POW=1007,
   VARIABLE_SAVED=1008,
   VARIABLE_PUSHED=1009,
   LAST_PRINTED=1010
};


