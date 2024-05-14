#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void InsertSort(int* a, int size);
void ShellSort(int* a, int size);
void BubbleSort(int* a, int size);
void SelectSort(int* a, int size);
void HeapSort(int* a, int size);
void QuickSort(int* a, int begin, int end);

void PrintArray(int* a, int size);