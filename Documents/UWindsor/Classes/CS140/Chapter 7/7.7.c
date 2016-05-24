//
//  7.7.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <math.h>

void cubeByReference(int *numPtr);

void cubeByReference(int *numPtr)
{
    *numPtr = pow(*numPtr, 3);
    
    return;
}

int
main(void)
{
    int number = 5;
    
    printf("The original value of number is %d\n", number);
    
    cubeByReference( &number);
    
    printf("The new value of number is %d\n", number);
    
    
    return 0;
}