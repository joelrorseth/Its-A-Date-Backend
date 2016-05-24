//
//  Title: Assign5redo
//  Date: August 8, 2013
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

typedef QueueNode * QueueNodePtr;

// function prototypes
void enqueue(QueueNode *list, QueueNode *head, QueueNode *tail, int value);
int isEmpty(QueueNode * check);
void radixSort (QueueNode* listing[], int size);

int
main (void)
{
    QueueNode * headNode = NULL, * tailNode;      // pointer to structure
    int num;
    QueueNode *list[11];    // create array of structures
    QueueNodePtr Head[11]= {NULL};
    QueueNodePtr Tail[11]= {NULL};

    do{
        printf("Please enter value: ");
        while (!scanf("%d", &num)){
            fclose(stdin);
            freopen("/dev/tty", "r", stdin);
            printf("Invalid input!\n");
        }
        enqueue(list[10], Head, Tail, num);
    }while (!EOF);
    
    list[10] = Head[10];
    
    while (list[10]->nextNode != NULL) {
        printf("%d\n", list[10]->number);
    }
    return 0;
}

void enqueue(QueueNode * list, QueueNodePtr *head, QueueNodePtr *tail, int value)
{
    QueueNode * temp;
    temp = malloc(sizeof(QueueNode));
    temp->number = value;
    temp->nextNode = NULL;
    if (*head == NULL) {
        *head = *tail = temp;
    }
    else {
        while((*head)->nextNode != NULL)
            *head = (*head)->nextNode;
        *tail = temp;
        (*head)->nextNode = *tail;
    }
    return;
}