#include <stdio.h>//printf()
#include <time.h>// time()
#include <stdlib.h>//rand()

int gcd(int sor,int end) {
	int n;
	while (sor != 0) {
		n = sor;
		sor = end % sor;
		end = n;
	}
	return end;
}
int gcd2(int sor, int end) {
	return end != 0 ? gcd2(end, sor % end) : sor;
}

int main(void){
	int divisor;
	int dividend;
	printf("Enter the divisor :");
	scanf("%d", &divisor);
	printf("Enter the dividend :");
	scanf("%d", &dividend);
	printf("The GCD is %d\n",gcd(divisor,dividend) );
	printf("The GCD2 is %d\n", gcd2(divisor, dividend));
}

