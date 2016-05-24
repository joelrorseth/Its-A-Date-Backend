//
//  lab2review.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define NUM 100
#define EFF 5

int binary (int AB[EFF], int * x, int count, int a);
void Insert (int AB[], int *x, int *count, int a);

int
main(void)
{
    int BA[NUM];
    int x, count = 5;
    
//    for (x = 0; x < NUM; x++)
//        BA[x] = 0;
//    
//    while (count-- > 0) {
//        printf("Please enter value: ");
//        scanf("%d", &x);
//        BA[x] = 1;
//    }
//    
//    for (x = 0; x < NUM; x++) {
//        if (BA[x] == 1)
//            printf("%d\n", x);
//    }
    
    int AB[EFF];
    count = 0;
    int y, i, aord;
    
    for (x = 0; x < EFF; x++)
        AB[x] = 0;

    do {
        printf("1. Ascending\n2.Descending\n");
        if (!scanf("%d", &aord) == 1) {printf("Invalid. Bye.\n"); return -1;}
    }while (aord < 1 || aord > 2);
    
    while (i++ < EFF) {
        printf("Please enter value: ");
        scanf("%d", &x);
        if (binary(AB, &x, count, aord) == -1)
            Insert(AB, &x, &count, aord);
    }
    for (x = 0; x < EFF; x++) {
        if (AB[x] != 0)
            printf("%d\n", AB[x]);
    }
    return 0;
}


int binary (int AB[EFF], int * x, int count, int a)
{
    int min = 0, max = count;
    int mid;
    if(a == 1){
    while (min <= max) {
        mid = (max + min)/2;
        if (*x < AB[mid])
            max = mid-1;
        else if (*x > AB[mid])
            min = mid +1;
        else
            return mid;
        }
    }
    else{
        while (min <= max) {
            mid = (max + min)/2;
            if (*x > AB[mid])
                max = mid-1;
            else if (*x < AB[mid])
                min = mid +1;
            else
                return mid;
        }
    }
    return -1;
}

void Insert (int AB[], int *x, int *count, int a)
{
    void swap(int *, int *);
    int temp;
    int k = *count;
    AB[k] = *x;
    *count += 1;
    if (a == 1){
        while (k > 0 && AB[k-1] > AB[k]) {
            swap(&AB[k-1], &AB[k]);
            k--;
        }
    }
    else{
        while (k > 0 && AB[k-1] < AB[k]) {
            swap(&AB[k-1], &AB[k]);
            k--;
        }
    }
    return;
}

void swap(int * ap, int *bp)
{
    int temp = *ap;
    *ap = *bp;
    *bp = temp;
}