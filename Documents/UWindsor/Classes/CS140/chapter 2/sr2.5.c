//
//  Chapter 2-2.5 self review.c
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
    int x, y, z, result;
    //prompt & receive variables
    printf("Please provide 3 integers:");
    scanf("%d %d %d", &x, &y, &z);
    // do math
    result = x * y * z;
    // return result
    printf("The product is %d\n", result);
    return 0;
}