//
//  8.6.c
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
    const char string[] = "500% are admitted";
    
    double d;
    char *stringptr;
    
    d = strtod(string, &stringptr);
    
    printf("%s\n", string);
    printf("%%%.2f\n%s\n", d, stringptr);
    
    
    return 0;
}