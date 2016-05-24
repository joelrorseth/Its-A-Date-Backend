//
//  Title: main for Lab3
//  Date: July 22, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: Read lines and provide ability to do functions- templete supplied
//

#include <stdio.h> 
#define LEN 1000
#define OPTIONS 7
#define MAXLINES 100
#include <string.h> 
#include <time.h>
#include "readLines.c"
#include "getLine.c"
#include "writeLines.c" 
#include "sorting.c" 
#include "allocateStorage.c" 
#include "printarray.h"
#include "DisplayMenu.h"
#include "Maximum.h"
#include "Minimum.h"
#include "Query.h"

// function prototypes
char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void bubbleSort(char *lineptr[], int nlines, int x);
void query (char *lineptr[], int nlines, int x);

int main(void)
{
    double start = 0, end = 0;
    start = clock();
    int nlines;                         /*number of lines read */
    int choice;                     // users selection variable
    void (*processFunction[6])(char *lineptr[], int nlines, int x)= { bubbleSort, maximum, minimum, maxlength, minlength, query };          // array of functions
    
    // prompt user for array values
    printf("Enter values for functions:(empty line return or EOF to complete.)\n");
    
    // scan items into array
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
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
        DisplayMenuLab3();                  // display menu for choices and prompt user for selection
        do {
            choice = 7;                                     // sets to stay in this loop if scanf invalid
                printf("Please enter your selection: ");        
            if (!scanf("%d", &choice)){
                    fclose (stdin);
                    freopen("/dev/tty", "r", stdin);
                    printf("You did not enter valid input.Please try again!\n");
                }
        } while (choice < 0 || choice > 6);
        if (choice != 6)
            (*processFunction[choice])(lineptr, nlines, choice);        // enter choice into function
    }while (choice != 6);
    
    end = clock();          // run time check
    printf ("Run time is %f seconds\n", (end - start)/ (double) CLOCKS_PER_SEC);
    return 0;
}