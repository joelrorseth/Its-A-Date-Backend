//
//  sumeven.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int sum = 0;            // declare sum variable
    
    
    // perform loop to count even numbers
    for (int x = 0; x <= 30; x += 2)
    {
        sum += x;
    }
    
    // display results
    printf("Sum of even numbers to 30 is: %d\n", sum);
    
    return 0;
}