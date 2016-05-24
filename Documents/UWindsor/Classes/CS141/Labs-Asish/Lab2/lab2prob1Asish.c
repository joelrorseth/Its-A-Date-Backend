// Solution to Problem 1, Lab2
// Written by AM, 21 July, 2013
// Revised 13 August, 2013

// Problem: Consider the problem of reading in 20 integers lying in the range 0 to 99, both
//inclusive, and printing them, after removing duplicates.

// If space is not at a premium one solution is to maintain a binary array BA of size 100, ini-
// tialized to 0's to begin with. If a number x is read in then BA[x] is set to 1 the rst time it is
//read in and remains unchanged on any subsequent reading of x. Once all numbers have been
// read in, the numbers x for which BA[x] = 1 is output. Implement this scheme in C.

//If space is at a premium, we declare and maintain an integer array of size 20. As each number
//x is read in, we search for it in the existing list, maintained in increasing order, using binary
//search. If it already exists in this list, then we do nothing; else, we insert it into this list, by
//shifting the numbers that are greater than x, if any, to the right, as in insertion sort.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZE 20

// function prototypes
void insertNumber(int list[], int, int *);
int binSearch(int list[], int, int);


int main(void)
{
    int numberList[SIZE]; // number list
    int i; // loop variable
    int number; // read a number
    int listEnd = -1; // initial value, we have an empty list
    
    // read input from a file
    FILE *fPtr;
    fPtr = fopen("inputList", "w");
    
    
    srand(time(NULL));
    for (i = 0; i < SIZE; i++){
        number = rand() % 100;   // this generates random +ve integers less than 100
        fprintf(fPtr, "%d\n", number);
    }
    fclose(fPtr);
    
    // get input
    fPtr = fopen("inputList", "r");
    for (i = 0; i < SIZE ; i++){
        fscanf(fPtr, "%d", &number);
        insertNumber(numberList, number, &listEnd);
    }
    
    // OR simple input style: read in 20 integers from terminal
    /*
     printf("\nInput 20 integers in the range 0 to 99: \n\n");
     
     for (i = 0; i < 20; i++){
     if(scanf("%d", &number) != 1){
     printf("%d-th entry in input list is not an integer; aborting program \n", i);
     // return -1;
     exit(1);
     } // end if
     else insertNumber(numberList, number, &listEnd);
     //printf("The current end of list is %d \n:", listEnd);
     } // end of for
     */
    
    printf("\nThe list without duplicates is:\n\n");
    for (i = 0; i <= listEnd; i++)
        printf("%d  ", numberList[i]);
    printf("\n");
} // end of main

// definition of insertNumber
void insertNumber(int list[], int n, int *p)
{
    int found = 0;
    
    found = binSearch(list, n,*p); // search the list for n
    if (!found) {  // insert n in list
        int j = *p;
        while (j > -1 && list[j] > n){  // the correctness of this part is crucial
            list[j+1] = list[j]; // move list[j] left
            j = j-1;}
        list[j+1] = n;  // if we bottom out we will increment j to 0 before we insert n
        *p = *p+1;
    }
    return;
} // end of insertNumber

// definition of binary search
int binSearch(int list[], int n, int listEnd)
{
    int low, high, mid;
    
    low = 0;
    high = listEnd;
    
    while(low <= high){
        mid = (low+high)/2;
        if(n < list[mid])
            high = mid -1;
        else if (n >list[mid])
            low = mid +1;
        else /*found match */
            return 1;
    }
    return 0; /* no match */
} // end of binSearch