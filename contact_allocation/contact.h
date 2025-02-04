#ifndef _CONTACT_PROGRAM_
#define _CONTACT_PROGRAM_

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEFAULT_CAPACITY 3

// 为方便选择功能代码阅读。
enum
{
	EXIT,
	ADD,
	DELETE,
	FIND,
	MODIFY,
	PRINT,
	CLEAN,
	SORT
};

// 存储用户信息对象
typedef struct PeopleInfo
{
	char name[20];
	int age;
	char gender[10];
	char tele[20];
	char address[20];
}PeopleInfo;

// 联系簿对象
typedef struct Contact
{
	// 动态开辟空间
	PeopleInfo* people_info;
	int size; // 数组中真实元素个数
	int capacity; // 数组容量，用于扩容
}Contact;


void contact_init(Contact* contact);
void add_contact(Contact* contact);
// 因为不需要更改联系簿，所以使用const修饰，增加健壮性。
void print(const Contact* contact);
void del_contact(Contact* contact);
void modi_contact(Contact* contact);
void find(Contact* contact);
void sort_by_name(Contact* contact);
void clean(Contact* contact);
void destroy_contact(Contact* contact);
#endif
