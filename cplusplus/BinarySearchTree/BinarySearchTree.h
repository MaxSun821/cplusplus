#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

template <typename T>
struct TreeNode {
    T data_;
    TreeNode<T>* left_;
    TreeNode<T>* right_;
    TreeNode(const T& data)
        : data_(data), left_(nullptr), right_(nullptr)
    {}
};

template <typename T>
class BinarySearchTree {
public:
    BinarySearchTree() : root_(nullptr) {}
    bool insert(const T& data) {
        if (root_ == nullptr) {
            root_ = new TreeNode<T>(data);
            return true;
        }

        TreeNode<T>* prev = nullptr;
        TreeNode<T>* cur = root_;
        while (cur != nullptr) {
            prev = cur;
            if (data > cur->data_) {
                cur = cur->right_;
            }
            else if (data < cur->data_) {
                cur = cur->left_;
            }
            else {
                return false;
            }
        }
        cur = new TreeNode<T>(data);
        if (data < prev->data_) {
            prev->left_ = cur;
        }
        else {
            prev->right_ = cur;
        }
        return true;
    }
    bool erase(const T& data) {
        if (root_ == nullptr) {
            return false;
        }
        TreeNode<T>* cur = root_;
        while (cur != nullptr) {
            if (data < cur->data_) {
                cur = cur->left_;
            }
            else if (data > cur->data_) {
                cur = cur->right_;
            }
            else {
                if (cur->left_ == nullptr) {
                    // 左子树为空

                }
            }
        }
    }
    void print() {
        _print(root_);
    }
private:
    void _print(TreeNode<T>* root) {
        if (root == nullptr) {
            return;
        }
        _print(root->left_);
        std::cout << root->data_ << " ";
        _print(root->right_);
    }
    TreeNode<T>* root_;
};

#endif //BINARYSEARCHTREE_H
