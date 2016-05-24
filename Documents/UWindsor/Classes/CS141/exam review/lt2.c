//
//  lt2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node * lfnd;
    int n;
    struct node * rtnd;
}Node;

typedef Node * ndpt;

ndpt addtree (ndpt, int);
void post(ndpt);

int
main(void)
{
    int val;
    
    FILE *fptr;
    ndpt start;
    if ((fptr = fopen("numbers.txt", "r")) == NULL) {
        puts("No file.");
    }
    
    else{
        while (!feof(fptr)) {
            fscanf(fptr, "%d", &val);
            start = addtree( start, val);
        }
    }
    
    post(start);
    return 0;
}


ndpt addtree (ndpt start, int d)
{
    
    if (start == NULL) {
        start = malloc (sizeof(Node));
        start->n = d;
        start->lfnd = NULL;
        start->rtnd = NULL;
    }
    
    else if (start->n < d)
        start->lfnd = addtree(start->lfnd, d);
    else
        start->rtnd = addtree(start->rtnd, d);
    
    return start;
}

void post(ndpt p)
{
    if (p != NULL) {
        printf("%d\n", p->n);
        post(p->lfnd);
        //printf("%d\n", p->n);
        post(p->rtnd);
        //printf("%d\n", p->n);
    }
    
}