#include "ArrayList.h"

void ArrayListTest1();
void ArrayListTest2();
void ArrayListTest3();
void ArrayListTest4();
void ArrayListTest5();


int main()
{
	ArrayListTest5();
	return 0;
}

void ArrayListTest1()
{
	ArrayList list;
	Init(&list);

	PushFront(&list, 1);
	PushFront(&list, 2);
	PushFront(&list, 3);
	PushFront(&list, 4);
	PushFront(&list, 5);
	PushFront(&list, 6);
	PushFront(&list, 7);

	Print(&list);
	PopBack(&list);
	Print(&list);
	PopFront(&list);

	Print(&list);

	Destroy(&list);
}

void ArrayListTest2()
{
	ArrayList list;
	Init(&list);

	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	Print(&list);

	Insert(&list, 2, 40);
	Insert(&list, 4, 50);

	Print(&list);

	Destroy(&list);
}

void ArrayListTest3()
{
	ArrayList list;
	Init(&list);

	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	Print(&list);

	Insert(&list, 2, 40);
	Insert(&list, 4, 50);

	Print(&list);

	Erase(&list, 0);
	Print(&list);
	Erase(&list, 3);
	Print(&list);


	Destroy(&list);
}

void ArrayListTest4()
{
	ArrayList list;
	Init(&list);

	PushFront(&list, 1);
	PushFront(&list, 2);
	PushFront(&list, 3);
	PushFront(&list, 4);
	PushBack(&list, 5);
	PushBack(&list, 6);
	PushBack(&list, 7);
	

	Print(&list);
	PopBack(&list);
	Print(&list);
	PopFront(&list);

	Print(&list);

	Destroy(&list);
}

void ArrayListTest5()
{
	ArrayList list;
	Init(&list);

	PushFront(&list, 1);
	PushFront(&list, 2);
	PushFront(&list, 3);
	PushFront(&list, 4);
	PushBack(&list, 5);
	PushBack(&list, 6);
	PushBack(&list, 7);

	Print(&list);
	
	int pos = Find(&list, 6);
	Erase(&list, pos);
	Print(&list);
	Destroy(&list);
}