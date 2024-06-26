#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;

typedef struct QNode
{
	QDataType val;
	struct QNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
    int size;
}Queue;

void QInit(Queue* q);
QNode* QBuyNode(QDataType x);

void QPush(Queue* q, QDataType x);
void QPop(Queue* q);
QDataType QFront(Queue* q);
QDataType QBack(Queue* q);

bool QEmpty(Queue* q);
int QSize(Queue* q);



void QDestroy(Queue* q);