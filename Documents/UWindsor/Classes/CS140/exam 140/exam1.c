//
//  exam1.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

//0 1 2 3 4 5
//n 0 p 1 j 0



#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 10

int
main(void)
{
    char postal[SIZE];
    int x = 0;
    
    printf("Please enter a postal code: ");
    scanf("%s", postal);
    
    if (strlen(postal) < 6 || strlen(postal) > 7)
        return 1;
    
    if (strlen(postal) == 6) {
        if (isalpha(postal[0]) == 0 || isalpha(postal[2]) == 0 || isalpha(postal[4]) == 0)
            return 1;
        if (isdigit(postal[1]) == 0 || isdigit(postal[3]) == 0 || isdigit(postal[5]) == 0)
            return 1;
        if (isupper(postal[0]) == 0 || isupper(postal[2]) == 0 || isupper(postal[4]) == 0)
            return 1;
    }
    
    else if (strlen(postal) == 7) {
        if (postal[3] != '-')
            return 1;
        if (isalpha(postal[0]) == 0 || isalpha(postal[2]) == 0 || isalpha(postal[5]) == 0)
            return 1;
        if (isdigit(postal[1]) == 0 || isdigit(postal[4]) == 0 || isdigit(postal[6]) == 0)
            return 1;
        if (isupper(postal[0]) == 0 || isupper(postal[2]) == 0 || isupper(postal[5]) == 0)
            return 1;
    }
    
    printf("Valid\n");
    
    return 0;
}