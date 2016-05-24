//
//  lab4areview.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define MAX 50


int strindex(char s[], char t[]);

int
main(void)
{
    char string1[MAX];
    char string2[MAX];
    int pointer;
    
    printf("Please enter string 1: ");
    fgets(string1, MAX, stdin);
    
    printf("Please enter string 2: ");
    fgets(string2, MAX, stdin);
    
    printf("\n%s\n", string1);
    printf("%s\n", string2);
        
    ((strindex(string1, string2) != -1)) ?
    printf("Last occurance string 2 FOUND at element %d\n", strindex(string1, string2)):
           printf("Not found.\n");
    
    
    return 0;
}


/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    int far = -1;
    for(i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        if (k > 0 && t[k] == '\0')
            far = i;
    }
    if (far > -1) {
        return far;
    }
    return -1;
}