//
//  decrement.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    // declare variables
    int x = 5;
    
    // predecremeneting
    puts("Predecrementing x = 5");
    printf("%d\n", x);
    printf("%d --x\n", --x);
    printf("%d\n", x);
    puts("");
    //postdecrement
    puts("Postdecrementing x = 4");
    printf("%d\n", x);
    printf("%d x--\n", x--);
    printf("%d\n", x);
    
    return 0;
}