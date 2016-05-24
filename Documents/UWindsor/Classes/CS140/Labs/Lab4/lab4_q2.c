/* PEARSON, Ryan
 *  ID: 103965059
 *  Lab Exercise #lab4_q2
 *  Date: Feb 12, 2013
 *  Purpose: read 2 integers between 1 & 100. Display sequences requested
 */

#include <stdio.h>

int
main(void)
{
    int n = 0;                      // variable for int n
    int m = 0;                      // variable for int m
    int value = 0;                  // holder variable
    // ask user for integers
    printf("Please enter an integer value for n and m (n < m): ");
    scanf("%d%d", &n, &m);
    
    // check for valid answers
    if ( n > m)
        printf("Invalid input. Goodbye.\n");
    else
        if (n < 1 || n > 100)
            printf("Invalid input. Goodbye.\n");
        else if (m < 1 || m > 100)
            printf("Invalid input. Goodbye.\n");
    
    // give proper results
        else
        {
            // give results of n thru m
            for (value = n; value <= m; value++)
                printf("%d ", value);
            puts("");
            
            // give all odd numbers between n & m
            for (value = n; value <= m; value++)
            {
                if ((value % 2) == 1)
                    printf("%d ", value);
            }
            puts("");
            
            // give all values that are multiples of 5
            for (value = n; value <= m; value++)
            {
                if ((value % 5) == 0)
                    printf("%d ", value);
            }
            puts("");
            
            //count backwards from m to n
            for (value = m; value >= n; value--)
                printf("%d ", value);
            puts("");
        }
    
    return 0;
}
