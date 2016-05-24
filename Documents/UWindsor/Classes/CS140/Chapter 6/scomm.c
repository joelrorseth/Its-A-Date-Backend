//
//  scomm.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 11

int getRate(float gross);
// function to get commission salary
// input : float
// output: integer commision rate
int getRate(float gross)
{
    int total = 0;
    gross *= .09;
    return total = (200 + (int)gross) /100;
}


int
main(void)
{
    int counter[SIZE] = {0};
    float gross = 0;
    int comm = 0;
    
    do {
        printf("Please enter the gross sales for this employee(-1 to exit): ");
        scanf("%f", &gross);
        
        comm = getRate(gross);
        
        if (comm >= 10)
            counter[10]++;
        else if (gross == -1)
            break;
        else
            counter[comm]++;
        
    } while (gross != -1);
    
    for (int x = 2; x < SIZE; x++) {
        if (x == 10)
            printf("Number of employees in $%d00-%d99 range = %d\n", x, x, counter[x]);
        else
            printf("Number of employees in $%d00-%d99   range = %d\n", x, x, counter[x]);
    }
    
}