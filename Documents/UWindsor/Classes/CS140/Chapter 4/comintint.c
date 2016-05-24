//
//  comintint.c
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
    unsigned int amount = 0;
    //unsigned int adecimal = 0;
    int principle = 100000;      // $1000 to erase decimal
    float rate = .05;           
    unsigned int year;        // year counter
    
    printf("%4s%21s\n", "Year", "Amount on Deposit");
    
    for (year = 1; year <= 10; ++year)
    {
        amount = principle * pow(1 + rate, year);
        
        if (amount % 100 < 10)
            printf("%4u%21u.0%u\n", year, amount / 100, amount % 100);
        else
            printf("%4u%21u.%2u\n", year, amount / 100, amount % 100);
    }
    
    return 0;
}