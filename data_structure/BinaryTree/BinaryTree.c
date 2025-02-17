#include "BinaryTree.h"

BINTree* BuyNode(BTDataType x)
{
	BINTree* tree_node = (BINTree*)malloc(sizeof(BINTree));
	if (tree_node == NULL)
	{
		perror("BuyNode::malloc");
		return NULL;
	}
	tree_node->val = x;
	tree_node->left = NULL;
	tree_node->right = NULL;

	return tree_node;
}
BINTree* CreateTree()
{
	BINTree* node1 = BuyNode(1);
	BINTree* node2 = BuyNode(2);
	BINTree* node3 = BuyNode(3);
	BINTree* node4 = BuyNode(4);
	BINTree* node5 = BuyNode(5);
	BINTree* node6 = BuyNode(6);
	//BINTree* node7 = BuyNode(7);


	node1->left = node2;
	node2->left = node3;
	node1->right = node4;
	node4->left = node5;
	node4->right = node6;
	//node2->right = node7;

	return node1;

}
void TreeDestroy(BINTree* root)
{
	if (root == NULL)
	{
		return;
	}
	TreeDestroy(root->left);
	TreeDestroy(root->right);
	free(root);
}
int TreeSize(BINTree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return TreeSize(root->left) + TreeSize(root->right) + 1;
}
int TreeLeafSize(BINTree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
int TreeHeight(BINTree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left_height = TreeHeight(root->left);
	int right_height = TreeHeight(root->right);

	return left_height > right_height ? left_height + 1 : right_height + 1;
}

void PreOrder(BINTree* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->val);
	PreOrder(root->left);
	PreOrder(root->right);
}
void InOrder(BINTree* root)
{
	if (root == NULL)
	{
		return;
	}
	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);
}
void PostOrder(BINTree* root)
{
	if (root == NULL)
	{
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->val);
}

int TreeLevelKSize(BINTree* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return TreeLevelKSize(root->left, k - 1) + TreeLevelKSize(root->right, k - 1);
}

BINTree* TreeFind(BINTree* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->val == x)
	{
		return root;
	}
	BINTree* left_tree = TreeFind(root->left, x);
	if (left_tree)
	{
		return left_tree;
	}
	BINTree* right_tree = TreeFind(root->right, x);
	if(right_tree)
	{
		return right_tree;
	}
	return NULL;
}

void LevelOrder(BINTree* root)
{
	Queue q;
	QInit(&q);

	if (root == NULL)
	{
		QDestroy(&q);
		return;
	}

	QPush(&q, root);
	while (!QisEmpty(&q))
	{
		BINTree* tree_node = QFront(&q);
		QPop(&q);

		printf("%d ", tree_node->val);

		if (tree_node->left != NULL)
		{
			QPush(&q, tree_node->left);
		}
		if (tree_node->right != NULL)
		{
			QPush(&q, tree_node->right);
		}
	}

	QDestroy(&q);
}

bool TreeComplete(BINTree* root)
{
	Queue q;
	QInit(&q);

	if (root == NULL)
	{
		QDestroy(&q);
		return false;
	}

	QPush(&q, root);

	while (!QisEmpty(&q))
	{
		BINTree* tree_node = QFront(&q);
		QPop(&q);

		if (tree_node != NULL)
		{
			QPush(&q, tree_node->left);
			QPush(&q, tree_node->right);
		}
		else
		{
			break;
		}
	}

	while (!QisEmpty(&q))
	{
		BINTree* tree_node = QFront(&q);
		if (tree_node != NULL)
		{
			QDestroy(&q);
			return false;
		}
		QPop(&q);
	}

	QDestroy(&q);
	return true;
}
