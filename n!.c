#include <stdio.h> 
 
int main(void)
{
	int n;
	int m = 1;
	int sum = 1;

	printf("Enter a positive integer:");
	scanf("%d", &n);
	while (n < 0) {
		printf("Error! Please enter again!\n");
		printf("Enter a positive integer:");
		scanf("%d", &n);

	}
	for (m = n; m > 0; m--)
		sum *= m;
		printf("%d!=%d\n", n, sum);
		sum = 1;
		system("PAUSE");
		return 0;
}