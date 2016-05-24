//
//  linked2.c
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

struct node * addToList(struct node *, int);

int
main(void)
{
    struct node *start = NULL, *pntr;
    int x, key;
    
    FILE * fptr;
    if ((fptr = fopen( "listinput.dat", "r")) == NULL) {
        puts("No file");
    }
    else
        for (x = 0; x < 5; x++) {
            fscanf(fptr, "%d", &key);
            start = addToList(start, key);
        }
    pntr = start;
    while (pntr != NULL) {
        printf("%d\n", pntr->key);
        pntr= pntr->next;
    }
    
    
}

struct node * addToList(struct node *start, int key)
{
    struct node * listptr;
    listptr = (struct node*) malloc(sizeof (struct node));
    listptr->key = key;
    listptr->next = start;
    return listptr;
    
}