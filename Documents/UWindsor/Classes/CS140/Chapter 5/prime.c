//
//  prime.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <math.h>

void prime (void);
void prime2 (void);

int
main(void)
{
    prime();
    puts("\n\n");
    prime2();
    return 0;
}

void
prime2(void)
{
    int counter =0;
    for (double x = 2; x < 10000; x++)
    {
        int primes = 2;
      
        while (primes < sqrt(x))
        {
            if ((int)x % primes == 0)
                break;
            else
            {
                primes++;
                continue;
            }
        }
        
        if (primes > sqrt(x))
        {
            printf("%d ", (int)x);
            counter++;
        }
    }
    puts("\n\n");
    printf("%d\n\n", counter);
    puts("\n\n\n");
}


/*void
prime3(void)
{
    int i, j;
    i = 2;
    while ( i < 300 )
    {
        j = 2;
        while ( j < sqrt(i) ){
            if ( i % j == 0 )
                break;
            else{
                ++j;
                continue;
            }
        }
        if ( j > sqrt(i) )
            printf("%d\t", i);
        ++i;
    }
}
*/

void
prime(void)
{
    int counter1 =0;
    for (int x = 1; x < 10000; x++)
    {
        int primes = 2;
        int counter = 0;
        while (primes <= x)
        {
            if (x % primes == 0)
                counter++;
            primes++;
        }
        
        if (counter == 1)
        {
            printf("%d ", x);
            counter1++;
        }
    }
    puts("\n\n");
    printf("%d\n\n", counter1);
    
}