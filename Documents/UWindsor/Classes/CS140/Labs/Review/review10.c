//
//  review10.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 10


int
main(void)
{
    char phoneNumber[SIZE];
    int x, len = 0, digit = 1;
    
    for (x = 0; x < SIZE; x++)  // initialize to zer0
        phoneNumber[x] = 0;
    
    printf("%s", "Please enter a phone number: ");
    scanf("%10s", phoneNumber);
    
    for (x = 0; x < (strlen(phoneNumber)-1); x++) {
        if (isdigit(phoneNumber[x]) == 0){
            digit = 0;
            break;
        }
    }
    
    if (strlen(phoneNumber) == 7 && digit == 1){
        printf("You typed (raw): %s\n", phoneNumber);
        printf("Formatted output: ");
        for (x = 0; x <=2; x++)
            printf("%c", phoneNumber[x]);
        printf("-");
        for (x = 3; x <= 6; x++) {
            printf("%c", phoneNumber[x]);
        }
        puts("");
    }
    
    else if (strlen(phoneNumber) == 10 && digit == 1){
        printf("You typed (raw): %s\n", phoneNumber);
        printf("Formatted output: ");
        for (x = 0; x <= 2; x++)
            printf("%c", phoneNumber[x]);
        printf("-");
        for (x = 3; x <= 5; x++) {
            printf("%c", phoneNumber[x]);
        }
        printf("-");
        for (x = 6; x <= 9; x++) {
            printf("%c", phoneNumber[x]);
        }
        puts("");
    }
    
    else
        printf("This is an invalid phone number, try again.\n");
    return 0;
}