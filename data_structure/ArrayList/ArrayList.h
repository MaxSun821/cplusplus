#ifndef C_CODE_ARRAYLIST_H
#define C_CODE_ARRAYLIST_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int DataType;

typedef struct ArrayList
{
	DataType* a;
	int size;
	int capacity;
} ArrayList;

void Init(ArrayList* pal);
void Destroy(ArrayList* pal);

void PushBack(ArrayList* pal, DataType x);
void PopBack(ArrayList* pal);

void PushFront(ArrayList* pal, DataType x);
void PopFront(ArrayList* pal);

void Insert(ArrayList* pal, int pos, DataType x);
void Erase(ArrayList* pal, int pos);

int Find(ArrayList* pal, DataType x);
void Modify(ArrayList* pal, int pos, DataType x);

void Print(ArrayList* pal);

#endif
