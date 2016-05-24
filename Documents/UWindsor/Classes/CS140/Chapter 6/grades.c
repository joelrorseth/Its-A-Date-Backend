//
//  grades.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

// fucntion prototypes
int minimum(int grades[][EXAMS], size_t pupils, size_t tests);
int maximum(int grades[][EXAMS], size_t pupils, size_t tests);
double average(const int setOfGrades[], size_t tests);
void printArray(int grades[][EXAMS], size_t pupils, size_t tests);

int
main(void)
{
    size_t student;
    
    int studentGrades[STUDENTS][EXAMS]= {{77, 68, 86, 73}, {96, 87, 89, 78}, {70, 90, 86, 81}};
    
    puts("The array is: ");
    
    printArray(studentGrades, STUDENTS, EXAMS);
    
    printf("\n\nLowest Grade: %d\nHighest Grade: %d\n", minimum(studentGrades, STUDENTS, EXAMS), maximum (studentGrades, STUDENTS, EXAMS));
           
    for(student = 0; student < STUDENTS; student++)
    {
        printf("The average grade for student %zu is %.2f\n",
               student, average(studentGrades[student], EXAMS));
    }
           
    return 0;
}

int minimum(int grades[][EXAMS], size_t pupils, size_t tests)
{

    int lowgrade = 100;
    for (int i = 0; i < pupils; i++) {
        for (int j = 0; j < tests; j++) {
            if (grades[i][j] < lowgrade) {
                lowgrade = grades[i][j];
            }
        }
    }
    return lowgrade;
}

int maximum(int grades[][EXAMS], size_t pupils, size_t tests)
{
        
    int highgrade = 0;
    for (int i = 0; i < pupils; i++) {
        for (int j = 0; j < tests; j++) {
            if (grades[i][j] > highgrade) {
                highgrade = grades[i][j];
            }
        }
    }
    return highgrade;
}

double average(const int setOfGrades[], size_t tests)
{
    double total = 0;
    
    for (int i = 0; i < tests; i++) {
        total += setOfGrades[i];
    }
    return total / tests;
}

void printArray(int grades[][EXAMS], size_t pupils, size_t tests)
    {
        printf("%s", "                [0]  [1]  [2]  [3]");
        
        for (int i = 0; i < pupils; i++) {
            printf("\nstudentGrade[%d] ", i);
            for (int j = 0; j < tests; j++) {
                printf("%-5d", grades[i][j]);
            }
        }
        
    }



