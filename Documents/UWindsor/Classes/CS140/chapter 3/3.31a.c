//
//  3.31a.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int x = 5, y = 7;
    
    if (y == 8)
    {
        if ( x == 5)
            puts("@@@@@");
    }
    else
    {
    puts("#####");
    puts("$$$$$");
    puts("&&&&&");
    }
    
    return 0;
}