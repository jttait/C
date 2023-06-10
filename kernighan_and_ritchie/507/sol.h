#define MAXLINE 1000
#define ALLOCSIZE 10000
#define MAXLEN 1000
#define MAXLINES 5000

int getline2(char s[], int lim);
void swap2(char *v[], int i, int j);
void qsort2(char *v[], int left, int right);
void writelines(char *lineptr[], int nlines);
int readlines(char *lineptr[], int maxlines);
int readlines507(char *lineptr[], int maxlines, char lines[MAXLINES][MAXLEN]);
