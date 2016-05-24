/* PEARSON, Ryan
 *  ID: 103965059
 *  Lab Exercise #lab8_q
 *  Date: March 19, 2013
 *  Purpose: create 1 dimensional array, initialize, randomize, print and search thru
 *  Addition: add bubble sort function and Binary search to show elements that have number
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define MIN 1

int GetNumber(int a, int b);
/*
 Function: retreive a number from the user and validate within acceptable range
 Input: 2 integers, the MAX and MIN
 Output: valid integer
 */
int GetNumber(int a, int b)
{
    int value = 0;
    
    do
    {
        printf("Please provide an integer between 1 and %d: ", b);
        scanf("%d", &value);
        
        (value < a || value > b) ? puts("You have entered an invalid entry!") : printf("");
        
    }while(value < a || value > b);
    
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
void BubbleSort( int array[MAX/2],const int size1, const int *ord);
/*
 Function: Sort array in designated order
 Input: one array, the size and integer order
 Output: nothing
 */
void BubbleSort( int array[MAX/2],const int size1, const int *ord)
{
    int hold = 0;                   // holder variable
    if (*ord == 1)
    {
        for (int pass = 0; pass < size1; pass++)
        {
            hold = 0;       // re-initialize holder variable to check swap
            for(int x = 0; x < size1 - 1; x++)
            {
                if (array[x] > array[x + 1])
                {
                    hold = array[x];
                    array[x] = array[x + 1];
                    array[x + 1] = hold;
                }
            }
            // kick out of loop if no swap
            if (hold == 0)
                return;
        }
    }
    
    else
    {
        for (int pass = 0; pass < size1; pass++)
        {
            hold = 0;       // re-initialize holder variable to check swap
            for(int x = 0; x < size1 - 1; x++)
            {
                if (array[x] < array[x + 1])
                {
                    hold = array[x];
                    array[x] = array[x + 1];
                    array[x + 1] = hold;
                }
            }
            // kick out if does not sort
            if (hold == 0)
                return;
        }
    }
    return;
}

int BinarySearch(const int array[MAX/2], int max, int key);
/*
 Function: perform binary search for key
 Input: one array, the size, key and min and max (4 integers)
 Output: key location(integer)
 */
int BinarySearch(const int array[MAX/2], int max, int key)
{
    int mid = 0;                    // declare mid for search
    int min = MIN - 1;              // set minimum
    
    // check for increment sort
    if(array[0] < array[max - 1])
    {
        // perform Binary search, if found, search for the 1st instance in array that this took place
        // else return -1
        do
        {
            mid = (min + max)/2;

            if (key == array[mid])
            {
                while(array[mid] == array[mid - 1])
                {
                    if (array[mid] == array[0])
                        return 0;
                    mid--;
                }
                return mid;
            }
            
            // change the max/min value of the search feature by element number
            if (key < array[mid])
                max = mid - 1;
            else
                min = mid + 1;
            
        }while (min <= max);
        return -1;
    }
    
    // loop if array has been sorted by decrement
    else
    {
        // perform Binary search, if found, search for the 1st instance in array that this took place
        // else return -1
        do
        {
            mid = (min + max)/2;
            
            if (key == array[mid])
            {
                while(array[mid] == array[mid - 1])
                {
                    if (array[mid] == array[0])
                        return 0;
                    mid--;
                }
                return mid;
            }
            
            // change the max/min value of the search feature by element number
            if (key > array[mid])
                max = mid - 1;
            else
                min = mid + 1;
        }while (min <= max);
        
        return -1;
    }
}
int
main(void)
{
    srand(time(NULL));
    int size = MAX/2;
    int found[size];
    int A[size];
    int key = 0;
    int counter = 0;
    char yesno, dummy;              // variables for loop continuation
    int order = 0;                  // designation of ascending or descending
    int *oPtr;
    oPtr = &order;
    
    //initialize 1/2 array to zero
    InitArray(A, size, 0);
    
    //initialize 1/2 array to number
    InitArray(A, size, GetNumber(MIN, MAX));
    
    //print 1/2 array
    PrintArray(A, size);

    // randomize array
    PopulateArray(A, size);
    
    // print array
    PrintArray(A, size);
    
    // ask user for ascending or descending order
    printf("Please enter 1 for ascending order or\n"
           "2 for descending order for the Bubblesort function: ");
    scanf("%d", &order);
    
    //bubblesort the array in designated order
    BubbleSort(A, size, oPtr);
    
    // print array
    PrintArray(A, size);
    
    // binary search for key reuse getnumber function
    order = BinarySearch(A, size, GetNumber(MIN, MAX/2));
    
    if (order != -1)
        printf("The key's first occurence is found at element %d\n", order);
    else
        printf("No key found.\n");
    /* search array until user does not wish to repeat
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
     */
    return 0;
}
