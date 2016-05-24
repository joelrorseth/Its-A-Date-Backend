//
//  lab3_q3.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
int
main(void)
{
    int pal = 0;                            // declare int for palindrome test
    int holder = 0;                         // declare holder for test
    int hol1 = 0;                           // declare holder value for position 1
    int hol2 = 0;                           // declare holder value for position 2
    int hol3 = 0;                           // declare holder value for position 3
    int hol4 = 0;                           // declare holder value for position 4
    
    // prompt user for integer
    printf("%s", "Please enter a 4 or 5 digit integer palindrome: ");
    scanf("%d", &pal);
    
    // test for proper number integer
    
    if ((pal / 1000) == 0 || (pal / 100000) > 0)
        printf("%s", "Your entry is invalid!!!\n");
    
    // if answer is valid perform math to test for palindrome
    
    else
    {
        // save pal value before break into individual int
        holder = pal;
        // separate numbers and assign to variables
        hol1 = pal / 10000;
        pal %= 10000;
        hol2 = pal / 1000;
        pal %= 1000;
        hol3 = pal / 100;
        pal %= 100;
        hol4 = pal / 10;
        pal %= 10;
        
        // validate for palindrome 5 digit
        if ((holder / 10000) >=  1)
        {
            if (hol1 == pal && hol2 == hol4)
                printf("%d%d%d%d%d is a palindrome!\n", hol1, hol2, hol3, hol4, pal);
            else
                printf("%d%d%d%d%d is not a palindrome!\n", hol1, hol2, hol3, hol4, pal);
        }
        
        // validate for palindrome 4 digit
        
        else
        {
            if(hol2 == pal && hol3 == hol4)
                printf("%d%d%d%d is a palindrome!\n", hol2, hol3, hol4, pal);
            else
                printf("%d%d%d%d is not a palindrome!\n", hol2, hol3, hol4, pal);
        }
    }
    return 0;
}