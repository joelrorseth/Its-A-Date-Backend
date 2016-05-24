//
//  lab11.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <string.h>
#define SIZE 30

int isPalindrome(const char string[SIZE]);

int isPalindrome(const char string[SIZE])
{
    int x;
    char rev[SIZE]= "";
    int y = 0;
    for (x = strlen(string) - 1; x >= 0; x--) {
        rev[y] = string[x];
        y++;
    }
    
    if (strcmp(rev, string) == 0)
        return 1;
    else
        return 0;

}

void GeneratePermutations(int *nptr);

void GeneratePermutations(int *nptr)
{
    int x;
    int y = 1;
    for (x = 1; x <= *nptr; x++) {
        printf("%d\n", x);
    }
    while (y <= *nptr) {
        for (x = y; x <= *nptr; x++) {
            if (y != 0 && x != y)
                printf("%d%d\n",y, x);
        }
        y++;
    }
    for (x = 1; x <= *nptr; x++)
        printf("%d", x);
    puts("");
}

int
main(void)
{
    char s[SIZE] = "";
    int n = 0;
    
    scanf("%s", s);
    
    printf("%s %s%s\n", s,
           isPalindrome(s) ? "is a " : "is not a ", "palindrome.");
    
    printf("%s", "Please enter a number: ");
    scanf("%d", &n);
    
    GeneratePermutations(&n);
    
    return 0;
}