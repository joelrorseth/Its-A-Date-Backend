#include <stdio.h>

int main()
{
	int x=0;
	int reverse=0;
	int hold=0;
	int loop=0;

	do
	{

	printf("\nPlease enter a 4 or 5 digit integer palindrome: ");
	scanf("%d", &x);

	if ( 1 <= x/10000 && x/10000 <= 9 || 1 <= x/1000 && x/1000 <= 9)
	{
	hold = x;
	reverse = 0;
	while( x != 0 )
		{
			reverse = reverse * 10; //12345	50	540	5430	54320
			reverse = reverse + x%10; //5	54	543	5432	54321
			x = x/10; //1234		123	12	1	0
		}
	if ( hold == reverse )
	{	
	printf("%d is a palindrome!\n\n", hold);
	loop = 1;
	}
	else if (hold != reverse)
	printf("%d is not a palindrome!!!\n\n", hold);
	}

	else
	printf("Your entry is invalid!");

	}while(loop == 0);


	return 0;
}
