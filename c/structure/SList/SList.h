

#ifndef C_SLIST_H
#define C_SLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SListDataType;

typedef struct ListNode
{
    SListDataType n;
    struct ListNode* next;
}ListNode;

void SLPrint(ListNode* pHead);

void SLPushFront(ListNode** ppHead, SListDataType x);
void SLPushBack(ListNode** ppHead, SListDataType x);
void SLPopBack(ListNode** ppHead);
void SLPopFront(ListNode** ppHead);

ListNode* SLFind(ListNode* pHead, SListDataType x);

void SLInsertAfter(ListNode** ppHead, ListNode* pos, SListDataType x);
void SLEraseAfter(ListNode** ppHead, ListNode* pos);



void SLDestroy(ListNode** pHead);

#endif //C_SLIST_H
