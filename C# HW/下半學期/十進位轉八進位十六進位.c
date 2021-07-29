#include <stdio.h>
#include <conio.h>

void displayHexs(unsigned int value);
void displayOcts(unsigned int value);
void displayOcts1(unsigned int, char*);
int main(void) {
	char test[13];
	unsigned int number1 = 65535;
	unsigned int numbera = 0;
	unsigned int numberb = 0;
	unsigned int numberc = 0;
	unsigned int numberd = 0;
	unsigned int numbere = 0;
	unsigned int mask = 1;
	displayHexs(number1);
	displayOcts(number1);
	displayOcts1(number1, test);
	printf("=%s\n", test);
	displayHexs(mask);
	displayOcts(mask);
	displayOcts1(mask, test);
	printf("=%s\n", test);
	number1 = 15;
	unsigned int setBits = 241;
	displayHexs(number1);
	displayOcts(number1);
	displayOcts1(number1, test);
	printf("=%s\n", test);
	displayHexs(setBits);
	displayOcts(setBits);
	displayOcts1(setBits, test);
	printf("=%s\n", test);
	number1 = 139;
	unsigned int number2 = 199;
	displayHexs(number1);
	displayOcts(number1);
	displayOcts1(number1, test);
	printf("=%s\n", test);
	displayHexs(number2);
	displayOcts(number2);
	displayOcts1(number2, test);
	printf("=%s\n", test);
	number1 = 21845;
	displayHexs(number1);
	displayOcts(number1);
	displayOcts1(number1, test);
	printf("=%s\n", test);
	number1 <<= 4;
	displayHexs(number1);
	displayOcts(number1);
	displayOcts1(number1, test);
	printf("=%s\n", test);
	number1 <<= 4;
	displayHexs(number1);
	displayOcts(number1);
	displayOcts1(number1, test);
	printf("=%s\n", test);
	number1 <<= 4;
	displayHexs(number1);
	displayOcts(number1);
	displayOcts1(number1, test);
	printf("=%s\n", test);
	number1 <<= 4;
	displayHexs(number1);
	displayOcts(number1);
	displayOcts1(number1, test);
	printf("=%s\n", test);
	printf("Enter a number: ");
	scanf("%d", &number1);
	displayHexs(number1);
	displayOcts(number1);
	displayOcts1(number1, test);
	printf("=%s\n", test);

	char type;
	do {
		while ((type = _getch()) != -32);
		type = _getch();
		if (72 == type) {
			printf("Enter two number: ");
			scanf("%d%d", &numbera, &numberb);
			numberc = numbera & numberb;
			numberd = numbera | numberb;
			numbere = numbera ^ numberb;
			printf(" and = %d\n or = %d\n xor = %d\n\n", numberc, numberd, numbere);
			displayHexs(numberc);
			displayOcts(numberc);
			displayOcts1(numberc, test);
			printf("=%s\n", test);
			displayHexs(numberd);
			displayOcts(numberd);
			displayOcts1(numberd, test);
			printf("=%s\n", test);
			displayHexs(numbere);
			displayOcts(numbere);
			displayOcts1(numbere, test);
			printf("=%s\n", test);
		}
		if (77 == type) {
			displayHexs(number1);
			displayOcts(number1);
			displayOcts1(number1, test);
			printf("=%s\n", test);
			number1 >>= 1;
		}
		if (75 == type) {
			displayHexs(number1);
			displayOcts(number1);
			displayOcts1(number1, test);
			printf("=%s\n", test);
			number1 <<= 1;
		}

	} while (type != 80);
}

void displayOcts(unsigned int value) {
	unsigned int displayMask = 3 << 30;
	printf(" = O");

	unsigned int temp;
	temp = (value & displayMask) >> 30;
	putchar(temp + 48);
	displayMask = 7 << 29;
	value <<= 2;
	for (unsigned int c = 1; c <= 10; ++c) {
		temp = (value & displayMask) >> 29;
		putchar(temp + 48);
		value <<= 3;
	}
}

void displayOcts1(unsigned int value, char* tempptr) {
	unsigned int displayMask = 3 << 30;
	*tempptr = '0';
	tempptr++;

	unsigned int temp;
	temp = (value & displayMask) >> 30;
	*tempptr = (temp + 48);
	tempptr++;
	displayMask = 7 << 29;
	value <<= 2;
	for (unsigned int c = 1; c <= 10; ++c) {
		temp = (value & displayMask) >> 29;
		*tempptr = (temp + 48);
		tempptr++;
		value <<= 3;
	}
	*tempptr = '\0';
}

void displayHexs(unsigned int value) {
	unsigned int displayMask = 15 << 28;
	printf("%10u = Ox", value);

	unsigned int temp;
	for (unsigned int c = 1; c <= 8; ++c) {
		temp = (value & displayMask) >> 28;
		if (temp < 10) {
			putchar(temp + 48);
		}
		else {
			putchar(temp + 55);
		}
		value <<= 4;
	}
}