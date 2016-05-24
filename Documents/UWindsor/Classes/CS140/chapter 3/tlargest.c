//
//  tlargest.c
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
    int counter = 0, number = 0, largest = 0, slargest =0, holder = 0;
    
    
    while (counter <=9)
    {
        printf("%s", "Please enter a number: ");
        scanf("%d", &number);
        counter++;
        
        if (number > slargest)
        {
            slargest = holder;
            slargest = number;
            
            if (number > largest)
            {
                slargest = largest;
                largest = number;
            }
        }
    }
    printf("Your largest number is %d, and the second largest is %d\n", largest, slargest);
    return 0;
}