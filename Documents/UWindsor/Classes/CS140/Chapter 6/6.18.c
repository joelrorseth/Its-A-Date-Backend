//
//  6.18.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
// reverses the order of the array and prints it out.

#include <stdio.h>
#define SIZE 10

void somefunc(const int b[], size_t startsub, size_t size);

int
main(void)
{
    int a[SIZE] = {8, 3, 1, 2, 6, 0, 9, 7, 4, 5};
    
    puts("Answer is: ");
    
    somefunc(a, 0, SIZE);
    puts("");
    
    
    return 0;
}

void somefunc(const int b[], size_t startsub, size_t size)
{
    if(startsub < size)
    {
        somefunc(b, startsub + 1, size);
        printf("%d   ", b[startsub]);
        
    }
    
    
}