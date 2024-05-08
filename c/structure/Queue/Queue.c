#include "Queue.h"

void QInit(Queue* q)
{
	assert(q);
	q->head = NULL;
	q->tail = NULL;
}

QNode* QBuyNode(QDataType x)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	if (node == NULL)
	{
		perror("malloc fail\n");
	}
	node->val = x;
	node->next = NULL;
	return node;
}

void QPush(Queue* q, QDataType x)
{
	assert(q);
	QNode* node = QBuyNode(x);
	if (q->tail == NULL)
	{
		q->head = q->tail = node;
	}
	else
	{
		q->tail->next = node;
		q->tail = q->tail->next;
	}
}
void QPop(Queue* q)
{
	assert(q);
	assert(!QEmpty(q));
	QNode* del = q->head;
	q->head = del->next;
	free(del);
	del = NULL;
}
QDataType QTop(Queue* q)
{
	assert(q);
	assert(!QEmpty(q));
	return q->head->val;
}
bool QEmpty(Queue* q)
{
	return q->head == NULL;
}
int QSize(Queue* q)
{
	assert(q);
	int count = 0;
	if (QEmpty(q))
	{
		return count;
	}
	QNode* cur = q->head;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

void QDestroy(Queue* q)
{
	QNode* cur = q->head;
	while (cur)
	{
		QNode* curNext = cur->next;
		free(cur);
		cur = curNext;
	}
}