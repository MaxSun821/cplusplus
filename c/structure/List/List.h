
#ifndef C_LIST_H
#define C_LIST_H


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LDataType;
typedef struct ListNode
{
    LDataType val;
    struct ListNode* prev;
    struct ListNode* next;
}ListNode;

ListNode* BuyNode(LDataType x);

ListNode* init();
void ListPushBack(ListNode* pHead, LDataType x);
void ListPushFront(ListNode* pHead, LDataType x);
void ListPopBack(ListNode* pHead);
void ListPopFront(ListNode* pHead);

ListNode* ListFind(ListNode* pHead, LDataType x);
void ListInsert(ListNode* pos, LDataType x);
void ListErase(ListNode* pos);

void ListPrint(ListNode* pHead);

void ListDestroy(ListNode* pHead);

#endif //C_LIST_H
