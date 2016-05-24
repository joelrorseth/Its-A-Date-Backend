//
//  bioct.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int x = 0;                  // number for binary
    int holder = 0;             // for math
    int value = 100000000;      // for division
    
    
    printf("Please provide a 12 digit binary number: ");
    scanf("%d", &x);
    
    while (x != 0)
    {
        holder = x / value;
        printf("%d\t", holder);
        printf("%o\n", holder);
        x %= value;
        value /= 1000;
        
    }
    puts("");
    return 0;
}