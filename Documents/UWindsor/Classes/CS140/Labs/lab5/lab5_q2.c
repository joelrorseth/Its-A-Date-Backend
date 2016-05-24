//
//  lab5_q2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int Max3(int a, int b);
/* function to calculate the greatest variable
* input: 2 integers(in class suggested this method
* output: largest int
*/

int
main(void)
{
    int x, y, z = 0;        // declare variables
    
    // prompt user for input
    printf("Please enter 3 integers: ");
    scanf("%d%d%d", &x, &y, &z);
    
    // provide answer
    printf("Max3 (%d, %d, %d) has returned %d\n", x, y, z, Max3(Max3(x, y), z));
    
    return 0;
}

int Max3(int a, int b)
{
    if (a < b)
        return b;
    else
        return a;
}