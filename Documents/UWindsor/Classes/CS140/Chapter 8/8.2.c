//
//  8.2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <ctype.h>

int
main(void)
{
    printf("%s\n%s%s\n%s%s\n\n", "Accoding to isdigit: ",
           isdigit('8') ? "8 is a " : "8 is not a ", "digit",
           isdigit('#') ? "# is a " : "# is not a ", "digit");
    
    printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n", "Accoding to isalpha:",
           isalpha('A') ? "A is a " : "A is not a ", "letter",
           isalpha('b') ? "b is a " : "b is not a ", "letter",
           isalpha('&') ? "& is a ": "& is not a ", "letter",
           isalpha('4') ? "4 is a " : "4 is not a ", "letter");
    
    printf("%s\n%s%s\n%s%s\n%s%s\n\n", "According to isalnum:",
          isalnum('A') ? "A is a " : "A is not a ", "digit or letter.",
          isalnum('8') ? "8 is a " : "8 is not a ", "digit or letter.",
          isalnum('#') ? "# is a " : "# is not a ", "digit or letter.");
    
    printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n",
           "According to isxdigit:",
           isxdigit('F') ? "F is a " : "F is not a ", "Hex digit",
           isxdigit('J') ? "J is a " : "J is not a ", "hex digit",
           isxdigit('7') ? "7 is a " : "7 is not a ", "hex digit",
           isxdigit('#') ? "# is a " : "# is not a ", "hex digit",
           isxdigit('f') ? "f is a " : "f is not a ", "hex digit");
    
    
    
    return 0;
}