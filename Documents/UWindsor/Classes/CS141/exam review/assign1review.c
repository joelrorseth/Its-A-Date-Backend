//
//  assign1review.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int a = 0, b = 0, x, y, min, max;
    
    printf("Please enter a and b: ");       // prompt for and check valid entries
    if (!scanf("%d", &a)){printf("Invalid entry!!\n"); return -1;}
    if (!scanf("%d", &b)){printf("Invalid entry!!\n"); return -1;}
    
    // set min and max to save space
    if (a < b)  { min = a; max = b;}
    else        { min = b; max = a;}
    
    int arr[min +1];                    // create min +1 array
    
    arr[0] = 0;                         // set initial element
    
    for (x = 1; x < min + 1; x++)       // initialize first row
        arr[x] = arr[x-1] - (x+1);
    
    for (x = 1; x <= max; x++) {        // initialize rows after
        arr[0] = arr[0] + (x+1);
        for (y = 1; y <= min+1; y++)
            arr[y] = (arr[y] + arr[y-1]);
    }
    
    a < b ? printf("Element is: -%d!!!\n", arr[min]) : printf("Element is: %d!!!\n", arr[min]);
    return 0;
}