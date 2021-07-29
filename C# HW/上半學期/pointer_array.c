#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 12

void mean(const unsigned int answer[]);
void bubbleSort(unsigned int a[]);

int main(void) {

	srand(time(NULL));

	puts("1.give 11 different random number");
	puts("2.give 11 different random number(2)");
	puts("3.give 11 different random number(3)");
	puts("4.give 11 different random number(4)");
	puts("5.give the mean of 11");
	puts("6.end");
	puts("Choose 1,2,3,4,5,6:");

	int choose;
	scanf("%d", &choose);
	int g = 0;
	while (g != 1) {
		if (choose == 1) {
			unsigned int a[SIZE-1] = { 0 };// create array a
			int* aPtr = a;
			int repeat[256] = { 0 };
			for (size_t i = 0; i < SIZE-1; ++i) {
				do {
					a[i] = rand() % 256;
				} while (repeat[a[i]]);
				repeat[a[i]]++;
			}
			bubbleSort(a);
			puts("11 different random number : ");
			for (size_t offset = 0; offset < SIZE-1; ++offset) {
				printf("*(bPtr + %u) = %d\n", offset, *(aPtr + offset));
			}
		}
		else if (choose == 2) {
			unsigned int a[SIZE - 1] = { 0 };// create array a
			int* aPtr = a;
			int repeat[256] = { 0 };
			for (size_t i = 0; i < SIZE - 1; ++i) {
				do {
					a[i] = rand() % 256;
				} while (repeat[a[i]]);
				repeat[a[i]]++;
			}
			bubbleSort(a);
			puts("11 different random number(Array index notation) : ");
			for (size_t i = 0; i < SIZE-1; ++i) {
				printf("b[%u] = %d\n", i, a[i]);
			}
		}
		else if (choose == 3) {
			unsigned int a[SIZE - 1] = { 0 };// create array a
			int* aPtr = a;
			int repeat[256] = { 0 };
			for (size_t i = 0; i < SIZE - 1; ++i) {
				do {
					a[i] = rand() % 256;
				} while (repeat[a[i]]);
				repeat[a[i]]++;
			}
			bubbleSort(a);
			puts("11 different random number(Pointer/offset notation) : ");
			for (size_t offset = 0; offset <SIZE-1; ++offset) {
				printf("*(b + %u) = %d\n", offset, *(a + offset));
			}
		}
		else if (choose == 4) {
			unsigned int a[SIZE - 1] = { 0 };// create array a
			int* aPtr = a;
			int repeat[256] = { 0 };
			for (size_t i = 0; i < SIZE - 1; ++i) {
				do {
					a[i] = rand() % 256;
				} while (repeat[a[i]]);
				repeat[a[i]]++;
			}
			bubbleSort(a);
			puts("11 different random number(Pointer index notation) : ");
			for (size_t i = 0; i < SIZE-1; ++i) {
				printf("bPtr[%u] = %d\n", i, aPtr[i]);
			}
		}

		else if (choose == 5) {
			unsigned int d[SIZE] = { 0 };// create array a
			int repeat[256] = { 0 };
			for (size_t i = 0; i < SIZE - 1; ++i) {
				do {
					d[i] = rand() % 256;
				} while (repeat[d[i]]);
				repeat[d[i]]++;
			}
			bubbleSort(d);
			mean(d);
		}
		else if (choose == 6) {
			printf("%s", "Byte! Byte!");
			break;
		}

		puts("\n\n1.give 11 different random number");
		puts("2.give 11 different random number(2)");
		puts("3.give 11 different random number(3)");
		puts("4.give 11 different random number(4)");
		puts("5.give the mean of 11");
		puts("6.end");
		puts("Choose 1,2,3,4,5,6:");

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

	printf(" The mean value for this run is: %u / %u = %.4f", total, SIZE-1, (double)total / SIZE-1);
}
