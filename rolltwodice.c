#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int freq[] = { 0 };
	double expected[] = { 0 };

	srand(time(NULL));

	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
			expected[i + j] += 1.0 / 36;

	for (int i = 0; i < 36000; i++)
		freq[1 + rand() % 6 + 1 + rand() % 6]++;

	printf("%10s%10s%10s%10s", "Sum", "Total", "Expected", "Actual\n");
	for (int i = 2; i <= 12; i++)
		printf("%10d%10d%10.3lf%%%10.3lf%%\n",
			i, freq[i], expected[i] * 100, freq[i] / 36000.0 * 100);
}