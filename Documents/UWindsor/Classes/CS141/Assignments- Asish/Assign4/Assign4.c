//
//  Title: Assign4
//  Date: July 28/2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: Hardware store record keeping
//

#include <stdio.h>
#include <string.h>
#define LEN 7           //inserted to avoid compilation errors in printarray function for alternate file it was used with
#define SIZE 20
#include "printarray.h"
#include "DisplayMenu.h"

// define structure
struct invent {
    unsigned int recNum;
    char toolName[SIZE];
    int quantity;
    double cost;
};

typedef struct invent Inventory;
// Function prototypes
void initializeFile (FILE *);
void inputData(FILE *);
int userMenu(void);
void listTools(FILE *);
void updateRecord(FILE *);          
//void insertRecord(FILE *);        // combined with initializeFile for this interpretation
void deleteRecord(FILE *);


int
main(void)
{
    int i = 0, choice;
    // pointer to functions
    void (*dofunctions[4])(FILE *) = { inputData, listTools, deleteRecord, updateRecord };
    // create 100 struct records
    Inventory records[100];
    
    FILE *recordsPtr;                           // create file pointer
    initializeFile(recordsPtr);                 // initialize file
    
    if ((recordsPtr = fopen("records.dat", "rb+")) == NULL){
        puts("File could not be opened");
        return -1;
    }
    do{
        do{
            choice = userMenu();
            if (choice != 4)
                (*dofunctions[choice])(recordsPtr);
        }while(choice != 4);
    }while (choice !=4);
    // close file
    fclose(recordsPtr);
    return 0;
}

/*Function: Create record for hardware file
 Input: file pointer
 Output: Nothing */
void initializeFile (FILE * inventoryPtr)
{
    struct invent inventA = { 0, "", 0, 0.0 }; // create blank struct
    int result;
    // create file
    // check for file, open, then do functions selected by user
    if ((inventoryPtr = fopen("records.dat", "rb+")) == NULL){
        puts("\n**File could not be opened or you do not have a database.**\nI will create a file for you because I am so nice.");
        inventoryPtr = fopen("records.dat", "w");
        for(int i = 1; i <= 100; i++)
            fwrite(&inventA, sizeof (struct invent ), 1, inventoryPtr);
        fclose(inventoryPtr);
        return;
    }
    else{
        while (!feof(inventoryPtr)) {
            if (fread(&inventA.recNum, sizeof(int), 1, inventoryPtr) > 0) {
                return;
            }
        }
        // initialize 100 records if new record
        for(int i = 1; i <= 100; i++)
            fwrite(&inventA, sizeof (struct invent ), 1, inventoryPtr);
        fclose(inventoryPtr);
    }
}
/* Function: Enter a new record into the random access file
 Input: file pointer
 Output: nothing */
void inputData(FILE * inventoryPtr)
{
    struct invent inventA = { 0, "", 0, 0.0 };  // create struct holder record
    unsigned int recordNum;                     // record number
    char dummy;                                // used to capture returns
    
    // prompt user for valid input
    do{
        recordNum = 101;
        printf("Please enter new record number(1-100)");
        if(!scanf("%u", &recordNum)){
            printf("Invalid Input\n");
            fclose(stdin);
            freopen("/dev/tty", "r", stdin);
        }
    }while( recordNum > 100);
    // search for record in file, then read file and put information into struct
    fseek(inventoryPtr, (recordNum) * sizeof(struct invent), SEEK_SET);
    fread (&inventA, sizeof (struct invent), 1, inventoryPtr);
    
    //check for information, if struct contains info exit, if not prompt for record info
    if (inventA.recNum !=0)
        printf("Record #%d already contains information.\n", inventA.recNum);
    else{
        printf("%s", "Toolname: ");
        scanf("%c", &dummy);            // catch return for remainder of entries
        fgets(inventA.toolName, SIZE, stdin);
        inventA.toolName[strlen(inventA.toolName)-1] = '\0';
        printf("Please enter quantity: ");
        scanf("%d", &inventA.quantity);
        printf("Please enter cost: ");
        scanf("%lf", &inventA.cost);
    }
    
    inventA.recNum = recordNum;             // set first part of structure to variable
    
    // research for the proper record and write the new information to the file.
    fseek(inventoryPtr, (inventA.recNum) * sizeof (struct invent), SEEK_SET);
    fwrite(&inventA, sizeof (struct invent), 1, inventoryPtr);
    
}

/* Function: Display menu prompt for proper choice
 Input: nothing
 Output: one integer- user's selection*/
int userMenu(void)
{
    int select;                 // users selection variable
    
    do{
        // Display Menu and prompt for valid input
        DisplayMenuAssign4();
        printf("Please select your option: ");
        // set choice to keep in loop for invalid input
        select = -1;
        if(!scanf("%d", &select)){
            printf("Invalid option\n");
            fclose(stdin);
            freopen("/dev/tty", "r", stdin);
        }
    }while (select < 0 || select > 4);
    
    // return user's choice
    return select;
}


/* Function: Print out list of tools on the screen
 Input: file pointer
 Output: Nothing */
void listTools(FILE * inventoryPtr)
{
    int record, check = 0;                             // record variable holder
    struct invent inventA = { 0, "", 0, 0.0 };    // struct record holder
    rewind (inventoryPtr);                      // ensure pointer at beginning
    
    printf("%s\n", "Record  Tool Name            Quantity    Cost");
    // find all records that are greater than 0 and print to screen
    while (!feof(inventoryPtr)) {
        record = fread (&inventA, sizeof (struct invent), 1, inventoryPtr);
        
        // print all records that are greater than zero, variable width adjustments
        if (record != 0 && inventA.recNum !=0 && (strlen(inventA.toolName)) > 14) {
            printf("%4d\t%.30s%10d\t$%6.2lf\n", inventA.recNum, inventA.toolName, inventA.quantity, inventA.cost);
            check++;
        }
        else if(record != 0 && inventA.recNum !=0 && (strlen(inventA.toolName)) < 9) {
            printf("%4d\t%.30s\t\t%10d\t$%6.2lf\n", inventA.recNum, inventA.toolName, inventA.quantity, inventA.cost);
            check++;
        }
        else if(record != 0 && inventA.recNum !=0 && (strlen(inventA.toolName)) < 14) {
            printf("%4d\t%.30s\t\t%2d\t$%6.2lf\n", inventA.recNum, inventA.toolName, inventA.quantity, inventA.cost);
            check++;
        }
    }
    if (check == 0)
        printf("No Records Found!\n");
}

/* Function: Delete a record in a random sequence file
 Input: File pointer
 Output: Nothing */
void deleteRecord(FILE * inventoryPtr)
{
    struct invent inventA;                      // create structure record
    struct invent blank = { 0, "", 0, 0.0 };     // initialize an "eraser" struct record
    unsigned int recordNum;                     // record variable to search for
    
    // prompt for valid input
    do{
        recordNum = 101;
        printf("%s", "Enter record number you wish to delete: ");
        if(!scanf("%d", &recordNum)){
            printf("Invalid Input!\n");
            fclose(stdin);
            freopen("/dev/tty", "r", stdin);
        }
    }while (recordNum > 100);
    
    // search file for record and copy info into struct
    fseek(inventoryPtr, (recordNum) * sizeof (struct invent), SEEK_SET);
    fread(&inventA, sizeof (struct invent), 1, inventoryPtr);
    
    // check if record exists, and copy blank struct into location if info is in record.
    if (inventA.recNum == 0) {
        printf("Record #%d does not exist.\n", recordNum);
    }
    else{
        fseek (inventoryPtr, recordNum * sizeof (struct invent), SEEK_SET);
        fwrite(&blank, sizeof (struct invent), 1, inventoryPtr);
        printf("Record #%d deleted.\n", recordNum);
    }
    
}

/* Function: Update record inventory with $ value and quantity in same pass
 Input: file pointer
 Output: nothing */
void updateRecord (FILE * inventoryPtr)
{
    unsigned int record, change, temp;                 //record variable, item change variable
    int valuequantity;                         // quantity variable
    double valuemoney;                          // money variable
    struct invent inventA = { 0, "", 0 , 0.0 };   // struct to hold information
    void deleteRecord2(FILE * inventoryPtr, int record);  // prototype for modified record delete
    char *copy, dummy;
    
    // prompt for valid input
    do{
        record = 101;
        printf("Enter record to update(1-100)");
        if (!scanf("%d", &record)){
            printf("Invalid Input!\n");
            fclose(stdin);
            freopen("/dev/tty", "r", stdin);
        }
    }while (record > 100);
    
    // search out record location and read file info into struct variable
    fseek (inventoryPtr, (record) * sizeof (struct invent), SEEK_SET);
    fread( &inventA, sizeof(struct invent),1, inventoryPtr);
    
    // check for info, if there, print then prompt for change in quantity and $ value
    if (inventA.recNum == 0)
        printf("Record #%d does not exist", record);
    else{
        printf("%s\n", "Record  Tool Name              Quantity    Cost");
        printf("%4d\t%.30s%17d\t$%6.2lf\n", inventA.recNum, inventA.toolName, inventA.quantity, inventA.cost);
        
        printf("What information would you like to change:\n");
        
        do{
            do{
                change = 6;
                changeMenuAssign4();
                if(!scanf("%d", &change)){
                    printf("Invalid Input!");
                    fclose(stdin);
                    freopen("/dev/tty", "r", stdin);
                }
            }while (change > 5);
            switch (change) {
                case 1:
                    
                    printf("Please enter the new record number: ");
                    scanf("%d", &valuequantity);
                    fseek(inventoryPtr, (valuequantity) * sizeof (struct invent), SEEK_SET);
                    fread(&temp, sizeof (int), 1, inventoryPtr);
                    if (temp > 0) {
                        printf("New record address has information already. This change can't occur.\n");
                        change = 6;
                        break;
                    }
                    deleteRecord2(inventoryPtr, record);            // delete old record on file
                    inventA.recNum = valuequantity;                 // change file to write to new value
                    record = valuequantity;                         // update record variable with new number
                    break;
                case 2:
                    printf("Please enter the new tool name: ");
                    scanf("%c", &dummy);                                      // catch newline character
                    fgets(inventA.toolName, SIZE, stdin);                       // get new string
                    inventA.toolName[(strlen(inventA.toolName)-1)] = '\0';    // erase newline character
                    break;
                case 3:
                    printf("%s\n", "Enter increase (+) or decease(-) in quantity: ");
                    scanf("%d", &valuequantity);                               // get quantity, add
                    inventA.quantity += valuequantity;
                    break;
                case 4:
                    printf("%s\n", "Enter increase (+) or decease(-) in $ value: ");
                    scanf("%lf", &valuemoney);                                 // get $ and add
                    inventA.cost += valuemoney;
                    break;
            }
            // only do change for appropriate selections
            if( change != 5 || change != 6){
                // search for proper record and re-write struct to file using offset.
                fseek(inventoryPtr,(inventA.recNum) * sizeof(struct invent), SEEK_SET);
                fwrite(&inventA, sizeof(struct invent), 1, inventoryPtr);
                if (change != 6)
                printf("Changes Updated!\nWould you like to enter another change request?\n");
            }
            
        }while (change != 5);
    }
}

/* Function: Delete a record in a random sequence file used with reassigning record number
 Input: File pointer
 Output: Nothing */
void deleteRecord2(FILE * inventoryPtr, int record)
{
    struct invent inventA;                      // create structure record
    struct invent blank = { 0, "", 0, 0.0 };     // initialize an "eraser" struct record
    
    // search file for record and copy info into struct
    fseek(inventoryPtr, (record) * sizeof (struct invent), SEEK_SET);
    fread(&inventA, sizeof (struct invent), 1, inventoryPtr);
    
    // check if record exists, and copy blank struct into location if info is in record.
    if (inventA.recNum == 0) {
        printf("Record #%d does not exist.\n", record);
    }
    else{
        fseek (inventoryPtr, record * sizeof (struct invent), SEEK_SET);
        fwrite(&blank, sizeof (struct invent), 1, inventoryPtr);
        printf("Original #%d deleted.\n", record);
    }
    
}
