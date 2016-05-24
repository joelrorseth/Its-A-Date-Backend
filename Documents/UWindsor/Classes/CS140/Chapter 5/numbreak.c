//
//  numbreak.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

void numbreak(int y);

int
main(void)
{
    int x = 0;
    
    do {
        printf("Please provide an int between 1 and 32767: ");
        scanf("%d", &x);
    } while ((x < 1) || (x > 32767));
    
    numbreak(x);
    puts("");
    return 0;
}

void
numbreak(int y)
{
    int holder;
    int counter;
    
    if (y / 10000 > 0)
    {
        counter = 5;
        holder = 10000;
    }
    else if (y / 1000 > 0)
    {
        holder = 1000;
        counter = 4;
    }
    else if (y / 100 > 0)
    {
        holder = 100;
        counter = 3;
    }
    else if (y / 10 > 0)
    {
        holder = 10;
        counter = 2;
    }
    else
        counter = 1;
    do {
        
        printf("%d  ", y / holder);
        y %= holder;
        holder /= 10;
        counter--;
    } while (counter > 0);
    
}