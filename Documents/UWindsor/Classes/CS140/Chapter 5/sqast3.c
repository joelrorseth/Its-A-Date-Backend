//
//  sqast3.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

void side(int s1, int c1);

int
main(void)
{
    int side1 = 0;              // variable for side
    int fill;
    
    printf("Please provide a character: ");
    fill = getchar();
    
    printf("Please give size: ");
    scanf("%d", &side1);

    //printf("Please provide a character: ");
    //fill = getchar();
    
    side(side1, fill);
    
    return 0;
}


void
side(int s1, int c1)
{
    for (int x = 1; x <= s1; x++)
    {
        for (int y = 1; y <= s1; y++)
        {
            printf("%c ", c1);
        }
        puts("");
    }
    
    return;
}