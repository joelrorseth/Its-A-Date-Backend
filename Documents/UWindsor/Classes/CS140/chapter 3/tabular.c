//
//  tabular.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int x = 3, counter = 1;
    
    puts("A\tA+2\tA+4\tA+6");
    while (counter <= 5)
    {
        printf("%d\t%d\t%d\t%d\n", x, x + 2, x + 4, x + 6);
        x = x + 3;
        counter++;
    }
    
    return 0;
}