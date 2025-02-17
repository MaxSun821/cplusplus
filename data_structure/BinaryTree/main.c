#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"

int main()
{
	BINTree* root = CreateTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");

	LevelOrder(root);
	printf("\n");
	BINTree* find = TreeFind(root, 3);
	if (find)
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}


	bool ret = TreeComplete(root);
	if (ret)
	{
		printf("是完全二叉树\n");
	}
	else
	{
		printf("不是完全二叉树\n");
	}

	TreeDestroy(root);

	return 0;
}