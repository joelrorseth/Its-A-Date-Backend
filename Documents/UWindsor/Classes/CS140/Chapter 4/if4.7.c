//
//  if4.7.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int grade;                          // one grade
    unsigned int acount = 0;             // number of A's
    unsigned int bcount = 0;                // number of B's
    unsigned int ccount = 0;                // number of c's
    unsigned int dcount = 0;                // number of d's
    unsigned int fcount = 0;                // number of e's
    
    puts("Enter the letter of grades.");
    puts("Enter EOF character to end input.");
    
    // loop until EOF
    
    while ((grade = getchar()) != EOF)
    {
        if (grade == 'a' || grade == 'A')
            acount++;
        if (grade == 'b' || grade == 'B')
            bcount++;
        if (grade == 'c' || grade == 'C')
            ccount++;
        if (grade == 'd' || grade == 'D')
            dcount++;
        if (grade == 'f' || grade == 'F')
            fcount++;
        if( grade == '\n' || grade == '\t' )
            continue;
        if( grade == ' ')
            continue;
        if (grade > 'f' && grade < 'z')
        {
            printf("%s", "Incorrect letter grade entered. ");
            puts("Enter a new grade.");
        }
        if (grade > 'F' && grade < 'Z')
        {
            printf("%s", "Incorrect letter grade entered. ");
            puts("Enter a new grade.");
        }
        if (grade == 'e' || grade == 'E')
        {
            printf("%s", "Incorrect letter grade entered. ");
            puts("Enter a new grade.");
        }
    }
    puts("totals for grades are:");
    printf("%u A's\n", acount);
    printf("%u B's\n", bcount);
    printf("%u C's\n", ccount);
    printf("%u D's\n", dcount);
    printf("%u F's\n", fcount);
    
    return 0;
}