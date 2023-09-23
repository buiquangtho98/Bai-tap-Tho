#include <stdio.h>

void main() {
	long long i = 0;
	long long j = 1;
	long long i_old = 0;
	long long j_old = 0;
	int n = 0;
	for (n = 0; n < 70; n++) {
		printf("%d %lld  \r\n", n, j);
		i_old = i;
		j_old = j;
		i = j_old;
		j = i_old + j_old;
	}
	getch();
}
