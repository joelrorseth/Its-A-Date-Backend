//
//  lab1review.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <math.h>

void DisplayMenu(void);
int Sum (int);
int SumSq (int);
int Fibonacci (int);
int function(int, int);
int power(int, int);
void Countdown(int);
void drawline(int);
void Inverted (int);
void Triangle (int, int);


int
main(void)
{
    int choice, a, b = 0;
    int (*Function[4])(int a) = {Sum, SumSq, Fibonacci};
    
    do {
        DisplayMenu();
        printf("Please enter your choice: ");
        if(!scanf("%d", &choice)){
            printf("Invalid Choice\n");
            fclose(stdin);
            freopen("/dev/tty", "r", stdin);
        }
        switch (choice) {
            case 1:
                printf("Please enter your integer: ");
                scanf("%d", &a);
                printf("Sum is %d\n", Function[choice-1](a));
                break;
            case 2:
                printf("Please enter your integer: ");
                scanf("%d", &a);
                printf("Sum of (x+1)^2 is %d\n", Function[choice -1](a + 1));
                break;
            case 3:
                printf("Please enter your integer: ");
                scanf("%d", &a);
                printf("Fibonacci %d\n", Function[choice -1](a));
                break;
            case 4:
                printf("Please enter your integer: ");
                scanf("%d", &a);
                printf("Please enter your 2nd integer: ");
                scanf("%d", &b);
                printf("Function %d\n", function(a, b));
                break;
            case 5:
                printf("Please enter your integer: ");
                scanf("%d", &a);
                printf("Please enter your 2nd integer: ");
                scanf("%d", &b);
                printf("Power %d\n", power(a, b));
                break;
            case 6:
                printf("Please enter your integer: ");
                scanf("%d", &a);
                printf("Countdown\n");
                Countdown(a);
            case 7:
                printf("Please enter your integer: ");
                scanf("%d", &a);
                printf("Inverted Triangle!\n");
                Inverted(a);
                break;
            case 8:
                printf("Please enter your integer: ");
                scanf("%d", &a);
                printf("Triangle!\n");
                Triangle(a, 1);
                break;
            default:
                break;
        }
    } while (choice != 9);
    return 0;
}

void DisplayMenu(void)
{
    const char *display[9] = {
        "1. Compute Sum",
        "2. Compute Sum i+1^2",
        "3. Compute Fibonacci",
        "4. Function compute",
        "5. Compute a^b",
        "6. Print Countdown from n",
        "7. Draw Inverted Triangle",
        "8. Draw Triangle",
        "9. Exit"
    };
    puts("");
    for (int x = 0;x < 9; x++) {
        printf("%s\n", display[x]);
    }
    puts("");
}

int Sum(int a)
{
    if (a == 1)
        return 1;
    else
        return a + Sum(a-1);
}

int SumSq(int a)
{
    if (a == 1)
        return 1;
    else
        return pow(a,2) + SumSq(a-1);
}

int Fibonacci(int a)
{
    if (a == 0)
        return 0;
    else if (a == 1)
        return 1;
    else
        return Fibonacci(a-1) + Fibonacci(a -2);

}
int function(int a, int b)
{
    if (a < 0 || b < 0)
        return a-b;
    else
        return function(a-1, b) + function(a, b-1);
}

int power(int a, int b)
{
    if (b == 1)
        return a;
    else
        return a * power(a, b-1);
}

void Countdown(int a)
{
    if (a == 1)
        printf("%d\n", a);
    else{
        printf("%d\n", a);
        return Countdown (a-1);
    }
}

void Inverted (int a)
{

    if (a == 1)
        return drawline(1);
    else{
        drawline(a);
        return Inverted(a-1);
    }
    
}

void Triangle(int a, int c)
{
    if (c == a)
        return drawline(c);
    else{
        drawline(c);
        return Triangle(a, c+1);
    }
}

void drawline(int a)
{
    if (a == 1){
        printf("*\n");
        return;
    }
    else{
        printf("*");
        return drawline(a-1);
    }
}