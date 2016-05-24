//
//  checkerboard.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    // declare counters
    int count = 1;             // height counter
    int counti = 1;            // length counter
    
    while (count <= 8)
    {
        while (counti <= 8)
        {
            printf("%s", "* ");
            counti++;
        }
        puts("");
        
        if (count % 2)
            printf("%s", " ");
        
        counti = 1;
        count++;
    }
    
    
    return 0;
}