//
//  hanoi2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


void move(int n, int from, int to, int via)
{
    if (n > 0) {
        move(n - 1, from, via, to);
        printf("Move disk from pole %d to pole %d\n", from, to);
        move(n - 1, via, to, from);
    }
}
int main()
{
    move(5, 1,2,3);
    return 0;
}