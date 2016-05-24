//
//  review5.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int Max(int *aptr, int *bptr);
int Max(int *aptr, int *bptr)
{
    if (*aptr > *bptr)
        return *aptr;
    else
        return *bptr;
    
}

int Sum(int a);
int Sum(int a)
{
    int total = 0;
    while (a != 0) {
        total += a;
        a--;
    }
    return total;
}

void drawsquare(int *xptr, char *sym);
void drawsquare(int *xptr, char *sym)
{
    int y, z;
    
    for (y = 0; y < *xptr; y++) {
        for (z = 0; z < *xptr; z++) {
            printf("%c ", *sym);
        }
        puts("");
    }
}


int
main(void)
{
    int a = 0, b = 0, c = 0, hold = 0;
    char symbol, dummy;
    
    printf("Please enter 2 integers: ");
    scanf("%d%d", &a, &b);
    
    printf("Max(%d, %d) has returned %d\n", a, b, Max(&a, &b));
    
    printf("Please enter 3 integers: ");
    scanf("%d%d%d", &a, &b, &c);
    
    hold = Max(&a, &b);
    printf("Max3(%d, %d, %d) has returned %d\n", a, b, c, Max(&hold, &c));
    
    printf("Please enter a postive integer n: ");
    scanf("%d", &a);
    b = a;
    printf("Sum(%d) = ", a);
    for (; a > 1; a--) {
        printf("%d+", a);
    }
    printf("1 = %d\n", Sum(b));
    
    printf("Please enter a size and character(no space in between): ");
    scanf("%d%c", &a, &symbol);
    
    drawsquare(&a, &symbol);
    return 0;
}