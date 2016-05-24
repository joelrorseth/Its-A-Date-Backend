//
//  iloop.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    
    unsigned int x = 2;
    
    while ( x != 1)
    {
        printf("%u\n", x);
        x *= 2;
    }
    return 0;
}
// once you go above 4 billion the loop generates a value of zero because. You go beyond the computers memory.