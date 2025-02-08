#ifndef C_CODE_SLinkedList_H
#define C_CODE_SLinkedList_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int DataType;
typedef struct Node
{
	DataType a;
	struct Node* next;
} Node;

void PushBack(Node** ppHead, DataType x);
void PushFront(Node** ppHead, DataType);

void PopBack(Node** ppHead);
void PopFront(Node** ppHead);

void Insert(Node** ppHead, Node* pos, DataType x);
void InsertAfter(Node* pos, DataType x);

void Erase(Node** ppHead, Node* pos);
void EraseAfter(Node* pos);

Node* Find(Node* pHead, DataType x);

void Print(Node* pHead);

void Destroy(Node** ppHead);
#endif
