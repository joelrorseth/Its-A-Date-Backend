//
//  mpg.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    // declare variable, set gallon to 1 to enter into the loop without previous prompting
    float gal = 1, mil, mpg, total = 0, average = 0;
    int counter = 0;
        
    // cycle thru loop while not sentinal value and determine tank mpg
        while ( gal != -1)
        {
        
            printf( "%s", "Enter the gallons used (-1 to end): ");
            scanf("%f", &gal);
            // check for sentinel value
            if ( gal != -1)
            {
                printf( "%s", "Enter the miles driven: ");
                scanf("%f", & mil);
                mpg = mil / gal;
                printf("This tank has a MPG of %f.\n", mpg);
                // keep track of total MPG and how many cycles
                counter++;
                total += mpg;
                puts ("");
            }
            // check for no entry into calculator
            else if ( gal == -1 && counter == 0)
            {
                puts ("You did not enter a value. Bye!");
                return 1;
            }
            // exit loop when sentinal value typed and provide average MPG for the group
            else
            {
                average = (total / counter);
                puts(" ");
                printf("Your average MPG is %.2f\n", average);
                return 0;
            }
        }
}
