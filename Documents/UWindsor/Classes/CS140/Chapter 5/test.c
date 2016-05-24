//
//  test.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include<stdio.h>

int main()
{
    int n,i,sum;
    
    printf("Perfect numbers are: ");
    for ( n=1 ; n<=1000000 ;n++)
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
    
    return 0;
}