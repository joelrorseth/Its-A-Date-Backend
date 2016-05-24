//
//  hanoi3.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

void move(int n, int from, int to, int via);

int
main(void)
{
    // declare variable for x
    int x = 0;
    
    printf("Please provide how many blocks there are: ");
    scanf("%d", &x);
    
    move (x, 1, 3, 2);
    
    return 0;
}

void
move(int n, int from, int to, int via)
{
    if (n > 0)
    {
        move(n-1, from, via, to);
        printf("%d -> %d\n", from, to);
        move(n-1, via, to, from);
    }
    
    
}