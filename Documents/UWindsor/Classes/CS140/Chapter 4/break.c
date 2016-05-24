//
//  break.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{

    for (int x = 20; x >= -10; x -= 6)
    {
        printf("%d\n", x);
    }
    return 0;
}