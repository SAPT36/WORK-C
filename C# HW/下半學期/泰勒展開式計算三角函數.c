#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

double termOfSin(double);
double termOfCos(double);
double taylorSeries(double, double, double, double(*)(double));

double epsilon, theta, radius;
int choose;

int main(void) {
	printf("%s", "計算三角函數泰勒展開式用，請輸入容許誤差量:");
	scanf("%lf", &epsilon);
	printf("%s", "請輸入計算用的角度:");
	scanf("%lf", &theta);
	radius = theta * M_PI / 180;
	do
	{
		printf("%s", "請選擇要計算的函數(1)sin(2)cos :");
		scanf("%d", &choose);
	} while (!(choose == 1 || choose == 2));
	switch (choose) {
	case 1:
		printf("%lf\n", taylorSeries(radius, epsilon, sin(radius), termOfSin));
		printf("%s", "內建函數計算結果:");
		printf("%lf\n", sin(radius));
		break;
	case 2:
		printf("%lf\n", taylorSeries(radius, epsilon, cos(radius), termOfCos));
		printf("%s", "內建函數計算結果:");
		printf("%lf\n", cos(radius));
		break;
	}
}
double termOfSin(double temp) {
	return temp;
}
double termOfCos(double temp) {
	return 1;
}
double taylorSeries(double x, double min, double builtin, double (*fun)(double y)) {
	double result = 0, term, sign = -1;
	int i;
	term = (*fun)(x);
	if (term == 1)
		i = 0;
	else
		i = 1;
	do {
		result += term;
		term *= sign * x * x / ((i + 1) * (i + 2));
		i += 2;
	} while (fabs(builtin - result) > min);
	if (i % 2 == 1)
		i -= 1;
	i /= 2;
	printf("%s", "泰勒展開式計算的項數:");
	printf("%d\n", i);
	printf("%s", "泰勒展開式計算的結果:");
	return result;
}
