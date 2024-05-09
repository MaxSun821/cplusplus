#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a; // 存放数据的数组
	int size; 
	int capacity; // 容量
}Heap;

void HeapInit(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
bool HeapEmpty(Heap* hp);
void HeapDestroy(Heap* hp);
