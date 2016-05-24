//
//  Assign4review.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <string.h>
#define MAX 40
//#include <stdlib.h>

typedef struct hardware {
    int record;
    char name[MAX];
    int quantity;
    float cost;
}Inventory;


void displayMenu(int);
void initializeFile(FILE *);
void inputData(FILE *);
void listTools(FILE *);
void update(FILE *);
void insertRec(FILE *);
void deleteRec(FILE *);

int
main(void)
{
    FILE * fptr;
    int choice;
    
    void(*functions[4])(FILE*) = {inputData, listTools, deleteRec, update};
    
    if ((fptr = fopen("hardware.dat", "r+")) == NULL) {
        printf("No File, will create one. Restart program.\n");
        fptr = fopen("hardware.dat", "w");
    }
    else{
        do{
            do{
                displayMenu(1);
                printf("Please enter your menu selection: ");
                if(!scanf("%d", &choice) == 1){printf("Invalid Input. Bye!\n"); return -1; }
            }while (choice < 1 || choice > 5);
            if (choice != 5)
                (*functions[choice-1])(fptr);
        }while(choice !=5);
    }
    return 0;
}

void displayMenu(int a)
{
    if (a == 1) {
        char *menu[] = {
            "1.Input Data",
            "2.List Tools",
            "3.Delete Record",
            "4.Update Info",
            "5.Exit"
        };
        
        for (a=0; a < 5; a++) {
            printf("%s\n", menu[a]);
        }
        return;
    }
    else{
        printf("\n***Update Menu***\n");
        char *menu2[] ={
            "1. Update Record#",
            "2. Update Toolname",
            "3. Update Quantity",
            "4. Update Value",
            "5. Exit"
        };
        for (a = 0; a< 5; a++)
            printf("%s\n", menu2[a]);
        return;
    }
}

void inputData(FILE * fptr)
{
    Inventory temp = {0, "", 0, 0.0 };
    int rec;
    char dummy;
    
    printf("Please enter record number you wish to input: ");
    scanf("%d", &rec);
    
    fseek(fptr, (rec -1) * (sizeof(Inventory)), SEEK_SET);
    fread(&temp, sizeof(Inventory), 1, fptr);
    
    if(temp.record != 0){
        printf("Record already holds information.\n");
        return;
    }
    else {
        scanf("%c", &dummy);
        printf("Enter Toolname: ");
        //fgets(temp.name, 40, stdin);
        //temp.name[strlen(temp.name)-1] = '\0';
        gets(temp.name);
        printf("Enter Quantity: ");
        scanf("%d", &temp.quantity);
        printf("Enter Value: ");
        scanf("%f", &temp.cost);
        temp.record = rec;
        fseek (fptr, (temp.record -1) * (sizeof(Inventory)), SEEK_SET);
        fwrite(&temp, sizeof(Inventory),1 , fptr);
    }
    puts("");
}

void listTools(FILE * fptr)
{
    Inventory temp = { 0, "", 0, 0.0 };
    int result = 1;
    
    rewind(fptr);
    printf("Record#\tTool\t\tQuantity\tCost\n");
    while (!feof(fptr)){
        result = fread (&temp, sizeof(Inventory), 1, fptr);
        if (result != 0 && temp.record != 0) {
            printf("%d\t%s\t%d\t\t$%.2f\n", temp.record, temp.name, temp.quantity, temp.cost);
        }
    }
    puts("");
    if(temp.record == 0 && result != 0)
        puts("No Inventory!\n\n");
    
}

void update(FILE * fptr)
{
    Inventory blank = {0,"",0,0.0};
    Inventory temp1, temp2;
    int choice, rec, recChan;
    char dummy;
    double money;
    
    listTools(fptr);
    printf("Please enter the record you wish to update: ");
    if((!scanf("%d", &rec) == 1)) { printf("Invalid. Bye"); return; }
    fseek (fptr, (rec -1) * sizeof(Inventory), SEEK_SET);
    fread (&temp1, sizeof(Inventory), 1, fptr);
    
    if (temp1.record == 0){
        printf("No record!\n\n");
        return;
    }
    
    
        do{
            listTools(fptr);
            displayMenu(0);
            printf("Please enter your selection: ");
            if(!scanf("%d", &choice) == 1){printf("Invalid. Bye\n");return;}
        }while (choice < 1 && choice > 5);
        switch (choice) {
            case 1:
                
                printf("Please enter new record number to change to: ");
                if(!scanf("%d", &recChan) == 1) { printf("Invalid. Bye.\n"); return; }
                fseek(fptr, (recChan-1) * sizeof(Inventory), SEEK_SET);
                fread(&temp2, sizeof(Inventory), 1, fptr);
                if (temp2.record == 0) {
                    fseek(fptr, (rec -1) * sizeof(Inventory), SEEK_SET);
                    fwrite(&blank, sizeof(Inventory), 1, fptr);
                    temp1.record = recChan;
                    fseek(fptr, (recChan -1) * sizeof(Inventory), SEEK_SET);
                    fwrite(&temp1, sizeof(Inventory), 1, fptr);
                    printf("Record Number Updated.\n");
                    return;
                }
                else{
                    printf("Existing record in position %d, no change will occur.\n", recChan);
                    return;
                }
                break;
            case 2:
                fseek(fptr, (rec -1) * sizeof(Inventory), SEEK_SET);
                fread(&temp1, sizeof(Inventory), 1, fptr);
                scanf("%c", &dummy);
                printf("Please enter record name: ");
                fgets(temp1.name, 40, stdin);
                temp1.name[strlen(temp1.name)-1] = '\0';
                fseek(fptr, (rec -1) * sizeof(Inventory), SEEK_SET);
                fwrite(&temp1, sizeof(Inventory), 1, fptr);
                printf("Name Updated.\n");
                return;
            case 3:
                fseek(fptr, (rec-1) * sizeof(Inventory), SEEK_SET);
                fread(&temp1, sizeof(Inventory), 1, fptr);
                scanf("%c", &dummy);
                printf("Please enter change in quantity: ");
                scanf("%d", &recChan);
                temp1.quantity += recChan;
                fseek(fptr, (rec-1) * sizeof(Inventory), SEEK_SET);
                fwrite(&temp1, sizeof(Inventory), 1, fptr);
                printf("Quantity updated.\n");
                return;
            case 4:
                fseek(fptr, (rec-1) * sizeof(Inventory), SEEK_SET);
                fread(&temp1, sizeof(Inventory), 1, fptr);
                scanf("%c", &dummy);
                printf("Please enter change in value: ");
                scanf("%lf", &money);
                temp1.cost += money;
                fseek(fptr, (rec-1) * sizeof(Inventory), SEEK_SET);
                fwrite(&temp1, sizeof(Inventory), 1, fptr);
                return;
        }
    
    
}

void deleteRec(FILE * fptr)
{
    int rec;
    
    Inventory temp = {0,"",0,0.0};
    Inventory temp1;
    
    printf("Please enter the record you wish to delete: ");
    if(!scanf("%d", &rec) == 1){printf("Invalid. Bye\n"); return;}
    
    fseek (fptr, (rec -1) * sizeof(Inventory), SEEK_SET);
    fread(&temp1, sizeof(Inventory), 1, fptr);
    
    if (temp1.record == 0) {
        printf("No record!\n\n");
    }
    else{
        fseek (fptr, (rec -1) * sizeof(Inventory), SEEK_SET);
        fwrite(&temp, sizeof(Inventory), 1, fptr);
        printf("Record Deleted\n\n");
    }
    
    return;
}