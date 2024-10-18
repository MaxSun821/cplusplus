#include "SList.h"
#include <stdbool.h>

int size(struct ListNode* head)
{
    int len = 0;
    while(head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* longHead, *shortHead;
    longHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    shortHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    longHead->next = headA;
    shortHead->next = headB;
    int longLen = size(headA);
    int shortLen = size(headB);

    if(shortLen > longLen)
    {
        longHead->next = headB;
        shortHead->next = headA;
    }

    int len = abs(longLen - shortLen);
    struct ListNode* fast = longHead->next;
    struct ListNode* slow = shortHead->next;
    while(len-- && fast)
    {
        fast = fast->next;
    }
    if(len > 0)
    {
        return NULL;
    }
    while(fast && slow)
    {
        if(fast == slow)
        {
            return slow;
        }
        fast = fast->next;
        slow = slow->next;
    }
    return NULL;
}

//int main(void)
//{
//    ListNode *node1 = (ListNode*) malloc(sizeof(ListNode));
//    ListNode *node2 = (ListNode*) malloc(sizeof(ListNode));
//    ListNode *node3 = (ListNode*) malloc(sizeof(ListNode));
//    ListNode *node4 = (ListNode*) malloc(sizeof(ListNode));
//    ListNode *node5 = (ListNode*) malloc(sizeof(ListNode));
//    ListNode *node6 = (ListNode*) malloc(sizeof(ListNode));
//    ListNode *node7 = (ListNode*) malloc(sizeof(ListNode));
//    ListNode *node8 = (ListNode*) malloc(sizeof(ListNode));
//
//    node1->n = 4;
//    node2->n = 1;
//    node3->n = 8;
//    node4->n = 4;
//    node5->n = 5;
//    node6->n = 5;
//    node7->n = 6;
//    node8->n = 1;
//
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    node5->next = NULL;
//    node6->next = node7;
//    node7->next = node8;
//    node8->next = node3;
//
//    getIntersectionNode(node1, node6);
//
//
//
//    return 0;
//}
