#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include <vector>

using std::pair;
using std::make_pair;
using std::cout;
using std::endl;
using std::vector;

enum Color {
    RED, BLACK
};

template<typename T>
struct TreeNode {
    TreeNode<T> *parent_;
    TreeNode<T> *left_;
    TreeNode<T> *right_;
    T value_;
    Color color_;

    TreeNode(const T &p)
        : parent_(nullptr), left_(nullptr), right_(nullptr), value_(p), color_(RED) {
    }
};

template<typename K, typename T, typename KeyOfValue>
class RBTree {
public:
    bool insert(const T &p) {

        if (root_ == nullptr) {
            root_ = new TreeNode<T>(p);
            root_->color_ = BLACK; // 根结点必须是黑色
            return true;
        }
        TreeNode<T> *parent = nullptr;
        TreeNode<T> *current = root_;
        KeyOfValue kov;
        while (current != nullptr) {
            parent = current;
            if (kov(p) < kov(current->value_)) {
                current = current->left_;
            } else if (kov(p) > kov(current->value_)) {
                current = current->right_;
            } else {
                // key有重复元素
                return false;
            }
        }
        current = new TreeNode<T>(p);
        current->color_ = RED;
        if (kov(p) < kov(parent->value_)) {
            parent->left_ = current;
        } else {
            parent->right_ = current;
        }
        current->parent_ = parent;
        // 调整颜色
        while (parent != nullptr && parent->color_ == RED) {
            TreeNode<T> *grandparent = parent->parent_;
            if (parent == grandparent->left_) {
                TreeNode<T> *uncle = grandparent->right_;
                if (uncle != nullptr && uncle->color_ == RED) {
                    parent->color_ = uncle->color_ = BLACK;
                    grandparent->color_ = RED;

                    current = grandparent;
                    parent = current->parent_;
                } else {
                    // uncle结点不存在或颜色为黑
                    //     g
                    //   p   u
                    // c
                    if (current == parent->left_) {
                        rotateR(grandparent);
                        parent->color_ = BLACK;
                        grandparent->color_ = RED;
                    } else {
                        rotateL(parent);
                        rotateR(grandparent);
                        current->color_ = BLACK;
                        grandparent->color_ = RED;
                    }
                    break;
                }
            } else {
                // parent == grandparent->right_
                TreeNode<T> *uncle = grandparent->left_;
                if (uncle != nullptr && uncle->color_ == RED) {
                    parent->color_ = uncle->color_ = BLACK;
                    grandparent->color_ = RED;

                    current = grandparent;
                    parent = current->parent_;
                } else {
                    // uncle结点不存在或颜色为黑
                    //     g
                    //   u   p
                    //         c
                    if (current == parent->right_) {
                        rotateL(grandparent);
                        parent->color_ = BLACK;
                        grandparent->color_ = RED;
                    } else {
                        rotateR(parent);
                        rotateL(grandparent);
                        current->color_ = BLACK;
                        grandparent->color_ = RED;
                    }
                    break;
                }
            }
        }

        root_->color_ = BLACK; // 根结点必须是黑色
        return true;
    }

    void rotateL(TreeNode<T> *parent) {
        TreeNode<T> *subRight = parent->right_;
        TreeNode<T> *subRL = subRight->left_;

        parent->right_ = subRL;
        subRight->left_ = parent;

        TreeNode<T> *pParent = parent->parent_;
        // 处理parent_
        parent->parent_ = subRight;
        if (subRL != nullptr) {
            subRL->parent_ = parent;
        }
        // 处理root
        if (parent == root_) {
            root_ = subRight;
            subRight->parent_ = nullptr;
        } else {
            if (pParent->left_ == parent) {
                pParent->left_ = subRight;
            } else {
                pParent->right_ = subRight;
            }
            subRight->parent_ = pParent;
        }

    }

    void rotateR(TreeNode<T> *parent) {
        TreeNode<T> *subLeft = parent->left_;
        TreeNode<T> *subLR = subLeft->right_;

        parent->left_ = subLR;
        subLeft->right_ = parent;
        TreeNode<T> *pParent = parent->parent_;

        parent->parent_ = subLeft;
        if (subLR != nullptr) {
            subLR->parent_ = parent;
        }
        if (parent == root_) {
            root_ = subLeft;
            subLeft->parent_ = nullptr;
        } else {
            if (pParent->left_ == parent) {
                pParent->left_ = subLeft;
            } else {
                pParent->right_ = subLeft;
            }
            subLeft->parent_ = pParent;
        }
    }

    void inorder() {
        inorder_(root_);
    }

    bool isBalanced() {
        if (root_ == nullptr) return true;
        if (root_->color_ == RED) return false;

        int blacknum = 0;

        return check(root_, blacknum);

    }

private:
    void inorder_(TreeNode<T> *root) {
        if (root != nullptr) {
            return;
        }
        inorder_(root->left_);
        cout << root->value_.first << endl;
        inorder_(root->right_);
    }
    bool check(TreeNode<T> *root, int blacknum) {
        if (root == nullptr) {
            cout << "黑色结点数：" << blacknum << endl;
            return true;
        }

        if (root->color_ == RED && root->parent_->color_ == RED) {
            cout << "有连续的红色结点" << endl;
            return false;
        }

        if (root->color_ == BLACK) {
            ++blacknum;
        }

        return check(root->left_, blacknum) && check(root->right_, blacknum);
    }
    TreeNode<T> *root_ = nullptr;
};

#endif
