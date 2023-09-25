
// Doc va ghi file van ban có day du so, chu cai, ky tu dac biet,
// tim va in so ra file rieng, chu ra file rieng, ky tu dac biet ra file rieng

// Noi dung file txt: buiquangtho25101998!@#$%buiquangtu17091995^&*()
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define CHU_CAI ((c>=65)&(c<=90))|((c>=97)&(c<=122))
#define CHU_SO ((c>=48)&(c<=57))
#define KY_TU ((c>=32)&(c<=47))|((c>=58)&(c<=64))|((c>=91)&(c<=96))|((c>=123)&(c<=126))

void main() {
	FILE* f_test = fopen("test_file.txt", "r");
	FILE* f_chu_cai = fopen("chu_cai_file.txt", "w");
	FILE* f_chu_so = fopen("chu_so_file.txt", "w");
	FILE* f_ky_tu = fopen("ky_tu_file.txt", "w");

	char c = fgetc(f_test);
	while (c != -1) {
		if (CHU_CAI) {
			fputc(c, f_chu_cai);
		}
		else if (CHU_SO) {
			fputc(c, f_chu_so);
		}
		else if (KY_TU) {
			fputc(c, f_ky_tu);
		}
		c = fgetc(f_test);
	}

	fclose(f_test);
	fclose(f_chu_cai);
	fclose(f_chu_so);
	fclose(f_ky_tu);

	printf("\nProgram ended, press any key");
	getch();
}
