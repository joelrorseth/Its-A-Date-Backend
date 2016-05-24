//
//  sumseq.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int x = 1;                  // declare holder variable
    int z = 0;                  // number to add up
    int sum = 0;                // declare sum
    
    printf("Please enter how many integers you plan to add up: ");
    scanf("%d", &x);
    
    for (int y = 1; y <= x; y++)
    {
        if (y == 1)
        {
            printf("First integer: ");
            scanf("%d", &z);
        }
        else if (y == x)
        {
            printf("And the last one: ");
            scanf("%d", &z);
        }
        else
        {
            printf("Next integer: ");
            scanf("%d", &z);
        }
        
        // set initial value
        if (y == 1)
            sum = z;
        
        // keep track of the lowest
        if (z < sum)
            sum = z;
    }
    
    printf("Your lowest value is: %d.\n", sum);
    
    
    return 0;
}