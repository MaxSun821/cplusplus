#include "SList.h"

void SLPushFront(ListNode** ppHead, SListDataType x)
{
    assert(ppHead);
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    node->n = x;
    if(node == NULL)
    {
        perror("malloc fail");
    }

    node->next = *ppHead; // node下一个节点指向原头节点
    *ppHead = node; // node给到新的头结点
}
void SLPushBack(ListNode** ppHead, SListDataType x)
{
    assert(ppHead);
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    node->n = x;
    if(*ppHead == NULL)
    {
        *ppHead = node;
        return;
    }

    ListNode* cur = *ppHead;

    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = node;
}

void SLPopBack(ListNode** ppHead)
{
    assert(ppHead);
    assert(*ppHead);

    if((*ppHead)->next == NULL)
    {
        // 链表中只有一个结点
        free(*ppHead);
        *ppHead = NULL;
        return;
    }

    ListNode* cur = *ppHead;

    while(cur->next->next != NULL)
    {
        cur = cur->next;
    }
    free(cur->next);
    cur->next = NULL;
}
void SLPopFront(ListNode** ppHead)
{
    assert(ppHead);
    assert(*ppHead);

    ListNode* cur = *ppHead;
    *ppHead = cur->next;
    free(cur);
    cur = NULL;
}

ListNode* SLFind(ListNode* pHead, SListDataType x)
{
    ListNode* cur = pHead;
    while(cur != NULL)
    {
        if(cur->n == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void SLInsertAfter(ListNode** ppHead, ListNode* pos, SListDataType x)
{
    assert(ppHead);
    assert(*ppHead);
    assert(pos);

    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    node->n = x;

    if(pos == *ppHead)
    {
        SLPushFront(ppHead, x);
        return;
    }
    if(pos->next == NULL)
    {
        SLPushBack(ppHead, x);
        return;
    }
    ListNode* cur = *ppHead;
    while(cur != pos)
    {
        cur = cur->next;
    }
    node->next = cur->next;
    cur->next = node;
}
void SLEraseAfter(ListNode** ppHead, ListNode* pos)
{
    assert(ppHead);
    assert(*ppHead);
    assert(pos);

    if(*ppHead == pos)
    {
        SLPopFront(ppHead);
        return;
    }
    if(pos->next == NULL)
    {
        SLPopBack(ppHead);
        return;
    }

    ListNode* cur = *ppHead;
    while(cur != pos)
    {
        cur = cur->next;
    }
    ListNode* del = cur->next;
    cur->next = del->next;
    free(del);
    del = NULL;
}


void SLPrint(ListNode* pHead)
{
    ListNode* cur = pHead;
    while(cur != NULL)
    {
        printf("%i->", cur->n);
        cur = cur->next;
    }
    printf("NULL\n");
}


void SLDestroy(ListNode** pHead)
{
    // 销毁
    ListNode* cur = *pHead;
    while(cur != NULL)
    {
        ListNode* curNext = cur->next;
        free(cur);
        cur = curNext;
    }
    *pHead = NULL;
}
