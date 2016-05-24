//
//  employee.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 50

typedef struct student{
    unsigned int sid;
    char *name;
    float gpa;
    struct student *nextNode;
}Student;

typedef Student *stPtr;

char* print (char *);

stPtr addnode(stPtr start, stPtr temp, int n);

// algorithm:
// read on line of code and enter it into struct
// read next line of code and create new node, using ID sort in order
// print in reverse to screen.
// write back to file in order.

int
main(void)
{
    FILE *fptr;
    int n = 0, count = 0;
    stPtr Start = NULL;
    stPtr current = NULL;
    stPtr previous = NULL;
    
    if ((fptr = fopen("studentlist.dat", "r+")) == NULL) {
        printf("New file created.\n");
        fptr = fopen("studentlist.dat", "w");
    }
    
    Student reader;
    
    // create listing.
    
    printf("\nOrder before list\n\n");
    reader.sid = 3;
    reader.name = "John_Smith";
    reader.gpa = 4.5;
    fwrite(&reader, sizeof(Student), 1, fptr);
    printf("%5d%20s%5.2f- enter\n", reader.sid, reader.name, reader.gpa);
    reader.sid = 1;
    reader.name = "Mary_Jane";
    reader.gpa = 3.10;
    fwrite(&reader, sizeof(Student), 1, fptr);
    printf("%5d%20s%5.2f- enter\n", reader.sid, reader.name, reader.gpa);
    reader.sid = 2;
    reader.name = "Bob_Smith";
    reader.gpa = 1.0;
    fwrite(&reader, sizeof(Student), 1, fptr);
    printf("%5d%20s%5.2f- enter\n", reader.sid, reader.name, reader.gpa);
    reader.sid = 4;
    reader.name = "David_Letterman";
    reader.gpa = 5.00;
    reader.nextNode = NULL;
    fwrite(&reader, sizeof(Student), 1, fptr);
    printf("%5d%20s%5.2f- enter\n", reader.sid, reader.name, reader.gpa);
    //rewind(fptr);
    freopen("studentlist.dat", "r", fptr);

    printf("\n\nReading into list\n\n");
    while (!feof(fptr)) {
        stPtr readers = malloc(sizeof(Student));
        n = fread (readers, sizeof(Student), 1, fptr);
        if (n != 0){
            Start = addnode(Start, readers, n);
            printf("%5d%20s%5.2f- start after function\n", Start->sid, Start->name, Start->gpa);
            count++;
        }
    }
    
    FILE *newfile;
    FILE *new2;
    current = Start;
    //newfile = fopen("new.txt", "w");
    new2 = fopen("new2.txt", "w");
    printf("\nOrder in list\n\n");
    Student temp3;
    while(current != NULL){
            printf("%5d%20s%5.2f\n", current->sid, print(current->name), current->gpa);
            //fprintf(newfile, "%d %s %f\n", current->sid, current->name, current->gpa);
            fwrite(current, sizeof(Student), 1, new2);
            current = current->nextNode;
    }

    printf("\nNew order in file\n\n");
    // reset pointer and open files as read only
    //fclose(newfile);
    if ((newfile = fopen("new.txt", "r"))== NULL)
        puts("Invalid option\n");
    fclose(new2);
    if ((new2 = fopen("new2.txt", "r"))== NULL)
        puts("Invalid option\n");

    int sid;
    char *name;
    float gpa;
    name = malloc (100 * sizeof(char));
//    fscanf(newfile, "%d %s %f", &sid, name, &gpa);
//
//    while (!feof(newfile)) {
//        printf("%5d%20s%5.2f\n", sid, name, gpa);
//        fscanf(newfile, "%d%s%f", &sid, name, &gpa);
//
//    }
    
    printf("\nRead from new file.\n\n");
    
    fread(&temp3, sizeof(Student), 1, new2);
    while (!feof(new2)) {
        //if (n != 0)
            printf("%5d%20s%5.2f\n", temp3.sid, print(temp3.name), temp3.gpa);
        fread(&temp3, sizeof(Student), 1, new2);
    }
    
    return 0;
}


stPtr addnode(stPtr start, stPtr temp, int n)
{
    stPtr current = NULL, previous = NULL;
    
    if (start == NULL){
        start = temp;
        return start;
    }
    else{
        previous = NULL;
        current = start;
        while (current != NULL && temp->sid > current->sid) {
            previous = current;
            current= current->nextNode;
        }
        if (previous != NULL) 
            previous->nextNode = temp;
        else
            start = temp;
        
        temp->nextNode = current;
        
    }
    return start;
    
}

char* print (char *word)
{
    char *first, *last = strchr(word, '_');
    last++;
    int n = last - word;
    first = malloc(sizeof(n));
    strncpy(first, word, n-1);
    first[n-1] = ' ';
    //char *test = malloc( 100 *(sizeof(char)));
    //sprintf(test, "%s %s", first, last);
    //printf("in function print- %s\n", test);
    return strcat(first, last);
    //return test;
}
