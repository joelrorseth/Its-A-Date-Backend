//
//  8.7.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    const char *string = "-1234567abc";
    
    char* remainderptr;
    long x;
    
    x = strtol(string, &remainderptr, 0);
    
    printf("%s\n", string);
    printf("%s\n", remainderptr);
    printf("%ld\n", x);
    printf("%ld\n", x + 567);
    
    
    return 0;
}