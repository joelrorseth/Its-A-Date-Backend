//
//  charreview.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <string.h>
#define MAX 50

void upper(char array[MAX]);
void upper(char array[MAX])
{
    int x = 0;
    while (array[x] != '\0') {
        for(; x < strlen(array); x++)
            if (array[x] < 'a' || array[x] > 'z') {
            }
            else
                array[x] -= 32;
    }
}

void lower(char array[MAX]);
void lower(char array[MAX])
{
    int x = 0;
    while (array[x] != '\0') {
        for(; x < strlen(array); x++)
            if (array[x] < 'A' || array[x] > 'Z') {
            }
            else
                array[x] += 32;
    }
}

void compare(char array[MAX]);
void compare(char array[MAX])
{
    int z = strlen(array) - 1;
    int x = 0;
    while (x < z) {
        if (array[x] != array[z]) {
            printf("Array is not a Palindrome!\n");
            return;
        }
        x++;
        z--;
    }
    printf("Array is a Palindrome!\n");
}

void digit(char array[MAX]);
void digit(char array[MAX])
{
    
    
    
    
}

int
main(void)
{
    char string[MAX];
    char copy[MAX];
    int y = 0;
    
    printf("Please enter a string: ");
    //scanf("%49s", string);
    gets(string);
    
    strcpy(copy, string);
    
    do {
        printf("Options:\n1. All upper\n2. All lower\n3. Original\n4. Palindrome test\n5. Exit!\nChoice:");
        scanf("%d", &y);
        switch (y) {
            case 1:
                upper(string);
                printf("Changed!->\t%s\n\n", string);
                break;
            case 2:
                lower(string);
                printf("Changed!->\t%s\n\n", string);
                break;
            case 3:
                printf("Original!->\t%s\n\n", copy);
                break;
            case 4:
                lower(string);
                compare(string);
                break;
            case 5:
                digit(string);
                break;
            case 6:
                printf("Bye!\n");
                break;
            default:
                printf("INVALID!INVALID!INVALID!\n");
        }

    }while (y != 6);
    
    char A[] = "hello";
    char B[] = "hello";
    if (strcmp(A,B) == 0) {
        printf("Same\n");
    }
    else
        printf("Different\n");
    return 0;
}