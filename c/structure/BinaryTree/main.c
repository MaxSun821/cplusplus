#include "BinaryTree.h"


BTNode *buyNode(BTDataType x) {
    BTNode *node = (BTNode *) malloc(sizeof(BTNode));
    node->val = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BTNode *createTree() {
    BTNode *node1 = buyNode(1);
    BTNode *node2 = buyNode(2);
    BTNode *node3 = buyNode(3);
    BTNode *node4 = buyNode(4);
    BTNode *node5 = buyNode(5);
    BTNode *node6 = buyNode(6);

    node1->left = node2;
    node2->left = node3;
    node1->right = node4;
    node4->left = node5;
    node4->right = node6;

    return node1;
}

int main(void) {
    BTNode *root = createTree();
    PreOrder(root);
    printf("\n");
    InOrder(root);
    printf("\n");
    PostOrder(root);
    printf("\n");

    int size = BTSize(root);
    int leftSize = BTLeafSize(root);
    printf("二叉树结点个数：%i\n", size);
    printf("二叉树叶子结点个数：%i\n", leftSize);

    int height = BTHeight(root);
    printf("树的高度是：%i\n", height);

    int levelSize = BTLevelSize(root, 2);
    printf("前两层结点数：%i\n", levelSize);

    BTNode *find = BTFind(root, 2);
    if (find != NULL) {
        printf("找到了\n");
    }

    BTLeverOrder(root);

    return 0;
}