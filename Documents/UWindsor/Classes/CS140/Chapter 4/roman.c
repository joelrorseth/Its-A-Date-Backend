//
//  roman.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int num = 0;            // number
    int tens = 0;           // tens column holder
    int ones = 0;           // ones column holder
    int holder = 0;
    
    
    for (num = 1; num <= 100; num++)
    {
        if(num / 100 == 1)
        {
            puts("C");
        }
        holder = num;
        tens = holder / 10;
        holder %= 10;
        
        if (tens > 0)
        {
            switch (tens) {
                case 1:
                    printf("%s", "X");
                    break;
                case 2:
                    printf("%s", "XX");
                    break;
                case 3:
                    printf("%s", "XXX");
                    break;
                case 4:
                    printf("%s", "XL");
                    break;
                case 5:
                    printf("%s", "L");
                    break;
                case 6:
                    printf("%s", "LX");
                    break;
                case 7:
                    printf("%s", "LXX");
                    break;
                case 8:
                    printf("%s", "LXXX");
                    break;
                case 9:
                    printf("%s", "XC");
                    break;
            }
        }
        
        if (holder > 0)
        {
            switch (holder)
            {
                case 1:
                    printf("%s", "I");
                    break;
                case 2:
                    printf("%s", "II");
                    break;
                case 3:
                    printf("%s", "III");
                    break;
                case 4:
                    printf("%s", "IV");
                    break;
                case 5:
                    printf("%s", "V");
                    break;
                case 6:
                    printf("%s", "VI");
                    break;
                case 7:
                    printf("%s", "VII");
                    break;
                case 8:
                    printf("%s", "VIII");
                    break;
                case 9:
                    printf("%s", "IX");
                    break;

            }
        }
        puts("");
    }
    
    
    return 0;
}
