//
//  lab1- without recursive functions.c
//  Created by: Ryan Pearson
//  Student ID: 103965059
//  Date: July 4, 2013
//

#include <stdio.h>
#include <math.h>

int total (int x);
int sumsquares (int x);
int fibonacci (int x);
int f (int x, int y);
int power (int x, int y);
void countdown (int x);
void triangle (int x, int counter);
void intriangle (int x);
void line(int x);

int
main (void)
{
    // variable for integer, control variable for switch
    int x = 0, y = 0, control = 1;
    // prompt user for correct integer
    do {
        printf("\n\nPlease enter your disired action:\n1.Summation\n2.Sum of Squares\n3.Fibonacci\n4.Function call f(x, y).\n5.Power\n6.Countdown\n7.Draw Inverted Triangle\n8.Draw Triangle\n9.End Program\nEnter Selection: ");
        scanf("%d", &control);
        if (control != 9) {
            do {
                printf("Please enter an integer greater than 0: ");
                scanf("%d", &x);
            } while (x < 0);
        }
        switch (control) {
            case 1:  // provide sum
                printf("\nYour total sum is: %d", total(x));
                break;
            case 2: // provide sum of squares
                printf("\nYour sum of squares value is: %d", sumsquares(x));
                break;
            case 3: // provide Fibonacci
                printf("\nYour Fibonacci value is: %d", fibonacci(x));
                break;
            case 4: // compute f(x,y) value
                printf("\nYou will need to provide an additional number.\nYour first value was %d.\nPlease enter a 2nd number to compute %d: ", x, x);
                do {
                    scanf("%d", &y);
                } while (y < 0);
                printf("\nThe value of f(%d, %d) is: %d", x, y, f(x, y));
                break;
            case 5: // provide power
                printf("\nYou will need to provide an additional number.\nYour first value was %d.\nPlease enter a 2nd number to compute %d to the power of: ", x, x);
                do {
                    scanf("%d", &y);
                } while (y < 0);
                printf("\n%d to the power of %d is: %d", x, y, power(x, y));
                break;
            case 6:  // countdown from n
                puts("");
                countdown(x);
                break;
            case 7:  // draw inverted triangle
                puts("");
                intriangle(x);
                break;
            case 8:  // draw triangle
                puts("");
                triangle(x, 1);
                break;
            default:
                break;
        }
    }while (control != 9);
    
    return 0;
}

/* Function: sum all numbers up to and including x
 Input: one integer
 Output: one integer- the sum */
int total (int x)
{
    if (x == 1)
        return 1;
    else
        return (x + (total (x - 1)));
}

/* Function: return the sum of squares of the integer
 Input: one integer pointer
 Output: one integer
 */
int sumsquares (int x)
{
    if (x == 1)
        return 1;
    else
        return (pow(x,2) + sumsquares(x-1));
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

/* Function: provide the value of the function f
Input: 2 integers
Output: 1 integer value */
int f(int x, int y)
{
    if (x < 0 || y < 0)
        return x-y;
    else
        return f(x-1, y) + f(x, y-1);
}

/* Function: return the power of numbers provided
 Input: a base and the exponential value- 2 integer pointers
 Output: one integer- value*/
int power (int x, int y)
{
    if (y == 1)
        return x;
    else
        return x * power(x, y-1);
}

/* Function: countdown values from n to 1;
 Input: integer variable pointer
 Output: nothing*/
void countdown (int x)
{
    // countdown and print each step
    if (x == 1)
        printf("1\n");
    else
    {
        printf("%d ", x);
        return (countdown (x-1));
    }
}

/* Function: return a triangle
 Input: an integer pointer
 Output:nothing*/
void triangle (int x, int counter)
{
    // draw triangle and increase size each turn
    if (counter == x)
        return line(x);
    else
    {
        line(counter);
        return triangle(x, counter + 1);
    }
}

/*  Function: return an inverted triangle
 Input: an integer pointer
 Output: nothing*/
void intriangle (int x)
{
    
    // loop to create inverter triangle and count down each step.
    if (x == 0)
        return line(x);
    else
    {
        line (x);
        return intriangle(x-1);
    }
}

/* Function: draw lines for triangles
Input: One integer
Output: nothing*/
void line(int x)
{
    if (x == 0)
        printf("\n");
    else
    {
        printf("*");
        return line(x-1);
    }
}