#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

uint32_t UCLN(uint32_t a, uint32_t b) {
	int i = 0;
	if (a < b) {
		int c = a;
		a = b;
		b = c;
	}
	for (i = 0; i < b; i++) {
		uint32_t j = a % (b - i);
		uint32_t k = b % (b - i);
		if (j == 0 && k == 0) {
			break;
		}
	}
	return b - i;
}

uint32_t BCNN(uint32_t a, uint32_t b) {
	uint32_t u = UCLN(a, b);
	uint32_t bcnn = (a / u) * (b / u) * u;
}

void main() {
	uint32_t a = 0, b = 0;
	printf("Nhap a:");
	scanf("%d",&a);
	printf("Nhap b:");
	scanf("%d",&b);
	uint32_t uoc = UCLN(a, b);
	uint32_t boi = BCNN(a, b);
	printf("UCLN cua %d va %d: %d\r\n", a, b, uoc);
	printf("BCNN cua %d va %d: %d\r\n", a, b, boi);
	printf("Press any key");
	getch();
}
