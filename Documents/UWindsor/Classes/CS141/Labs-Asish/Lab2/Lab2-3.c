//
//  Title: Lab2-3
//  Date: July 14, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: read 20 integers into an array of size 20 and return non duplicated values in order
//

#include <stdio.h>
#include "printarray.h"
#include "setArray.h"
#include "BinarySearch.h"
#include "InsertionSort.h"
#include "InsertionSortDescend.h"
#include "BinarySearchDescend.h"

#define SIZE 100
#define COUNT 20

int
main(void)
{
    int BA[COUNT], x, y;         // storage array, entry variable and counter
    int entry = 0;               // use to scan over proper size of array;
    int sort;                    // variable to determine sorting method
    
    set1dArray(BA, COUNT);       // assign all elements to zero 
    
    // prompt for sorting method
    do {
        printf("Please enter sorting method:\n1.Ascending\n2.Descending\nOption Selected:");
        scanf("%d", &sort);
    } while (sort < 1 || sort > 2);
    
    if (sort == 1){
        
        // loop once and set initial value. Avoid doing this check for remainder of loop
        do{
            printf("Please enter value %d between 0 and 99: ", 1);
            scanf("%d", &x);
        }while (x < 0 || x > SIZE);
        
        // set for initial entry to use this to catch if user enters all zeros
        if (entry == 0){
            BA[0] = x;
            entry++;
        }
        
        for (y = 1; y < COUNT; y++) {
            // prompt user for valid entry
            do{
                printf("Please enter value %d between 0 and 99: ", y+1);
                scanf("%d", &x);
            }while (x < 0 || x > SIZE);
            
            // check if element is in array, if not, then insert into array in proper order
            if (BinaryS(BA, &entry, x) == -1)
                InsertionS(BA, &entry, x);
        }
    }
    
    else{
        for (y = 0; y < COUNT; y++) {
            // prompt user for valid entry
            do{
                printf("Please enter value %d between 0 and 99: ", y+1);
                scanf("%d", &x);
            }while (x < 0 || x > SIZE);
            
            // set for initial entry to use this to catch if user enters all zeros
            if (entry == 0){
                BA[0] = x;
                entry++;
            }
            
            // check if element is in array, if not, then insert into array in proper order
            if (BinarySDES(BA, &entry, x) == -1)
                InsertionSDES(BA, &entry, x);
        }
    }
    
    Print1dArray(BA, entry, 0);                // return values stored in array
    return 0;
}