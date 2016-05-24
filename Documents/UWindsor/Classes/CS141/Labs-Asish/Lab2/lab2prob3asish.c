// Insertion sort with swap
// written by Asish Mukhopadhyay

//Implement in C a revised version of the insertion sort algorithm by using the
//swap routine that I discussed to in class to place two numbers in order by passing pointers
//to them. Allow the user to choose whether the numbers are to be sorted in ascending or
//descending order by providing a menu (read the bubble sort program in your text book in
//Section 7.6).

// Here I am providing an option through the argument list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 20

void insertionSortAscending(int list[], int);
void insertionSortDescending(int list[], int);
void swap(int *, int *);

//int main(void)
int main(int argc, char *argv[])
{
    int numberList[SIZE];
    int i; //loop variable
    int number; // to store number read
    
    
    srand(time(NULL));
    for (i = 0; i < SIZE; i++){
        number = rand() % 100;   // this generates random +ve integers less than 100
        //fprintf(fPtr, "%d\n", number);
        numberList[i] = number;
        
    }
    
    
    // or read in list in a simple way from the terminal
    // we need to guard against non-integer input being provided here
    // scanf returns an integer value, which is the number of items that
    // successfully matched the format specification
    /*
     printf("Input 20 integers: \n");
     for (i = 0; i < SIZE; i++)
     if(scanf("%d", &list[i]) != 1) {
     printf("list item %d is not an integer; aborting program\n", i);
     return -1;
     }
     */
    
    // providing order option through argument list: a for ascending, d for descending
    if (strcmp(argv[1], "-a") == 0)
        insertionSortAscending(numberList, SIZE); // works correctly
    //else insertionSortDescending(list, SIZE);
    if (strcmp(argv[1], "-d") == 0)
        insertionSortDescending(numberList, SIZE); // works correctly
    
    return 0;
}

// sorts in ascending order
void insertionSortAscending(int list[], int lim)
{
    int i = 1; //left-right loop
    int j; //right-left loop
    int temp;
    
    while (i <= lim-1){
        temp = list[i];
        j = i;
        //while(j > 0 && list[j-1] > temp){
        while(j > 0 && list[j-1] > list[j]){
            //list[j] = list[j-1];
            swap(&list[j], &list[j-1]);
            j = j-1;
        }// inner while
        //list[j] = temp;
        ++i;
    }// inner while
    for (i = 0; i < lim; i++)
        printf("%d  ", list[i]);
    printf("\n");
}

//sorts in dscending order
void insertionSortDescending(int list[], int lim)
{
    int i = 1; //left-right loop
    int j; //right-left loop
    int temp;
    
    while (i <= lim-1){
        temp = list[i];
        j = i;
        //while(j > 0 && list[j-1] > temp){
        while(j > 0 && list[j-1] < list[j]){
            //list[j] = list[j-1];
            swap(&list[j], &list[j-1]);
            j = j-1;
        }// inner while
        //list[j] = temp;
        ++i;
    }// inner while
    for (i = 0; i < lim; i++)
        printf("%d  ", list[i]);
    printf("\n");
}
// swaps two numbers, when pointers to these are supplied
void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}


