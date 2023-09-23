#include <stdio.h>

void main()
{
	unsigned int n = 0, i = 0, j = 0, k = 0;
	printf("Nhap so tu nhien n: ");
	scanf("%d", &n);
	printf("Cac so nguyen to < %d:\r\n", n);
	for (i = 1; i < n; i++)
	{
		k = 0;
		for (j = 2; j < i; j++)	{
			if ((i % j) == 0)
			{
				k++;
			}
		}
		if (k == 0)	{
			printf("%d\r\n", i);
		}
	}
}
