//
//  xmas.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    for (int x = 1; x <= 12; x++)
    {
        printf("%s", "On the ");
        switch (x)
        {
            case 1:
                printf("first ");
                break;
            case 2:
                printf("second ");
                break;
            case 3:
                printf("third ");
                break;
            case 4:
                printf("forth ");
                break;
            case 5:
                printf("fifth ");
                break;
            case 6:
                printf("sixth ");
                break;
            case 7:
                printf("seventh ");
                break;
            case 8:
                printf("eigth ");
                break;
            case 9:
                printf("ninth ");
                break;
            case 10:
                printf("tenth ");
                break;
            case 11:
                printf("elventh ");
                break;
            case 12:
                printf("twelfth ");
                break;
        }
        
        puts("day of Christmas,\nmy true love gave to me,\n");
        
        switch (x) {
            case 12:
                puts("Twelve drummers drumming,");
            case 11:
                puts("Eleven pipers piping,");
            case 10:
                puts("Ten lords-a-leaping,");
            case 9:
                puts("Nine ladies dancing,");
            case 8:
                puts("Eight maids-a-milking,");
            case 7:
                puts("Seven swans-a-swimming,");
            case 6:
                puts("Six geese-a-laying,");
            case 5:
                puts("Five golden rings,");
            case 4:
                puts("Four calling birds,");
            case 3:
                puts("Three french hens,");
            case 2:
                puts("Two turtle doves,");
                puts("And a partridge in a pear tree.");
                break;
                
                
            default:
                puts("A partridge in a pear tree.");
        }
        puts("");
    }
    
    return 0;
}