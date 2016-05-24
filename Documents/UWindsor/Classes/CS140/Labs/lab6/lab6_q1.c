/* PEARSON, Ryan
 *  ID: 103965059
 *  Lab Exercise #lab6_q1
 *  Date: March 5, 2013
 *  Purpose: Display a menu to perform some math functions
 *  Adjusted to reprompt for another number to perform math on.
 */

#include <stdio.h>


//function prototypes
void MenuController(void);
void min(int num);
void max(int num);
int GetNumber(void);
void DisplayMenu(void);
long int ComputeFactorial(int a);
int ComputeFibonacci(int a);
int SumOdd(int a);

/*
 *Function: control the program call proper functions at proper times
 *Input: Nothing
 *Output: nothing
 */
void MenuController(void)
{
    int n = 0;                      // value n for computing math functions
    int selection = 0;              // value for choosing the math function
    do {
        n = GetNumber();
        if (n == -1)
        {
            puts("Goodbye!");
            break;
        }
        
        DisplayMenu();
        if(GetNumber > 0)
        {
            do
            {
                printf("Please select one action from the above list? ");
                scanf("%d", &selection);
                
                switch(selection){
                    case 1:
                        printf("The factorial of %d (%d!) = %ld\n", n, n, ComputeFactorial(n));
                        break;
                    case 2:
                        printf("The fibonacci of %d = %d\n", n, ComputeFibonacci(n));
                        break;
                    case 3:
                        printf("The total of odd numbers between 1 & %d = %d\n", n, SumOdd(n));
                        break;
                    case 4:
                        puts("Goodbye!");
                        break;
                    default:
                        puts("Your entry was invalid!");
                }
                
            }while(selection != 4);
        }

    }while (n != -1);
}

/*
 Funtion: Compute factorial of an integer
 Input: one integer
 Output: one long int
 */

long int ComputeFactorial(int a)
{
    long int total = 1;
    
    for(int i = 1; i <= a; i++)
        total *= i;
    return total;
}

/*
 Funtion: Compute fibonacci of an integer
 Input: one integer
 Output: one long int
 */

int ComputeFibonacci(int a)
{
    int first = 0;
    int second = 1;
    int final = 0;
    
    if(a < 2)
        return a;
    else
    {
        for (int i = 1; i < a; i++)
        {
            final = first + second;
            first = second;
            second = final;
        }
        return final;
    }
    
}

/*
 Funtion: Compute sum of odd integers less than or equal to n
 Input: one integer
 Output: one int
 */

int SumOdd (int a)
{
    int total = 0;
    int i;
    
    for (i = 1; i <= a; i += 2)
        total += i;
    
    return total;
}



/*
 Function: check if number is below minimum value
 Input: integer value given by user
 Output: nothing
 */
void min( int num)
{
    if (num < 1)
        puts("Excuse me... That is below the limit.\nTry again.");
}


/*
 Function: check if number is above allowed value
 Input: integer value given by user
 Output: nothing
 */
void max(int num)
{
    if (num > 20)
        puts("Excuse me... That is above the limit.\nTry again.");
    
}

/*
 *Function: prompt user for number, check validity
 *Input: Nothing
 *Output: one integer
 */
int GetNumber(void)
{
    int num = 0;                            // provide n to the system for computing functions
    
    do
    {
        printf("\nPlease enter an integer between 1 and 20(-1 to exit): ");
        scanf("%d", &num);
        if (num == -1)
            break;
        
        min(num);
        max(num);
        
    }while(num < 1 || num > 20);
    
    return num;
    
}



/*
 *Function:Print to screen the Action list menu for the user
 *Input: Nothing
 *Output: Nothing
 */
void DisplayMenu(void)
{
    puts("\nACTION LIST MENU");
    puts("----------------\n");
    
    printf("%s\n", "   1. Compute Factorial of n");
    printf("%s\n", "   2. Compute Fibonacci of n");
    printf("%s\n", "   3. Compute Sum_Odd of n");
    printf("%s\n\n", "   4. Exit");
    
}



int
main(void)
{
    
    MenuController();
    
    return 0;
}
