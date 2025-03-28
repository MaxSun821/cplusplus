#include "BinarySearchTree.h"

int main() {
    int arr[] = {7, 5, 9, 10, 2, 3, 1, 6, 8, 4};
    BinarySearchTree<int> tree;
    for (int e : arr) {
        tree.insert(e);
    }
    tree.print();
    std::cout << std::endl;
    return 0;
}