//
//  3.29.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main (void)
{
    unsigned int row = 10;
    unsigned int column;
    
    while (row >= 1)
    {
        column = 1;
        
        while (column <= 10)
        {
            printf("%d", row % 2);
            printf("%s", row % 2 ? "<" : ">");
            ++column;
            
        }
        --row;
        puts("");
    }
    
    return 0;
}