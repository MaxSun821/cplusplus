

#include "AVLTree.h"

int main() {
    AVLTree<int, int> tree;
    tree.insert(std::pair<int, int>(1, 1));
    tree.insert(std::pair<int, int>(2, 2));
    tree.insert(std::pair<int, int>(3, 3));
    tree.insert(std::pair<int, int>(4, 4));



    return 0;
}
