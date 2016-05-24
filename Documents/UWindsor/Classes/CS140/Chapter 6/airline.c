//
//  airline.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 10

enum STATUS {OPEN, FULL};
int seatcheck1, seatchecke, premade = 0;

int assign(int seats[], int size, int choice);
/* 
 Function- assign seats on flight and determine if one section is full
 input: one array, the size, and the passengers choice
 output: the capacity
 */
int assign(int seats[], int size, int choice)
{
    int i;
    char yesno, dummy;
        
    if (choice == 1)
    {
        if (seats[5] == 0)
        {
            for (i = 1; i <= 5; i++)
            {
                if (seats[i] == 0) {
                    seats[i] = choice;
                    seatcheck1++;
                    return 0;
                }
            }
        }
    
        else if (seats[5] != 0)
        {
            printf("Section full. Change to other class? (Y or N)");
            scanf("%c%c", &dummy, &yesno);
            if (premade == 'y' || premade == 'Y')
            {
                printf("Switched to Economy.\n");
                premade = 2;
                return premade;
            }
            else
            {
                printf("Sorry we could not accomodate. Next flight in 3 hours.\n");
                return 0;
            }
        }
        
    }
    
    if (choice == 2)
    {
        if (seats[10] == 0)
        {
            for (i = 6; i <= 10; i++) {
                if (seats[i] == 0) {
                    seats[i] = choice;
                    seatchecke++;
                    return 0;
                }
            }
        }
        if (seats[10] != 0)
        {
            printf("Section full. Change to other class? (Y or N)");
            scanf("%c%c", &dummy, &yesno);
            if (yesno == 'Y' || yesno == 'y')
            {
                printf("Your selection has been changed to First Class.\n");
                premade = 1;
                return 1;
            }
            else
            {
                printf("Sorry we could not accomodate. Next flight in 3 hours.\n");
                return 0;
            }
        }
        
    }
    return 0;
}

int
main(void)
{
    int seats[SIZE];
    int choice = 0;
    int capacity = OPEN;
    
    for (int i = 0; i < SIZE; i++)
        seats[i] = 0;
    
    printf("Flights seats are all open.\n");
    
    do
    {
        if (premade ==0)
        {
            printf("Please select your flight seat\nFirst Class - 1\n"
                   "Economy- 2\n");
            scanf("%d", &choice);
        }
        if (premade == 1 || premade ==2)
            choice = premade;
        
        premade = assign(seats, SIZE, choice);
        
        if (seatcheck1 == 5 && seatchecke == 5) {
            printf("The plane is full.\n");
            capacity = FULL;
        }
        
    }while (capacity == OPEN);
        
    return 0;
}