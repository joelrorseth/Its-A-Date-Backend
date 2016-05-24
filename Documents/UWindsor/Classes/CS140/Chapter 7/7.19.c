//
//  7.19.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 80

void test (char *s1,  char *s2);

void test (char *s1,  char *s2)
{
    if (*s2 > *s1)
    {
        while (*s2 != '\0') {
            ++s2;
        }
        for (; (*s2 = *s1); ++s1, ++s2) {
            ;
        }
    }
    else
    {
        while (*s1 != '\0') {
            ++s1;
        }
        for (; (*s1 = *s2); ++s2, ++s1) {
            ;
        }
    }
}

int
main(void)
{
    char string1[SIZE];
    char string2[SIZE];
    
    puts("Enter two strings: ");
    scanf("%79s%79s", string1, string2);
    test(string1, string2);
    printf("String 1 - %s\n", string1);
    printf("String 2 - %s\n", string2);
    
    return 0;
}