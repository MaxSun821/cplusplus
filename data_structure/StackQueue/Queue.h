#ifndef C_CODE_QUEUE_H
#define C_CODE_QUEUE_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int QDataType;
typedef struct QNode
{
	QDataType x;
	struct QNode* next;
} QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
} Queue;

void QInit(Queue* pq);
void QPush(Queue* pq, QDataType x);
void QPop(Queue* pq);
QDataType QFront(Queue* pq);
QDataType QBack(Queue* pq);
int QSize(Queue* pq);
bool QisEmpty(Queue* pq);
void QDestroy(Queue* pq);

#endif