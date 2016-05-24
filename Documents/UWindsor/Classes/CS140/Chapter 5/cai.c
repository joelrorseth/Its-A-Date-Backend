//
//  cai.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int question(int add, int holder);
void ncomments(void);
void pcomments(void);

int
main(void)
{
    srand(time(NULL));
    int ans = 0;
    int value = 0;
    char yesno, dummy;
    int countright, countwrong, countwrong2 = 1;
    int mod = 10;
    int level = 2;
    
    do {
        if (countright == 5)
        {
            printf("You have %d right answers, and %d wrong answers.\n", countright, countwrong);
            printf("Doing good, let's get a bit harder!\n");
            value = question(2, mod);
            mod += 5;
            countwrong = 1;
            countwrong2 = 1;
            countright = 1;
            level += 1;
            printf("You have reached level %d!\n", level);
        }
        else if (countwrong == 5 && mod > 5)
        {
            printf("You have %d right, and %d wrong.\n", countright, countwrong);
            printf("Lets make this a bit easier...\n");
            value = question(-2, mod);
            mod -= 5;
            countwrong = 1;
            countwrong2 = 1;
            countright = 1;
            level -= 1;
            printf("We'll set you back to level %d!\n", level);
        }
        else if (countwrong == 5 && mod == 5)
        {
            printf("I can't really make this much easier, keep practicing.\n");
            value = question(0, mod);
            countwrong = 1;
            countwrong2 = 1;
            countright = 1;
        }
        else
            value = question(0, mod);
    
        do {
            printf("Your Answer is: ");
            scanf("%d%c", &ans, &dummy);
            if (ans == value)
            {
                pcomments();
                countright++;
            }
            else if(ans != value && countwrong2 == 2)
            {
                printf("Incorrect.\nThe correct answer is %d.\n", value);
                countwrong2 = 1;
                countwrong++;
                break;
            }
            else if( ans != value && countwrong < 10)
            {
                ncomments();
                countwrong++;
                countwrong2++;
            }

        }while(ans != value);
        
    printf("Would you like to play again? Y or N ");
    scanf("%c%c", &yesno, &dummy);
    }while (yesno == 'y' || yesno == 'Y');
    
    return 0;
}

int
question(int add, int holder)
{
    int value1, value2, q1 = 0;
    
    holder += add;

    value1 = rand() % holder;
    value2 = rand() % holder;
    
    printf("%d x %d = ?\n", value1, value2);
    return q1 = value1 * value2;
    
}

void
pcomments(void)
{
    int comment = rand() % 4;
    switch (comment) {
        case 0:
            printf("Very good!\n");
            break;
        case 1:
            printf("Excellent!\n");
            break;
        case 2:
            printf("Nice work!\n");
            break;
        case 3:
            printf("Keep up the good work!\n");
            break;

    }
}

void
ncomments(void)
{
    int comment = rand() % 4;
    switch (comment) {
        case 0:
            printf("No. Please try again.\n");
            break;
        case 1:
            printf("Wrong. Try again.\n");
            break;
        case 2:
            printf("Don't give up!\n");
            break;
        case 3:
            printf("No. Keep Trying.\n");
            break;
    }
}