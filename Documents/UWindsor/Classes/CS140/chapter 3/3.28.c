//
//  3.28.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int count = 1;
    
    
    while (count <= 10)
    {
        printf("%d", count % 2);
        puts(count % 2 ? "****" : "++++++++");
        count++;
    }
    
    return 0;
}