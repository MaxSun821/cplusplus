#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu();
int main()
{
	int input = 0;
	Contact contact;
	// 联系簿初始化
	contact_init(&contact);
	do
	{
		menu();
		printf("Enter your choice: ");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_contact(&contact);
			break;
		case DELETE:
			del_contact(&contact);
			break;
		case FIND:
			find(&contact);
			break;
		case MODIFY:
			modi_contact(&contact);
			break;
		case PRINT:
			print(&contact);
			break;
		case CLEAN:
			clean(&contact);
			break;
		case SORT:
			sort_by_name(&contact);
			break;
		case EXIT:
			save_contact(&contact);
			destroy_contact(&contact);
			printf("Exit Contact!\n");
			break;
		default:
			printf("Wrong choice!\n");
			break;
		}
	} while (input);
	return 0;
}

void menu()
{
	printf("---------------------------\n");
	printf("----- 1. add   2. del -----\n");
	printf("---- 3.find  4.modify  ----\n");
	printf("-----5.print  6. clean-----\n");
	printf("------7.sort   0.exit------\n");
	printf("---------------------------\n");
}