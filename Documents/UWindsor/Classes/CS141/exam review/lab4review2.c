//
//  lab4review2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 1000

typedef struct key{
    char *word;
    int count;
    struct key *nextNode;
}Key;

typedef Key *KeyPtr;

Key* addnode (Key *, char *);


int
main(void)
{
    char line[SIZE];
    char *word;
    KeyPtr start = NULL;
    KeyPtr printing = NULL;
    
    //FILE *fptr;
    
    fgets(line, SIZE, stdin);
    
    word = strtok(line, " " "," "\n" "\t" "1" "2" "3" "4" "5" "6" "7" "8" "9" "0" "!" "@" "#" "$" "%" "^" "&" "*");
    while (word != NULL) {
        //printf("%s\n", word);
        start = addnode(start, word);
            word = strtok(NULL, " " "," "\n" "\t" "1" "2" "3" "4" "5" "6" "7" "8" "9" "0" "!" "@" "#" "$" "%" "^" "&" "*");
    }
    
    printing = start;
    
    while (printing != NULL) {
        printf("%-10s%5d\n", printing->word, printing->count);
        printing = printing->nextNode;
    }
}


Key* addnode (Key *start, char *Word)
{
    KeyPtr previous = NULL, current = NULL, temp;
    
    temp = malloc(sizeof (Key));
    temp->word = malloc(sizeof(Word));
    temp->word = Word;
    temp->count = 1;
    temp->nextNode= NULL;
    
    if (start == NULL){
        printf("Exit Loop-1\n");
        return temp;
    }
    current = start;
    int condition = strcmp(Word, current->word);
    
    
    while (current != NULL && condition > 0) {
        previous = current;
        current = current->nextNode;
    }
    
    if (previous == NULL){
        temp->nextNode = current;
        return temp;
    }
    else if(current == NULL && condition > 0){
        previous->nextNode = temp;
    }
    else{
        temp->nextNode = current;
        previous->nextNode = temp;
    }

    return start;
}