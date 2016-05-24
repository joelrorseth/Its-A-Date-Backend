//
//  assign2review.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int maxSum = 0, start = 0, end = -1, i = 0, j = 0;
    int n, sum = 0;
    
    printf("Please enter length of array you wish to create: ");
    if (!scanf("%d", &n)== 1) { printf("Invalid. Bye\n"); return -1;}
    
    if (n <= 0) { printf("No array.\n");return 0;}
    int AB[n];
    
    while (i++ < n) {
        printf("Enter value: ");
        if (!scanf("%d", &start) == 1) {printf("Invalid. Bye"); return -1;}
        AB[i-1] = start;
    }
    start = 0;
    i = 0;
    for (; i < n; i++) {
        printf("%d\t", AB[i]);
    }
    puts("");
    
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j=i; j < n; j++) {
            sum += AB[j];
            if (sum >= maxSum){
                maxSum = sum;
                start = i;
                end = j;
            }
        }
    }
    printf("%d\n%d-start element\n%d-end element\n", maxSum, start, end);
    return 0;
}