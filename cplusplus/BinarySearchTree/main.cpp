#include "BinarySearchTree.h"

// int main() {
//     int arr[] = {8, 3, 1, 10, 6, 4, 7, 14, 13};
//     key::BinarySearchTree<int> tree;
//     for (int e : arr) {
//         tree.insertR(e);
//     }
//     tree.print();
//     std::cout << std::endl;
//
//     key::BinarySearchTree<int> tree2 = tree;
//     tree2.print();
//     return 0;
// }

int main() {
    key_value::BinarySearchTree<std::string, std::string> dict;
    dict.insert("hello", "你好");
    dict.insert("bye", "再见");
    dict.insert("Good", "好");
    dict.insert("dog", "狗");

    // dict.print();

    std::string str;
    while (std::cin >> str) {
        key_value::TreeNode<std::string, std::string>* ret = dict.find(str);
        if (ret) {
            std::cout << ret->value_ << std::endl;
        }
    }
    return 0;
}