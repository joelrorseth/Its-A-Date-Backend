//
//  fibnrec.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

unsigned long long int fiber(unsigned x);

int
main(void)
{
    unsigned int x = 0;
    
    printf("Please enter the n'th digit of the fibernacci sequence you would like to receive: ");
    scanf("%u", &x);
    
    printf("Fibernacci value: %lld\n", fiber(x));
    
    return 0;
}

unsigned long long int
fiber(unsigned int a)
{
    int sum = 0;
    int x = 0;
    int y = 1;
    int counter = 0;
    
    while (a != counter) {
        sum = x + y;
        counter++;
        
        if (counter % 2 == 0 && a != counter)
            x = sum;
        else if (counter % 2 == 1 && a != counter)
            y = sum;
        printf(" %d = sum, %d = x, %d = y\n", sum, x, y);
    }
    return sum;
}