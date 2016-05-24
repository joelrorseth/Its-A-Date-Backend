//
//  exponent.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int x = 1;
    int holder = 1;
    int i = 1;
    
    printf("give x: ");
    scanf("%d", &x);
    
    while (i <= x)
    {
        holder *= x;
        
        i++;
    }
    printf("%d\n", holder);
    return 0;
}