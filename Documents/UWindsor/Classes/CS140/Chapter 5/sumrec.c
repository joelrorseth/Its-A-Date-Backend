//
//  sumrec.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <math.h>

int sum (int);

int
main(void)
{
    int x = 5;
    
    printf("%d\n", sum(x));
    printf("%lf\n", fabs(7.5));
    printf("%lf\n", fabs(0.0));
    printf("%lf\n", ceil(0.0));
    printf("%lf\n", fabs(-6.4));
    printf("%lf\n", ceil(-6.4));
    printf("%lf\n", ceil(-fabs(-8 + floor(-5.5))));
    
    return 0;
}

int
sum(int n)
{
    if (n == 0) {
        return n;
    }
    else
    {
        return n + sum(n-1);
    }
    
    
    
}