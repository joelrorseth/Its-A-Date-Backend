//
//  numguess.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototype
int ran(void);
void guessing(int x, int c);


int
main(void)
{
    int x = 0;
    char ans = 'y';
    int counter = 0;
    
    puts("Please guess my number between 1 & 1000: ");
    do {
        
        x = ran();
        
        guessing(x, counter);
        
        //puts("WTF you guessed my number!");
        puts("Play again? y or n:");
        //scanf("%c", &ans);
        getchar();
        ans = getchar();
        if (ans != 'n' || ans != 'N' || ans != 'y' || ans != 'Y')
        {
            counter++;
            continue;
        }
        else
            puts("INVALID ENTRY! BYE!");
        
            
    } while (ans == 'y' || ans == 'Y');
    
    return 0;
}

int
ran(void)
{
    //srand(time(NULL));
    int x = 0;
    return x = rand() % 1000 + 1;
    
}

void
guessing(int x, int c)
{
    // reset guess variable
    int guess = 0;
    int counter = 1;
    
    if (c > 0)
        puts("I've selected my number, guess away!");
        
        do {
            scanf("%d", &guess);
            if (guess < x)
            {
                counter++;
                puts("Too low. Try again.");
            }
            else if (guess > x)
            {
                counter++;
                puts("Too high. Try again.");
            }
        } while (x != guess);
    
    if (counter < 10)
        puts("Either you knew my secret or you got lucky!");
    else if (counter == 10)
        puts("Ahah!");
    else
        puts("You can do better than that!");
    
}