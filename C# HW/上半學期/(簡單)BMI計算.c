#include <stdio.h>
int main() {
	int h, w;
	printf("Please enter your height(in inches):");
	scanf("%d", &h);
	printf("Please enter your weight(in pounds):");
	scanf("%d", &w);

	printf("Your BMI is %d\n\n", (w*703)/(h*h));

	printf("BMI VALUES\nUnderweight:  less than 18.5\n");
	printf("Normal:       between 18.5 and 24.9\nOverweight:   between 25 and 29.9\n");
	printf("Obese:        30 or greater");
}
https://1drv.ms/u/s!ArVFrCEec1RmgnyZgTsZn1oQSS1S?e=rHk448
