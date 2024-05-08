#include "Queue.h"

void QInit(Queue* q)
{
	assert(q);
	q->head = NULL;
	q->tail = NULL;
    q->size = 0;
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
    q->size++;
}
void QPop(Queue* q)
{
	assert(q);
	assert(!QEmpty(q));
    if(q->head->next == NULL)
    {
        free(q->head);
        q->head = q->tail = NULL;
    }
    else
    {
        QNode *del = q->head;
        q->head = del->next;
        free(del);
    }
    q->size--;
}
QDataType QFront(Queue* q)
{
	assert(q);
	assert(!QEmpty(q));
	return q->head->val;
}

QDataType QBack(Queue* q)
{
    assert(q);
    assert(!QEmpty(q));
    return q->tail->val;
}
bool QEmpty(Queue* q)
{
	return q->size == 0;
}
int QSize(Queue* q)
{
	assert(q);
	return q->size;
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
    q->head = q->tail = NULL;
    q->size = 0;
}