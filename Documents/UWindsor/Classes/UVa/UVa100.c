//
//  UVa100.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

void math(int a, int b, int *counter);

void math(int a, int b, int *counter)
{
    printf("%d. %4d\n", *counter, b);
    while (b != 1) {
        if(b % 2 == 1)
            b = b * 3 + 1;
        else
            b /= 2;
            
        *counter += 1;
        printf("%d. %4d\n", *counter, b);
    }
    //*counter += 1;
}

int
main(void)
{
    int i, j, counter, hcount = 0;
    scanf("%d%d", &i, &j);
    
    do
    {
        if(hcount !=0)
            i++;
        counter = 1;
        math(i, j, &counter);
        if (counter < hcount)
            hcount = counter;
    }while (i <= j);
        
    printf("%d %d %d\n", i, j, hcount);
    
    
    return 0;
}