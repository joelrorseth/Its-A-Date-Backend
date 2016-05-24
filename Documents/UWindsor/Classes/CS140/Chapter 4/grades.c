//
//  grades.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <math.h>

int
main(void)
{
    int grade;
    int acount = 0;
    int bcount = 0;
    int ccount = 0;
    int dcount = 0;
    int fcount = 0;
    
    puts("Enter the letter grades");
    puts("Enter the EOF character to end input.");
    
    while ( (grade = getchar()) != EOF)
    {
        switch (grade)
        {
            case 'A':
            case 'a':
                ++acount;
                break;
            case 'B':
            case 'b':
                ++bcount;
                break;
            case 'C':
            case 'c':
                ++ccount;
                break;
            case 'D':
            case 'd':
                ++dcount;
                break;
            case 'F':
            case 'f':
                ++fcount;
                break;
            case '\n':
            case '\t':
            case ' ':
                break;
                
            default:
                printf("%s", "Incorrect letter grade entered.");
                puts("Enter a new grade.");
                break;
        }
    }
    puts("\nThe totals for each letter grade are:");
    printf("A: %d\n", acount);
    printf("B: %d\n", bcount);
    printf("C: %d\n", ccount);
    printf("D: %d\n", dcount);
    printf("F: %d\n", fcount);
    
    float icount = acount + bcount + ccount + dcount + fcount;
    
    acount *= 8;
    bcount *= 7;
    ccount *= 6;
    dcount *= 5;
    fcount *= 4;
    
    float tcount = acount + bcount + ccount + dcount + fcount;
    printf("%.2f\n", (float)tcount);
    tcount /= icount;
    tcount = floorf(tcount * 100) / 100;
    grade = tcount;
  
    printf("%.2f\n", (float)tcount);
        
    switch (grade)
    {
        case (8):
            printf("You average is A\n");
            break;
        case (7):
            printf("You average is B\n");
            break;
        case (6):
            printf("You average is C\n");
            break;
        case (5):
            printf("You average is D\n");
            break;
        case (4):
            printf("You average sucks. Fail.\n");
            break;

    }
    return 0;
}