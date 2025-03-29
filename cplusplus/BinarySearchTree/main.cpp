#include "BinarySearchTree.h"

int main() {
    int arr[] = {8, 3, 1, 10, 6, 4, 7, 14, 13};
    BinarySearchTree<int> tree;
    for (int e : arr) {
        tree.insertR(e);
    }
    tree.print();
    std::cout << std::endl;

    return 0;
}