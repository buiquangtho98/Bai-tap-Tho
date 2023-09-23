#include <stdio.h>

void doi_cho(char* pa, char* pb)
{
	char x = *pa;
	*pa = *pb;
	*pb = x;
}

void sap_xep_tang(char* ARR, int N)
{
	int k = 1;
	while (k != 0)
	{
		k = 0;
		int i = 0;
		for (i = 0; i < N - 1; i++)
		{
			if (ARR[i] > ARR[i + 1])
			{
				doi_cho(&ARR[i], &ARR[i + 1]);
				k++;
			}
		}
	}
}

void main()
{
	char arr[] = { 5,10,8,36,6,7,3,1,9,10,25,12,20 };
	int i=0;
	int n = sizeof arr / sizeof arr[0];
	printf("Ban dau: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	sap_xep_tang(arr, n);
	printf("Sap xep tang: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\r\nPress any key");
	getch();
}
