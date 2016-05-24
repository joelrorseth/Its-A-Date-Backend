//
//  lab11.2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int a = 3;

int f(int a)
{
    printf("%d ", a);
    return a+1;
    
}

int g(int A[])
{
    int n = 0;
    n+= (A[f(a)]);
    printf("%d %d\n", A[a], n);
    return A[a] + n;
}

int
main(void)
{
    int A[10] = {1,2,3,4,5,6,7,8,9,0};
    printf("%d %d\n", a, A[a]);
    printf("%d\n", f(g(A)));
    A[0] = A[1];
    printf("%d\n", g(A));
    printf("%d\n", a);
    return 0;
}