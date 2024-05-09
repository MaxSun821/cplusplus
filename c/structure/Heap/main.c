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

	while (!HeapEmpty(&hp))
	{
		printf("%i ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");

	HeapDestroy(&hp);
}

int main(void)
{
	//HeapTest1();
	HeapTest2();
	return 0;
}