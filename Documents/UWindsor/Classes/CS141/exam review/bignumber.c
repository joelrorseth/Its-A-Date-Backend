//
//  bignumber.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define MAX 10

struct bigNumber{
    char digit[MAX];
};

typedef struct bigNumber Big;

void Shift_Big( Big N1, Big *N2, int r);

int
main(void)
{
    //Big N1 = { '2', '0', '5', '7', '3', '1', '4', '0', '9', '1'};
    Big N1 = { "HelloWorl" };
    Big N2;
    int R = 4;
    Shift_Big(N1, &N2, R);
        puts("\nOriginal!");
    for (R = 0; R < 10; R++)
        printf("%c\n", N1.digit[R]);
    puts("\nChanged!");
    for (R = 0; R < 10; R++)
        printf("%c\n", N2.digit[R]);
    
    return 0;
}

void Shift_Big( Big N1, Big *N2, int r)
{
    
    for (int x = 0; x < MAX; x++) {
        if ((x + r) >= 10)
            N2->digit[x] = N1.digit[(x+4)%10];
        else
            N2->digit[x] = N1.digit[x+4];
    }
    
}