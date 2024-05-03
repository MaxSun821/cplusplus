

#ifndef C_SEQLIST_H
#define C_SEQLIST_H

#include <stdio.h>
#include <stdlib.h>


typedef int SLDataType;

typedef struct SeqList
{
    SLDataType* a; // 数组
    int size; // 元素个数
    int capacity; // 容量
}SL;

void init(SL* psl);
void destroy(SL* psl);

void SLPushBack(SL* psl, SLDataType x);
void SLPushFront(SL* psl, SLDataType x);
void SLPopBack(SL* psl);
void SLPopFront(SL* psl);

void SLInsert(SL* psl, int index, SLDataType x);
void SLErase(SL* psl, int index);

int SLFind(SL* psl, SLDataType key);

void SLCheckCapacity(SL* psl); // 检查数组是否已满
int SLCheckSize(SL* psl); // 检查数组是否已空

void SLPrint(SL* psl);


#endif //C_SEQLIST_H
