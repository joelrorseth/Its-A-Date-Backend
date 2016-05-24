//
//  search.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

size_t linearSearch(const int array[], int key, size_t size);
/*function: perform a linear search
 input: array, item to search for and size of array
 output: unsigned int, either key or -1 for unsucessful search*/

size_t linearSearch(const int array[], int key, size_t size)
{
    
    for (size_t n = 0; n <= SIZE; n++) {
        if (array [n] == key) {
            printf("%zdth element\n", n);
            return array [n];
        }
    }
    
    return -1;
    
}

int
main(void)
{
    int a[SIZE] = {0};          // create array a
    size_t x;                   // counter to initialize elements
    int searchkey = 0;          // value to locate in array a
    size_t element;             // variable to hold location of searchkey
    srand(time(NULL));
    
    
    //create the random array entries
    for (x = 0; x < SIZE; x++) {
        a[x] = rand() % 100 + 1;
    }
    
    puts("Enter integer Search Key: ");
    scanf("%d", &searchkey);
    
    // search element for searchkey
    element = linearSearch(a, searchkey, SIZE);
    
    if (element != -1) {
        printf("You found %zd in the array!\n", element);
        printf("You found %d in the array!\n", searchkey);
    }
    else
        puts("value not found.\n");
    
    return 0;
}


