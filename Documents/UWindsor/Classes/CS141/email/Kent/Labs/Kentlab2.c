//
//  Kentlab2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int summation (int x);
int factorial (int x);
int fibonacci (int x);
int gcd (int x, int y);
int power (int x, int y);

int
main (void)
{
    // variable for integer, control variable for switch
    int x = 0, y = 0, control = 1;
    // prompt user for correct integer
    do {
        printf("\nPlease enter your computation:\n1.Summation\n2.Factorial\n3.Fibonacci\n4.Greatest Common Divisor\n5.Power\n6.End Program\n");
        scanf("%d", &control);
        if (control != 6) {
            do {
                printf("Please enter an integer greater than 0: ");
                scanf("%d", &x);
            } while (x < 0);
        }
        switch (control) {
            case 1:  // provide sum
                printf("Your total sum is: %d\n", summation(x));
                break;
            case 2: // provide Factorial
                printf("Your Factorial value is: %d\n", factorial(x));
                break;
            case 3: // provide Fibonacci
                printf("Your Fibonacci value is: %d\n", fibonacci(x));
                break;
            case 4: // provide GCD
                printf("You will need to provide an additional number.\nYour first value was %d.\nPlease enter a 2nd number to compute GCD: ", x);
                scanf("%d", &y);
                printf("The GCD is: %d", gcd(x, y));
                break;
            case 5: // provide power
                printf("You will need to provide an additional number.\nYour first value was %d.\nPlease enter a 2nd number to compute %d to the power of: ", x, x);
                do {
                    scanf("%d", &y);
                } while (y < 0);
                printf("%d to the power of %d is: %d", x, y, power(x, y));
                break;
            default:
                break;
        }
    }while (control != 6);
        
    return 0;
}

/* Function: sum all numbers up to and including x
 Input: one integer
 Output: one integer- the sum */
int summation (int x)
{
    if (x == 1)
        return 1;
    else
        return (x + (summation (x - 1)));
}

/* Function: factorial all numbers up to and including x
 Input: one integer
 Output: one integer- the factorial */
int factorial (int x)
{
    if (x == 1)
        return 1;
    else
        return (x * (factorial (x-1)));
}

/* Function:  provide the fibonacci value of x
 Input: one integer
 Output: one integer- the fibonacci value */
int fibonacci (int x)
{
    if (x == 1 || x == 0)
        return x;
    else
        return (fibonacci (x-1) + fibonacci(x-2));
}

/* Function: provide GCD
Input: 2 integers
Output: one integer, the GCD*/
int gcd (int x, int y)
{
    if (x == y)
        return x;
    else if (x < 0 || y < 0)
        return 1;
    else if (x < y)
        return gcd (x, y-x);
    else if (x > y)
        return gcd (x-y, y);

}

/* Function: provide power of 2 numbers
 Input: 2 integers
 Output: one integer, the exponential value*/
int power (int x, int y)
{
    if (y == 1)
        return x;
    else
        return x * power(x, y - 1);
}