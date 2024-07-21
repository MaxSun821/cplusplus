

#include "AVLTree.h"

int main() {
    const int N = 30;
    std::vector<int> v;
    v.reserve(N);
    srand(time(0));

    for (int i = 0; i < N; i++) {
        v.push_back(rand());
    }

    AVLTree<int, int> tree;
    for (auto e: v) {
        tree.insert(std::make_pair(e, e));
        std::cout << "insert:" << e << "->" << tree.isBalance() << std::endl;
    }

    tree.inorder();


    return 0;
}
