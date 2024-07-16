
#include "BinarySearchTree.h"

int main() {
    key_value::BSTree<std::string, std::string> tree;
    tree.insert("abandon", "遗忘");
    tree.insert("cat", "猫");
    tree.insert("dog", "狗");
    tree.insert("panda", "熊猫");

    std::string str;
    while (std::cin >> str) {
        auto ret = tree.find(str);
        if (ret) {
            std::cout << ret->_value << std::endl;
        }
        else {
            std::cout << "没有查到这个单词" << std::endl;
        }
    }

    return 0;
}
