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

template<typename K, typename V>
struct TreeNode {
    TreeNode<K, V> *parent_;
    TreeNode<K, V> *left_;
    TreeNode<K, V> *right_;
    pair<K, V> value_;
    Color color_;

    TreeNode<K, V>(const pair<K, V> &p)
        : parent_(nullptr), left_(nullptr), right_(nullptr), value_(p), color_(RED) {
    }
};

template<typename K, typename V>
class RBTree {
public:
    bool insert(const pair<K, V> &p) {
        if (root_ == nullptr) {
            root_ = new TreeNode<K, V>(p);
            root_->color_ = BLACK; // 根结点必须是黑色
            return true;
        }
        TreeNode<K, V> *parent = nullptr;
        TreeNode<K, V> *current = root_;
        while (current != nullptr) {
            parent = current;
            if (p.first < current->value_.first) {
                current = current->left_;
            } else if (p.first > current->value_.first) {
                current = current->right_;
            } else {
                // key有重复元素
                return false;
            }
        }
        current = new TreeNode<K, V>(p);
        current->color_ = RED;
        if (p.first < parent->value_.first) {
            parent->left_ = current;
        } else {
            parent->right_ = current;
        }

        // 调整颜色
        while (parent != nullptr && parent->color_ == RED) {
            TreeNode<K, V> *grandparent = parent->parent_;
            if (parent == grandparent->left_) {
                TreeNode<K, V> *uncle = grandparent->right_;
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
                TreeNode<K, V> *uncle = grandparent->left_;
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

    void rotateL(TreeNode<K, V> *parent) {
        TreeNode<K, V> *subRight = parent->right_;
        TreeNode<K, V> *subRL = subRight->left_;

        parent->right_ = subRL;
        subRight->left_ = parent;

        TreeNode<K, V> *pParent = parent->parent_;
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

    void rotateR(TreeNode<K, V> *parent) {
        TreeNode<K, V> *subLeft = parent->left_;
        TreeNode<K, V> *subLR = subLeft->right_;

        parent->left_ = subLR;
        subLeft->right_ = parent;
        TreeNode<K, V> *pParent = parent->parent_;

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
    void inorder_(TreeNode<K, V> *root) {
        if (root != nullptr) {
            return;
        }
        inorder_(root->left_);
        cout << root->value_.first << endl;
        inorder_(root->right_);
    }
    bool check(TreeNode<K, V> *root, int blacknum) {
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
    TreeNode<K, V> *root_ = nullptr;
};

#endif
