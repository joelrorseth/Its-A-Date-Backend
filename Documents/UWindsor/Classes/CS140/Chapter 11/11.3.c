//
//  11.3.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int account;
    char name[30];
    double balance;
    
    FILE *cfPtr;
    
    if ((cfPtr = fopen("clients.dat", "w")) == NULL){
        puts("File could not be opened");
    }
    else {
        puts("Enter the account, name, and balance.");
        puts ("Enter EOF to end input.");
        printf("%s", "? ");
        scanf("%d%29s%lf", &account, name, &balance);
        
        while (!feof(stdin)){
            fprintf(cfPtr, "%d %s %.2f\n", account, name, balance);
            printf("%s", "? ");
            scanf("%d%29s%lf", &account, name, &balance);
        }
        
        fclose(cfPtr);
        
    }
    
    
    
    return 0;
}