//
//  turtle.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 30

enum direction {NORTH, EAST, SOUTH, WEST};
enum direction orient;
enum pen {UP, DOWN};
enum pen pen;
int x, y = 0;

void printMenu();
// print a menu, no input or output
void printMenu()
{
    printf("1- Pen Up\n2- Pen Down\n3- Turn Right\n4- Turn Left\n5- Move\n6- Print\n7- Print Menu\n9- Exit\n");
}

void move(int array[][SIZE]);//, int x, int y);
/*
 Function: perform the move
 input: nothing
 output: nothing
 */
void move(int array[][SIZE])//, int x, int y)
{
    int moves, a = 0;
    printf("How many moves? ");
    scanf("%d", &moves);
    
    
    
    if (orient == NORTH)
    {
        if(pen == UP)
        {
            for(a = 0; a < moves; a++)
                x -= 1;
        }
        else if(pen == DOWN)
        {
            for(a = 0; a < moves; a++)
            {
                array[x][y] = 1;
                x -= 1;
            }
            puts("");
        }
    }
    
    if (orient == SOUTH)
    {
        if(pen == UP)
        {
            for(a = 0; a < moves; a++)
                x += 1;
        }
        else if(pen == DOWN)
        {
            for(a = 0; a < moves; a++)
            {
                array[x][y] = 1;
                x += 1;
            }
            puts("");
        }
    }

    if (orient == EAST)
    {
        if(pen == UP)
        {
            for(a = 0; a < moves; a++)
                y += 1;
        }
        else if(pen == DOWN)
        {
            for(a = 0; a < moves; a++)
            {
                array[x][y] = 1;
                y += 1;
            }
            puts("");
        }
    }

    if (orient == WEST)
    {
        if(pen == UP)
        {
            for(a = 0; a < moves; a++)
                y -= 1;
        }
        else if(pen == DOWN)
        {
            for(a = 0; a < moves; a++)
            {
                array[x][y] = 1;
                y -= 1;
            }
            puts("");
        }
    }

    
}

void printArray(int monthsales[][SIZE]);
/*
 Function: prints array
 input: one array and size
 output: nothing.
 */
void printArray(int monthsales[][SIZE])
{
    int i, x;
    for (i = 0; i < SIZE; i++) {
        for (x = 0; x < SIZE; x++) {
            if (monthsales[i][x] == 1)
                printf("%s", "* ");
            else
                printf("%s", "  ");
        }
        puts("");
    }
}

void work(int array[][SIZE], int status);
/*
 Function: perform the work functions
 input: status integer
 output: nothing
 */
void work(int array[][SIZE], int status)
{

    switch (status) {
        case 1:
            pen = UP;
            break;
        case 2:
            pen = DOWN;
            break;
        case 3:
            if ( orient == WEST)
                orient = NORTH;
            else if( orient == NORTH)
                orient = EAST;
            else if( orient == EAST)
                orient = SOUTH;
            else if (orient == SOUTH)
                orient = WEST;
            break;
        case 4:
            if (orient == NORTH)
                orient = WEST;
            else if (orient == WEST)
                orient = SOUTH;
            else if (orient == SOUTH)
                orient = EAST;
            else if (orient == EAST)
                orient = NORTH;
            break;
        case 5:
            move(array);
            break;
        case 6:
            printArray(array);
        case 7:
            printMenu();
        case 9:
            break;
    }
    return;
}


int
main(void)
{
    //static int x, y;
    int test = 0;
    int array[SIZE][SIZE];
    int status = 0;
    
    // set field to zeros
    for (x = 0; x < SIZE; x++) {
        for (y = 0; y < SIZE; y++) {
            array[x][y] = 0;
        }
    }
    
    printf("Establish starting position(30 x 30 grid) x, y, & NORTH(0), EAST(1), SOUTH(2) or WEST(3): ");
    scanf("%d%d%d", &x, &y, &test);
    
    switch (test) {
        case 0:
            orient = NORTH;
            break;
        case 1:
            orient = EAST;
            break;
        case 2:
            orient = SOUTH;
            break;
        case 3:
            orient = WEST;
    }
    
    do {
        printf("Enter code(1-7, or 9 ** 7 Prints Menu): ");
        scanf("%d", &status);
        if (status != 9)
            work(array, status);
    } while (status != 9);

    return 0;
}