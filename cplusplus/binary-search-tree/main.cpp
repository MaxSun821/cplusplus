
#include "BinarySearchTree.h"

int main() {
    int a[] = {8, 3, 1, 10, 6, 4, 7, 14, 13};
    BSTree<int> tree;
    for(auto i : a) {
        tree.insertR(i);
    }

    tree.inorder();

    tree.eraseR(8);
    tree.inorder();


    return 0;
}
