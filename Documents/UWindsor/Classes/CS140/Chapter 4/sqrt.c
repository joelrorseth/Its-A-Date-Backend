//
//  sqrt.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <math.h>

int
main(void)
{
    float x = 0;
    
    printf("provide a number ");
    scanf("%f", &x);
    
    printf("%.2f\n", round (sqrt(x)));
    printf("%d\n", (int)pow(x, 3));
    
    return 0;
}