/* PEARSON, Ryan
 *  ID: 103965059
 *  Lab Exercise #lab10_q1.c
 *  Date: April 2, 2013
 *  Purpose: working with chars and writing strlen function
 */

#include <stdio.h>
#include <ctype.h>
//#include <string.h>
#define SIZE 11

int checkvalid (char phone[SIZE],int *len);
/* Function: check size of string
 * Input: one char string
 * Output: one integer */
int checkvalid (char phone[SIZE],int *len)
{
    int x, test;
    for (x = 0; x < *len; x++){
        if(isdigit(phone[x]) == 0)
            return 0;
    }
    return 1;
}

int strlength (char *phone);
/* Function: return size of string
 * Input: one char string
 * Output: one integer */
int strlength (char *phone)
{
    int len = 0;
    while (*phone != '\0') {
        phone++;
        len++;
    }
    return len;
}

int
main(void)
{
    char phoneNumber[SIZE];
    int x, digits = 0, length = 0;
    
    printf("%s", "-Please enter a phone number: ");
    scanf("%10s", phoneNumber);
    
    length = strlength(phoneNumber);
    
    digits = checkvalid(phoneNumber, &length);
    
    if ((digits == 0 || length < 7) || (length == 8 || length == 9))
        puts("This is an invalid phone number, try again.");
    
    if ((length == 7 && digits == 1) || (length == 10 && digits == 1)){
        printf("%s", "You typed (raw): ");
        for( x = 0; x <= length; x++)
            printf("%c", phoneNumber[x]);
    }
    
    if (length == 7 && digits == 1) {
        printf("\n%s", "Formatted output: ");
        for (x = 0; x < 3; x++)
            printf("%c", phoneNumber[x]);
        printf("%s", "-");
        for (x = 3; x <= length; x++)
            printf("%c", phoneNumber[x]);
    }
    
    if (length == 10 && digits == 1) {
        printf("\n%s", "Formatted output: (");
        for (x = 0; x <= 2; x++)
            printf("%c", phoneNumber[x]);
        printf("%s", ") ");
        for (x = 3; x <= 5; x++)
            printf("%c", phoneNumber[x]);
        printf("%s", "-");
        for (x = 6; x <= length; x++)
            printf("%c", phoneNumber[x]);
    }
    puts("");
    return 0;
}
