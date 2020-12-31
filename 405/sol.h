int getline2(char s[], int lim);
void copy(char to[], char from[]);
void rpn(void);

#define MAXLINE 1000
#define MAXLINES 100

enum function {
   NUMBER=0,
   PEEK=1,
   SWAP=2,
   DUPLICATE=3,
   CLEAR=4,
   SIN=5,
   EXP=6,
   POW=7
};


