#include <stdio.h>

int main(void)
{
	double pi = 0;
	double arr[4];
	int n[] = { 0,0,0,0 };

	for (int i = 1; i <= 400; i++) {
		if (i % 2 == 0)
			pi -= (double)4 / (double)(i * 2 - 1);
		else
			pi += (double)4 / (double)(i * 2 -1);
		if (pi - 3.14 < 0.001 && pi - 3.14 > 0.0 && !n[0]) {
			n[0] = i; arr[0] = pi;
		}
		else if(pi - 3.141 < 0.0001 && pi - 3.141 > 0.0 && !n[1]) {
			n[1] = i; arr[1] = pi;
		}
		else if (pi - 3.1415 < 0.00001 && pi - 3.1415 > 0.0 && !n[2]) {
			n[2] = i; arr[2] = pi;
		}
		else if (pi - 3.14159 < 0.000001 && pi - 3.14159 > 0.0 && !n[3]) {
			n[3] = i; arr[3] = pi;
		}
		printf("%6d%20.6f\n", i, pi);
	}
	printf("The term of this series before first get 3.14 is %d%20.6f\n",n[0],arr[0]);
	printf("The term of this series before first get 3.141 is %d%20.6f\n", n[1], arr[1]);
	printf("The term of this series before first get 3.1415 is %d%20.6f\n", n[2], arr[2]);
	printf("The term of this series before first get 3.14159 is %d%20.6f\n", n[3], arr[3]);
}
