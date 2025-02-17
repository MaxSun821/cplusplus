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
		printf("�ҵ���\n");
	}
	else
	{
		printf("û�ҵ�\n");
	}


	bool ret = TreeComplete(root);
	if (ret)
	{
		printf("����ȫ������\n");
	}
	else
	{
		printf("������ȫ������\n");
	}

	TreeDestroy(root);

	return 0;
}