/*
 Dragan Lukic
 103600796
 Assignment 5
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define max(a, b) a > b ? a : b // simple max function

struct queueNode{ // structure declarization
    int data;
    struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode; // synonym for struct queueNode
typedef QueueNode *QueueNodePtr; // synonym for QueueNode*

QueueNodePtr headPtr[11] = {NULL}; // initialize headPtr
QueueNodePtr tailPtr[11] = {NULL}; // initialize tailPtr

// variable declaration
int input, i = 0, j, k, l, a, biggest = 0, limit;
FILE *file;
char buf[50];

// prototypes
void PrintQueue(QueueNodePtr currentPtr);
void PrintContents();
int IsEmpty(QueueNodePtr headPtr);
int Dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void Enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int value);

int main()
{
    file = fopen("input.txt", "r"); // sets the file pointer
    fscanf(file, "%d", &input); // scans an initial input
    while(!feof(file)) // continues scanning input and placing them into Enqueue
    {
        biggest = max(input, biggest); // finds the biggest value to trace it to know when the loops can be ended
        // this a part lets us know the value of the digit of concern, so we can place the input number into the correct array
        a = (input % ( ((int) (pow(10, i))) *10)) / ((int) (pow(10, i))); // on second run, say input = 543, ( (543 % 100) / 10 ) = 4
        Enqueue( &headPtr[a], &tailPtr[a], input ); // place the input number into the array[a] where a is the value at that digit of input
        fscanf(file, "%d", &input); // keeps scanning till EOF
    }
    
    sprintf(buf, "%d", biggest);
    limit = strlen(buf); // using strlen we just find the number of digits in our biggest number
    
    for (k = 0; k < limit; k++)
    {
        PrintContents();
        i++;
        for(j = 0; j < 10; j++) // for array[0] to array[9]
            while(!IsEmpty(headPtr[j])) // we now empty all the array conents from 0-9 into 10 in order
            {
                input = Dequeue(&headPtr[j], &tailPtr[j]); // dequeue a value untill that array is empty
                Enqueue(&headPtr[10], &tailPtr[10], input); // stash those values into array[10]
            }
        
        while(!IsEmpty(headPtr[10]) && k != limit - 1) // take from array[10] and stash into array[0] to array[9] base on the next digits (digits 2 to limit)
        {
            input = Dequeue(&headPtr[10], &tailPtr[10]); // dequeue from array[10] into input
            a = (input % ( ((int) (pow(10, i))) *10)) / ((int) (pow(10, i))); // finds the value at the next digit
            Enqueue(&headPtr[a], &tailPtr[a], input); // puts the dequeue value into the correct array
        }
    }
    PrintContents(); // print the contents for array[0] to array[10]
}

void PrintContents()
{
    for (j = 0; j < 11; j++) // for loop
    {
        if (j == 0 && k < limit)
            printf("Pass %d:\n", i+1);
        else if (j == 0)
            printf("After complete sorting, the result is:\n");
        
        if (!IsEmpty(headPtr[j])) // dont go to next array, untill current array is empty
        {
            if (k < limit) // wont print column 10 on very last filter into array[10] for results display
                printf("Column %d: ", j); // prints the number associated to what it was sorted with respect to
            PrintQueue( headPtr[j] ); // prints the values of that array
            printf("\n");
        }
    }
    printf("\n");
}

void Enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int value)
{
    QueueNodePtr newPtr; /* pointer to new node */
    newPtr = malloc( sizeof( QueueNode ) ); // allocates memory for newPtr
    if ( newPtr != NULL ) // as long as memory could be allocated  run this
    {
        newPtr->data = value; // sets the data value of the structure to the input value
        newPtr->nextPtr = NULL; // sets the nextPtr of the structure
        if ( IsEmpty( *headPtr ) ) // sets next headPtr
            *headPtr = newPtr;
        else // sets next tailPtr
            ( *tailPtr )->nextPtr = newPtr;
        *tailPtr = newPtr;
    }
    else // not enought memory
        printf( "%d not inserted. No memory available.\n", value );
}

int Dequeue( QueueNodePtr *headPtr, QueueNodePtr *tailPtr )
{
    int value; // sets the value to be returned from what gets dequeued
    QueueNodePtr tempPtr; // pointer variable declaration
    value = ( *headPtr )->data; // sets value's value
    tempPtr = *headPtr; // sets temp to head
    *headPtr = ( *headPtr )->nextPtr; // sets head's nextPtr to head
    if ( *headPtr == NULL ) // sets headPtrs next was Null, sets tail to Null
        *tailPtr = NULL;
    free( tempPtr ); // frees the tempptr from memory
    return value; // returns the value that has been removed from the linked list
}

int IsEmpty( QueueNodePtr headPtr )
{
    return headPtr == NULL; // returns 1 if NULL (empty) 0 if not NULL (not empty)
}

void PrintQueue( QueueNodePtr currentPtr )
{
    printf( "%d", currentPtr->data ); // prints the value
    currentPtr = currentPtr->nextPtr; // sets ptr to the next ptr value
    while ( currentPtr != NULL ) // keeps printing untill it reaches a point where the next ptr is NULL
    {
        printf( " -> %d", currentPtr->data );
        currentPtr = currentPtr->nextPtr;
    }
    printf( " -> NULL" ); // prettyness
}