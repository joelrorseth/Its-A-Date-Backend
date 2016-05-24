// Assignment 5 solution
// by Asish Mukhopadhyay
// started 03 August, 2013
// This program works for inputs that are at most d digits long


// libraries
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// node in a queue

struct queueNode {
    int key;
    struct queueNode *next;
};


// function prototypes
int dequeue( struct queueNode **, struct queueNode **);
void enqueue(struct queueNode **, struct queueNode **, int);
int isEmpty( struct queueNode *);

int main(void)
{
    // declarations
    int number, tempNumber;
    int numberOfDigits;
    int i,j; // loop control variables
    int queueNumber;
    struct queueNode *head[11]; // head pointers of 11 queues
    struct queueNode *tail[11]; // tail pointers of 11 queues
    struct queueNode *qPntr;    // a travelling pointer
    
    
    // initialize the head and tail pointers
    for (i= 0; i <11; i++){ head[i] = NULL; tail[i] = NULL;}
    
    // open file
    FILE *fPtr;
    fPtr = fopen("numberList", "r");
    
    // get input
    printf("Input the maximum number of digits in the numbers:");
    scanf("%d", &numberOfDigits);
    
    fscanf(fPtr, "%d", &number);
    while (!feof(fPtr)) {
        queueNumber = number % 10; // get queue number for the number read
        enqueue(&head[queueNumber], &tail[queueNumber], number);
        fscanf(fPtr, "%d", &number);
    } // end while
    
    // the first round of dequeing and enqueing
    printf("Out of the initial queueing loop\n");
    for (i = 0; i <10; i++){
        if (head[i] != NULL) {
            while(!isEmpty(head[i])){
                printf("Now here\n");
                number = dequeue(&head[i], &tail[i]);
                enqueue(&head[10], &tail[10], number);
            } // end while
        } // end if
    } // end of first for
    
    // print contnts of the 11-th queue after the first round
    qPntr = head[10];
    while (qPntr!= NULL){
        printf("%d\n", qPntr -> key);
        qPntr = qPntr->next;
    } // end while`
    
    // enqueue-deque for numberOfDigits- 1 rounds more
    for (i = 1; i < numberOfDigits; i++) {
        // fill up the 10 queues
        if (head[10] != NULL) {
            while (!isEmpty(head[10])){
                number = dequeue(&head[10], &tail[10]);
                queueNumber = (number%((int)pow(10, i+1)))/((int)pow(10,i)); // some problem with this for 999
                // the result of / is being rounded up
                if (queueNumber == 10) queueNumber--; // this is to handle the case when 9.99 is rounded to 10
                enqueue(&head[queueNumber], &tail[queueNumber], number);
            } // end while
        } // end if
        
        //empty the 10 queues and put them in queue 11
        for (j = 0; j <10; j++){
            if (head[j] != NULL) {
                while (!isEmpty(head[j])){
                    number = dequeue(&head[j], &tail[j]);
                    enqueue(&head[10], &tail[10], number);
                } // end while
            } // end if
        } // end inner for
    } // end outer for
    
    //qPntr = head[11];
    printf("Now here, printing the final queue\n");
    qPntr = head[10];
    while (qPntr!= NULL){
        printf("%d\n", qPntr -> key);
        qPntr = qPntr->next;
    } // end while
} // end main


// dequeue routine
int dequeue( struct queueNode **head, struct queueNode **tail)
{
    int value; // node value
    struct queueNode *tempPtr; // temporary node pointer
    
    value = ( *head )->key;
    tempPtr = *head;
    *head = (*head)->next;
    
    // if queue is empty
    if ( *head == NULL ) {
        *tail= NULL;
    } // end if
    
    free( tempPtr );
    return value;
} // end function dequeue


// enqueue routine
void enqueue(struct queueNode **head, struct queueNode **tail, int number)
{
    struct queueNode *newPtr; // pointer to new node
    
    newPtr = (struct queueNode *)malloc( sizeof( struct queueNode ) );
    
    if ( newPtr != NULL ) { // is space available
        newPtr->key = number;
        newPtr->next = NULL;
        
        // if empty, insert node at head
        if ( isEmpty( *head ) )
            *head = newPtr;
        else
            (*tail)->next = newPtr;
        
        *tail = newPtr;
    } // end if
    else
        printf( "%number not inserted. No memory available.\n", number);
} // end function enqueue


// isEmpty routine
int isEmpty( struct queueNode *head )
{
    return head == NULL;
} //end isEmpty





