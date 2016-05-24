// Assignment 3 60-141 Solution
// Modified example from book
// Modifications made by Jeffrey Drake 28 July 2013

// Fig. 6.22: fig06_22.c
// Double-subscripted array manipulations.
#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

// a type for our function pointer
typedef void (*operation)(int(*)[4],size_t,size_t);

// function prototypes
void minimum( int grades[][ EXAMS ], size_t pupils, size_t tests );
void maximum( int grades[][ EXAMS ], size_t pupils, size_t tests );
void average(int grades[][ EXAMS ], size_t pupils, size_t tests);
void printArray( int grades[][ EXAMS ], size_t pupils, size_t tests );


// function main begins program execution
int main( void )
{
    // array of operations
    operation operations[4] = { printArray, minimum, maximum, average };
    unsigned response;
    
    // initialize student grades for three students (rows)
    int studentGrades[ STUDENTS ][ EXAMS ] =
    { { 77, 68, 86, 73 },
        { 96, 87, 89, 78 },
        { 70, 90, 86, 81 } };
    
    do {
        printf("Enter a choice:\n");
        printf("0 Print the array of grades\n");
        printf("1 Find the minimum grade\n");
        printf("2 Find the maximum grade\n");
        printf("3 Print the average\n");
        printf("4 Quit\n> ");
        
        if (scanf("%u", &response) == 1)
        {
            if (response < 4) {
                operations[response](studentGrades, STUDENTS, EXAMS);
            }
        } else {
            printf("Invalid input\n");
            // invalid input to scanf, so clear until newline
            while (getchar() != '\n');
        }
    } while (response != 4);
    
} // end main

// Find the minimum grade
void minimum( int grades[][ EXAMS ], size_t pupils, size_t tests )
{
    size_t i; // student counter
    size_t j; // exam counter
    int lowGrade = 100; // initialize to highest possible grade
    
    // loop through rows of grades
    for ( i = 0; i < pupils; ++i ) {
        
        // loop through columns of grades
        for ( j = 0; j < tests; ++j ) {
            
            if ( grades[ i ][ j ] < lowGrade ) {
                lowGrade = grades[ i ][ j ];
            } // end if
        } // end inner for
    } // end outer for
    
    // return lowGrade; // return minimum grade
    printf("Lowest grade: %d\n", lowGrade);
} // end function minimum

// Find the maximum grade
void maximum( int grades[][ EXAMS ], size_t pupils, size_t tests )
{
    size_t i; // student counter
    size_t j; // exam counter
    int highGrade = 0; // initialize to lowest possible grade
    
    // loop through rows of grades
    for ( i = 0; i < pupils; ++i ) {
        
        // loop through columns of grades
        for ( j = 0; j < tests; ++j ) {
            
            if ( grades[ i ][ j ] > highGrade ) {
                highGrade = grades[ i ][ j ];
            } // end if
        } // end inner for
    } // end outer for
    
    // return highGrade; // return maximum grade
    printf("Highest grade: %d\n", highGrade);
} // end function maximum



// Determine the average grade for a particular student
void average(int grades[][ EXAMS ], size_t pupils, size_t tests)
{
    size_t student; // student counter
    
    for ( student = 0; student < pupils; ++student ) {
        // previous content of function average
        size_t i; // exam counter
        int total = 0; // sum of test grades
        
        // total all grades for one student
        for ( i = 0; i < tests; ++i ) {
            total += grades[ student ][ i ];
        } // end for
        
        // return ( double ) total / tests; // average
        printf("The average grade for student %zu is %.2f\n", student, (double)total/tests);
    }
} // end function average


// Print the array
void printArray( int grades[][ EXAMS ], size_t pupils, size_t tests )
{
    size_t i; // student counter
    size_t j; // exam counter
    
    // output column heads
    printf( "%s", "                 [0]  [1]  [2]  [3]" );
    
    // output grades in tabular format
    for ( i = 0; i < pupils; ++i ) {
        
        // output label for row
        printf( "\nstudentGrades[%zu] ", i );
        
        // output grades for one student
        for ( j = 0; j < tests; ++j ) {
            printf( "%-5d", grades[ i ][ j ] );
        } // end inner for
    } // end outer for
} // end function printArray

/**************************************************************************
 * (C) Copyright 1992-2013 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
