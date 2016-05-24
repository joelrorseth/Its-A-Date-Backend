//  Assign2.c
//  PEARSON, RYAN
//  STUDENT ID: 103965059
//  DATE MARCH 5, 2013.
// I ATTEST THAT THIS IS SOLELY MY OWN WORK.
// Program allows variables of size unsigned long long int(apprx 10 characters per variable)
//(20 characters when joined for testing largest combination)
#include <stdio.h>
#include <math.h>
#define SIZE 50

//function prototypes & functions
int count1(unsigned long long int a);
 /*function: to return the number of elements prior to hitting zero
* intput: one integer
 output: one integer*/
int count1(unsigned long long int a)
{
    int counter = 0;        // variable to track decimal places
    // establish how many decimal places
    while (a != 0) {
        a /= 10;
        counter++;
    }
    return counter;
}

unsigned long long int attach(unsigned long long int a, unsigned long long int b, int count);
 /*function: join 2 long integers
 input: 2 long integers, the count of decimal spaces
 output: 1 long integer*/
unsigned long long int attach(unsigned long long int a, unsigned long long int b, int count)
{
    return a * pow(10, count) + b;
}

void work(unsigned long long int value[], int n);
/*function: control all work for sorting array
 input: one array
 output: sorted array*/
void work(unsigned long long int value[], int n)
{
    unsigned long long int holder1= 0;             // variable to compare numbers
    unsigned long long int holder2= 0;             // variable to compare numbers
    int x, i;                                   // counter variables
    
    // loop thru the series "n - 1" times to move variables
    for (x = 1; x < n; x++) {
        for (i = 0; i < n - 1; i++) {
            // evaluate total decimal places in element with count1
            // attach the element to the alternate element for comparing highest numbers in holder variables
            holder1 = attach(value[i], value[i + 1], count1(value[i + 1]));
            holder2 = attach(value[i+1], value[ i ], count1(value[i]));
            
            // use the holder variables to evaluate which is larger and move element if required
            if (holder1 < holder2){
                holder1 = value[i];
                value[i] = value[i+1];
                value[i+1] = holder1;
            }
        }
    }
}

int
main(void)
{
    int n = 0;                                  // value for the number of integers
    int i;                                      // counter variable
    
    // prompt user for number of integers
    do {
        // ensure user enters a valid number
        do {
            printf("\nPlease enter the total number of integers, (0 < n > 50), you wish to enter: ");
            scanf("%d", &n);
        } while (n < 0 || n > 50);
        
        unsigned long long int value[SIZE];         // reset values of array to zero
        for (i = 0; i < SIZE; i++) {
            value[i] = 0;
        }
        /* get integers. Assumes proper number of ints entered & approx < 10 characters per element*/
        if(n != 0){
            printf("Please enter the appropriate number of integers >= 0:\n");
            for (i = 0; i < n; i++)
                scanf("%llu", &value[i]);
            
            work(value, n);                       // function to perform work
            
            // return largest value
            printf("\n%s", "The largest combination is: ");
            for (i = 0; i < n; i++)
                printf("%llu", value[i]);
        }
    }while (n != 0);
    return 0;
}
