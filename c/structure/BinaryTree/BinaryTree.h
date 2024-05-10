#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int BTDataType;

typedef struct BTNode
{
	BTDataType val;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

void PreOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);