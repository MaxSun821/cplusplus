#include "Sort.h"

void TestOP();
void InsertSortTest();
void ShellSortTest();
void BubbleSortTest();
void SelectSortTest();
void HeapSortTest();
void QuickSortTest();
void QuickSortNoRTest();
void MergeSortTest();
void MergeSortNorTest();
void CountSortTest();
void PrintArray(int* a, int size);

int main()
{
	//srand((unsigned int)time(NULL));
	/*InsertSortTest();
	ShellSortTest();
	BubbleSortTest();
	SelectSortTest();
	HeapSortTest();
	QuickSortTest();
	QuickSortNoRTest();*/
	MergeSortTest();
	MergeSortNorTest();
	CountSortTest();


	//TestOP();
	return 0;
}

void TestOP()
{
	const int N = 1000000;
	int* a1 = (int*)malloc(N * sizeof(int));
	int* a2 = (int*)malloc(N * sizeof(int));
	int* a3 = (int*)malloc(N * sizeof(int));
	int* a4 = (int*)malloc(N * sizeof(int));
	int* a5 = (int*)malloc(N * sizeof(int));
	int* a6 = (int*)malloc(N * sizeof(int));
	int* a7 = (int*)malloc(N * sizeof(int));
	int* a8 = (int*)malloc(N * sizeof(int));


	int i = 0;
	for (i = 0; i < N; i++)
	{
		a1[i] = rand() % N;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];

	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();
	printf("InsertSort: %d\n", end1 - begin1);

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	printf("ShellSort: %d\n", end2 - begin2);

	int begin3 = clock();
	//BubbleSort(a3, N);
	int end3 = clock();
	printf("BubbleSort: %d\n", end3 - begin3);

	int begin4 = clock();
	//SelectSort(a4, N);
	int end4 = clock();
	printf("SelectSort: %d\n", end4 - begin4);

	int begin5 = clock();
	HeapSort(a5, N);
	int end5 = clock();
	printf("HeapSort: %d\n", end5 - begin5);

	int begin6 = clock();
	QuickSort(a6, 0, N - 1);
	int end6 = clock();
	printf("QuickSort: %d\n", end6 - begin6);

	int begin7 = clock();
	MergeSort(a7, N);
	int end7 = clock();
	printf("MergeSort: %d\n", end7 - begin7);

	int begin8 = clock();
	CountSort(a8, N);
	int end8 = clock();
	printf("CountSort: %d\n", end8 - begin8);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);

}

void InsertSortTest()
{
	int a[] = { 5,2,7,9,1,3,6,4,8,0 };
	InsertSort(a, 10);
	printf("Ö±½Ó²åÈëÅÅÐò£º");
	PrintArray(a, 10);
}

void ShellSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	ShellSort(a, 10);
	printf("Ï£¶ûÅÅÐò£º");
	PrintArray(a, 10);
}

void BubbleSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	BubbleSort(a, 10);
	printf("Ã°ÅÝÅÅÐò£º");
	PrintArray(a, 10);
}

void SelectSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	SelectSort(a, 10);
	printf("Ñ¡ÔñÅÅÐò£º");
	PrintArray(a, 10);
}

void HeapSortTest()
{
	int a[] = { 5,2,7,9,1,3,6,4,8,0 };
	HeapSort(a, 10);
	printf("¶ÑÅÅÐò£º");
	PrintArray(a, 10);
}

void QuickSortTest()
{
	int a[] = { 5,2,7,9,1,3,6,4,8,0 };
	QuickSort(a, 0, 9);
	printf("¿ìËÙÅÅÐò£º");
	PrintArray(a, 10);
}

void QuickSortNoRTest()
{
	int a[] = { 5,2,7,9,1,3,6,4,8,0 };
	QuickSortNoR(a, 0, 9);
	printf("¿ìËÙÅÅÐò·ÇµÝ¹é£º");
	PrintArray(a, 10);
}

void MergeSortTest()
{
	int a[] = { 5,2,7,9,1,3,6,4,8,0 };
	MergeSort(a, 10);
	printf("¹é²¢ÅÅÐò£º");
	PrintArray(a, 10);
}

void MergeSortNorTest()
{
	int a[] = { 5,2,7,9,1,3,6,4,8,0 };
	MergeSortNoR(a, 10);
	printf("¹é²¢ÅÅÐò·ÇµÝ¹é£º");
	PrintArray(a, 10);
}

void CountSortTest()
{
	int a[] = { 5,2,7,9,1,3,6,4,8,0 };
	CountSort(a, 10);
	printf("¼ÆÊýÅÅÐò£º");
	PrintArray(a, 10);
}

void PrintArray(int* a, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}