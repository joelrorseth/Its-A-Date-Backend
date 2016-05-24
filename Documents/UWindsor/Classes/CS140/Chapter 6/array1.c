//
//  array1.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 10

int
main(void)
{
    
    
    int n[ SIZE ];    // array with 10 integers
    size_t i;
    int total = 0;
    
    for( i = 0; i < 10; i++)
    {
        n[ i ] = 2 + 2 * i;
        total += n[i];
    }
    
    printf("%s%13s\n", "Element", "Value");
    
    for (i = 0; i < 10; i++) {
        printf("%7d%13d\n", i, n[i]);
    }

    printf("The total value of your array is %d\n", total);
    
    return 0;
}