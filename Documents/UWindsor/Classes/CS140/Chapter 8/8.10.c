//
//  8.10.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 80

void reverse(const char * const sPtr);

int
main(void)
{

    char sentence[SIZE];
    
    puts("Enter line of text:");
    
    fgets(sentence, SIZE, stdin);
    
    puts("The line printed backwards is:");
    
    reverse(sentence);
    
    puts("");
    
    puts(sentence);
    
    return 0;
}

void reverse(const char * const sPtr)
{
    if ('\0' == sPtr[0])
        return;
    else{
        reverse(&sPtr[1]);
        putchar(sPtr[0]);
    }
}