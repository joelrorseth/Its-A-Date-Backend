// Solution to lab4
// Written by Asish Mukhopdhyay over 05-06  August, 2013

// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//defines
#define MAXWORD 100
#define NKEYS 100
#define BUFSIZE 100

// key structure
struct key {
    char* word;
    int count;
};

//prototypes
int getword(char *, int);
int binSearch(char *, struct key keytab[],int);
void insertWord(char *word, struct key list[], int *);
void addToList(char *word, struct key list[], int *);
char *dupStr(char *);

// main function
int main(void)
{
    int n;
    int i; //loop index
    char word[MAXWORD];
    int listend = -1;
    struct key tab[NKEYS];
    
    // initialize array tab[]
    for ( i = 0; i < NKEYS ; i++) {
        tab[i].word = NULL;
        tab[i].count = 0;
    }
    
    // fetch a word and add to list
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            addToList(word, tab, &listend);
    
    // print the frequency list
    printf("frequency      word\n");
    printf("-------------------\n");
    for (i = 0; i <= listend; i++)
        printf("    %-10d %s\n", tab[i].count, tab[i].word);
    return 0;
} // end main

// function adds a word to a list
void addToList(char *word, struct key list[], int *listend)
{
    struct key temp;
    int index;
    int i;
    
    if (*listend == -1){  // special case when empty list
        temp.word = dupStr(word);
        temp.count = 1;
        list[++(*listend)] = temp;
    } // if
    else {
        if((index = binSearch(word, list, *listend)) < 0)
            insertWord(word, list, listend);
        else (list[index].count)++;
    }
    return;
} // end addToList



// get next word or character from input
int getword(char *word, int lim)
{
    //declarations
    int c, getch(void);
    void  ungetch(int);
    char *w = word;
    
    while (isspace(c = getch())) // skip spaces
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    } // end of if
    
    for (  ; --lim > 0; w++)
        if (!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }// end of if
    *w = '\0';
    return word[0];
} // end of getword



char buf[BUFSIZE]; // bufffer for ungetch
int bufp  =  0; // next free position in buf

int getch(void) //get a (possibly pushed back) character
{
    return (bufp >0)  ?  buf[--bufp] :  getchar();
}// end getch

void ungetch(int c) // push character back on inout
{
    if (bufp  >=  BUFSIZE)
        printf("ungetch: too many characters \n");
    else
        buf[bufp++]  =  c;
}// end ungetch

//char *strdup(char *s) makes a duplicate of s
char *dupStr(char *s)
{
    char *p;
    p = (char *) malloc(strlen(s) + 1); /* +1 for ‘\0’ */
    if (p!= NULL)
        strcpy(p,s);
    return p;
}


// search for word in list key[]
int binSearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;
    
    low = 0;
    high = n;
    while(low <= high){
        mid = (low+high)/2;
        cond = strcmp(word, tab[mid].word);
        if(cond < 0)
            high = mid -1;
        else if (cond > 0)
            low = mid +1;
        else
            return mid;
    }  // end while
    return -1; // no match
} // end of binSearch

// inserts a word into the list
void insertWord(char *word, struct key list[], int *p)
{
    struct key temp;
    int j;
    
    temp.word = dupStr(word); // miss this and word will not be printed
    temp.count = 1;
    
    j = *p;
    while (j > -1 && strcmp(list[j].word, word) > 0){  // the correctness of this part is crucial
        list[j+1] = list[j];
        j = j-1;
    } // end while
    list[j+1] = temp;
    *p = *p+1;
    return;
} // end insert word




