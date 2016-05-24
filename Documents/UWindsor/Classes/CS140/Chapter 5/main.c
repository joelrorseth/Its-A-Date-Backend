//
//  main.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

void go(int count);

int
main(void)
{
    static int count = 1;
    go(count);
    printf("Main - %d\n", count);
    return 1;
}

void
go(int count)
{
    if (count <= 10)
    {
    
    printf("Function- %d\n", count);
    count++;
    main();
    }
    
}