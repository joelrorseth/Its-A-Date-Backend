//
//  Title: Assign5
//  Date: August 3, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: Read values into a Queue structure and Radix sort
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//struct define
typedef struct queueNode{
    int number;
    struct queueNode *nextNode;
}QueueNode;

// function prototypes
QueueNode *enqueue(QueueNode * head, int value);
void radixSort (QueueNode* listing[], int size);

int
main (void)
{
    QueueNode * headNode = NULL;      // pointer to structure
    
    QueueNode *list[11];    // create array of structures
    
    int value = 0;          // variable for counting and storing user input
    int nodecount, decimalhold, countdown;
    
    for(value = 0; value < 11; value++)
        list[value] = NULL;
    
    // get number of nodes for queue
    printf("How many values do you wish to enter into the dynamic list: ");
    scanf("%d", &nodecount);
    
    // prompt for size of structure element number
    printf("How many places will your values hold(must be less than 8): ");
    scanf("%d", &decimalhold);
    countdown = decimalhold;
    decimalhold = pow(10, decimalhold);         // use to validate entries
    
    // prompt for valid input and fill struct pointer array in location 10 to start
    while (nodecount != 0) {
        do{
            printf("Please enter your values to create dynamic list: ");
            scanf("%d", &value);
            if (value / decimalhold > 0){
                printf("Invalid Input!\n");
            }
        }while(value / decimalhold > 0);
        
        headNode = enqueue(headNode, value);        // fill structure via headNode pointer
        nodecount--;
    }
    
    list[10] = headNode;                            // assign headnode to array of structure pointers
    radixSort(list, countdown);                     // put queue into sort with loop countdown

    // print results
    if ((headNode = list[10]) != NULL){
        printf("\nYour result: ");
        while (headNode != NULL) {
            printf("%d\t", headNode->number);
            headNode = headNode->nextNode;
        }
    }
    puts("");
    return 0;
}

/* Function: add a value to the tail of the queue
   Input: the head of the queue and the user value to become tail node
   Output: pointer to the head of the Queue */
QueueNode *enqueue(QueueNode * head, int value)
{
    QueueNode * newQueue, *current = NULL;
    newQueue = (QueueNode*) malloc(sizeof( QueueNode));
    newQueue->number = value;
    newQueue->nextNode = NULL;
    
    if (head == NULL)
        return newQueue;
    // find the end of the queue and attach the user entry
    else{
        current = head;
        while (current->nextNode != NULL)
            current = current->nextNode;
        current->nextNode = newQueue;
        return head;
    }
}

/* Function: Perform radix sort on Queue structure
 Input: array of pointers to structure type Queuenode, one integer size
 Output: nothing */
void radixSort(QueueNode * listing[], int size)
{
    QueueNode *previous, *current, *temp;
    int y = 10;             // variable for doing math on struct element
    int x = 1;              // counter variable
    int upsize = 1;         // variable for doing math on struct element
    int moveposition = 0;   // variable for designating position in struct pointer array
    
    for (; size > 0; size--) {
        // cycle over listing struct pointer array and assign to each struct location
        while (listing[10] != NULL) {
            current = listing[10];
            listing[10] = current->nextNode;
            current->nextNode = NULL;
            moveposition = current->number % y;
            moveposition /= upsize;
            if (listing[moveposition] != NULL)
            {
                temp = malloc (sizeof(QueueNode));
                previous = NULL;
                temp = listing[moveposition];
                while (temp->nextNode != NULL && temp->number != current->number) {
                    previous = temp;
                    temp = temp->nextNode;
                }
                temp->nextNode = current;
            }
            else
                listing[moveposition] = current;
     
        }
        // reset all in new order to location 10, found more efficient to just point head back
        // to last node of element 10 of array rather than one at a time.
        for (x = 0; x < 10; x++) {
            while (listing[x] != NULL) {
                current = listing[x];
                listing[x] = NULL;
                if (listing[10] != NULL)
                {
                    temp = listing[10];
                    while (temp->nextNode != NULL)
                        temp = temp->nextNode;
                    temp->nextNode = current;
                }
                else
                    listing[10] = current;
            }
        }
        // increase y and upsize variable for tracking 1's, 10's, etc
        y *= 10;
        upsize *= 10;
        
        // print pass if not the last pass
        if(size != 1){
            current = listing[10];
            if (current != NULL){
                printf("\nPASS*******- ");
                while (current != NULL) {
                    printf("%d\t", current->number);
                    current = current->nextNode;
                }
                printf("\n");
            }
            
        }
    }
}