//
//  lab1- without recursive functions.c
//  Created by: Ryan Pearson
//  Student ID: 103965059
//  Date: July 4, 2013
//

#include <stdio.h>
#include <math.h>

int total (int *xptr);
int sumsquares (int *xptr);
int fibonacci (int *xptr);
int power (int *xptr, int *yptr);
void countdown (int *xptr);
void triangle (int *xptr);
void intriangle (int *xptr);

int
main (void)
{
    // variable for integer, control variable for switch
    int x = 0, y = 0, control = 1;
    // prompt user for correct integer
    do {
        printf("\nPlease enter your disired action:\n1.Summation\n2.Sum of Squares\n3.Fibonacci\n4.Not used in this program.\n5.Power\n6.Countdown\n7.Draw Inverted Triangle\n8.Draw Triangle\n9.End Program\nEnter Selection: ");
        scanf("%d", &control);
        if (control != 9 && control != 4) {
            do {
                printf("Please enter an integer greater than 0: ");     // ensure proper integer
                scanf("%d", &x);
            } while (x <= 0);
        }
        switch (control) {
            case 1:  // provide sum
                printf("\nYour total sum is: %d\n", total(&x));
                break;
            case 2: // provide sum of squares
                x+=1;
                printf("\nYour sum of squares value is: %d\n", sumsquares (&x));
                break;
            case 3: // provide Fibonacci
                printf("\nYour Fibonacci value is: %d\n", fibonacci(&x));
                break;
            case 4: // not used in this function
                printf("\nThis selection is not used in this program. Try again.\n");
                break;
            case 5: // provide power
                printf("\nYou will need to provide an additional number.\nYour first value was %d.\nPlease enter a 2nd number to compute %d to the power of: ", x, x);
                do {
                    scanf("%d", &y);
                } while (y < 0);
                printf("\n%d to the power of %d is: %d\n", x, y, power(&x, &y));
                break;
            case 6:  // countdown from n
                puts("");
                countdown(&x);
                break;
            case 7:  // draw inverted triangle
                puts("");
                intriangle(&x);
                break;
            case 8:  // draw triangle
                puts("");
                triangle(&x);
                break;
            default:
                break;
        }
    }while (control != 9);
    
    return 0;
}

/* Function: add all numbers up to and including x
 Input: one integer pointer
 output: one integer */
int total (int *xptr)
{
    int sums = 0;           // create variable to hold total
    // do math
    do {
        sums += *xptr;
        *xptr = *xptr - 1;
    } while (*xptr != 0);
    
    return sums;            // return total
}

/* Function: return the sum of squares of the integer
 Input: one integer pointer
 Output: one integer */
int sumsquares (int *xptr)
{
    int sums = 0;           // create variable to hold sum of squares
    int holder  = 0;        // holder variable
    
    do {
        holder = *xptr;
        sums += (pow(holder, 2));
        *xptr = *xptr - 1;
    } while (*xptr > 0);
    
    return sums;            // return value
}

/* Function: return the fibonacci value of the integer
 Input: one integer pointer
 Output: one integer */
int fibonacci (int *xptr)
{
    int a = 0, b = 1, c = 0;       // declare variables for sequence
    
    // return simple cases (even though you can't enter zero thru previous programming)
    if (*xptr == 0)
        return 0;
    if (*xptr == 1)
        return 1;
    // else do calculation to return proper value. count down xptr to know where you are in sequence.
    else
    {
        *xptr = *xptr - 1;
        do {
            c = a + b;
            a = b;
            b = c;
            *xptr = *xptr - 1;
        } while (*xptr != 0);
        
        // return value
        return c;
    }
}

/* Function: return the power of numbers provided
Input: a base and the exponential value- 2 integer pointers
Output: one integer- value */
int power (int *xptr, int *yptr)
{
    return pow (*xptr, *yptr);      // use math library to perform task
}

/* Function: countdown values from n to 1;
Input: integer variable pointer
Output: nothing */
void countdown (int *xptr)
{
    // countdown and print each step
    while (*xptr !=0 ) {
        printf("%d ", *xptr);
        *xptr = *xptr - 1;
    }
    
    puts("");
}

/* Function: return a triangle
Input: an integer pointer
Output:nothing */
void triangle (int *xptr)
{
    // draw triangle and increase size each turn
    for (int y = 1; y <= *xptr; y++) {
        for (int z = 1; z <= y; z++)
            printf("*");
        printf("\n");
    }
}

/*  Function: return an inverted triangle
Input: an integer pointer
Output: nothing */
void intriangle (int *xptr)
{
    // loop to create inverter triangle and count down.
    for (int y = *xptr; y > 0; y--) {
        for (int z = *xptr; z > 0; z--) {
            printf("*");
        }
        printf("\n");
        // reduce size each turn
        *xptr = *xptr - 1;
    }
}