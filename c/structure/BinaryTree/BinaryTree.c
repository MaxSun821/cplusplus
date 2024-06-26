#include "BinaryTree.h"
#include "Queue.h"

void PreOrder(BTNode *root) {
    if (root == NULL) {
        printf("N ");
        return;
    }
    printf("%d ", root->val);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(BTNode *root) {
    if (root == NULL) {
        printf("N ");
        return;
    }
    InOrder(root->left);
    printf("%d ", root->val);
    InOrder(root->right);
}

void PostOrder(BTNode *root) {
    if (root == NULL) {
        printf("N ");
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->val);
}

int BTSize(BTNode *root) {
    if (root == NULL) {
        return 0;
    }
    return BTSize(root->left) + BTSize(root->right) + 1;
}

int BTLeafSize(BTNode *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    return BTLeafSize(root->left) + BTLeafSize(root->right);
}

int BTHeight(BTNode *root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = BTHeight(root->left);
    int rightHeight = BTHeight(root->right);
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int BTLevelSize(BTNode *root, int k) {
    assert(k);
    if (root == NULL) {
        return 0;
    }
    if (k == 1) {
        return 1;
    }
    int leftLevelSize = BTLevelSize(root->left, k - 1);
    int rightLevelSize = BTLevelSize(root->right, k - 1);

    return leftLevelSize + rightLevelSize;
}

BTNode* BTFind(BTNode* root, BTDataType x)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->val == x)
    {
        return root;
    }

    BTNode* leftTree = BTFind(root->left, x);
    if(leftTree != NULL)
    {
        return leftTree;
    }
    BTNode* rightTree = BTFind(root->right, x);
    if(rightTree != NULL)
    {
        return rightTree;
    }
    return NULL;
}

void BTLeverOrder(BTNode* root)
{
    Queue q;
    QInit(&q);

    if(root != NULL)
        QPush(&q, root);
    while(!QEmpty(&q))
    {
        BTNode* top = QFront(&q);
        printf("%d ", top->val);
        if(top->left != NULL)
        {
            QPush(&q, top->left);
        }
        if(top->right != NULL)
        {
            QPush(&q, top->right);
        }
        QPop(&q);
    }
    QDestroy(&q);
}

bool isComplete(BTNode* root)
{
    Queue q;
    QInit(&q);

    if(root != NULL)
    {
        QPush(&q, root);
    }
    while(!QEmpty(&q)) {
        BTNode *top = QFront(&q);
        QPop(&q);
        if (top == NULL)
        {
            break;
        }
        QPush(&q, top->left);
        QPush(&q, top->right);
    }
    while(!QEmpty(&q))
    {
        BTNode *top = QFront(&q);
        QPop(&q);
        if(top)
        {
            QDestroy(&q);
            return false;
        }
    }
    QDestroy(&q);
    return true;
}

void BTDestroy(BTNode* root)
{
    // 采用后序遍历来释放空间
    if (root == NULL)
    {
        return;
    }
    BTDestroy(root->left);
    BTDestroy(root->right);
    free(root);
    root = NULL;
}
