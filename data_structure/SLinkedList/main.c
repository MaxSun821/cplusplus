#include "SLinkedList.h"

void SLinkedListTest1();
void SLinkedListTest2();
void SLinkedListTest3();
void SLinkedListTest4();

int main()
{
	SLinkedListTest4();
	return 0;
}

void SLinkedListTest1()
{
	Node* plist = NULL;

	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PushBack(&plist, 6);
	PushBack(&plist, 7);

	Print(plist);

	Destroy(&plist);

}

void SLinkedListTest2()
{
	Node* plist = NULL;

	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PushFront(&plist, 5);
	PushBack(&plist, 6);
	PushBack(&plist, 7);

	Print(plist);

	Destroy(&plist);
}

void SLinkedListTest3()
{
	Node* plist = NULL;

	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PushFront(&plist, 5);
	PushBack(&plist, 6);
	PushBack(&plist, 7);

	Print(plist);

	PopBack(&plist);
	PopBack(&plist);
	PopBack(&plist);
	PopBack(&plist);
	PopBack(&plist);
	PopBack(&plist);
	Print(plist);

	PopFront(&plist);
	Print(plist);

	Destroy(&plist);
}

void SLinkedListTest4()
{
	Node* plist = NULL;

	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PushFront(&plist, 5);
	PushBack(&plist, 6);
	PushBack(&plist, 7);

	Print(plist);

	Node* ret = Find(plist, 4);
	Insert(&plist, ret, 30);
	Print(plist);
	InsertAfter(ret, 40);
	Print(plist);
	Node* ret2 = Find(plist, 5);
	Erase(&plist, ret2);
	Print(plist);

	EraseAfter(ret);
	Print(plist);

}