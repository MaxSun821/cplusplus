#ifndef C_CODE_LIST_H
#define C_CODE_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct Node
{
	struct Node* prev;
	struct Node* next;
	DataType val;
} Node;

Node* Init();
void PushBack(Node* pHead, DataType x);
void PushFront(Node* pHead, DataType x);

void PopBack(Node* pHead);
void PopFront(Node* pHead);

Node* Find(Node* pHead, DataType x);

void Insert(Node* pHead, Node* pos, DataType x);
void InsertAfter(Node* pHead, Node* pos, DataType x);

void Erase(Node* pos);
void EraseAfter(Node* pos);

void Print(Node* pHead);

void Destroy(Node* pHead);

#endif
