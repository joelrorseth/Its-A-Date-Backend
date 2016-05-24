//
//  Linked3.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node *next;
};

typedef struct node nodes;

struct node* addToList(nodes *, int);

int
main(void)
{
    struct node* start = NULL, *pntr;
    int key, x = 0;
    
    FILE * fptr;
    fptr = fopen ("listinput.dat", "r");
    for (; x < 10; x++) {
        fscanf(fptr, "%d", &key);
        start = addToList(start, key);
    }
    pntr = start;
    while (pntr != NULL) {
        printf("%d\n", pntr->key);
        pntr = pntr->next;
    }
    
    
    return 0;
}

struct node* addToList(nodes * start, int key)
{
    nodes * listPtr, *prev, *current;
    listPtr = (struct node*)malloc(sizeof(struct node));
    listPtr->key = key;
    listPtr->next = NULL;
    // add to empty list
    if (start == NULL){
        return listPtr;
    }
    else{
        prev = NULL;
        current = start;
        while (current != NULL && current->key < listPtr->key) {
            prev = current;
            current = current->next;
        }
        if (prev != NULL)
            prev->next =listPtr;
        else
            start = listPtr;
        listPtr->next = current;
        return start;
    }
    
}