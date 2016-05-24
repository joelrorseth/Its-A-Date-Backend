/* PEARSON, Ryan
 *  ID: 103965059
 *  Lab Exercise #lab4_q4
 *  Date: Feb 12, 2013
 *  Purpose:art class with *'s and loops
 */

#include <stdio.h>

int
main(void)
{
    int n = 0;                              // declare variable for generating art
    
    // prompt user for input
    do
    {
        printf("Please enter an integer between 1 and 10: ");
        scanf("%d", &n);
    }while (n < 1 || n > 10);
    
    // create box
    for (int y = 1; y <= n; y++)
    {
        for (int x = 0; x < n; x++)
            printf("%s", "* ");
        puts("");
    }
    
    puts("\n");                             // create a space
    // create triangle
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= y; x++)
            printf("%s", "*");
        puts("");
    }
    
    return 0;
}