#ifndef C_CODE_SORT_H
#define C_CODE_SORT_H

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

void InsertSort(int* a, int size);
void ShellSort(int* a, int size);
void BubbleSort(int* a, int size);
void SelectSort(int* a, int size);
void HeapSort(int* a, int size);
void QuickSort(int* a, int begin, int end);
void QuickSortNoR(int* a, int begin, int end);
void MergeSort(int* a, int size);
void MergeSortNoR(int* a, int size);
void CountSort(int* a, int size);

#endif
