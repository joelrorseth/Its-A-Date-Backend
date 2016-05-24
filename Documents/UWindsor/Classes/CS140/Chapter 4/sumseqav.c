//
//  sumseqav.c
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
    int counter = 0;            // use a counter to keep track of how many integers entered
    
    printf("Please enter how many integers you plan to add up: ");
    scanf("%d", &x);
    
    for (int y = 1; y <= x; y++)
    {
        if (y == 1)
        {
            printf("First integer: ");
            scanf("%d", &z);
            counter++;
        }
        else if (y == x)
        {
            printf("And the last one: ");
            scanf("%d", &z);
            counter++;
        }
        else
        {
            printf("Next integer: ");
            scanf("%d", &z);
            counter++;
        }
        
        // total the sum
        sum += z;
        
    }
    
    printf("Your sum is: %d.\n", sum);
    
    // average the sum
    sum /= counter;
    printf("Your average is: %d.\n", sum);
    
    return 0;
}