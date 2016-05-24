//
//  strings.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <string.h>
#define SIZE 145

int
main(void)
{
    char string1[SIZE];
    char string2[100]= "Hi I'm Ryan!";
    char string3[100] = "What is your name?";
    char string4[SIZE] = "What is your namen?";
    char find;
    char dummy;
    
    int b = strcmp(string3, string4);
    
    if (b == 0)
        printf("Strings equal!\n");
    else
        printf("Not equal\n");
    printf("\n1%s\n", strcat(string1, string2));
    printf("4 into 3%s\n", strcat(string3, string4));
    printf("2 into 3%s\n", strcat(string3, string2));
    printf("3 into 4%s\n\n", strcat(string4, string3));
    
    printf("Enter Character: ");
    scanf("%c%c", &find, &dummy);
    
    printf("Length of string 2 is %zd\n", strlen(string2));
    
    char *sptr = string3;
    int count = 0;
    
    do{
        sptr = strchr(sptr, find);
        if (sptr != '\0')
        {
            count++;
            sptr += 1;
        }
    }while (sptr != NULL);
    
    printf("%c occurs %d time%s in the string.\n", find, count, (count > 1 ? "s" : "" ));
    
    return 0;
}