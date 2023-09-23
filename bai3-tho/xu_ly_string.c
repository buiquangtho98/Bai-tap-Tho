
#include <stdio.h>
#include <string.h>
#define REASON1 ((arr[i]>32)&(arr[i]<65)) | ((arr[i]>90)&(arr[i]<97)) | (arr[i]>122)
#define REASON2 ((arr[i-1]==' ')&(arr[i]==' ')) | (arr[i-1]==-1)&(arr[i]==' ')
#define REASON3 (arr[i-1]==-1)&(arr[i]!=-1)

// Swap value
void swap(char* pa, char* pb)
{
	char x = *pa;
	*pa = *pb;
	*pb = x;
}

// Clear multi spaces
void clear_spaces(char* arr) {
	int i = 0;
	while (arr[i] != 0) {
		if (i != 0) {
			if (REASON2) {
				arr[i] = -1;
			}
		}
		i++;
	}
}

// Clear the abnormal characters
void clear_trashs(char* arr) {
	int i = 0;
	while (arr[i] != 0) {
		if (REASON1) {
			arr[i] = -1;
		}
		i++;
	}
}

// Re-arrange the right characters
void arrange(char* arr) {
	int k = 1;
	int i = 0;
	while (k != 0) {
		k = 0;
		i = 0;
		while (arr[i] != 0) {
			if (i != 0) {
				if (REASON3) {
					swap(&arr[i - 1], &arr[i]);
					k++;
				}
			}
			i++;
		}
	}
}

// Clear the -1 value
void clear_minus(char* arr) {
	int i = 0;
	while (arr[i] != 0) {
		if (arr[i] == -1) {
			arr[i] = 0;
		}
		i++;
	}
}

void front_to_back(char* arr) {
	int len = strlen(arr);
	int i = 0;
	for (i = 0; i < (len - 1) / 2; i++) {
		swap(&arr[i], &arr[len - 1 - i]);
	}
}

void chu_thuong(char* arr) {
	int i = 0;
	while (arr[i] != 0) {
		if ((arr[i] >= 65) & (arr[i] <= 90)) {
			arr[i] += 97-65;
		}
		i++;
	}
}

void main() {
	char arr[128] = { 0 };
	//printf("Nhap chuoi: ");
	//scanf("%[^\n]%*c", arr);
	sprintf(arr, "Bui35454   Qua#$%^ng   Th3548o hell$%^#$o    wor@$%@ld str315435ing     opera54164tion!@#$ test");

	clear_spaces(arr);
	clear_trashs(arr);
	arrange(arr);
	clear_minus(arr);
	puts(arr);

	front_to_back(arr);
	puts(arr);

	front_to_back(arr);
	chu_thuong(arr);
	puts(arr);

	printf("\r\nPress any key");
	getch();
}
