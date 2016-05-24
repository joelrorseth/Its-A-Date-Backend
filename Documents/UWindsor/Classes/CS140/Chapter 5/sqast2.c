//
//  sqast2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

void side(int s1);

int
main(void)
{
    int side1 = 0;              // variable for side
    
    printf("Please give size: ");
    scanf("%d", &side1);
    
    side(side1);
    
    return 0;
}


void
side(int s1)
{
    for (int x = 1; x <= s1; x++)
    {
        for (int y = 1; y <= s1; y++)
            printf("* ");
        puts("");
    }
    
    return;
}