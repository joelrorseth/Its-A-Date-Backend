//
//  review7.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MIN 1
#define MAX 10

void PrintArray(int array[MAX]);
void PrintArray(int array[MAX])
{
    printf("A=[");
    for (int x = 0; x <= MAX-2; x++)
        printf("%d,", array[x]);
    printf("%d]\n", array[MAX - 1]);
}

void GetNumber(int *yptr);
void GetNumber(int *yptr)
{
    puts("");
    do{
        printf("Please enter an integer between 1 & 10: ");
        scanf("%d", &*yptr);
        
        if (*yptr < MIN || *yptr > MAX) {
            printf("INVALID!INVALID!INVALID!\n");
        }
    }while (*yptr < MIN || *yptr > MAX);
    puts("\n");
}

void InitArray(int array[MAX], int *yptr);
void InitArray(int array[MAX], int *yptr)
{
    for (int x = 0; x < MAX; x++)
        array[x] = *yptr;
}

void PopulateArray(int array[MAX]);
void PopulateArray(int array[MAX])
{
    for (int x = 0; x < MAX; x++)
        array[x] = rand() % MAX + 1;
}

void Sort(int array[MAX]);
void Sort(int array[MAX])
{
    int check, temp;
    for (int x = 0; x < MAX; x++) {
        check = 0;
        for (int z = 0; z < MAX-1; z++) {
            if (array[z] > array[z+1]) {
                temp = array[z];
                array[z] = array[z+1];
                array[z + 1] = temp;
                check++;
            }
        }
        if (check == 0)
            return;
    }
}

void SearchArray(int array[MAX], int *yptr);
void SearchArray(int array[MAX], int *yptr)
{
    int counter = 0, occurance = 0;
    char response, dummy;
    
    do {
        counter = 0;
        do {
            printf("Please enter a key between %d and %d: ", MIN, MAX);
            scanf("%d", &*yptr);
        }while (*yptr < MIN || *yptr > MAX);
        for (int x = 0; x < MAX; x++) {
            if (*yptr == array[x])
                counter++;
        }
        
        if (counter < 1)
            printf("No occurance found for value %d in the array!\n", *yptr);
        else {
            printf("%d occurance%s found for value %d in the array!\n", counter, (counter > 1) ? "s" : "" , *yptr);
        }
        
        if (counter >= 1) {
            for (int x = 0; x < MAX; x++) {
                if (*yptr == array[x]) {
                    printf("The first occurance takes place in element %d of the array.\n", x);
                    break;
                }
            }
        }
        
        printf("Do you want to search for more keys?");
        scanf("%c%c", &dummy, &response);
        if (response == 'n' || response == 'N')
            printf("Goodbye!\n");
        
    }while (response == 'Y' || response == 'y');
}

void BinarySearch(int array[MAX], int *yptr);
void BinarySearch(int array[MAX], int *yptr)
{
    do {
        printf("Please enter a key between %d and %d: ", MIN, MAX);
        scanf("%d", &*yptr);
    }while (*yptr < MIN || *yptr > MAX);

    int min = 0;
    int max = MAX;
    int middle;
    while (min <= max) {
        middle = (min + max)/2;
        if (*yptr == array[middle]){
            printf("Key %d is found first at element %d!\n", *yptr, middle);
                do {
                    if (*yptr == array[middle -1] && middle != 0) {
                        middle -= 1;
                    }
                    
                }while (*yptr == array[middle -1] && middle != 0);
                if (*yptr == array[middle +1]) {
                    printf("And the first occurance of key %d is element %d!\n", *yptr, middle);
                    return;
                }
        }
        else if (*yptr <= array[middle])
            max = middle - 1;
        else
            min = middle + 1;
    }
    printf("No Key.\n");
}

int
main(void)
{
    int A[MAX];
    int y = 0;
    srand(time(NULL));
    
    InitArray(A, &y);
    PrintArray(A);
    GetNumber(&y);
    InitArray(A, &y);
    PrintArray(A);
    PopulateArray(A);
    PrintArray(A);
    printf("Binary (2) or Bubble (1) sort: ");
    scanf("%d", &y);
    if (y == 1) {
        Sort(A);
        PrintArray(A);
        SearchArray(A, &y);
    }
    else if (y == 2){
        Sort(A);
        PrintArray(A);
        BinarySearch(A, &y);
    }
    else
        printf("What are you talking about!?!\n");
    return 0;
}