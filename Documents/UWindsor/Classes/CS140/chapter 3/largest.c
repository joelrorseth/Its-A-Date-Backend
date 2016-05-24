//
//  largest.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    //declare variables
    int counter = 0, number = 0, largest = 0;
    // initialize loop and prompt user for input
    while (counter <= 9)
    {
        printf("%s", "Please enter number: ");
        scanf("%d", &number);
        // evaluate number and replace largest if required, increase counter
        if (number >= largest)
        {
            largest = number;
            counter++;
        }
        else
            counter++;
    }
    // give back results
    printf("The individual that scored %d wins.\n", largest);
    return 0;
}