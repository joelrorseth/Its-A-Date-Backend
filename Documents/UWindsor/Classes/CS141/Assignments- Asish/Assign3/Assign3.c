//
//  Title: Assign3
//  Date: July 20, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: Grade calculations modified with pointers.
//

#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4
#define LEN EXAMS                   // use LEN for definition in custom header files
#include "printarray.h"
#include "DisplayMenu.h"
#include "MinArray.h"
#include "MaxArray.h"
#include "AvArrayLine.h"

int
main(void)
{
    size_t student; // student counter
    int choice;      // users selection
    // declare array of pointers to functions
    void (*processGrades[EXAMS])(int[][EXAMS], const size_t, const size_t) = { print2dArray, minimum, maximum, average };
    
    // initialize student grades for three students (rows)
    int studentGrades[ STUDENTS ][ EXAMS ] =
    { { 77, 68, 86, 73 },
        { 96, 87, 89, 78 },
        { 70, 90, 86, 81 } };

    do{
        DisplayMenuAssign3();               // display menu for user each time and prompt for selection
        do {
            printf("Please enter selection: ");
            scanf("%d", &choice);
        } while (choice < 0 || choice > 4);
                    
        if (choice != 4)
            (*processGrades[choice])(studentGrades, STUDENTS, EXAMS );      // perform function if not escape value using array
        
    }while(choice != 4);
    
    return 0;
}

