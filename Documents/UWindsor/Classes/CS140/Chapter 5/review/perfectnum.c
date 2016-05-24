//
//  perfectnum.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

void perfect(void);

int
main(void)
{
    perfect();
    
    return 0;
}

void
perfect(void)
{
    int n, i, sum;
    
    printf("Perfect numbers are: ");
    for ( n=1 ; n<=10000 ;n++)
    {
        i=1;
        sum = 0;
        
        while(i<n)
        {
            if(n%i==0)
                sum=sum+i;
            i++;
        }
        
        if(sum==n)
            printf("%d ",n);
        
    }
    puts("");
    
}