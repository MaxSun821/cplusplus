#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void InsertSort(int* a, int size);
void ShellSort(int* a, int size);
void BubbleSort(int* a, int size);
void SelectSort(int* a, int size);
void HeapSort(int* a, int size);
void QuickSort(int* a, int begin, int end);
void QuickSortNonR(int* a, int begin, int end);
void MergeSort(int* a, int size);
void MergeSortNonR(int* a, int size);
void CountSort(int* a, int size);

void PrintArray(int* a, int size);