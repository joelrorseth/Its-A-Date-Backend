 //
//  fiber3.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

unsigned long long int fiber(unsigned x);

int
main(void)
{
    unsigned int x = 0;
    
    printf("Please enter the n'th digit of the fibernacci sequence you would like to receive: ");
    scanf("%u", &x);
    
    printf("Fibernacci value: %lld\n", fiber(x));
    
    return 0;
}

unsigned long long int
fiber(unsigned x)
{
    
    if ( x == 0 || x == 1)
        return x;
    else
        return fiber(x -1) + fiber (x -2);
    
}