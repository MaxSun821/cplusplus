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

void HeapSort(HPDataType* a, int size)
{
	// 堆排序
	// 1. 建堆
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		// 排降序，建大堆
		// 使用向下调整建大堆
		AdjustDown(a, i, size);
	}
	// 收尾元素互换，再建大堆
	int end = size - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, 0, end);
		--end;
	}
	for (int i = 0; i < size; i++)
	{
		printf("%i ", a[i]);
	}
	printf("\n");
}

void createData()
{
	// 创建1000000个数据，写入文件
	int n = 1000;
	srand(time(NULL));
	FILE* file = fopen("data.txt", "w");
	for (int i = 0; i < n; i++)
	{
		int num = rand() % 100000;
		fprintf(file, "%d\n", num);
	}
	fclose(file);
	file = NULL;
}

void printTopK(int k)
{
	// 用前k个元素建小堆
	int* a = (int*)malloc(k * sizeof(int));
	if (a == NULL)
	{
		printf("malloc fail\n");
		return;
	}
	FILE* file = fopen("data.txt", "r");

	for (int i = 0; i < k; i++)
	{
		fscanf(file, "%d", &a[i]);
	}
	while (!feof(file))
	{
		int val = 0;
		fscanf(file, "%d", &val);
		if (val > a[0])
		{
			a[0] = val;
			AdjustDown(a, 0, k);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	fclose(file);

}

int main(void)
{
	//HeapTest1();
	//HeapTest2();

	//HPDataType a[] = { 38, 5, 24, 69, 21, 90, 77, 45 };
	//HeapSort(a, sizeof(a) / sizeof(a[0]));

	//createData();

	printTopK(5);
	return 0;
}