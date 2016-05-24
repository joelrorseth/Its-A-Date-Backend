/* PEARSON, Ryan
 *  ID: 103965059
 *  Lab Exercise #lab7_q
 *  Date: March 12, 2013
 *  Purpose: create 1 dimensional array, initialize, randomize, print and search thru etc
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

int GetNumber(void);
/*
 Function: retreive a number from the user and validate within acceptable range
 Input: Nothing
 Output: valid integer
 */
int GetNumber(void)
{
    int value = 0;
    
    do
    {
        printf("Please provide an integer between 1 and 10: ");
        scanf("%d", &value);
        
        (value < 1 || value > MAX) ? puts("You have entered an invalid entry!") : printf("");
        
    }while(value < 1 || value > MAX);
    
    return value;
    
}

void InitArray( int array[MAX/2], int size1, int value);
/*
 Function: initialize array to variable
 input: one array, the size, and the initialization value
 Output: nothing
 */
void InitArray( int array[MAX/2], int size1, int value)
{
    // initialize array to value
    for(int i  = 0; i < size1; i++)
        array[i] = value;
    return;
}

void PrintArray(const int array[MAX/2], int size1);
/*
 Function: print array
 input: Array and size
 output: nothing
 */
void PrintArray(const int array[MAX/2], int size1)
{
    int i;
    printf("%s", "A=[");
    
    for(i = 0; i < size1 - 1; i++)
        printf("%d,", array[i]);
        
        printf("%d]\n", array[4]);
        
        return;
}

void PopulateArray(int array[MAX/2], int size1);
/*
 Function: randomize array with numbers 1-5
 Input: one array, the size
 Output: nothing
 */
void PopulateArray(int array[MAX/2], int size1)
{
    for(int i = 0; i < size1; i++)
        array[i] = rand() % (MAX/2) + 1;
    
    return;
}

int SearchArray(const int array[MAX/2], int size1, int key);
/*
 Function: linear search array for key provided by user, repeat if necessary
 Input: One array and size
 Output: nothing
 */
int SearchArray(const int array[MAX/2], int size1, int key)
{
    int counter =0;                 // counter for keeping track of occurences
    
    //perform search, add to counter if it occurs
    for( int i = 0; i < size1; i++)
        key == array[i] ? counter++ : 1 ;
    
    return counter;
}


int
main(void)
{
    srand(time(NULL));
    int size = MAX/2;
    int A[size];
    int key = 0;
    int counter = 0;
    char yesno, dummy;              // variables for loop continuation
    
    //initialize 1/2 array to zero
    InitArray(A, size, 0);
    
    //initialize 1/2 array to number
    InitArray(A, size, GetNumber());
    
    //print 1/2 array
    PrintArray(A, size);
    
    // randomize array
    PopulateArray(A, size);
    
    // print array
    PrintArray(A, size);
    
    
    // search array until user does not wish to repeat
    
    do
    {
        
        printf("Please enter a key between 1 and 5: ");
        scanf("%d", &key);
        
        // search array with key
        counter = SearchArray(A, size, key);
        
        //return number of times key occured
        if (counter == 0)
            printf("No occurence found for value %d in the array!\n", key);
        else if (counter == 1)
            printf("%d occurence found for value %d in the array!\n", counter, key);
        else
            printf("%d occurences found for value %d in the array!\n", counter, key);
        // ask for another try
        printf("Do you want to search for more keys? ");
        scanf("%c%c", &dummy, &yesno);
        
        (yesno == 'n' || yesno == 'N')? puts("Goodbye!\n") : 1 ;
        
    }while(yesno == 'y' || yesno == 'Y');
    
    return 0;
}
        


