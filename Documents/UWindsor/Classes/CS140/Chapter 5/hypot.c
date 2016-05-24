//
//  hypot.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <math.h>

double hypotenuse(double s1, double s2);

int
main(void)
{
    double side1 = 0;
    double side2 = 0;
    
    printf("\nPlease provide 2 sides of a triangle: ");
    scanf("%lf%lf", &side1, &side2);
    
    printf("Hypotenuse for the sides provided is: %.0lf\n\n", hypotenuse(side1, side2));
    
    return 0;
}

double
hypotenuse(double s1, double s2)
{
    return sqrt( (pow(s1, 2) + (pow(s2, 2))));
    
}