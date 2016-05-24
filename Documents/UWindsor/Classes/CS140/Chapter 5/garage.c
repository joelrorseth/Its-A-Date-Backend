//
//  garage.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

float value(float *z);


int
main(void)
{
    float hours = 0;
    int counter = 1;
    float sumhours = 0;
    float sumamount = 0;
    
    for (int x =1; x <=3; x++)
    {
        printf("Please enter the hours that the car stayed in the garage: ");
        scanf("%f", &hours);
    
        if (counter ==1)
            printf("%s", "Car\tHours\tCharge\n");
        printf("%d\t%.1lf\t%.2lf\n", counter, hours, value(&hours));
        sumhours += hours;
        sumamount += value(&hours);
        counter++;
    }
    
    printf("TOTAL\t%.1f\t%.2f\n", sumhours, sumamount);
    return 0;
}

float
value(float *z)
{
    if (*z < 3)
        return 2.00;
    else if (((*z - 3) * .5 + 2) >= 10.)
        return 10.00;
    else
    {
        return (*z - 3) * .5 + 2.;
    }
    
}