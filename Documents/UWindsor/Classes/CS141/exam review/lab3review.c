//
//  lab3review.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 100


void sort(char*words[], int x);
void displayMenu();
void ascending(char *words[], int len);
void descending(char *words[], int len);
void lexmax(char *words[], int len);
void lexmin(char *words[], int len);
void maxlen(char *words[], int len);
void minlen(char *words[], int len);
void query(char *words[], int len);
void binary (char *words[], int len, char key[]);


int
main(void)
{
    char sentence[NUM];
    char *words[NUM];
    char *tokenptr;
    int x = 0, len, choice;
    char *temp;
    
    FILE* fptr;
    
    if ((fptr = fopen("Untitled.txt", "r")) == NULL) {
        printf("No file\n");
        return -1;
    }
    else{
        
        fgets(sentence, NUM, fptr);
        while (!feof(fptr)) {
            tokenptr = strtok(sentence, " " "," "." "/" "\n" "!");
            
            while (tokenptr != NULL) {
                temp = malloc(sizeof(tokenptr));
                temp = tokenptr;
                words[x] = malloc(sizeof(tokenptr));
                strcpy (words[x++], temp);
                tokenptr = strtok(NULL, " " "," "." "/" "\n" "!");
            }
            fgets(sentence, NUM, fptr);
        }
    }
    printf("%d- Number of words\n", x);
    sort(words, x);
    len = x;
    fclose(stdin);
    freopen("/dev/tty", "r", stdin);
    do{
        do{
            
            displayMenu();
            printf("Enter selection: ");
            if(!scanf("%d", &choice)== 1){printf("Invalid. Bye!\n"); return -1; }
        }while (choice < 1 || choice > 8);
        if (choice != 8)
            switch (choice) {
                case 1:
                    ascending(words, x);
                    break;
                case 2:
                    descending(words, x);
                    break;
                case 3:
                    lexmax(words, x);
                    break;
                case 4:
                    lexmin(words, x);
                    break;
                case 5:
                    maxlen(words, x);
                    break;
                case 6:
                    minlen(words, x);
                    break;
                case 7:
                    query(words, x);
                    break;
            }
    }while (choice != 8);
    
//    x = 0;
//    while (words[x] != NULL) {
//        printf("%s\n", words[x++]);
//    }
    return 0;
}


void sort(char*words[], int x)
{
    char *temp;
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < (x-1)-i; j++){
            if (strcmp(words[j], words[j+1]) > 0) {
                temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
            }
        }
    }
}

void displayMenu (void)
{
    puts("");
    char *menu[] = {
        "1.Sort Ascending",
        "2.Sort Descending",
        "3.Lex. Max",
        "4.Lex. Min",
        "5.Max Length",
        "6.Min Length",
        "7.Query",
        "8.Exit"
    };
    
    for (int x = 0; x < 8; x++) {
        printf("%s\n", menu[x]);
    }
}

void ascending(char *words[], int len)
{
    len = 0;
    while (words[len] != NULL) printf("%s\n", words[len++]);
}

void descending(char *words[], int len)
{
    len--;
    while (len >= 0) printf("%s\n", words[len--]);
}

void lexmax(char *words[], int len)
{
    printf("%s\n", words[len-1]);
}

void lexmin(char *words[], int len)
{
    printf("%s\n", words[0]);
}
void maxlen(char *words[], int len)
{
    int big = 0, biggest = 0, local;
    for(int x = 0; x < len; x++){
        big = strlen(words[x]);
        if (big > biggest) {
            biggest = big;
            local = x;
        }
    }
    
    printf("%s- size %d\n", words[local], biggest);
}
void minlen(char *words[], int len)
{
    int big = 100, biggest = 100, local;
    for(int x = 0; x < len; x++){
        big = strlen(words[x]);
        if (big < biggest) {
            biggest = big;
            local = x;
        }
    }
    
    printf("%s- size %d\n", words[local], biggest);
}

void query(char *words[], int len)
{
    char key[NUM];
    printf("Enter key word to search for: ");
    scanf ("%s", key);
    
    binary(words, len, key);  
}

void binary (char *words[], int len, char key[])
{
    int low = 0, high = len, mid;
    
    while (low <= high) {
        mid = (low + high)/2;
        if ((strcmp(words[mid], key)) > 0)
            high = mid-1;
        else if ((strcmp(words[mid], key)) < 0)
            low = mid +1;
        else{
            printf("Found %s in array!\n", key);
            return;
        }
    }
    printf("Did not find key in array.\n");    
}



