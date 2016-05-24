//
//  kentlab1.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <math.h>

int total (int *xptr);
/* Function: add all numbers up to and including x
 Input: one integer
 output: one integer
 */
int total (int *xptr)
{
    int sums = 0;
    do {
        sums += *xptr;
        *xptr = *xptr - 1;
    } while (*xptr != 0);
    
    return sums;
    
}

int factorial (int *xptr);
/* Function: return the factorial of the integer
 Input: one integer
 Output: one integer
 */
int factorial (int *xptr)
{
    
    int sums = 1;
    
    if (*xptr == 1 || *xptr == 0)
        printf("1");
    else
        do {
            sums *= *xptr;
            *xptr = *xptr - 1;
        } while (*xptr != 1);
    
    return sums;
}

int fibonacci (int *xptr);
/* Function: return the factorial of the integer
 Input: one integer
 Output: one integer
 */
int fibonacci (int *xptr)
{
    int as = 0, b = 1, c = 0;
    
    if (*xptr == 0)
        return 0;
    if (*xptr == 1)
        return 1;
    else
    {
        *xptr = *xptr - 1;
        do {
            c = as + b;
            as = b;
            b = c;
            *xptr = *xptr - 1;
            
        } while (*xptr != 0);
        
        return c;
    }
}


int gcd (int *xptr, int *aptr);
/* Function: return the factorial of the integer
 Input: two integers
 Output: one integer- the gcd
 */
int gcd (int *xptr, int *aptr)
{
    
    int temp;
    do {
        temp = *xptr;
        *xptr = *aptr;
        *aptr = temp % *aptr;
        
    } while (*aptr > 0);

    return *xptr;
}

int
main(void)
{
    int sum = 0, x = 0, a = 0;             // sum variable
    
    // prompt user for number to sum all numbers up to and including that number
    do {
        printf("Please enter a number greater than 1 and I will sum all numbers: ");
        scanf("%d", &x);
    } while (x < 1);
    
    printf("Your total is: %d\n", total(&x));
    
    puts("\n\n");
    
    // prompt user for number to return the factorial
    do {
        printf("Please enter a number greater than 1 and I will return the factorial: ");
        scanf("%d", &x);
    } while (x < 1);
    
    printf("Factorial is: %d\n", factorial(&x));
    
    puts("\n\n");
    
    // prompt user for number to give the fibonacci value
    do {
        printf("Please enter a number greater than 1 and I will return the value in the fibonacci sequence: ");
        scanf("%d", &x);
    } while (x < 1);
    
    printf("Fibonacci Value is: %d\n", fibonacci(&x));
    
    // prompt user for 2 numbers and give the greatest common divisor
    do {
        printf("Please enter 2 numbers and i will return the greatest common divisor: ");
        scanf("%d%d", &x, &a);
    } while (x < 1 && a < 1);
    
    printf("%d\n", gcd(&x, &a));
    
    puts("\n\n");
    
    // prompt user for 2 numbers and return the first to the power of the 2nd. use existing math function "pow"
    do {
        printf("Please enter 2 numbers and i will return the first number to the power of the second number: ");
        scanf("%d%d", &x, &a);
    } while (x < 1 && a < 1);
    
    printf("The value is %.0f\n", pow(x,a));
    
    return 0;
}