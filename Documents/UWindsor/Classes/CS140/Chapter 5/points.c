//
//  points.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

enum points {F, D, C, B, A, DEF};
enum points grade;

int qualitypoints(double avg);


int
main(void)
{
    double grd = 0;
    int acounter, bcounter, ccounter, dcounter, fcounter = 0;
    
    do {
        printf("Please enter grade, (-1 to exit): ");
        scanf("%lf", &grd);
        if (grd < -1 || grd > 100)
        {
            puts("INVALID ENTRY!");
            continue;
        }
        else
        {
        switch (qualitypoints(grd)) {
            case A:
                acounter++;
                break;
            case B:
                bcounter++;
                break;
            case C:
                ccounter++;
                break;
            case D:
                dcounter++;
                break;
            case F:
                fcounter++;
            default:
                break;
        }
        }
    }while (grd != -1);
        
    puts("Grade Range\t\tTotal Number");
    printf("100 thru 90 %%\t\t%6d\n", acounter);
    printf("90 thru 80 %%\t\t%6d\n", bcounter);
    printf("80 thru 70 %%\t\t%6d\n", ccounter);
    printf("70 thru 60 %%\t\t%6d\n", dcounter);
    printf("Less than 60 %%\t\t%6d\n", fcounter);
    
    return 0;
}

int
qualitypoints(double avg)
{
    if (avg == -1)
        grade = DEF;
    else if (avg < 60)
        grade = F;
    else if (avg < 70)
        grade = D;
    else if (avg < 80)
        grade = C;
    else if (avg < 90)
        grade = B;
    else if (avg < 100)
        grade = A;
    
    return grade;
}




