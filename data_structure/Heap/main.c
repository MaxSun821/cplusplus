#include "Heap.h"

int main()
{
	Heap heap;
	HeapInit(&heap);
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < size; i++)
	{
		HeapPush(&heap, arr[i]);
	}

	while (!HeapisEmpty(&heap))
	{
		HDataType top = HeapTop(&heap);
		HeapPop(&heap);
		printf("%d\n", top);
	}
	printf("--------");
	return 0;
}