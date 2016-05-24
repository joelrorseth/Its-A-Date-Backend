//
//  lab5_q4.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

void DrawSquare(int L, char s);
/*Function to draw a square
* input: one integer and a character
* output: nothing, but draw a square
*/
void DrawHollow(int L, char s);
/*Function to draw a hollow square
 * input: one integer and a character
 * output: nothing, but draw a square
 */
void DrawStairs(int L, char s);
/*Function to draw a stairs
 * input: one integer and a character
 * output: nothing, but draw a square
 */
void DrawRStairs(int L, char s);
/*Function to draw a stairs in reverse
 * input: one integer and a character
 * output: nothing, but draw a square
 */
void DrawDiamond(int L, char s);
/*Function to draw a diamond
 * input: one integer and a character
 * output: nothing, but draw a square
 */


int
main(void)
{
    int x = 0;          // variable for size
    char item, gar;         // string for character
    //item = getchar();
    //printf("Please enter a symbol (single char): ");
    //scanf("%c%c", &gar, &item);

    printf("Please enter a positive integere for L: ");
    scanf("%d%c", &x, &item);
    printf("Please enter a symbol (single char): ");
    scanf("%c%c", &gar, &item);
    
    
    puts("");
    DrawSquare(x, gar);
    puts("");
    DrawHollow(x, gar);
    puts("");
    DrawStairs(x, gar);
    puts("");
    DrawRStairs(x, gar);
    puts("");
    DrawDiamond(x, gar);
    puts("");
    
    
    return 0;
}


void DrawSquare(int L, char s)
{
    for (int x = 0; x < L; x++)
    {
        for (int y = 0; y < L; y++)
            printf("%c ", s);
        puts("");
    }
}

void DrawHollow(int L, char s)
{
    // draw a hollow square with the values provided
    for (int i = 0; i < L; i++)
    {
        if (i == 0 || i == (L - 1))
        {
            for (int j = 0; j < L; j++)
                printf("%c ", s);
        }
        else
        {
            for (int  j = 0; j < L; j++)
            {
                if(j == 0 || j == (L - 1))
                    printf("%c ", s);
                else
                    printf("  ");
            }
        }
        puts("");
    }
    
}

void DrawStairs(int L, char s)
{
    // draw stairs with values provided
    for(int x = 1; x <= L; x++)
    {
        for (int y = 1; y <= x; y++)
            printf("%c ", s);
        puts("");
    }
    
    
}

void DrawRStairs(int L, char s)
{
    int counter = L;
    
    // draw stairs in reverse with values provided
    for(int x = 1; x <= L; x++)
    {
        for (int y = counter; y > 1; y--)
        {
            printf("  ");
        }
        counter--;
        for (int y = 1; y <= x; y++)
            printf("%c ", s);
        
        puts("");
    }
    
    
}



void DrawDiamond(int L, char s)
{
    int counter = L;                // counter to adjust size
    int upperlower = 1;             // variable to track upper or lower side of diamond
    int v = 0;                      // variable to reverse count.
    
    // draw diamond in reverse with values provided
    // draw diamond if size is even
    if(L % 2 == 0)
    {
        for(int x = 1; x <= L; x++)
        {
            // draw top half
            if (upperlower <= (L / 2))
            {
                for (int y = counter; y >= 1; y--)
                    printf(" ");
                counter--;
                for (int y = 1; y <= x; y++)
                    printf("%c ", s);
                puts("");
                upperlower++;
            }

            // draw lower half

            else if (upperlower > (L /2))
            {
                for (int y = counter; y >= 0; y--)
                    printf(" ");
                counter++;
                for (int y =((L / 2) - v); y > 0; y--)
                    printf("%c ", s);
                v++;
                puts("");
            }
        }

    }

}

