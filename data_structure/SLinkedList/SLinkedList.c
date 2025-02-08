#include "SlinkedList.h"

Node* BuyNode(DataType x)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->a = x;
	new_node->next = NULL;
	return new_node;
}

void PushBack(Node** ppHead, DataType x)
{
	assert(ppHead);
	Node* node = BuyNode(x);
	if ((*ppHead) == NULL)
	{
		*ppHead = node;
	}
	else
	{
		Node* cur = *ppHead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = node;
	}
}

void PushFront(Node** ppHead, DataType x)
{
	assert(ppHead);
	Node* node = BuyNode(x);
	node->next = *ppHead;
	*ppHead = node;
}

void PopBack(Node** ppHead)
{
	assert(ppHead);
	assert(*ppHead);
	if ((*ppHead)->next == NULL)
	{
		free(*ppHead);
		*ppHead = NULL;
	}
	else
	{
		Node* cur = *ppHead;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void PopFront(Node** ppHead)
{
	assert(ppHead);
	assert(*ppHead);
	/*if ((*ppHead)->next == NULL)
	{
		free(*ppHead);
		*ppHead = NULL;
	}
	else
	{
		Node* del = *ppHead;
		*ppHead = (*ppHead)->next;
		free(del);
		del = NULL;
	}*/

	Node* del = *ppHead;
	*ppHead = (*ppHead)->next;
	free(del);
}

void Insert(Node** ppHead, Node* pos, DataType x)
{
	assert(ppHead);
	assert(pos);

	if (*ppHead == pos)
	{
		// Í·²å
		PushFront(ppHead, x);
	}
	else
	{
		Node* prev = *ppHead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		Node* node = BuyNode(x);
		prev->next = node;
		node->next = pos;
	}
}

void InsertAfter(Node* pos, DataType x)
{
	assert(pos);
	Node* node = BuyNode(x);
	node->next = pos->next;
	pos->next = node;
}

void Erase(Node** ppHead, Node* pos)
{
	assert(ppHead);
	assert(*ppHead);
	assert(pos);

	if (*ppHead == pos)
	{
		PopFront(ppHead);
	}
	else
	{
		Node* prev = *ppHead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}

void EraseAfter(Node* pos)
{
	assert(pos);
	assert(pos->next);

	Node* next = pos->next;
	pos->next = next->next;
	free(next);
}

void Print(Node* pHead)
{
	Node* cur = pHead;
	while (cur != NULL)
	{
		printf("%d->", cur->a);
		cur = cur->next;
	}
	printf("NULL\n");
}

Node* Find(Node* pHead, DataType x)
{
	assert(pHead);

	Node* cur = pHead;
	while (cur != NULL)
	{
		if (cur->a == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void Destroy(Node** ppHead)
{
	while (*ppHead != NULL)
	{
		Node* del = *ppHead;
		*ppHead = (*ppHead)->next;
		free(del);
	}
}