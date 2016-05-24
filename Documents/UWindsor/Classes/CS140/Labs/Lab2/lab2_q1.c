//
//  lab2_q1.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{

    int a, b, c, d, e;      // individual numbers
    int max;                // holder value
    
    // prompt user for input
    printf("Please enter five integers: ");
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    
    // evaluate highest number
    
    if (a > b && a > c && a > d && a > e)
        printf("The Max is : %d\n", a);
    else if (b > a && b > c && b > d && b > e)
        printf("The Max is : %d\n", b);
    else if (c > a && c > b && c > d && c > e)
        printf("The Max is : %d\n", c);
    else if (d > a && d > b && d > c && d > e)
        printf("The Max is : %d\n", d);
        else
            printf("The Max is : %d\n", e);
    
    // evaluate lowest number
    
    if (a < b && a < c && a < d && a < e)
        printf("The Min is : %d\n", a);
    else if (b < a && b < c && b < d && b < e)
        printf("The Min is : %d\n", b);
    else if (c < a && c < b && c < d && c < e)
        printf("The Min is : %d\n", c);
    else if (d < a && d < b && d < c && d < e)
        printf("The Min is : %d\n", d);
    else
        printf("The Min is : %d\n", e);
    
    return 0;
}