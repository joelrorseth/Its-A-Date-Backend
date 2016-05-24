//
//  array5.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 20

int
main(void)
{
    
    char s1[SIZE]= {0};                          // string array by size
    char s2[]= "Name is Ryan";                // string literal
    
    printf("Please enter string: ");
    scanf("%19s", s1);
    
    printf("You typed in prior to breaks: %s\n\n", s1);
    
    for (size_t i = 0; i < 13 && s2 != '\0'; i++) {
        printf("%c ", s2[i]);
        //if (i % 2 == 0)
          //  puts("");
    }
    puts("");
    
    return 0;
}