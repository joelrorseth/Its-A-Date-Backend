//
//  review6.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


void DisplayMenu();
void DisplayMenu()
{
    printf("ACTION LIST MENU\n ----------------\n");
    printf("1. Compute Factorial of n\n2. Compute Fibonacci of n\n3. Compute the Sum_Odd of n\n4. Exit\n");
}

void GetNumber(int *yptr);
void GetNumber(int *yptr)
{
    puts("");
    do{
        printf("Please enter an integer between 1 & 20: ");
        scanf("%d", &*yptr);
        
        if (*yptr < 1 || *yptr > 20) {
            printf("INVALID!INVALID!INVALID!\n");
        }
    }while (*yptr < 1 || *yptr > 20);
    puts("\n");
}

void MenuController(int *xptr);
void MenuController(int *xptr)
{
    int y = 0;
    GetNumber(&*xptr);
    DisplayMenu();
}

int ComputeFactorial(int xref);
int ComputeFactorial(int xref)
{
    int value = 1;
    while (xref >= 1) {
        value *= xref;
        xref--;
    }

    return value;
}

int ComputeFibonacci(int xref);
int ComputeFibonacci(int xref)
{
    int a = 0, b = 1, c = 0;
    
    if (xref == 1)
        return 1;
    else{
        while (xref != 1) {
            c = b + a;
            a = b;
            b = c;
            xref--;
        }
    }
    
    return c;
}

int Sum_Odd(int x);
int Sum_Odd(int x)
{
    int y = 1, sum = 0;
    
    while (y <= x) {
        sum += y;
        y += 2;
    }
    
    return sum;
}

int
main(void)
{
    int x = 0, choice = 0;
    MenuController(&x);
    do{
        printf("Please select one action from the above list? ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("%d\n", ComputeFactorial(x));
                break;
            case 2:
                printf("%d\n", ComputeFibonacci(x));
                break;
            case 3:
                printf("%d\n", Sum_Odd(x));
                break;
            case 4:
                break;
            default:
                printf("Your entry was invalid!\n");
        }
    }while (choice != 4);
    
    return 0;
}