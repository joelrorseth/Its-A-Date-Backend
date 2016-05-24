//
//  Assign3review.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

void displayMenu();
void print (int grades[][EXAMS], int hi, int len);
void lowGrade (int grades[][EXAMS], int hi, int len);
void highGrade (int grades[][EXAMS], int hi, int len);
void Average (int grades[][EXAMS], int hi, int len);

int
main(void)
{
    int student, choice;
    void (*function[4])(int[][EXAMS], int, int) = { print, lowGrade, highGrade, Average};
    
    int studentGrades[STUDENTS][EXAMS] = {
        {77, 68, 86, 73},
        {96, 87, 89, 78},
        {70, 90, 86, 81} };
    
    do{
        do {
            displayMenu();
            if((!scanf("%d", &choice) == 1)){printf("Invalid Selection. Bye!\n"); return -1;}
        }while (choice < 1 || choice > 5);
        if (choice != 5) (*function[choice-1])(studentGrades, STUDENTS, EXAMS);
    } while (choice != 5);
    
    return 0;
}

void displayMenu()
{
    char *menu[5]= {
        "1. Print Array",
        "2. Minimum Grade",
        "3. Maximum Grade",
        "4. Average for each student",
        "5. Exit"
    };
    puts("");
    for (int x = 0; x < 5; x++)
        printf("%s\n", menu[x]);
}

void print (int grades[][EXAMS], int hi, int len)
{
    printf("Student\tExam 1\tExam 2\tExam 3\tExam 4\n");
    for (int i = 0; i < hi; i++) {
        printf("St. %d:\t", i + 1);
        for (int j = 0; j < len; j++) {
            printf("%d\t", grades[i][j]);
        }
        puts("");
    }
}
void lowGrade (int grades[][EXAMS], int hi, int len)
{
    int min = 100;
    
    for (int i = 0; i < hi; i++) {
        for (int j = 0; j < len; j++) {
            if( grades[i][j] < min)
                min = grades[i][j];
        }
    }
    printf("%d-low grade\n", min);
}
void highGrade (int grades[][EXAMS], int hi, int len)
{
    int max = 0;
    
    for (int i = 0; i < hi; i++) {
        for (int j = 0; j < len; j++) {
            if( grades[i][j] > max)
                max = grades[i][j];
        }
    }
    printf("%d-high grade\n", max);
}
void Average (int grades[][EXAMS], int hi, int len)
{
    double sum = 0;
    printf("Student\tAverage\n");
    for (int i = 0; i < hi; i++) {
        printf("St. %d:\t", i + 1);
        sum = 0;
        for (int j = 0; j < len; j++) {
            sum += grades[i][j];
        }
        sum /= EXAMS;
        printf("%.2f\n", sum);
    }
}