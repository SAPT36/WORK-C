#include <stdio.h>

int main(void)
{
	double begin;
	double end;
	printf("Enter begin temperatures(in Celsius):\n");
	scanf("%lf", &begin);

	printf("Enter end temreratures(in Celsius):\n");
	scanf("%lf", &end);

	printf("%7s%21s\n", "Celsius", "Fahrenheit");

	double fahrenheit;


	for (double i = begin; i <= end;i++) {
		fahrenheit = 1.8 * i + 32;
	    printf("%7.2lf%21.2lf\n", i, fahrenheit);
	}
}


