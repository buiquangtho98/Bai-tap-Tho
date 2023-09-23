
#include <stdio.h>
#include <string.h>

// Swap value
void swap(char* pa, char* pb)
{
	char x = *pa;
	*pa = *pb;
	*pb = x;
}

void insert_c(char* ptr, char* ch) {
	char temp[1] = { 0 };
	temp[0] = *ch;
	int i = 0;
	while (*temp != 0) {
		swap(temp, &ptr[i]);
		i++;
	}
}

void main() {
	char arr[128] = { 0 };
	sprintf(arr, "fresher embedded");
	puts(arr);
	char* ptr = arr;
	char temp_arr[1] = { 'f' };
	while (strstr(ptr, "e") != 0) {
		ptr = strstr(ptr, "e");
		ptr++;
		insert_c(ptr, temp_arr);
	}
	puts(arr);
	printf("\r\nPress any key");
	getch();
}
