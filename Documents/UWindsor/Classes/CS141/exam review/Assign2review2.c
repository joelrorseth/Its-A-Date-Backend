//
//  Assign2review2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int i, j, maxSum = 0, sum = 0, start = -1, end = -1, num;
    
    printf("Please enter your array size: ");
    if (!scanf("%d", &num) == 1){printf("Invalid\n"); return -1;}
    
    int AB[num];
    
    for (i = 0; i < num; i++) {
        printf("Enter value: ");
        if (!scanf("%d", &start) == 1){printf("Invalid\n"); return -1;}
        AB[i] = start;
    }
    i = 0;
    j = 0;
    start = 0;
    while (j < num) {
        sum += AB[j];
        if (sum > maxSum) {
            maxSum = sum;
            start = i;
            end = j;
        }
        if (sum < 0){
            i= j+1;
            sum = 0;
        }
        j++;
    }
    
    printf("%d- start\n%d-end\n%d-maxsum\n", start, end, maxSum);
    return 0;
}