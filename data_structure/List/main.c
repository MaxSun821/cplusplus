#include "List.h"


void ListTest1();
void ListTest2();
void ListTest3();
void ListTest4();

int main()
{
	ListTest4();
	return 0;
}

void ListTest1()
{
	Node* plist = Init();

	PushBack(plist, 1);
	PushBack(plist, 2);
	PushBack(plist, 3);
	PushBack(plist, 4);
	PushBack(plist, 5);
	PushBack(plist, 6);

	Print(plist);

}

void ListTest2()
{
	Node* plist = Init();

	PushBack(plist, 1);
	PushBack(plist, 2);
	PushBack(plist, 3);
	PushBack(plist, 4);
	PushFront(plist, 5);
	PushFront(plist, 6);

	Print(plist);

	PopBack(plist);
	Print(plist);

	PopFront(plist);
	Print(plist);

	PopBack(plist);
	PopBack(plist);
	PopBack(plist);
	Print(plist);
	PopBack(plist);
	PopBack(plist);
	PopBack(plist);

}

void ListTest3()
{
	Node* plist = Init();

	PushBack(plist, 1);
	PushBack(plist, 2);
	PushBack(plist, 3);
	PushBack(plist, 4);
	PushFront(plist, 5);
	PushFront(plist, 6);

	Print(plist);

	Node* find = Find(plist, 3);
	Insert(plist, find, 30);

	Print(plist);

	find = Find(plist, 1);
	InsertAfter(plist, find, 10);
	Print(plist);
}

void ListTest4()
{
	Node* plist = Init();

	PushBack(plist, 1);
	PushBack(plist, 2);
	PushBack(plist, 3);
	PushBack(plist, 4);
	PushFront(plist, 5);
	PushFront(plist, 6);

	Print(plist);

	Node* find = Find(plist, 3);
	Erase(find);

	Print(plist);

	find = Find(plist, 1);
	EraseAfter(find);
	Print(plist);

	Destroy(plist);
	plist = NULL;
}