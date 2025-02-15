#ifndef C_CODE_HEAP_H
#define C_CODE_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HDataType;
typedef struct Heap
{
	HDataType* a;
	int size;
	int capacity;
} Heap;

void HeapInit(Heap* ph);
void Destroy(Heap* ph);
void HeapPush(Heap* ph, HDataType x);
void HeapPop(Heap* ph);
HDataType HeapTop(Heap* ph);
int HeapSize(Heap* ph);
bool HeapisEmpty(Heap* ph);

#endif
