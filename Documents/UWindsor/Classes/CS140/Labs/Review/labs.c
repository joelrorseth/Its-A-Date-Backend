//
//  labs.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <math.h>
#define SIZE 20

void drawline();
void drawline()
{
    printf("+");
    for (int x = 0; x < SIZE * 2; x++)
        printf("-");
    printf("+\n");
}
int
main(void)
{
    char name[SIZE];
    char dummy;
    
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello %s, how are you?\nI hope you feel 100%% today!\n", name);
    
    int num1 = 0;
    
    printf("Please enter a positive integer: ");
    scanf("%d", &num1);
    printf("The quotient of %d/3 is: %d\nThe remainder of %d/3 is (%d%%3): %d\n", num1, num1/3, num1, num1, num1 % 3);
    
    printf("\n\ncs140, W2013, lecture schedule:\n");
    drawline();
    printf("Day\t\tStart time\tEnd time\n");
    drawline();
    printf("Tuesday\t\t4:00 pm\t\t5:20 pm\nThursday\t4:00 pm\t\t5:20 pm\n");
    drawline();
    
    float num2= 0;
    
    printf("Please enter a number with decimal digits: ");
    scanf("%f", &num2);
    
    printf("The rounded value to 2 decimals digits is: %.2f\n", num2);
    printf("Round way 2: %f\n", floor(num2* 100 + .5)/ 100);
    
    int x = 0, y = 0, z = 0;
    printf("Please enter 3 integers: ");
    scanf("%d%d%d", &x, &y, &z);
    printf("Their sum is: %d\n", x + y + z);
    printf("Their average is: %.2f\n", (float)(x + y + z)/3);
    
    printf("Please enter a value for integer x: ");
    scanf("%d", &x);
    printf("f(x) = %d\n", (-2 * x + 5));
    printf("g(x) = %d\n", (int)(pow(x, 3))+ (2 * x - 4));
    printf("h(x) = %.2f\n", (float)(3 * x + 2)/(2 * x - 4));
    
    int cel = 0, far = 0;
    printf("Please enter a temperature in Celsius: ");
    scanf("%d", &cel);
    printf("%d Celsius = %d Fahrenheit\n", cel, (int)(cel*1.8+32));
    printf("Please enter a temperature in Fahrenheit: ");
    scanf("%d", &far);
    printf("%d Fahrenheit = %d Celsius\n", far, (int)((far-32)/1.8));
    
    printf("'80/100' looks like \"80%%\" that's about $80.00\n");
    
    return 0;
}