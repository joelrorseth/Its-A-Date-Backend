//
//  triangle.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int a = 0;          // side a of triangle
    int b = 0;          // side b of triangle
    int c = 0;          // side c of triangle
    int counter = 0;    // variable to confirm if sides meet criteria
    
    // aks user for sides of triangle.
    
    printf("Please provide 3 integers for triangle check: ");
    scanf("%d%d%d", &a, &b, &c);
    
    // check sides for triangle
    
    if ( (a + b) > c)
    {
        puts("Check 1 ok");
        counter++;
    }
    else
        puts("Check 1 failed");
    if ( (a + c) > b)
    {
        puts("Check 2 ok");
        counter++;
    }
    else
        puts("Check 2 failed");
    if ( (b + c) > a)
    {
        puts("Check 3 ok");
        counter++;
    }
    else
        puts("Check 3 failed");
    if (counter == 3)
        puts("Numbers provided could be a triangle.");
    else
        puts("Not a valid triangle");
    
    
    return 0;
}