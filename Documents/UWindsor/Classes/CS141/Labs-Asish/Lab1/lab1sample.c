
/*
 Lab 1 iterative: Solution
 Writtten by: Ziad Kobti and Quazi Rahman
 Updated: July 2012.
 Updated 14 July 2013 by Jeffrey Drake
 */

/* includes */
#include <stdio.h>
#include <string.h>
#include <math.h>

#define _QUIT_ 0
#define _INFINITY_ 999999

/* Specifics for the interactive/dynamic menu */
const char *MENU[] = {  "Iterative Sum i",
    "Iterative Sum (i+1)^2",
    "Iterative Fibonacci",
    "Iterative Power",
    "Iterative Print(n)",
    "Iterative DrawTriangleInverted",
    "Iterative DrawTriangle"};

const int MENU_COUNT = 7;

/* prototypes */
int GetInput(const char* msg, int min, int max);
int GetMenuItem();

/* Iterative Versions */
int Sum(int n);
int Sum2(int n);
int Fibonacci(int n);
long Power(int a, int b);
void Print(int n);
void DrawTriangleInverted(int n);
void DrawTriangle(int n);


/* main program function */
int main() {
    int key;                   // stores the input from the user
    do {                        // Main program loop
        key = GetMenuItem("Lab 1 Iterative");      // Retreive a valid input selection from the user
        
        if (key != _QUIT_) {
            switch(key) {
                case 1:
                    printf("\nAnswer: %d\n", Sum(GetInput("Enter a positive Integer: ", 1, _INFINITY_)));
                    break;
                case 2:
                    printf("\nAnswer: %d\n", Sum2(GetInput("Enter a positive Integer: ", 1, _INFINITY_)));
                    break;
                case 3:
                    printf("\nAnswer: %d\n", Fibonacci(GetInput("Enter a positive Integer: ", 1, _INFINITY_)));
                    break;
                case 4:
                    printf("\nAnswer: %ld\n", Power(GetInput("Enter a positive Integer a: ", 0, _INFINITY_),
                                                    GetInput("Enter a positive Integer b: ", 0, _INFINITY_)));
                    break;
                case 5:
                    printf("\nAnswer:\n");
                    Print(GetInput("Enter a positive Integer n: ", 1, _INFINITY_));
                    break;
                case 6:
                    printf("\nAnswer:\n");
                    DrawTriangleInverted(GetInput("Enter a positive Integer n: ", 1, _INFINITY_));
                    break;
                case 7:
                    printf("\nAnswer:\n");
                    DrawTriangle(GetInput("Enter a positive Integer n: ", 1, _INFINITY_));
                    break;
            }
        }
    } while(key != _QUIT_);
    
    printf("Goodbye!\n");
    return 0;                       // exit main (normal = 0)
}

/* Interactive/Dynamic menu that displays the menu and retrieves a selection
 INPUT: requires MENU[], MENU_COUNT and _QUIT_ to be defined, uses int GetInput(const char* msg, int min, int max)
 OUTPUT: a valid menu item
 */
int GetMenuItem(const char *menu_title) {
    int i;
    
    printf("\n%s\n", menu_title);
    for (i=0; i<strlen(menu_title); i++) {
        printf("-");
    }
    printf("\n");
    
    for (i=0; i<MENU_COUNT; i++) {
        printf("%3d - %s\n", i+1, MENU[i]);
    }
    printf("%3d - QUIT\n", _QUIT_);
    
    return GetInput("\nPlease enter a selection: ", 0, MENU_COUNT);
}


/* Prompts the user and retrieves a valid input
 INPUT: the user supplies the valid prompt and range (min and max)
 OUTPUT: returns a valid user selection
 */
int GetInput(const char* msg, int min, int max) {
    int n = 0;
    do {
        printf("%s", msg);
        scanf("%d", &n);
        
        if(n >= min && n <= max)
            return n;
        else
            printf("\n*Invalid Input.*");
        
    } while(1);
    
    //return -1;
}



/* Iterative Versions */

/* Compute the sum of the first n positive integers
 INPUT: a positive integer n
 OUTPUT: returns the sum of 1+2+3+..+n
 */
int Sum(int n) {
    int i;              // counter
    int total = 0;      // accumulator
    
    for (i = 1; i <= n; i++) {
        total += i;
    }
    
    return total;
}

/* Compute the sum of (i+1)^2 from i=0 to n
 INPUT: a positive integer n
 OUTPUT: returns the sum of (i+1)^2 from i=0 to n
 */
int Sum2(int n) {
    int i;              // counter
    int total = 0;      // accumulator
    
    for (i = 1; i <= n; i++) {
        total += pow(i+1,2);
    }
    
    return total;
}


/* Compute the fibonacci number for n
 INPUT: a positive integer n
 OUTPUT: returns the value of the fibonacci series: 1,1,2,3,5,...((n-1)+(n-2))
 */
int Fibonacci(int n) {
    if ( n < 2 ) return n;
    
    int i;                   // counter
    int term_minus_2 = 0;    // temporary storage for i-2
    int term_minus_1 = 1;    // temporary storage for i-1
    int term;                // current fib value of sequence i
    
    // Note: this technique is bottom-up, it starts with the simplest values 1+1 and proceeds
    // to compute larger values from the previous two it calculated
    for (i = 2; i <= n; i++) {
        term = term_minus_1 + term_minus_2;
        term_minus_2 = term_minus_1;
        term_minus_1 = term;
    }
    
    return term;
}

/* Compute power(a,b)
 INPUT: integers a (base) and b (exponent)
 OUTPUT: returns the value of a raised to the power of b
 */
long Power(int a, int b) {
    if (b == 0) return 1;
    
    long total = 1;       // accumulator
    int i;                // counter
    
    for (i = 1; i <= b; i++) {
        total *= a;
    }
    
    return total;
}

/* prints n downto 1
 INPUT: integer n, n>0
 OUTPUT: none
 SIDE EFFECTS: prints n down to 1
 */
void Print(int n) {
	for (; n > 0; --n) {
		printf(" %d ", n);
	}
}

/* prints an inverted triangle
 INPUT: integer n, n>0
 OUTPUT: none
 SIDE EFFECTS: prints a triangle starting with n width
 */
void DrawTriangleInverted(int n) {
	for (; n > 0; --n) {
		printf("  ");
		for (int i = n; i > 0; --i) {
			printf("*");
		}
		printf("\n");
	}
}

/* prints an triangle
 INPUT: integer n, n>0
 OUTPUT: none
 SIDE EFFECTS: prints a triangle starting
 with 1 width, up to n width
 */
void DrawTriangle(int n) {
	for (int i = 1; i <= n; ++i) {
		printf("  ");
		for (int j = 0; j < i; ++j) {
			printf("*");
		}
		printf("\n");
	}
}