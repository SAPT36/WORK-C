#include <stdio.h>

int main(void)
{
	float principal, rate, days;
	
	printf("Enter loan principal(-1 to end):");
	scanf("%f", &principal);

	if (principal == -1)
	{
		printf("Thanks for using!");

	}

	while (principal != -1)
	{
		printf("Enter interest rate:");
		scanf("%f", &rate);

		printf("Enter term of the loan in days:");
		scanf("%f", &days);

		printf("The interest charge is $%.2f\n\n\n", (float)principal*rate*days/365);

		printf("Enter loan principal(-1 to end):");
		scanf("%f", &principal);
		if (principal == -1)
		{
			printf("Thanks for using!");
		}
	}

}