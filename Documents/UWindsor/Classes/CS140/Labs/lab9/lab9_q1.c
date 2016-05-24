/* PEARSON, Ryan
 *  ID: 103965059
 *  Lab Exercise #lab9_q1.c
 *  Date: March 26, 2013
 *  Purpose: explain pointers
 */

#include <stdio.h>

int
main(void)
{
    int a = 7;                      //declare variable a
    int *aPtr;                      //declare aPtr as a pointer to an int
    aPtr = &a;                      //assign aPtr to the address of a
    printf("%p\n", &a);             // give location of a in memory
    printf("%p\n", aPtr);           // give location in memory where aPtr points
    printf("%p\n", &aPtr);          // give location in memory of aPtr
    printf("%d\n", a);              // give value of a
    printf("%d\n", *aPtr);          // give value of what aPtr points to
    printf("%p\n", *&aPtr);         // give location of where aPtr points
    printf("%p\n", &*aPtr);         // give location of where aPtr points
    printf("%d\n", *&a);            // point to address of a & give value
    //printf("%d\n", &*a);          // nothing, there is no *a looking to multiply
    
    return 0;
}