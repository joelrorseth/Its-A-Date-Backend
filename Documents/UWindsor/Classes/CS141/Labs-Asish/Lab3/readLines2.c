//
//  Title: readLines2
//  Date: July 22, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: readline function provided for lab- template provided
//

#include <stdio.h>
#define MAXLEN 1000
int getlines(char *, int); // prototypes
/* readlines: read input lines */
int readlines(char *lineptr[], char *linestor, int maxlines)
{
    int len, nlines;
    char *p;                // pointer to current position in array
    p = linestor;          // initialize to start of linestor array
    char *m, line[MAXLEN];
    nlines = 0;
    while((len = getlines(line, MAXLEN)) > 0)//{
        if (nlines >= maxlines)
            return -1;
        // relocate the space check from allocate storage to this function
        else if (linestor + ALLOCSIZE - p >= len){
            p += len;
            m = (p - len);
            line[len-1] = '\0';                /*delete newline symbol*/
            strcpy(m, line);
            lineptr[nlines++] = m;
        }
        else
            return -1; /* not enough room */
    //}
    return nlines;
}