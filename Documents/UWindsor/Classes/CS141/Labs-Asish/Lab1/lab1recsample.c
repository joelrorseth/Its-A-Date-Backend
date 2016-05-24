/*
 Lab 1 recursive: Solution
 Writtten by: Ziad Kobti and Quazi Rahman
 Updated: Jan. 2013.
 Updated 14 July 2013 by Jeffrey Drake
 
 */

/* includes */
#include <stdio.h>
#include <string.h>
#include <math.h>

#define _QUIT_ 0
#define _INFINITY_ 999999

/* Specifics for the interactive/dynamic menu */
const char *MENU[] = {  "Recursive Sum i",
    "Recursive Sum (i+1)^2",
    "Recursive Fibonacci",
    "Recursive f(x,y)",
    "Recursive Power",
    "Recursive Print(n)",
    "Recursive DrawTriangleInverted",
    "Recursive DrawTriangle"
};

//AM: how did this get to be 14 ?
//const int MENU_COUNT = 14;
const int MENU_COUNT = 8;

/* prototypes */
int GetInput(const char* msg, int min, int max);
int GetMenuItem();

/* Recursive Versions */
int SumR(int n);
int SumR2(int n);
int FibonacciR(int n);
long f(long x, long y);
long PowerR(int a, int b);
void PrintR(int n);
void DrawTriangleInvertedR(int n);
void DrawTriangleR(int n);



/* main program function */
int main() {
    int key;                   // stores the input from the user
    do {                        // Main program loop
        key = GetMenuItem("Lab 1");      // Retreive a valid input selection from the user
        
        if (key != _QUIT_) {
            switch(key) {
                case 1:
                    printf("\nAnswer: %d\n", SumR(GetInput("Enter a positive Integer: ", 1, _INFINITY_)));
                    break;
                case 2:
                    printf("\nAnswer: %d\n", SumR2(GetInput("Enter a positive Integer: ", 1, _INFINITY_)));
                    break;
                case 3:
                    printf("\nAnswer: %d\n", FibonacciR(GetInput("Enter a positive Integer: ", 1, _INFINITY_)));
                    break;
                case 4:
                    printf("\nAnswer: %ld\n", f(GetInput("Enter a positive Integer a: ", 0, _INFINITY_),
	                                            GetInput("Enter a positive Integer b: ", 0, _INFINITY_)));
                    break;
                case 5:
                    printf("\nAnswer: %ld\n", PowerR(GetInput("Enter a positive Integer a: ", 0, _INFINITY_),
                                                     GetInput("Enter a positive Integer b: ", 0, _INFINITY_)));
                    break;
                case 6:
                    printf("\nAnswer:\n");
                    PrintR(GetInput("Enter a positive Integer n: ", 1, _INFINITY_));
                    break;
                case 7:
                    printf("\nAnswer:\n");
                    DrawTriangleInvertedR(GetInput("Enter a positive Integer n: ", 1, _INFINITY_));
                    break;
                case 8:
                    printf("\nAnswer:\n");
                    DrawTriangleR(GetInput("Enter a positive Integer n: ", 1, _INFINITY_));
                    break;
                    
            }
        }
    } while(key != _QUIT_);
    
    printf("Goodbye!\n");
    return 0;                       // exit main (normal = 0)
}

/* Prompts the user and retrieves a valid input
 INPUT: the user supplies the valid prompt and range (min and max)
 OUTPUT: returns a valid user selection
 */
int GetInput(const char* msg, int min, int max) {
    int n = 0;
    do {
        printf("%s",msg);
        scanf("%d", &n);
        
        if(n >= min && n <= max)
            return n;
        else
            printf("*Invalid Input* ");
        
    } while(1);
    
    //return -1;
}

int GetMenuItem(const char *menu_title) {
    int i;
    
    printf("\n%s\n", menu_title);
    for (i=0; i<strlen(menu_title); i++)
    {
        printf("-");
    }
    printf("\n");
    
    for (i=0; i<MENU_COUNT; i++)
    {
        printf("%3d - %s\n", i+1, MENU[i]);
    }
    printf("%3d - QUIT\n", _QUIT_);
    
    return GetInput("Please enter a selection: ", 0, MENU_COUNT);
}


/* Recursive Versions */

/* Compute the sum of the first n positive integers
 INPUT: a positive integer n
 OUTPUT: returns the sum of 1+2+3+..+n
 */
int SumR(int n) {
    if (n <= 1)             // base case
        return 1;
    else                 // recursive call
        return SumR(n-1) + n;
}

/* Compute the sum of (i+1)^2 from i=0 to n
 INPUT: a positive integer n
 OUTPUT: returns the sum of (i+1)^2 from i=0 to n
 */
int SumR2(int n)
{
    if (n <= 0)             // base case
        return 0;
    else                 // recursive call
        return SumR2(n-1) + pow(n+1,2);
}

/* Compute the fibonacci number for n-Recursive
 INPUT: a positive integer n
 OUTPUT: returns the value of the fibonacci series: 1,1,2,3,5,...((n-1)+(n-2))
 */
int FibonacciR(int n)
{
    if (n <= 2)             // base case
        return 1;
    else                 // recursive call
        return FibonacciR(n-1) + FibonacciR(n-2);
}

/* Compute power(a,b) - Recursive
 INPUT: integers a (base) and b (exponent) - ASSUME b is POSITIVE
 OUTPUT: returns the value of a raised to the power of b
 */
long PowerR(int a, int b)
{
    if (b == 0)
        return 1;
    else
        return a * PowerR(a, b-1);
}

/* prints f(x,y) from lab
 INPUT: long integer x and y, positive
 OUTPUT: f(x,y) value
 */
long f(long x, long y) {
	if (x < 0 || y < 0)
		return x - y;
	return f(x-1, y) + f(x, y-1);
}


/* prints n downto 1
 INPUT: integer n, n>0
 OUTPUT: none
 SIDE EFFECTS: prints n down to 1
 */
void PrintR(int n) {
	for (; n > 0; --n)
		printf(" %d ", n);
}

/* prints * n times, used for triangles
 INPUT: integer n
 OUTPUT: none
 SIDE EFFECTS: prints n *s
 */
void PrintStars(int n) {
	if (n == 0) return;
	printf("*");
	PrintStars(n-1);
}

/* prints an inverted triangle
 INPUT: integer n, n>0
 OUTPUT: none
 SIDE EFFECTS: prints a triangle starting with n width
 */
void DrawTriangleInvertedR(int n) {
	if (n == 0) return;
    
	printf("  ");
	PrintStars(n);
	printf("\n");
    
	DrawTriangleInvertedR(n-1);
}

/* prints an triangle
 INPUT: integer n, n>0
 OUTPUT: none
 SIDE EFFECTS: prints a triangle starting
 with 1 width, up to n width
 */
void DrawTriangleR2(int i, int n); // helper function

void DrawTriangleR(int n) {
	DrawTriangleR2(1, n);
}

/* prints an triangle - helper function
 INPUT: integer n, n>0
 integer i, iterates up to and including n
 OUTPUT: none
 SIDE EFFECTS: prints a triangle starting
 with 1 width, up to n width
 */
void DrawTriangleR2(int i, int n) {
	if (i > n) return;
    
	printf("  ");
	PrintStars(i);
	printf("\n");
	
	DrawTriangleR2(i+1, n);
}

