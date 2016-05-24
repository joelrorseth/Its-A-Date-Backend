//
//  func.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int max(int x, int y, int z);

int
main(void)
{
    int number1, number2, number3 = 0;
    
    printf("Please give 3 numbers: ");
    scanf("%d%d%d", &number1, &number2, &number3);
    
    printf("%d is the largest number!\n", max (number1, number2, number3));
    
    return 0;
}


int
max(int x, int y, int z)
{
    
    int max = x;
    
    if (y > max)
        max = y;
    
    if (z > max)
        max = z;

    return max;
    
    
}