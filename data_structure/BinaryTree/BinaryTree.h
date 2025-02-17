#ifndef C_CODE_BINARY_TREE_H
#define C_CODE_BINARY_TREE_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "Queue.h"

typedef char BTDataType;

typedef struct BinaryTree
{
	BTDataType val;
	struct BinaryTree* left;
	struct BinaryTree* right;
} BINTree;

BINTree* CreateTree();
void TreeDestroy(BINTree* root);
int TreeSize(BINTree* root);
int TreeLeafSize(BINTree* root);
int TreeHeight(BINTree* root);
void PreOrder(BINTree* root);
void InOrder(BINTree* root);
void PostOrder(BINTree* root);
int TreeLevelKSize(BINTree* root, int k);
BINTree* TreeFind(BINTree* root, BTDataType x);
void LevelOrder(BINTree* root);
bool TreeComplete(BINTree* root);


#endif