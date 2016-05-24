//
//  bisearch.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 15

size_t binarySearch(const int b[], int searchKey, size_t low, size_t high);
void printHeader(void);
void printRow(const int b[], size_t low, size_t mid, size_t high);


int
main(void)
{
    int a[SIZE];
    size_t i;
    int key;
    size_t result;
    
    // create data
    for (i = 0; i < SIZE; i++) {
        a[i] = 2 * i;
    }
    
    printf("%s", "Please enter a number between 0 and 28: ");
    scanf("%d", &key);
    
    printHeader();
    
    result = binarySearch(a, key, 0, SIZE -1);
    
    if (result != -1) {
        printf("\n%d found in array element %zd\n", key, result);
    }
    else
        printf("\n%d not found\n", key);
    
    return 0;
}


// function to perform search of an array
size_t binarySearch(const int b[], int searchKey, size_t low, size_t high)
{
    int middle;
    
    // loop until low subscript is higher than high subscript
    while (low <= high) {
        middle = (low + high) / 2;
        
        printRow(b, low, middle, high);
        
        if (searchKey == b[middle]) {
            return middle;
        }
        else if (searchKey < b[middle])
            high = middle -1;
        else
            low = middle +1;
        
    }
    return -1;
}

void printHeader(void)
{
    
    unsigned int i;
    
    puts ("\nSubscripts");
    
    for (i = 0; i < SIZE; i++) {
        printf("%3u ", i);
    }
    puts("");
    
    for (i = 1; i <= 4 * SIZE; i++) {
        printf("%s", "-");
    }
    puts("");
}

void printRow (const int b[], size_t low, size_t mid, size_t high)
{
    size_t i;
    
    for (i = 0; i < SIZE; i++) {
        if (i < low || i > high) {
            printf("%s", "    ");
        }
        else if( i == mid){
            printf("%3d*", b[i]);
        }
        else
            printf("%3d ", b[i]);
    }
    puts("");
    
}