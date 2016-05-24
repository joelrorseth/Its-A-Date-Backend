//
//  7.10.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <ctype.h>

void convertToUppercase (char *sPtr);

void convertToUppercase(char *sPtr)
{
    while (*sPtr != '\0') {
        *sPtr = toupper(*sPtr);
        sPtr++;
    }
}


int
main(void)
{
    char string[] = "cHaracTers and $32.98";
    
    printf("The string before conversion is: \n%s\n", string);
    convertToUppercase(string);
    printf("The string after conversion is: \n%s", string);
    puts("");
    
    return 0;
}