//
//  payscale.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int code = 0;                   // designate employee code
    double salary = 0;              // salary amount
    float hours = 0;                // hours amounta
    
    do
    {
    // ask user for employee code
    printf("Please provide employee code 1 thru 4,\n1. Manager\n2. Hourly\n3. Commission\n4. Piece-worker\n5. 5 to exit program\ncode: ");
    scanf("%d", &code);
    
    //use switch to follow proper pay scale and return value
    
    switch (code)
    {
        case 1:
            printf("What is salary rate for 1 week? ");
            scanf("%lf", &salary);
            printf("How many hours worked per week? ");
            scanf("%f", &hours);
            printf("Salary Pay 2 weeks:\t$%6.2lf\n", salary * 2);
            printf("Hours worked:\t\t%8.2lf\n\n", hours * 2);
            break;
        case 2:
            printf("What is the amount of pay per hour? ");
            scanf("%lf", &salary);
            printf("How many hours worked per 1 week? ");
            scanf("%f", &hours);
            if (hours < 40)
            {
                printf("Salary Pay 2 weeks:\t$%6.2lf\n", (salary * hours) * 2);
                printf("Hours worked:\t\t%8.2f\n\n", hours * 2);
            }
            else
            {
                printf("Salary Pay 2 weeks:\t$%6.2lf\n", (40 * salary + (1.5 * salary) * (hours - 40)) * 2);
                printf("Hours worked:\t\t%8.2f\n\n", hours * 2);
            }
            break;
        case 3:
            printf("How much money in sales did the commision worker earn in week 1: ");
            scanf("%lf", &salary);
            printf("How much money in sales did the commision worker earn in week 2: ");
            scanf("%f", &hours);
            printf("Salary per 2 weeks:\t$%6.2lf\n\n", ((salary + hours)* .057 * 2 + (250.0 * 2)));
            break;
        case 4:
            printf("Item manufactured rate: ");
            scanf("%lf", &salary);
            printf("How many items were made: ");
            scanf("%f", &hours);
            printf("Piece-worker commission: $%6.2lf\n\n", salary * hours);
            break;
        case 5:
            break;
            
        default:
            printf("Invalid code\n");
            break;
    }
    }while (code != 5);
    
    return 0;
}