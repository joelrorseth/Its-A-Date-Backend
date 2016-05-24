//
//  7.10.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    long int value1 = 200000;
    long int value2;
    
    long *lPtr;
    lPtr = &value1;
    value2 = *lPtr;
    
    printf("%ld\n", *lPtr);
    printf("%ld\n", value2);
    
    printf("%p\n", &value1);
    printf("%p\n", lPtr);
    
    
    
    return 0;
}