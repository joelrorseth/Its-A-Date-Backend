//
//  copy.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <string.h>
#define SIZE 10

void copy(char *str2, char *str);
void copy(char *str2, char *str)
{
    for (; (*str2 = *str) != '\0'; str++, str2++);
}

void reverse(char *str);
void reverse(char *str)
{
    int x = strlen(str) - 1;
    int y, holder;
    
    for (y = 0; y < x; y++) {
        holder = str[y];
        str[y] = str[x];
        str[x] = holder;
        x--;
    }
}

int
main(void)
{
    char string[] = "Helto!";
    char string2[SIZE];
    
    copy(string2, string);
    reverse(string);
    
    printf("%s\n", string2);
    printf("%s\n", string);
    return 0;
}