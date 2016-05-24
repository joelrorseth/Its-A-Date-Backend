//
//  output.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>
struct demo {
    int num1;
    int num2;
    struct demo *ptrNext;
};
void main() {
    int N[]={2,8,2,7,9,-1};
    int M[]={1,2,3,4,5,6};
    int n=0;
    struct demo *ptrTemp=NULL;
    struct demo *ptrLast=NULL;
    struct demo *ptrFirst=NULL;
    while (N[n]!=-1) {
        ptrTemp = (struct demo*)(malloc(sizeof(struct demo)));
        ptrTemp->num1 = N[n];
        ptrTemp->num2 = M[n];
        ptrTemp->ptrNext = NULL;
        if (n==0) {
            ptrFirst = ptrTemp;
            ptrLast = ptrTemp;
        }
        else {
            if (ptrTemp->num1 >= ptrLast->num2) {
                ptrLast->ptrNext = ptrTemp;
                ptrLast = ptrTemp;
            }
            else {
                ptrTemp->ptrNext = ptrFirst;
                ptrFirst = ptrTemp;
            }
        }
        n++;
    }
    ptrTemp = ptrFirst;
    n = 0;
    while(ptrFirst != NULL) {
        printf("%d: %d %d\n", n, ptrTemp->num1, ptrTemp->num2);
        ptrTemp = ptrFirst->ptrNext;
        free(ptrFirst);
        ptrFirst = ptrTemp;
        n++;
    }
}
