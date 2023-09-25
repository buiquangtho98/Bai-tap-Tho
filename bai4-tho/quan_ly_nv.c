
#include <stdio.h>
#include <string.h>

typedef struct {
	char ten[32];
	unsigned int id;
	int luong;
}employee_t;

typedef enum {
	false = 0,
	true
}run_stat;

employee_t company[50] = { 0 };
int TotalEmployee = 0;
char run = true;
int choice = 0;

void Option()
{
	printf("\nEmployee Management System\n");
	printf("MAIN MENU\n");
	printf("[1] Add New\n");
	printf("[2] Show All\n");
	printf("[3] Search\n");
	printf("[4] Delete\n");
	printf("[5] Exit\n");
	printf("Enter option number: ");
	scanf("%d%*c", &choice);
}

void GobackOrExit()
{
	char Option;
	printf("Back(b)? or Exit(0)?: ");
	scanf("%c%*c", &Option);
	if (Option == '0')
	{
		run = false;
	}
}

void AddEmployee() {
	printf("\nNhap thong tin nhan vien\n");
	printf("Ten: "); scanf("%[^\n]%*c", company[TotalEmployee].ten);
	printf("Ma so: "); scanf("%d%*c", &company[TotalEmployee].id);
	printf("Luong: "); scanf("%d%*c", &company[TotalEmployee].luong);
	printf("\n");
	TotalEmployee++;
}

void ShowEmployee(employee_t* A) {
	printf("%s\t%d\t%d\r\n",
		A->ten,
		A->id,
		A->luong);
}

void ShowAllEmployee() {
	printf("\nShowing all employee...\r\n");
	printf("Ten\t\tMa so\tLuong\r\n");
	int i = 0;
	for (i = 0; i < TotalEmployee; i++) {
		if (company[i].id != 0) {
			ShowEmployee(&company[i]);
		}
	}
	printf("\r\n");
}

void SearchEmployee() {
	printf("\nSearch for employee\r\n");
	char Option = 0;
	char search_name[32] = { 0 };
	int search_id = 0;
	printf("Using Name (n) or ID (i)?: "); scanf("%c%*c", &Option);
	if (Option == 'n') {
		printf("Search for the name: ");
		scanf("%[^\n]%*c", search_name);
		printf("Ten\t\tMa so\tLuong\r\n");
		int i = 0;
		for (i = 0; i < TotalEmployee; i++) {
			if (strstr(company[i].ten, search_name) != 0) {
				ShowEmployee(&company[i]);
			}
		}
	}
	else {
		printf("Search for the ID: ");
		scanf("%d%*c", &search_id);
		printf("Ten\t\tMa so\tLuong\r\n");
		int i = 0;
		for (i = 0; i < TotalEmployee; i++) {
			if (company[i].id == search_id) {
				ShowEmployee(&company[i]);
			}
		}
	}
	printf("\n");
}

void erase_info(employee_t* addr) {
	int i = 0;
	for (i = 0; i < 32; i++) {
		addr->ten[i] = 0;
	}
	addr->id = 0;
	addr->luong = 0;
}

void DeleteEmployee() {
	printf("\nDelete employee\r\n");
	char Option = 0;
	char confirm = 'n';
	char delete_name[32] = { 0 };
	int delete_id = 0;
	printf("Using Name (n) or ID (i)?: "); scanf("%c%*c", &Option);
	if (Option == 'n') {
		printf("Delete with the name: ");
		scanf("%[^\n]%*c", delete_name);
		printf("Ten\t\tMa so\tLuong\r\n");
		int i = 0;
		for (i = 0; i < TotalEmployee; i++) {
			if (strstr(company[i].ten, delete_name) != 0) {
				ShowEmployee(&company[i]);
			}
		}
		printf("Delete confirm? (y/n): "); scanf("%c%*c", &confirm);
		if (confirm == 'y') {
			int i = 0;
			for (i = 0; i < TotalEmployee; i++) {
				if (strstr(company[i].ten, delete_name) != 0) {
					erase_info(&company[i]);
				}
			}
			printf("Info deleted\n");
		}
		else {
			printf("Delete canceled\n");
		}
	}
	else {
		printf("Delete with the id: ");
		scanf("%d%*c", &delete_id);
		printf("Ten\t\tMa so\tLuong\r\n");
		int i = 0;
		for (i = 0; i < TotalEmployee; i++) {
			if (company[i].id == delete_id) {
				ShowEmployee(&company[i]);
			}
		}
		printf("Delete confirm? (y/n): "); scanf("%c%*c", &confirm);
		if (confirm == 'y') {
			int i = 0;
			for (i = 0; i < TotalEmployee; i++) {
				if (company[i].id == delete_id) {
					erase_info(&company[i]);
				}
			}
			printf("Info deleted\n");
		}
		else {
			printf("Delete canceled\n");
		}
	}
	printf("\n");
}

void main() {
	while (run) {
		Option();
		switch (choice) {
		case 0:
			run = false;
			break;
		case 1:
			AddEmployee();
			GobackOrExit();
			break;
		case 2:
			ShowAllEmployee();
			GobackOrExit();
			break;
		case 3:
			SearchEmployee();
			GobackOrExit();
			break;
		case 4:
			DeleteEmployee();
			GobackOrExit();
			break;
		case 5:
			run = false;
			break;
		}
	}
	printf("\nClosing program...\n");
	printf("Press any key");
	getch();
}
