//
//  sumav.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int x = 0;
    int sum = 0;                // total value of items
    int counter = 0;            // counter to keep track of number of loops
    
    while( x != 9999)
    {
        printf("Integer please: ");
        scanf("%d", &x);
        sum += x;
        counter++;
    }
    
    printf("Your sum of numbers was: %d...\n", sum - 9999);
    printf("You entered %d integers...\n", counter -1);
    printf("So your average is: %d\n", (sum - 9999) / (counter -1));
    
    return 0;
}