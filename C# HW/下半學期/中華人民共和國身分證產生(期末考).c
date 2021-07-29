#include <string.h> 
#include <ctype.h> 
# include <stdio.h>
# include <stdlib.h>
# include <windows.h>

void gene() {
	srand(time(NULL) % 32767);
	printf("請輸入生日年份:\n");
	int a[20],s;
	scanf("%d",&s);
	printf("請輸入生日日期:\n");
	for (int i = 11; i <= 14; i++) {
		scanf("%1d", &a[i]);
	}
	for (int j = 15; j <= 18; j++) {
		a[j] = rand() % 10;
	}
	printf("916040%d%d%d%d%d%d%d%d%d\n\n",s+1911,a[11], a[12], a[13], a[14], a[15], a[16], a[17], a[18]);
}

void check() {
	int i, a[20], sum = 0, b, m = 0;
	int c;
	long area;
	printf("請輸入需要驗證之身分證號初17碼:\n");
	for (i = 1; i <= 17; i++) {
		scanf("%ld", &a[i]);
	}
	printf("請輸入需要驗證之身分證號末碼:\n");
	scanf("%d", &c);
	sum = a[1] * 7 + a[2] * 9 + a[3] * 10 + a[4] * 5 + a[5] * 8 + a[6] * 4 + a[7] * 2
		+ a[8] * 1 + a[9] * 6 + a[10] * 3 + a[11] * 7 + a[12] * 9 + a[13] * 10 + a[14] * 5
		+ a[15] * 8 + a[16] * 4 + a[17] * 2;
	b = sum % 11;
	switch (b) {//1 0 X 9 8 7 6 5 4 3 2 
	case 0:  if (c == 1) { m = 1; }
		  else { c = 1; }  break;
	case 1:  if (c == 0) { m = 1; }  
		  else { c = 0; }  break;
	case 2: if (c == 10 ) { m = 1; }
		  else { c = 10; } break;
	case 3:  if (c == 9) { m = 1; }
		  else { c = 9; }  break;
	case 4:  if (c == 8) { m = 1; }  
		  else { c = 8; }  break;
	case 5:  if (c == 7) { m = 1; }  
		  else { c = 7; }  break;
	case 6:  if (c == 6) { m = 1; }  
		  else { c = 6; }  break;
	case 7:  if (c == 5) { m = 1; }  
		  else { c = 5; }  break;
	case 8:  if (c == 4) { m = 1; }  
		  else { c = 4; }  break;
	case 9:  if (c == 3) { m = 1; }  
		  else { c = 3; }  break;
	case 10: if (c == 2) { m = 1; }  
		  else { c = 2; }  break;
	}
	if (m != 1) {
		printf("\a錯誤，正確應為(10表X)\n");
		printf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n\n", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10], a[11], a[12], a[13], a[14], a[15], a[16], a[17], c);
	}
	else {
		printf("正確");
	}
	return 0;
}
int main(void) {
	SetConsoleTitle(L"身分證查詢系統");
	int choose;
	do {
		printf("(1)身份證驗證與更正\n(2)特定生日身分證產生\n(3)結束\n請輸入選項：");
		scanf("%d", &choose);
		switch (choose) {
		case 1:
			check();
			break;
		case 2:
			gene();
			break;
		case 3:
			break;
		default:
			puts("請重新輸入\n");
		}
	} while (choose != 3);
	return 0;
}