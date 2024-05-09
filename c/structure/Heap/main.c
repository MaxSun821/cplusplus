#include "Heap.h"


void HeapTest1()
{
	Heap hp;
	HeapInit(&hp);
	int arr[] = { 65,100,70,32,50,60 };

	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
	{
		HeapPush(&hp, arr[i]);
	}
	HeapDestroy(&hp);
}

void HeapTest2()
{
	Heap hp;
	HeapInit(&hp);
	int arr[] = { 65,100,70,32,50,60 };

	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
	{
		HeapPush(&hp, arr[i]);
	}

	HeapPush(&hp, 10);
	HeapPush(&hp, 33);
	
	HeapPop(&hp);
	int top = HeapTop(&hp);
	HeapDestroy(&hp);
}

int main(void)
{
	//HeapTest1();
	HeapTest2();
	return 0;
}