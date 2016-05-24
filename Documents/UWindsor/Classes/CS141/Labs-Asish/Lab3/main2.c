//
//  Title: main for Lab3- question2
//  Date: July 22, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: Read lines and provide ability to do functions- templete supplied
//

#include <stdio.h> 
#define LEN 1000
#define OPTIONS 7
#define MAXLINES 100
#define ALLOCSIZE 10000 /* size of available space */
#include <string.h>
#include <time.h>
#include "readLines2.c"
#include "getLine.c"
#include "writeLines.c" 
#include "sorting.c" 
#include "printarray.h"
#include "DisplayMenu.h"
#include "Maximum.h"
#include "Minimum.h"
#include "Query.h"

// Function prototypes
char *lineptr[MAXLINES];
int readlines(char *lineptr[], char *linestor, int nlines);
void writelines(char *lineptr[], int nlines);
void bubbleSort(char *lineptr[], int nlines, int x);
void query (char *lineptr[], int nlines, int x);

int main(void)
{
    double start = 0, end = 0;          // run time check
    start = clock();

    int nlines; /*number of lines read */
    int choice = 0;
    char dummy;
    
    char linestor[ALLOCSIZE];           // variable for buffer storage
    
    void (*processFunction[6])(char *lineptr[], int nlines, int x)= { bubbleSort, maximum, minimum, maxlength, minlength, query };          // array of functions
    
    // prompt user for array values
    printf("Enter values for functions:(empty line return or EOF to complete.)\n");
    
    // scan items into array
    if ((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0){
        fclose (stdin);
        freopen("/dev/tty", "r", stdin);
    }
    else {
        printf("error: Input too big to sort \n");
        return 1;
    }

    printf("Array successfully loaded. Please select your option: \n");
    
    // display menu to user and scan for valid choice
    do{
        DisplayMenuLab3();          //Display menu for choices and prompt for selection
        do {
            choice = 7;             // sets to stay in loop if invalid input
            printf("Please enter your selection: ");        
            if(!scanf("%d", &choice)){
                fclose(stdin);
                freopen("/dev/tty", "r", stdin);
                printf("You did not enter valid input. Please try again.\n");
            }
        } while (choice < 0 || choice > 6);
        if (choice != 6)
            (*processFunction[choice])(lineptr, nlines, choice);        // enter choice into function
    }while (choice != 6);

    end = clock();                  // run time check
    printf ("Run time is %f seconds\n", (end - start)/ (double) CLOCKS_PER_SEC);
    return 0;
}
