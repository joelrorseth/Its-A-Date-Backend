//
//  celfar2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

double celsius(int f);
double fahrenheit(int c);

int
main(void)
{
    // draw top line
    printf("Celsius\tFahrenheit\tCelsius\tFahrenheit\tCelsius\tFahrenheit\n");
    
    for (int counter = -44; counter <= 100; counter++)
    {
        printf("||%d->\t%.2lf\t\t", counter, celsius(counter));
        
        if (counter % 3 == 0)
            puts("");
        
    }
    puts("\n");
    
    printf("Fahrenheit\tCelsius\tFahrenheit\tCelsius\tFahrenheit\tCelsius\n");
    
    for (int fcounter = 32; fcounter <= 212; fcounter++)
    {
        printf("||%d->\t\t%.2lf\t", fcounter, fahrenheit(fcounter));
        
        if (fcounter % 3 == 0)
            puts("");
    }
    puts("");
    
    return 0;
}


double
celsius(int f)
{
    return (double)f * 9 / 5 + 32;
    
}

double
fahrenheit(int c)
{
    return (c - 32) * 5 / 9;
    
}