//
//  hanoiit.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main (void)
{
    int n, x;
    printf("\nEnter the no. of Disks: ");
    scanf("%d", &n);
    for (x = 1; x < (1 << n); x++)
        printf("\nMove from Peg %d to Peg %d", (x&x-1)%3+1,((x|x-1)+1)%3+1);
    
    printf("\n");
    return 0;
}