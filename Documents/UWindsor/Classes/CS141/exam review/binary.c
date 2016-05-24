//
//  binary.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

int binary(int arax[10], int x);
void insertD (int aray[10]);
void insertA (int aray[10]);
void swap (int *, int *);

#include <stdio.h>

int
main(void)
{
    int x = 0, found;
    
    int arax[10] = { 1,2, 2, 4, 32 , 56 ,58 ,59 , 60, 61 };
    int aray[10] = {0};
    
    fprintf(stdin, "%s", "Enter number: ");
    if(!scanf("%d", &x)) {printf("Invalid Entry. Bye.\n"); return -1; }
    
    if ((found = binary(arax, x)) != -1)
        puts("Fucking found that bitch!\n");
    else
        puts("Did not find\n");
    int y = 0;
    for (x = 0; x < 10; x++)
        printf("%d ", aray[x]);
    puts("");
    
    for (x = 0; x < 10; x++)
        aray[x] = arax[x];
    for (x = 0; x < 10; x++)
        printf("%d ", aray[x]);
    puts("");
    
    insertD(aray);
    for (x = 0; x < 10; x++)
        printf("%d ", aray[x]);
    puts("");
    
    printf("And Back!\n");
    
    insertA(aray);
    for (x = 0; x < 10; x++)
        printf("%d ", aray[x]);
    puts("");
    
    return 0;
}


int binary(int arax[10], int x)
{
    int low = 0, high = 10;
    int mid;
    
    while (low <= high) {
        mid = (low + high)/2;
        if (x < arax[mid])
            high = mid -1;
        else if (x > arax[mid])
            low = mid +1;
        else
            return x;
    }

    return -1;
}

void insertD (int aray[10])
{
    int i = 1;
    int j;
    while (i <= 9) {
        j = i;
        while (j > 0 && aray[j-1] < aray[j]) {
            swap(&aray[j], &aray[j-1]);
            j--;
        }
        i++;
    }
    return;
}

void insertA (int aray[10])
{
    int i = 1;
    int j;

    while (i <= 9) {
        j = i;
        while (j > 0 && aray[j-1] > aray[j]) {
            swap(&aray[j], &aray[j-1]);
            j--;
        }
        i++;
    }
    return;
}

void swap (int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    
    
}