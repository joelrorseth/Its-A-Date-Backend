//
//  atof.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int
main(void)
{
    char s[] = " 9232hi my name is ";
    double val, power;
    int i, sign;
    double number;
    char *s1;
    
    
    for (i = 0; isspace (s[i]); i++);
    sign = (s[i] == '-') ? -1: 1;
    if (s[i] == '+' || s[i] == '-') i++;
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        if (s[i] == '.') i++;
        for (power = 1.0; isdigit(s[i]); i++){
            val = 10.0 * val + (s[i] - '0');
            power *= 10.0;
        }
    }
    printf("%lf\n", val/power);
    number = strtod(s,&s1);
    while (number > 10) {
        number/=10;
    }
    printf("%.2lf, %s\n", number, s1);
    return 0;
}