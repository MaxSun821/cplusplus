
#include "List.h"


ListNode* BuyNode(LDataType x)
{
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    if(node == NULL)
    {
        perror("malloc fail");
        return NULL;
    }
    node->val = x;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

ListNode* init()
{
    ListNode* pHead = BuyNode(-1);
    pHead->next = pHead;
    pHead->prev = pHead;
    return pHead;
}

bool empty(ListNode* pHead)
{
    return pHead->next == pHead;
}

void ListPushBack(ListNode* pHead, LDataType x)
{
    assert(pHead);
    ListNode* node = BuyNode(x);

    ListNode* prev = pHead->prev;
    node->next = pHead;
    node->prev = prev;
    prev->next = node;
    pHead->prev = node;
}

void ListPushFront(ListNode* pHead, LDataType x)
{
    assert(pHead);
    ListNode* node = BuyNode(x);

    ListNode* next = pHead->next;
    node->next = next;
    pHead->next = node;
    next->prev = node;
    node->prev = pHead;
}
void ListPopBack(ListNode* pHead)
{
    assert(pHead);
    assert(!empty(pHead));
    ListNode* tail = pHead->prev;

    ListNode* newTail = tail->prev;
    pHead->prev = newTail;
    newTail->next = pHead;
    free(tail);
}
void ListPopFront(ListNode* pHead)
{
    assert(pHead);
    assert(!empty(pHead));
    ListNode* del = pHead->next;
    pHead->next = del->next;
    del->next->prev = pHead;
    free(del);
}

ListNode* ListFind(ListNode* pHead, LDataType x)
{
    assert(pHead);
    ListNode* cur = pHead->next;
    while(cur != pHead)
    {
        if(cur->val == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void ListInsert(ListNode* pos, LDataType x)
{
    assert(pos);
    ListNode* prev = pos->prev;
    ListNode* node = BuyNode(x);
    prev->next = node;
    node->next = pos;
    pos->prev = node;
    node->prev = prev;
}
void ListErase(ListNode* pos)
{
    assert(pos);
    ListNode* del = pos->prev;
    del->prev->next = pos;
    pos->prev = del->prev;
    free(del);
}


void ListPrint(ListNode* pHead)
{
    ListNode* cur = pHead->next;
    while(cur != pHead)
    {
        printf("%i->", cur->val);
        cur = cur->next;
    }
    printf("哨兵位\n");
}

void ListDestroy(ListNode* pHead)
{
    ListNode* cur = pHead->next;
    while(cur != pHead)
    {
        ListNode* curNext = cur->next;
        free(cur);
        cur = curNext;
    }
    free(pHead);
    pHead = NULL;
}
