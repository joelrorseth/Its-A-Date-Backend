//
//  pointer.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct gradeNode{
    char lastName[20];
    double grade;
    struct gradeNode *nextPtr;
};

typedef struct gradeNode GradeNode;
typedef GradeNode *GradeNodePtr;

GradeNodePtr addNode(GradeNodePtr, char *key, int keyint);

int
main(void)
{
    float number1 = 7.3, number2;
    float *fptr = &number1;
    
    char *names[]= { "Adams", "Thompson", "Pritchard"};
    float grades[] = { 85.0, 73.5, 66.5 };
    
    printf("%f\n", *fptr);
    number2 = *fptr;
    
    printf("%f\n", number2);
        printf("%p\n", &number1);
        printf("%p\n", fptr);
    
//    char string[50];
//    printf("%1s\n", "Monday");
//    
//    puts("\"A string in quotes\"");
//    
//    printf("%+.3e\n", 123.456789);
//    
//    printf("%#o \n", 100);
//    
//    fgets(string, 50, stdin);
//    printf("%s\n\n", string);
//    
//    
//    int x = 10, y = 3;
//    printf("%*.*lf\n", x, y, 87.4573);
//    
//    float percent;
//    scanf("%f[^%%]", &percent);
//    printf("%.4f\n", percent);
//  
//    printf("%+*.*f\n",20, 3, 3.333333);
    
    GradeNodePtr startPtr = NULL;
    GradeNodePtr newPtr = malloc (sizeof(GradeNode));
    strcpy(newPtr->lastName, "Jones");
    newPtr->grade = 91.5;
    newPtr->nextPtr = NULL;
    
    startPtr = newPtr;
    
    GradeNodePtr next = malloc (sizeof(GradeNode));
    strcpy(next->lastName, "Smith");
    next->nextPtr = NULL;
    startPtr->nextPtr = next;
    
    
    for (int x = 0; x < 3; x++) {
        //printf("%-15s%8.3f\n", names[x], grades[x]);
        startPtr = addNode(startPtr, names[x], grades[x]);
    }
    
    GradeNodePtr current = startPtr;
    
    while (current != NULL) {
        fprintf(stdout, "%-15s%%%6.2f\n", current->lastName, current->grade);
        current = current->nextPtr;
    }
    
    free(newPtr);
    
    return 0;
}


GradeNodePtr addNode(GradeNodePtr start, char *key, int keyint)
{
    GradeNodePtr previous = NULL, next = NULL;
    next = previous= start;
    GradeNodePtr temp = malloc (sizeof(GradeNode));
    strcpy(temp->lastName, key);
    temp->grade = keyint;
    temp->nextPtr = NULL;
    
    if (strcmp(key, previous->lastName) < 0){
        temp->nextPtr = start;
        return temp;
    }
    
    while ( next != NULL) {
        previous = next;
        next = next->nextPtr;
        if (strcmp(key, previous->lastName) < 0)
            break;
    }
    
    previous->nextPtr = temp;
    if (next != NULL)
        temp->nextPtr = next;
    
    return start;
    
}