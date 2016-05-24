//
//  tes.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main()
{
    int x = 1, y = 1;
    int z = x + y;
    
    printf("%d", ++(z));
    return 0;
}