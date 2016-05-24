//
//  assign1.c
//  
//
//  PEARSON, Ryan
//  Date Jan, 30, 2013
//  Student ID: 103965059
//  Purpose: Create cash register receipt
//  I ATTEST THAT THIS IS FULLY MY OWN WORK
//
/* THIS TEMPLATE IS WRITTEN BY DR. ZIAD KOBTI TO BE USED FOR ASSIGNMENT 1
 YOU NEED TO MODIFY THE TODO SECTIONS AND ADD WHAT IS NECESSARY TO SOLVE
 THE ASSIGNMENT QUESTION.
 (C)2013 DR. ZIAD KOBTI.
 */

#include <stdio.h>
#include <math.h>


// function prototypes
void PrintHeader();
void PrintFooter();

// PrintHeader: Display the header information of the receipt
// Input: no paramenters required, call it at the start of a new receipt
// Output: no return, simply outputs the appropriate header messages
void PrintHeader()
{
	int x = 1;                      // initialize counter variable
    
    // creates line
    while ( x <= 73)
    {
        printf("%s", "-");
        x++;
    }
    
    // insert 2 blank lines WMFF header and welcome info
    puts("\n\n\t\t    _-=== Windsor Market Farm Fresh ===-_\n");
    puts("Welcome!");
    
    
    // Print the header lines, title, and the welcome message--- Done
    
    
}


// PrintFooter: Display the footer information of the receipt
// Input: no paramenters required, call it at the end of a receipt
// Output: no return, simply outputs the appropriate footer messages
void PrintFooter()
{
    int x = 1;                      // initialize counter variable
    
    // creates line break
    while ( x <= 73)
    {
        printf("%s", "-");
        x++;
    }
    
    // print blank lines and thank you
    puts("\n\nTHANK YOU FOR SHOPPING AT WINDSOR MARKET FARM FRESH, PLEASE COME AGAIN\n");
    
    x = 1;                      // counter variable reset
    
    // create line break
    while ( x <= 73)
    {
        printf("%s", "-");
        x++;
    }
    puts("");
	//Print the footer lines and thank you message---- Done
}


int main()
{
	//Variable Declarations and Initializations here----- Done
	int code=0;                 // use this variable to enter the product codes
    float quan = 0;             // quantity variable
    int x = 1;                  // variable to create line
    double stotal = 0;           // subtotal variable
    double tax = 0;              // tax variable
    
	// Display Heading
	PrintHeader();
    
    
	// Main program loop
	do
	{
            // prompt user for item code and Quantity
            printf("%s", "Enter Item code: ");
            scanf("%d", &code);
        
            // capture invalid codes entered into the system... or proper code.
            if ((code / 10000) == 0 && code != 00)
                puts("<INVALID CODE, PLEASE TRY AGAIN>");
        
            else if ((code / 10000) > 6)
                puts("<INVALID CODE, PLEASE TRY AGAIN>");
        
            else if (code == 0)
                printf("%s", "");
            
            else if (code < 0)
                puts("<INVALID CODE, PLEASE TRY AGAIN>");

        
        
            // capture items in Department 1 error code
            else if ((code / 10000) == 1 && (code / 1000) > 13)
                puts("<INVALID CODE, PLEASE TRY AGAIN>");
        
            // capture items in Department 1 acceptable
            else if ((code / 10000) == 1 && (code / 1000) <= 13)
            {
                // get quantity from user, check for negative entry and don't allow
                
                do
                {
                    printf("%s", "Enter Quantity: ");
                    scanf("%f", &quan);
                }while (quan < 0);
                
                printf("\t> Produce Bulk, ");
                code %= 10000;
                        
                // capture sub-grouping, use existing variable "tax" as holder for math functions
                // calculate line item totals, round to nearest 2nd
                // store running subtotal
                if ((code / 1000) == 1)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    stotal += (tax * quan);
                    printf("local vegetables, $%.2f/lb @ %.1f =\t$%.2f\n", tax, quan, floorf((tax * quan) * 100.0 + .5) / 100.0);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                   
                }
                else if ((code / 1000) == 2)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    stotal += (tax * quan);
                    printf("local fruits, $%.2f/lb @ %.1f =\t\t$%.2f\n", tax, quan, floorf((tax * quan) * 100.0 + .5) / 100.0);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                    
                }
                else if ((code / 1000) == 3)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    stotal += (tax * quan);
                    printf("imports, $%.2f/lb @ %.1f =\t\t$%.2f\n", tax, quan, floorf((tax * quan) * 100.0 + .5) / 100.0);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                    
                }
            }

        

            // capture items in Department 2 error code
            else if ((code / 10000) == 2 && (code / 1000) > 23)
                puts("<INVALID CODE, PLEASE TRY AGAIN>");
        
            // capture items in Department 2 acceptable
            else if ((code / 10000) == 2 && (code / 1000) <= 23)
            {
                // get quantity from user, check for negative entry and don't allow
                
                do
                {
                    printf("%s", "Enter Quantity: ");
                    scanf("%f", &quan);
                }while (quan < 0);
                
                printf("\t> Produce Item, ");
                code %= 10000;
                    
                // capture sub-grouping, use existing variable "tax" as holder for math functions
                // calculate line item totals, round to nearest 2nd
                // store running subtotal
                if ((code / 1000) == 1)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    stotal += (tax * quan);
                    printf("local vegetables, $%.2f each @ %.0f =\t$%.2f\n", tax, quan, floorf((tax * quan) * 100.0 + .5)/100.0);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                    
                }
                else if ((code / 1000) == 2)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    stotal += (tax * quan);
                    printf("local fruits, $%.2f each @ %.0f =\t\t$%.2f\n", tax, quan, floorf((tax * quan) * 100.0 + .5)/100.0);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                    
                }
                else if ((code / 1000) == 3)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    stotal += (tax * quan);
                    printf("imports, $%.2f each @ %.0f =\t\t$%.2f\n", tax, quan, floorf((tax * quan) * 100.0 + .5)/100.0);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                    
                }
            }
                   
        
        
            // capture items in Department 3 error code
            else if ((code / 10000) == 3 && (code / 1000) > 33)
                puts("<INVALID CODE, PLEASE TRY AGAIN>");
        
            // capture items in Department 3 acceptable
            else if ((code / 10000) == 3 && (code / 1000) <= 33)
            {
                // get quantity from user, check for negative entry and don't allow
                
                do
                {
                    printf("%s", "Enter Quantity: ");
                    scanf("%f", &quan);
                }while (quan < 0);
                
                printf("\t> Floral, ");
                code %= 10000;
                    
                // capture sub-grouping, use existing variable "tax" as holder for math functions
                // calculate line item totals, round to nearest 2nd
                // store running subtotal
                if ((code / 1000) == 1)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    stotal += (tax * quan);
                    printf("roses, $%.2f each @ %.0f =\t\t\t$%.2f\n", tax, quan, roundf((tax * quan) * 100.0)/100.0);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                    
                }
                else if ((code / 1000) == 2)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    stotal += (tax * quan);
                    printf("bouquet, $%.2f each @ %.0f =\t\t\t$%.2f\n", tax, quan, roundf((tax * quan) * 100.0)/100.0);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                    
                }
                else if ((code / 1000) == 3)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    stotal += (tax * quan);
                    printf("house plant, $%.2f each @ %.0f =\t\t\t$%.2f\n", tax, quan, roundf((tax * quan) * 100.0)/100.0);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                    
                }
            }
            
        
        
            //capture items in department 4 error code
            else if ((code / 10000) == 4 && (code / 1000) > 44)
                puts("<INVALID CODE, PLEASE TRY AGAIN>");
        
            // capture items in department 4 acceptable
            else if ((code / 10000) == 4 && (code / 1000) <= 44)
            {
                // get quantity from user, check for negative entry and don't allow
                do
                {
                    printf("%s", "Enter Quantity: ");
                    scanf("%f", &quan);
                }while (quan < 0);
                
                printf("\t> Dairy, ");
                code %= 10000;
                    
                // capture sub-grouping, use existing variable "tax" as holder for math functions
                // calculate line item totals, round to nearest 2nd
                // store running subtotal
                if ((code / 1000) == 1)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    stotal += (tax * quan);
                    printf("milk, $%.2f each @ %.0f =\t\t\t\t$%.2f\n", tax, quan, floorf((tax * quan) * 100.0 + .5 )/100.0);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                    
                }
                else if ((code / 1000) == 2)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    stotal += (tax * quan);
                    printf("eggs, $%.2f each @ %.0f =\t\t\t\t$%.2f\n", tax, quan, floorf((tax * quan) * 100.0 + .5 )/100.0);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                    
                }
                else if ((code / 1000) == 3)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    printf("butter, $%.2f each @ %.0f =\t\t\t$%.2f\n", tax, quan, floorf((tax * quan) * 100.0 + .5 )/100.0);
                    stotal += (tax * quan);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                }
                else if ((code / 1000) == 4)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    stotal += (tax * quan);
                    printf("yogurt, $%.2f each @ %.0f =\t\t\t$%.2f\n", tax, quan, floorf((tax * quan) * 100.0 + .5 )/100.0);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                    
                }
            }
            
                    
            //Capture items in department 5 error code
            else if ((code / 10000) == 5 && (code / 1000) > 55)
                puts("<INVALID CODE, PLEASE TRY AGAIN>");
        
            //capture items in Department 5 acceptable
            else if ((code / 10000) == 5 && (code / 1000) <= 55)
            {
                // get quantity from user, check for negative entry and don't allow
                
                do
                {
                printf("%s", "Enter Quantity: ");
                scanf("%f", &quan);
                }while (quan < 0);
                
                printf("\t> Meats, ");
                code %= 10000;
                
                    
                // capture sub-grouping, use existing variable "tax" as holder for math functions
                // calculate line item totals, round to nearest 2nd
                // store running subtotal
                if ((code / 1000) == 1)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    stotal += (tax * quan);
                    printf("beef, $%.2f each @ %.0f =\t\t\t\t$%.2f\n", tax, quan, floorf((tax * quan) * 100.0 + .5 )/100.0);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                    
                }
                else if ((code / 1000) == 2)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    stotal += (tax * quan);
                    printf("chicken, $%.2f each @ %.0f =\t\t\t$%.2f\n", tax, quan, floorf((tax * quan) * 100.0 + .5 )/100.0);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                    
                }
                else if ((code / 1000) == 3)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    stotal += (tax * quan);
                    printf("turkey, $%.2f each @ %.0f =\t\t\t$%.2f\n", tax, quan, floorf((tax * quan) * 100.0 + .5 )/100.0);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                    
                }
                else if ((code / 1000) == 4)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    stotal += (tax * quan);
                    printf("pork, $%.2f each @ %.0f =\t\t\t\t$%.2f\n", tax, quan, floorf((tax * quan) * 100.0 + .5 )/100.0);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                    
                }
                else if ((code / 1000) == 5)
                {
                    code %= 1000;
                    tax = code;
                    tax /= 100.0;
                    stotal += (tax * quan);
                    printf("rabbit, $%.2f each @ %.0f =\t\t\t$%.2f\n", tax, quan, floorf((tax * quan) * 100.0 + .5 )/100.0);
                    code = 1;                           // set code to 1 to catch system from kicking out of free item
                    
                }
            }
            
                    
            // capture items in department 6, no subgroup
            // calculate line item totals, round to nearest 2nd
            // store running subtotal
            else if ((code / 10000) == 6 && (code / 1000) != 60)
                puts("<INVALID CODE, PLEASE TRY AGAIN>");
            
            
            else if ((code / 10000) == 6 && (code / 1000) == 60)
            {
                do                                      // catch negative quantity
                {
                    printf("%s", "Enter Quantity: ");
                    scanf("%f", &quan);
                } while (quan < 0);
                code %= 1000;
                tax = code;
                tax /= 100.0;
                stotal += (tax * quan);
                printf("\t> Other, other item $%.2f each @ %.0f =\t\t\t$%.2f\n", tax, quan, floorf((tax * quan) * 100.0 + .5 )/100.0);
                code = 1;                           // set code to 1 to catch system from kicking out of free item
                
            }
        
                        
                           
		// Prompt for item, get the quantity, update sub-total;---- Done
		// if the code is 00 you should compute totals and calculate the change.
        
       
        
	}while(code != 0);	// this loop will keep repeating until a code of zero is entered! (00=0)
    
    // creates line break
    while ( x <= 73)
    {
        printf("%s", "-");
        x++;
    }

    // print sub total and tax & new line, round to nearest 2nd
    printf("\n\t> SUB-TOTAL\t$%2.2f\n", floorf(stotal * 100.0 + .5 ) / 100.0);
    tax = (stotal * .07);
    
    // account for space in the decimal area based on how much the bill is for (match sub total alignment with tax decimal)
    if ((((int)stotal / 10000) > 0) && (tax <= 1000))
        printf("\t> TAX@7%%\t$  %.2f\n", floorf(tax * 100.0 + .5) / 100.0);
    else if ((((int)stotal / 10000) > 0) && (tax > 1000))
        printf("\t> TAX@7%%\t$ %.2f\n", floorf(tax * 100.0 + .5) / 100.0);
    else if ((((int)stotal / 1000) > 0) && (tax <= 100))
        printf("\t> TAX@7%%\t$  %.2f\n", floorf(tax * 100.0 + .5) / 100.0);
    else if ((((int)stotal / 1000) > 0) && (tax > 100))
        printf("\t> TAX@7%%\t$ %.2f\n", floorf(tax * 100.0 + .5) / 100.0);
    else if ((((int)stotal / 100) > 0) && (tax <= 10))
        printf("\t> TAX@7%%\t$  %.2f\n", floorf(tax * 100.0 + .5) / 100.0);
    else if ((((int)stotal / 100) > 0) && (tax > 10))
        printf("\t> TAX@7%%\t$ %.2f\n", floorf(tax * 100.0 + .5) / 100.0);
    else if (((int)stotal / 10) > 0)
        printf("\t> TAX@7%%\t$ %.2f\n", floorf(tax * 100.0 + .5) / 100.0);
    else
        printf("\t> TAX@7%%\t$%.2f\n", floorf(tax * 100.0 + .5) / 100.0);
    
    
    x = 1;                          // reset counter
    
    // creates line break
    while ( x <= 73)
    {
        printf("%s", "-");
        x++;
    }
    
    
    // display total & new line
    stotal += tax;
    
    //printf("\n\t> TOTAL\t\t$%.2f\n", floor(stotal * 100.0 +.5) / 100.0);    // rounding does not work on example
    //printf("\n\t> TOTAL\t\t$%.2f\n", round(stotal * 100.0 + .5) / 100.0);   // rounding does not work on example
    printf( "\n\t> TOTAL\t\t$%.2f\n", (stotal * 100.0 + .5) / 100.0 );
    
    x = 1;                          // reset counter
    
    // creates line break
    while ( x <= 73)
    {
        printf("%s", "-");
        x++;
    }
    
    // calculate change due. re-use variables no longer in play (quan)
    // perform loop when change due is is negative as money is still owing, encourage proper amount of money.
    
    do
    {
        printf("\n\nEnter CASH AMOUNT: ");
        scanf("%f", &quan);
        if ((quan - stotal) < 0)
            printf("\t>INSUFFICIENT FUNDS-- TOTAL IS: $%.2f", (stotal * 100.0 + .5) / 100.0 );
        else
            printf("\t>CHANGE TO CUSTOMER DUE: $%.2f\n\n", floorf((quan - stotal) * 100.0 - .5) / 100.0 );
    }while ((quan - stotal) < 0);

	// Display Footer
	PrintFooter();
    
	return 0;
}