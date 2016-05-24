//
//  Title: Lab2-2
//  Date: July 14, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: Provided program to demostrate pointers
//

#include <stdio.h>

int
main(void)
{
    int x = 1, y = 2, z[10];
    int *ip;    // ip is a pointer to int
    
    ip = &x;    // ip now points to x
    printf("The address of the variable x that ip points to is: %p\n", ip);
    
    y = *ip;
    printf("The value of the variable y is: %d\n", y);
    
    *ip = 0;
    printf("The value of the variable ip points to is : %d\n", *ip);
    
    ip = &z[10];
    printf("The address of the variable ip now points to is: %d\n", *ip);
    
    *ip = *ip + 10;
    printf("The value of the variable ip now points to is %d\n", *ip);
    
    printf("The operators & and * are complementary as \n");
    printf("*&ip = %p and &*ip = %p are the same\n", &*ip, *&ip);
    
    return 0;
}