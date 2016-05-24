//
//  mainorig.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h> 
#include <string.h> 
#include "getline.c" 
#include "readLines.c" 
#include "writeLines.c" 
#include "sorting.c" 
#include "allocateStorage.c" 
#define MAXLINES 5000 

char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void bubbleSort(char *lineptr[], int nlines, int x);

int main(void)
{
    int nlines; /*number of lines read */
    int choice;
    
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
        bubbleSort(lineptr, nlines , 1);
        writelines(lineptr, nlines);
        fclose (stdin);
        freopen("/dev/tty", "r", stdin);
        //return 0;
    }else {
        printf("error: Input too big to sort \n");
        return 0;
    }
    
    do  {
        //DisplayMenuLab3();
        do {
            printf("Please enter your selection: ");
            scanf("%d", &choice);
            //if (scanf == 1);
        }while (choice < 0 || choice > 6);
        if (choice != 6){}
        //(*processFunction[choice])(lineptr, nlines, choice);
    }while (choice != 6);
} // end main
