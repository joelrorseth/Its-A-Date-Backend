// Lab3, Problem 1
// putting all the functions in one source file
// to students: experiment with putting the individual functions in separate source
// files; create a project and compile this project
// written by Asish Mukhopadhyay
// revised 14 August, 2013


//includes and defines
#include <string.h>
#include <stdio.h>
#define MAXLEN 1000
#define MAXLINES 5000
#define ALLOCSIZE 10000 /* size of available space */

//function prototypes
int readlines( char *lineptr[], int );
void bubbleSort( char *lineptr[], int );
void writelines( char *lineptr[], int );
int getline(char s[], int );
void swap( char *lineptr[], int, int );
char *alloc( int );

// external variables
char *lineptr[MAXLINES];
char allocbuf[ALLOCSIZE];
char *allocp = allocbuf;

int main(void)
//int main(argc, char *argv[])
{
    int nlines; /*number of lines read */
    
    //get input from a file by redirection
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
        bubbleSort(lineptr, nlines);
        writelines(lineptr, nlines);
        return 0;
    }else {
        printf("error: Input too big to sort \n");
        return 0;
    }
} // end main

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    int i;
    
    nlines = 0;
    while((len = getline(line,MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            for(i=0; i < len; i++) //test to chexck if line is being correctly read
                printf("%c", line[i]);
            //printf("\n");
            
            line[len-1] = '\0'; /*delete newline symbol*/
            strcpy(p, line); // copy line into buffer
            lineptr[nlines++] = p; // set pointer in array to point to p
        }
    printf("\n");
    return nlines;
}// readline

//getline
int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}// end of getline

//writelines
void writelines(char *lineptr[], int nlines)
{
    int i;
    
    for(i=0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}// end of writelines

// bubblesort
void bubbleSort( char *lineptr[], int size )
{
    
    unsigned int pass; // pass counter
    size_t j; // comparison counter
    
    // loop to control passes
    for ( pass = 0; pass < size - 1; ++pass ) {
        // loop to control comparisons during each pass
        for ( j = 0; j < size - 1; ++j ) {
            if(strcmp(lineptr[j], lineptr[j+1]) > 0)
                swap(lineptr, j, j+1);
        } // end inner for
    } // end outer for
} // end function bubbleSort

//swap
void swap( char *lineptr[], int j, int k)
{
    char *hold = lineptr[j];
    lineptr[j] = lineptr[k];
    lineptr[k] = hold;
} // end function swap

// alloc
char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp -n; /* the old p */
    } else
        return 0; /* not enough space */
} // end of alloc