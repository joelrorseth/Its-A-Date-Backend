//
//  lab2_q1v2.c
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
    int num;                // holder value
    
    // prompt user for input
    printf("Please enter five integers: ");
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    
    // evaluate highest number
    num = a;
    if (num < a)
        num = a;
    else if (num < b)
        num = b;
    else if (num < c)
        num = c;
    else if (num < d)
        num = d;
    else if (num < e)
        num = e;

    printf("The Max is : %d\n", num);
        
    
    // evaluate lowest number
    
    num = a;
    if (num > a)
        num = a;
    else if (num > b)
        num = b;
    else if (num > c)
        num = c;
    else if (num > d)
        num = d;
    else if (num > e)
        num = e;
    
    printf("The Min is : %d\n", num);
    
    return 0;
}