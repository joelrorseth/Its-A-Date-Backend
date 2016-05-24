//
//  Title: lab4-2.c
//  Date: July 30, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: read in a text file and sort the occurance of each word
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXLENGTH 1000
#define SIZE 500

// struct definition
typedef struct {
    char *word;
    int freq;
}Values;

// function prototypes
void breakline (char *, int, Values * Values1, int *);
void addword (char *begin, char * end, Values * Values1, int *);

int
main(void)
{
    char line[MAXLENGTH];       // holder char array for reading input

    Values list[SIZE];          // create list array of structs
    int listsize = 0;
    
    FILE * fptr;                // pointer to file, & read in input
    if ((fptr = fopen("Words", "r")) == NULL){
        printf("No file.\n");
        return -1;
    }
    
    // reads the text into one string array, changes newlines to '\0''s
    while (fgets(line, MAXLENGTH, fptr)){
        breakline(line, strlen(line), list, &listsize);
    }
    // print results
    printf("Word\t\tFrequency\n");
    for (int x = 0; x < listsize; x++)
        strlen(list[x].word) < 3 ? printf("%s-word\t\t%d-freq\n", list[x].word, list[x].freq):
                                    printf("%s-word\t%d-freq\n", list[x].word, list[x].freq);

    fclose(fptr);

    return 0;
}
/* Function: use state's to go in and out of words and separate them
 Input: char pointer, integer length, pointer to array of structs, integer pointer
 Output: Nothing, pass by pointer */
void breakline ( char * lineb, int length, Values * Values1, int *listsize)
{
    int state = 1;                      // catch whitespace at beginning of line
    char *endword = lineb;              // pointer to start of word
    char *startword = lineb;            // pointer to start of word
    
    // loop over string going in and out of states to separate words
    while (endword != lineb + length){
        switch (state) {
            case 0:
                if (!isalpha(*endword)){
                    addword(startword, endword, Values1, listsize);
                    state = 1;
                }
                break;
            case 1:
                if (isalpha(*endword)){
                    startword = endword;
                    state = 0;
                }
        }
        endword++;
    }
}


/*Function: take word in and assign to new array element or just increase frequency
 Input: char pointer X 2, pointer to struct element array, pointer to integer
 Output: nothing- everything done by pointer */
void addword (char *begin, char * end, Values * Values1, int *listsize)
{
    int n = 0, x = 0;
    int wordsize = end - begin;              // get size of word
    char *buffer;
    buffer = malloc(sizeof(wordsize+1));      // allocate space for word in buffer variable

    strncpy(buffer, begin, wordsize);       // copy the word into buffer
    //printf("%c\n", buffer[wordsize]);
    
    // search structs for matching element and increment if match, if not create structure and set frequency
    for (; x < *listsize; x++) {
        if ((strcmp (buffer, Values1[x].word) == 0)) {
            Values1[x].freq++;
            return;
        }
    }
    // allocate size of array and copy buffer into element and increment variables
    Values1[*listsize].word = malloc (sizeof(wordsize));
    strncpy(Values1[*listsize].word, buffer, wordsize);
    Values1[*listsize].freq = 1;
    n++;
    *listsize+=1;
}