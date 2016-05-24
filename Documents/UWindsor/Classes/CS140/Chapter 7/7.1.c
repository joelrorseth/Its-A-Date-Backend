//
//  7.1.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int a;
    int *aPtr;
    
    a = 7;
    aPtr = &a;
    
    printf("\n\nThe address of a is %p"
           "\nThe value of aPtr is %p", &a, aPtr);
    
    printf("\n\nThe value fo a is %d"
           "\nThe value of *aPtr is %d", a, *aPtr);
    
    printf("\n\nShowing that * and & are complements of "
           "each other\n&*aPtr = %p"
           "\n*&aPtr = %p\n", &*aPtr, *&aPtr);
    
    return 0;
}