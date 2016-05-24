//
//  time.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int time(int hs, int min, int sec);

int
main(void)
{
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    
    printf("Please give hours, minutes and seconds as integers: ");
    scanf("%d%d%d:", &hours, &minutes, &seconds);
    
    printf("The time in seconds since the last strike is %d\n", time(hours, minutes, seconds));
    printf("The time until the clock strikes 12 again in seconds is %d.\n", ((12 *60 *60)- time(hours, minutes, seconds)));
    
    return 0;
}

int
time(int hs, int min, int sec)
{
    return hs * 60 * 60 + min * 60 + sec;
    
}