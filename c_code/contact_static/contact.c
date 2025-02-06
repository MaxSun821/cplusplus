#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void contact_init(Contact* contact)
{
	assert(contact);
	// 将people_info数组置为全0, size为0。
	memset(contact->people_info, 0, sizeof(contact->people_info));
	contact->size = 0;
}

void add_contact(Contact* contact)
{
	assert(contact);
	if (contact->size == 100)
	{
		printf("The contact is full. Fail to add person infomation.\n");
		return;
	}
	printf("Enter the name: ");
	scanf("%s", contact->people_info[contact->size].name);
	printf("Enter the age: ");
	scanf("%d", &(contact->people_info[contact->size].age));
	printf("Enter the gender: ");
	scanf("%s", contact->people_info[contact->size].gender);
	printf("Enter the telephone: ");
	scanf("%s", contact->people_info[contact->size].tele);
	printf("Enter the address: ");
	scanf("%s", contact->people_info[contact->size].address);

	++contact->size;
	printf("Successful!\n");
}

void print(const Contact* contact)
{
	assert(contact);

	printf("    name   |   age   |    gender   |   telephone   |  address  \n");
	printf("---------------------------------------------------------------\n");
	int i = 0;
	for (i = 0; i < contact->size; i++)
	{
		printf(" %d  %s        %d         %s        %s    %s\n",
			(i + 1),
			contact->people_info[i].name,
			contact->people_info[i].age,
			contact->people_info[i].gender,
			contact->people_info[i].tele,
			contact->people_info[i].address);
	}
}

int find_by_name(Contact* contact, char* name)
{
	int i = 0;
	for (i = 0; i < contact->size; i++)
	{
		if (strcmp(contact->people_info[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void del_contact(Contact* contact)
{
	assert(contact);
	if (contact->size == 0)
	{
		printf("The contact is empty!\n");
		return;
	}
	char name[20] = { 0 };
	printf("Enter the name you wanna delete: ");
	scanf("%s", name);
	// find the person by name.
	// return index
	int index = find_by_name(contact, name);
	if (index == -1)
	{
		printf("There isn't have this name in contact.Fail to delete.\n");
		return;
	}
	int i = 0;
	for (i = index; i < contact->size - 1; i++)
	{
		contact->people_info[i] = contact->people_info[i + 1];
	}
	--contact->size;
}

void modi_contact(Contact* contact)
{
	assert(contact);

	char name[20] = { 0 };
	printf("Enter the name you wanna modify: ");
	scanf("%s", name);
	int index = find_by_name(contact, name);
	if (index == -1)
	{
		printf("There isn't have this name in contact.Fail to modify.\n");
		return;
	}
	printf("Enter the name: ");
	scanf("%s", contact->people_info[index].name);
	printf("Enter the age: ");
	scanf("%d", &(contact->people_info[index].age));
	printf("Enter the gender: ");
	scanf("%s", contact->people_info[index].gender);
	printf("Enter the telephone: ");
	scanf("%s", contact->people_info[index].tele);
	printf("Enter the address: ");
	scanf("%s", contact->people_info[index].address);

	printf("Successful!\n");
}

void find(Contact* contact)
{
	assert(contact);
	char name[20] = { 0 };
	printf("Enter the name you wanna find: ");
	scanf("%s", name);

	int index = find_by_name(contact, name);
	if (index == -1)
	{
		printf("Fail to find.\n");
		return;
	}

	printf("    name   |   age   |    gender   |   telephone   |  address  \n");
	printf("---------------------------------------------------------------\n");
	
	printf(" %d  %s        %d         %s        %s    %s\n",
		1,
		contact->people_info[index].name,
		contact->people_info[index].age,
		contact->people_info[index].gender,
		contact->people_info[index].tele,
		contact->people_info[index].address);
}

int compare(const void* p1, const void* p2)
{
	return strcmp(((PeopleInfo*)p1)->name, ((PeopleInfo*)p2)->name);
}

void sort_by_name(Contact* contact)
{
	assert(contact);
	if (contact->size == 0)
	{
		printf("No element in the contact.\n");
		return;
	}

	qsort(contact->people_info, contact->size, sizeof(contact->people_info[0]), compare);
}

void clean(Contact* contact)
{
	assert(contact);

	contact->size = 0;
}