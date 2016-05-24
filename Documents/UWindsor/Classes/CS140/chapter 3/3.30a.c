//
//  3.30a.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int x = 9;
    int y = 11;
    
    if (x < 10)
        if (y > 10)
            puts("*****");
    else
        puts("#####");
    
    puts("$$$$$");
    
    return 0;
}