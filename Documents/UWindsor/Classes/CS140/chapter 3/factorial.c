//
//  factorial.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main()
{
    int n = 0;          // declare value for factorial
    //int fac = 0;
    int i = 1;     // declare value
    int counter = 1;
    
    // ask user for positive integer
    
    printf("%s", "Please provide positive integer: ");
    scanf("%d", &n);
    
    // do math
    
    while (i <= n)
    {
        counter *= i;
        i++;
    }
    
    printf("%d\n", counter);
    return 0;
}