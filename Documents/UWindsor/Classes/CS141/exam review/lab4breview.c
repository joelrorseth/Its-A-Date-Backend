//
//  lab4breview.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct li{
    char *word;
    int freq;
}List;

List listing[MAX];

int
main(void)
{
    char line[MAX];
    int count = 0, y, check, add = 0;          // index of array
    char *tkptr, *temp, *compare;
    FILE * fptr;
    
    for (; count < MAX; count++) {
        listing[count].word = NULL;
        listing[count].freq = 0;
    }
    
    count = 0;
    
    if ((fptr = fopen("words.txt", "r")) == NULL) {
        printf("No File.\n");
        return -1;
    }
    else{
        while (!feof(fptr)) {
            fgets(line, MAX, fptr);
            tkptr = strtok(line, " ,?\n\t.!");
            while (tkptr != NULL) {
                temp = malloc(sizeof(tkptr));
                temp = tkptr;
                y= 0;
                check = 0;
                tkptr = strtok(NULL, " ,?\n\t.!");
                if (count != 0){
                    for(;y < count; y++) {
                        if ((strcmp(listing[y].word, temp) == 0)) {
                            //printf("Match and increasing Frequency\n");
                            listing[y].freq+=1;
                            check = -1;
                        }
                    }
                }
                if (check != -1) {
                    listing[count].word = malloc(sizeof(tkptr));
                    strcpy (listing[count].word, temp);
                    listing[count].freq += 1;
                    count++;
                }
            }
        }
    }
    
    printf("\nFrom Struct array:\n");
    y = 0;
    while (y++ < count) {
            printf("%s\t%d\n", listing[y-1].word, listing[y-1].freq);
    }
    
    puts("");
    return 0;
}