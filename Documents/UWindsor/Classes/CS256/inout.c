//
//  inout.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define IN 1
#define OUT 0

int
main(void)
{
    int state;
    char c;
    
    state = OUT;
    
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '\t':
            case '\n':
            case ' ':
                if (state == IN) {
                    state = OUT;
                    printf("\n");
                }
                break;
                
            default:
                if (state == OUT)
                    state = IN;
                    putchar(c);
                break;
        }
    }
    
    return 0;
}