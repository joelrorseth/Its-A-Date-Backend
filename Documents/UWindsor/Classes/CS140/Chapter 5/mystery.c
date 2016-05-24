//
//  mystery.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int mystery(int a, int b);
static int d = 0;

int
main(void)
{
    int x = 0;
    int y = 0;
    int z = 0;
    
    printf("enter 2 numbers: ");
    scanf("%d%d", &x, &y);
    
    z = mystery(x, y);
    
    if (d == 1)
        printf("The result is %d\n", z * -1);
    else
        printf("The result is %d\n", mystery(x, y));
    return 0;
}


int
mystery(int a, int b)
{
    int c;
    if (b < 0)
    {
        d = 1;
        b *= -1;
    }
    
    if (b == 1)
        return a;
    else
        return (a + mystery(a, b-1));
    
}