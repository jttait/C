int getline2(char s[], int lim);
void copy(char to[], char from[]);
void rpn(void);

#define MAXLINE 1000
#define MAXLINES 100

enum function {
   NUMBER=0,
   SIN=1000,
   EXP=1001,
   POW=1002,
   PEEK=1003,
   DUPLICATE=1004,
   CLEAR=1005,
   SWAP=1006
};


