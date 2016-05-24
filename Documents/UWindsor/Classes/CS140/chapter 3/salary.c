//
//  salary.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    // declare variables
    float thours = 0, rhours, rate;
    
    while (thours != -1)
    {
        printf("Provide total hours worked (-1 to exit): ");
        scanf("%f", &thours);
        
        if (thours != -1)
        {
            printf("Please provide the rate of pay: ");
            scanf("%f", &rate);
            // compute for overtime
            if (thours <= 40)
                rhours = thours * rate;
            else if (thours > 40)
                rhours = (40 * rate) + ((thours - 40) * (rate * 1.5));
            printf("Salary is $%.2f.\n", rhours);
            
        }
        else
        {
            puts("oh... so you want out... to bad your stuck");
            puts("Provide total hours worked, (you can't exit)");
            puts("joking, bye");
        }
            
    }
    
    return 0;
}