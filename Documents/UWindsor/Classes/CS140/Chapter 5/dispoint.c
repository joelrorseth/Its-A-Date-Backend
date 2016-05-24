//
//  dispoint.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

double distance(double x1, double x2);


int
main(void)
{
    double a1, a2, b1, b2 = 0;
    
    printf("Please provide points x1, y1 and points x2, y2: ");
    scanf("%lf%lf%lf%lf", &a1, &b1, &a2, &b2);
    
    printf("The distance between your points is: (%.2lf, %.2lf)\n", distance(a1, a2), distance(b1, b2));
    
    return 0;
}


double
distance(double x1, double x2)
{
    
    return x1 - x2;
    
    
}