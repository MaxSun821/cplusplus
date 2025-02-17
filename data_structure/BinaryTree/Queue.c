#include "Queue.h"

void QInit(Queue* pq)
{
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

QNode* QBuyNode(QDataType x)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	if (node == NULL)
	{
		perror("BuyNode::malloc");
		return NULL;
	}
	node->x = x;
	node->next = NULL;
	return node;
}

void QPush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* node = QBuyNode(x);
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = node;
	}
	else
	{
		pq->tail->next = node;
		pq->tail = node;
	}
	pq->size++;
}
void QPop(Queue* pq)
{
	assert(pq);
	assert(!QisEmpty(pq));

	if (pq->head->next == NULL)
	{
		// 只剩一个节点
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
	pq->size--;
}
QDataType QFront(Queue* pq)
{
	assert(pq);
	assert(!QisEmpty(pq));
	return pq->head->x;
}
QDataType QBack(Queue* pq)
{
	assert(pq);
	assert(!QisEmpty(pq));
	return pq->tail->x;
}
int QSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
bool QisEmpty(Queue* pq)
{
	return pq->size == 0;
}
void QDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->head;
	while (cur != NULL)
	{
		QNode* cur_next = cur->next;
		free(cur);
		cur = cur_next;
	}
	pq->head = pq->tail = NULL;
	pq->size = 0;
}