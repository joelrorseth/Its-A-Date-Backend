//
//  examples.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <string.h>

void check(const char A[], int* num);

void check(const char A[], int* num)
{
    int i = 0;
    while (A[i] != '\0') {
        i++;
        *num += 1;
    }
}

int
main(void)
{
    /*char A[] = "This is a sentence.";
    int number = 0;
    
    check(A, &number);
    
    for (int x = 0; x < number; x++) {
        printf("%c ", A[x]);
    }
    printf("%s\n", A);
    printf("%d\n", number);
    
    char buffer[15];
    char password[] = "secret";
    int p = 0;
    int match = 1;
    printf("What is the password: ");
    gets(buffer);
    printf("\n%s\n", buffer);
    while (password[p] != '\0') {
        if (password[p] != buffer[p]) {
            match = 0;
        }
        p++;
    }
    
    if (match == 1)
        puts("Welcome to the program.");
    else
        puts("Give it another try hotshot.");
    
    if (match == 1) {
        char B[20] = {'H','e','l','l','o',' ', '\0'};
        char C[] = "there";
        char yes[2];
        strcat(B, C);
        
        printf("A = %s\nB = %s\n", B, C);
        
        char *D = "Hello";
        char E[10];
        printf("What am i thinking... hint-say Hi the long way\n");
        printf("or would you like me to do it? y or n ");
        scanf ("%1s", yes);
        if (yes[0] == 'y')
            strcpy(E, D);
        else if (yes[0] == 'n')
            scanf("%9s", E);
        
        if (strcmp(E, D) == 0)
            printf("Same as my string!\n");
        else
            printf("Incorrect\n");
        
        char *H = "Hello World!";
        char *pH = H;
        int count = 0;
        do {
            pH = strchr(pH, 'l');
                if (pH != '\0')
                {
                    count++;
                    pH += 1;
                }
        } while (pH != NULL);
        printf("\n%d\n", count);
        printf("%s\n", H);
        printf("%s\n", pH);
        
    }
    
    char X[] = "HHi HMy HName, HIs HRyan";
    char *Xptr = X;
    
    //Xptr += 6;
    printf("%s\n", Xptr);
    printf("%c\n", X[6]);
    
    Xptr = strtok(X, "H");
    
    while (Xptr != NULL) {
        
        printf("%s\n", Xptr);
        Xptr = strtok(NULL, "a");
    }
    printf("%p\n\n\n", &Xptr);*/
    
    char string[10] = "Hi the!";
    char string1[10];
    
    memcpy(string1, string, 10);
    
    printf("%s\n", string1);
    return 0;
}