//
//  smflo.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

double small(double a, double b, double c);

int
main(void)
{
    double x, y, z = 0;         // declare integers
    
    // prompt user for input
    printf("Please provide 3 decimal numbers: ");
    scanf("%lf%lf%lf", &x, &y, &z);
    
    printf("%lf is the smallest.\n", small(x, y, z));
    
    return 0;
}


double
small(double a, double b, double c)
    {
        double max = a;
        
        if (b < max)
            max = b;
        if (c < max)
            max = c;
        return max;
        
    }