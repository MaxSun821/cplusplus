#include "Sort.h"

void TestInsertSort()
{
	int a[] = { 6,5,9,11,3,2,6,7,1,8,12,10 };
	int size = sizeof(a) / sizeof(int);
	PrintArray(a, size);
	InsertSort(a, size);
	PrintArray(a, size);
}

void TestShellSort()
{
	int a[] = { 6,5,9,11,3,2,4,7,1,8,12,10 };
	int size = sizeof(a) / sizeof(int);
	PrintArray(a, size);
	ShellSort(a, size);
	PrintArray(a, size);
}

void TestSelectSort()
{
	int a[] = { 6,5,9,11,3,2,4,7,1,8,12,10 };
	int size = sizeof(a) / sizeof(int);
	PrintArray(a, size);
	SelectSort(a, size);
	PrintArray(a, size);
}

void TestBubbleSort()
{
	int a[] = { 6,5,9,11,3,2,4,7,1,8,12,10 };
	int size = sizeof(a) / sizeof(int);
	PrintArray(a, size);
	BubbleSort(a, size);
	PrintArray(a, size);
}

void TestHeapSort()
{
	int a[] = { 6,5,9,11,3,2,4,7,1,8,12,10 };
	int size = sizeof(a) / sizeof(int);
	PrintArray(a, size);
	HeapSort(a, size);
	PrintArray(a, size);
}

void TestQuickSort()
{
	int a[] = { 6,5,9,11,3,2,4,7,1,8,12,10 };
	int size = sizeof(a) / sizeof(int);
	PrintArray(a, size);
	QuickSort(a, 0, size - 1);
	PrintArray(a, size);
}

void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	BubbleSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	SelectSort(a4, N);
	int end4 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("BubbleSort:%d\n", end3 - begin3);
	printf("SelcetSort:%d\n", end4 - begin4);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

int main(void)
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestBubbleSort();
	//TestHeapSort();
	TestQuickSort();

	//TestOP();
	return 0;
}