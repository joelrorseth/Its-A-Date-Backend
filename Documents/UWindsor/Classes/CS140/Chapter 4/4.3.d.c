//
//  4.3.d.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main()
{
    int x = 1;                      // declare variable
    
    // intialize loop and watch for line 5. Create new line on 5th increment
    while (x <= 20)
    {
        if ( x % 5 != 0)
            printf("%d\t", x);
        else
            printf("%d\n", x);
        x++;
        
    }
    
    return 0;
}