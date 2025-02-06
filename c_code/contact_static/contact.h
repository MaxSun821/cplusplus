#ifndef _CONTACT_PROGRAM_
#define _CONTACT_PROGRAM_

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Ϊ����ѡ���ܴ����Ķ���
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

// �洢�û���Ϣ����
typedef struct PeopleInfo
{
	char name[20];
	int age;
	char gender[10];
	char tele[20];
	char address[20];
}PeopleInfo;

// ��ϵ������
typedef struct Contact
{
	PeopleInfo people_info[MAX_SIZE];
	int size; // ��������ʵԪ�ظ���
}Contact;


void contact_init(Contact* contact);
void add_contact(Contact* contact);
// ��Ϊ����Ҫ������ϵ��������ʹ��const���Σ����ӽ�׳�ԡ�
void print(const Contact* contact);
void del_contact(Contact* contact);
void modi_contact(Contact* contact);
void find(Contact* contact);
void sort_by_name(Contact* contact);
void clean(Contact* contact);

#endif
