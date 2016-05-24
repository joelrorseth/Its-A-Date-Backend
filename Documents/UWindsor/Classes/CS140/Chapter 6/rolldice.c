//
//  rolldice.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define FACE 6

int rolldie(void);
/*
 Function: simulate rolling 1 die
 input: nothing
 output: 1 integer
 */
int rolldie(void)
{
    int a = 0;
    
    return a = rand() % FACE + 1;
}

int
main(void)
{
    int die1, die2, x = 0;
    int sumface[13];
    
    for (int x = 0; x < 13; x++) {
        sumface[x] = 0;
    }
    
    srand(time (NULL));
    for (x = 0; x < 36000; x++)
    {
        die1 = rolldie();
        die2 = rolldie();
        sumface[(die1 + die2)]++;
    }
    
    printf("The sum of your rolled dice by frequency is:\n");
    for (x = 2; x < 13; x++) {
        printf("%d\t%d\n", x, sumface[x]);
    }
    return 0;
}