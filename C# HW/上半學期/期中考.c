#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 12

void mean(const unsigned int answer[]);
void bubbleSort(unsigned int a[]);

int main(void) {

	srand(time(NULL));

	puts("1.give 11 different random number");
	puts("2.give the mean of 11");
	puts("3.end");
	puts("Choose 1,2,3:");

	int choose;
	scanf("%d", &choose);
	int g = 0;
	while (g != 1) {
		if (choose == 1) {
			unsigned int a[SIZE - 1] = { 0 };// create array a
			int repeat[256] = { 0 };
			for (size_t i = 0; i < SIZE - 1; ++i) {
				do {
					a[i] = rand() % 256;
				} while (repeat[a[i]]);
				repeat[a[i]]++;
			}
			bubbleSort(a);
			puts("11 different random number : ");
			for (size_t i = 0; i < SIZE - 1; ++i) {
				printf("%d ", a[i]);
			}
		}
		else if (choose == 2) {
			unsigned int d[SIZE] = { 0 };// create array a
			int repeat[256] = { 0 };
			for (size_t i = 0; i < SIZE - 1; ++i) {
				do {
					d[i] = rand() % 256;
				} while (repeat[d[i]]);// repeat[d[i]]為true表示d[i]值重複過(0為false,1為true)
				repeat[d[i]]++;
			}
			bubbleSort(d);
			mean(d);
		}
		else if (choose == 3) {
			printf("%s", "Byte! Byte!");
			break;
		}

		puts("\n\n1.give 11 different random number");
		puts("2.give the mean of 11");
		puts("3.end");
		puts("Choose 1,2,3:");

		scanf("%d", &choose);
	}
}
// function that sorts an array with bubble sort algorithm
void bubbleSort(unsigned int a[])
{
	// loop to control number of passes
	for (unsigned int pass = 1; pass < SIZE; ++pass) {

		// loop to control number of comparisons per pass
		for (size_t j = 0; j < SIZE - 1; ++j) {

			// swap elements if out of order
			if (a[j] > a[j + 1]) {
				unsigned int hold = a[j];
				a[j] = a[j + 1];
				a[j + 1] = hold;
			}
		}
	}
}
void mean(unsigned int answer[])
{
	unsigned int total = 0; // variable to hold sum of array elements

	// total response values
	for (size_t j = 0; j < SIZE; ++j) {
		total += answer[j];
	}

	printf(" The mean value for this run is: %u / %u = %.4f", total, SIZE - 1, (double)total / SIZE - 1);
}
