//
//  holesq.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    for (int x = 1; x <= 10; x++)
    {
        for (int y = 1; y <= 10; y++)
        {
            if (x == 1 || x == 10)
                printf("* ");
            else if ((x != 1 || x != 10) && (y == 1 || y == 10))
                printf("%s", "* ");
            else if ((x != 1 || x != 10) && (y != 1 || y != 10))
                printf("  ");
        }
        puts("");
    }
    
    return 0;
}