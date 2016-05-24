/* PEARSON, Ryan
 *  ID: 103965059
 *  Lab Exercise #lab9_q2.c
 *  Date: March 26, 2013
 *  Purpose: use pointers to swap and triple
 */

#include <stdio.h>

void swap(int *aPtr, int *bPtr);
/*
 Function: swap the integers
 input: 2 pointer variables
 output: nothing*/
void swap(int *aPtr, int *bPtr)
{
    int holder = 0;         // holder variable
    //swap items
    holder = *aPtr;
    *aPtr = *bPtr;
    *bPtr = holder;
}

int triple(int *dPtr);
/*
 Function: triple a value
 input: one pointer variable
 outout: one integer*/

int triple(int *dPtr)
{
    int value = 0;          // tripled value
    *dPtr = *dPtr * 3;
    return value;
}

int
main(void)
{
    int a = 2;
    int b = 4;
    int d = 10;
    
    //call function swap
    swap(&a, &b);
    printf("%d- a, %d- b\n", a, b);
    printf("%d\n", d);
    // call function triple
    triple(&d);
    printf("%d\n", d);
    return 0;
}
