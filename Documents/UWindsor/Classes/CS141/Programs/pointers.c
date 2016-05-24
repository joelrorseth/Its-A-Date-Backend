//
//  pointers.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 4

// prototypes
void bubble (int work[], size_t size, int (*compare) (int a, int b));
int ascending (int a, int b);
int descending (int a, int b);

int
main(void)
{
    int order;
    size_t counter;
    
    
    int a[SIZE] = {0};
    
    printf("%s", "Enter 1 to sort in ascending order,\n"
           "Enter 2 to sort in descending order: ");
    scanf("%d", &order);
    
    for (int x = 0; x < SIZE; x++){
        do {
            printf("Enter value %d: ", x +1);
            scanf("%d", &a[x]);
        } while (a[x] < 0);
    }
    
    puts("\nData items in original order");
    
    for (counter = 0; counter < SIZE; ++counter)
        printf("%5d", a[counter]);
    
    if (order == 1){
        bubble (a, SIZE, ascending);
        puts("\nData items in ascending order");
    }
    else {
        bubble (a, SIZE, descending);
        puts("\nData items in descending order");
    }
    
    for (counter =0; counter < SIZE; ++counter)
        printf("%5d", a[counter]);
    
    puts("");
    
    return 0;
}

void bubble (int work [], size_t size, int (*compare)(int a, int b))
{
    unsigned int pass;
    size_t count;
    
    void swap (int *element1Ptr, int *element2Ptr);
    
    for (pass = 1; pass < size; ++pass) {
        for (count = 0; count < size-1; ++count) {
            if ((*compare)(work[count], work[count +1]))
                swap(&work[count], &work[count+1]);
        }
    }
}

void swap (int *element1Ptr, int *element2Ptr)
{
    printf("Swap!\n");
    int hold;
    hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}

int ascending (int a, int b)
{
    printf("\n%d- a, %d- b\n", a, b);
    printf("%d\n", b < a);
    return b < a;
}

int descending (int a, int b)
{
    printf("%d- a, %d- b\n", a, b);
    printf("%d\n", b > a);
    return b > a;
}