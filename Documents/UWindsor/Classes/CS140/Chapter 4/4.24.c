//
//  4.24.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main()
{
    int i = 1;
    int j = 2;
    int k = 3;
    int m = 2;
    
    printf("%d\n", i == 1);
    printf("%d\n", j == 3);
    printf("%d\n", i >= 1 && j < 4);
    printf("%d\n", m <= 99 && k < m);
    printf("%d\n", j <= i || k == m);
    printf("%d\n", k + m < j || 3 - j <= k);
    
    

    
    return 0;
}