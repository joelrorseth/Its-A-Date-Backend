//
//  7.21.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int number = 1;
    int *numberp = &number;
    
    float *realptr;
    float *integerptr;
    
    integerptr = realptr;
    
    int * x, y;
    x = &y;
    
    char s[] = {"this is a character array"};
    
    int count;
    for (count = 0; s[count] != '\0'; count++) {
        printf("%c ", s[count]);
    }
    puts("");
    
    //printf("%d\n", *numberp);
    
    short *numPtr, result = 2;
    numPtr = &result;
    short *genericPtr = numPtr;
    result = *genericPtr + 7;
    
    printf("%d\n", result);
    
    
    return 0;
}