//
//  cinterest.c
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
    double amount;
    double principle = 1000.0;
    double rate = .05;
    unsigned int year;
        
    printf("%4s%21s\n", "Year", "Amount on deposit");
    
    for (int counter = 1; counter <= 6; counter++)
    {
        printf("Rate %.0f%%\n", rate * 100);
        
        for (year = 1; year <= 10; ++year)
        {
            amount = principle * pow(1.0 + rate, year);
        
            printf("%4u %21.2f\n", year, amount);
        }
        
        rate += .01;
        
    }
    
    return 0;
}