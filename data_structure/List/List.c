#include "List.h"

Node* BuyNode(DataType x)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = x;
	return node;
}

Node* Init()
{
	Node* pHead = BuyNode(-1);
	if (pHead == NULL)
	{
		perror("Init::malloc");
		return NULL;
	}
	pHead->prev = pHead;
	pHead->next = pHead;
	return pHead;
}
void PushBack(Node* pHead, DataType x)
{
	assert(pHead);
	Node* node = BuyNode(x);
	if (node == NULL)
	{
		perror("PushBack::malloc");
		return;
	}
	Node* tail = pHead->prev;
	tail->next = node;
	node->prev = tail;
	node->next = pHead;
	pHead->prev = node;
}

void PushFront(Node* pHead, DataType x) 
{
	assert(pHead);

	Node* node = BuyNode(x);

	Node* next = pHead->next;

	node->next = next;
	node->prev = pHead;
	next->prev = node;
	pHead->next = node;

}

void PopBack(Node* pHead)
{
	assert(pHead);
	assert(pHead->prev != pHead); // 链表内无元素

	Node* tail = pHead->prev;
	pHead->prev = tail->prev;
	tail->prev->next = pHead;

	free(tail);
}

void PopFront(Node* pHead)
{
	assert(pHead);
	assert(pHead->prev != pHead); // 链表内无元素

	Node* next = pHead->next;

	pHead->next = next->next;
	next->next->prev = pHead;

	free(next);
}

Node* Find(Node* pHead, DataType x)
{
	assert(pHead);

	Node* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void Insert(Node* pHead, Node* pos, DataType x)
{
	assert(pHead);

	Node* node = BuyNode(x);

	Node* prev = pos->prev;
	node->next = pos;
	node->prev = prev;
	pos->prev = node;
	prev->next = node;
}
void InsertAfter(Node* pHead, Node* pos, DataType x)
{
	assert(pHead);

	Node* node = BuyNode(x);

	Node* next = pos->next;
	node->next = next;
	next->prev = node;
	pos->next = node;
	node->prev = pos;
}

void Erase(Node* pos)
{
	assert(pos);

	Node* prev = pos->prev;
	Node* next = pos->next;
	prev->next = next;
	next->prev = prev;

	free(pos);
}

void EraseAfter(Node* pos)
{
	assert(pos);


	Node* del = pos->next;
	Node* next = del->next;

	pos->next = next;
	next->prev = pos;
	free(del);
}

void Print(Node* pHead)
{
	assert(pHead);
	Node* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

void Destroy(Node* pHead)
{
	assert(pHead);
	Node* cur = pHead->next;
	while (cur != pHead)
	{
		Node* curNext = cur->next;
		free(cur);
		cur = curNext;
	}
	free(pHead);
}