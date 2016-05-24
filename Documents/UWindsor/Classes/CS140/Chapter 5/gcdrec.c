//
//  gcdrec.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int gcd(int a, int b);

int
main(void)
{
    // integer variables
    int x, y = 0;
    //get variables from user
    printf("Please provide 2 variables to compare for greatest common divisor: ");
    scanf("%d%d", &x, &y);
    // return answer
    printf("The greatest common divisor of the 2 is: %d\n", gcd(x, y));
    
    return 0;
}

// function to compare numbers
int
gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b,a % b);
        
        
    
    
    
    
    
/*    int max = 0;
    int value = 1;
    
    if (b > a)
    {
        
        do
        {
            if ((a % value) == 0)
            {
                max = a / value;
                if ((b % max) == 0)
                    break;
                else
                {
                    max = 0;
                    value++;
                }
                
            }
            else
                value++;
        }while (max == 0);
    }
    else
    {
        
        do
        {
            if ((b % value) == 0)
            {
                max = b / value;
                if ((a % max) == 0)
                    break;
                else
                {
                    max = 0;
                    value++;
                }
                
            }
            else
                value++;
        }while (max == 0);
    }
    
    
    return max;*/
}