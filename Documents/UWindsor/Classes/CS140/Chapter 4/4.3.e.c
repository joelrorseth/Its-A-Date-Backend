//
//  4.3.e.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main()
{
    for (int x = 1; x <= 20; x++)
    {
        if ( x % 5 != 0)
            printf("%d\t", x);
        else
            printf("%d\n", x);
    }
    
    return 0;
}