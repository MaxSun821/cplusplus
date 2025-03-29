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

        TreeNode<T>* prev = nullptr;
        TreeNode<T>* cur = root_;

        while (cur != nullptr) {
            if (data < cur->data_) {
                prev = cur;
                cur = cur->left_;
            }
            else if (data > cur->data_) {
                prev = cur;
                cur = cur->right_;
            }
            else {
                if (cur->left_ == nullptr) {
                    // 左子树为空
                    if (cur == root_) {
                        root_ = cur->right_;
                    }
                    else {
                        if (prev->left_ == cur) {
                            prev->left_ = cur->right_;
                        }
                        else if (prev->right_ == cur) {
                            prev->right_ = cur->right_;
                        }
                    }
                    delete cur;
                }
                else if (cur->right_ == nullptr) {
                    // 右子树为空
                    if (cur == root_) {
                        root_ = cur->left_;
                    }
                    else {
                        if (prev->left_ == cur) {
                            prev->left_ = cur->left_;
                        }
                        else if (prev->right_ == cur) {
                            prev->right_ = cur->left_;
                        }
                    }
                    delete cur;
                }
                else {
                    // 左右子树都不为空
                    // 找到右子树最小值
                    prev = cur;
                    TreeNode<T>* tmp = cur->right_;
                    while (tmp->left_ != nullptr) {
                        prev = tmp;
                        tmp = tmp->left_;
                    }
                    std::swap(cur->data_, tmp->data_);
                    if (tmp == prev->left_) {
                        prev->left_ = tmp->right_;
                    }
                    else {
                        prev->right_ = tmp->right_;
                    }
                    delete tmp;
                }
                return true;
            }
        }
        return false;
    }
    bool find(const T& data) {
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
                return true;
            }
        }
        return false;
    }
    bool insertR(const T& data) {
        // 使用递归
        _insertR(root_, data);
    }
    bool eraseR(const T& data) {

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
    bool _insertR(TreeNode<T>*& root, const T& data) {
        if (root == nullptr) {
            root = new TreeNode<T>(data);
            return true;
        }
        if (data < root->data_) {
            // 在左子树插入
            return _insertR(root->left_, data);
        }
        if (data > root->data_) {
            // 在右子树插入
            return _insertR(root->right_, data);
        }
        return false;
    }
    TreeNode<T>* root_;
};

#endif //BINARYSEARCHTREE_H
