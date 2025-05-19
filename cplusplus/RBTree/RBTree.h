#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>

using std::pair;
using std::make_pair;
using std::cout;
using std::endl;

enum Color {
	RED, BLACK
};

template<typename K, typename V>
struct TreeNode {
    TreeNode<K, V>* parent_;
    TreeNode<K, V>* left_;
    TreeNode<K, V>* right_;
    pair<K, V> value_;
    Color color_;

    TreeNode<K, V>(const pair<K, V>& p)
        : parent_(nullptr), left_(nullptr), right_(nullptr), value_(p), color_(RED) {
    }
};

template<typename K, typename V>
class RBTree {
public:
    bool insert(const pair<K, V>& p) {
        if (root_ == nullptr) {
            root_ = new TreeNode<K, V>(p);
			root_->color_ = BLACK; // 根节点必须是黑色
            return true;
        }
        TreeNode<K, V>* parent = nullptr;
        TreeNode<K, V>* current = root_;
        while (current != nullptr) {
            parent = current;
            if (p.first < current->value_.first) {
                current = current->left_;
            }
            else if (p.first > current->value_.first) {
                current = current->right_;
            }
            else {
                // 已有重复key
                return false;
            }
        }
        current = new TreeNode<K, V>(p);
        current->color_ = RED;
        if (p.first < parent->value_.first) {
            parent->left_ = current;
        }
        else {
            parent->right_ = current;
        }

		// 调整颜色
        while (parent != nullptr && parent->color_ == RED) {
            TreeNode<K, V>* grandparent = parent->parent_;
            TreeNode<K, V>* uncle = nullptr;
            if (parent == grandparent->left_)
                uncle = grandparent->right_;
            else
                uncle = grandparent->left_;

            if (uncle != nullptr && uncle->color_ == RED) {
                parent->color_ = uncle->color_ = BLACK;
                grandparent->color_ = RED;

                current = grandparent;
                parent = current->parent_;
            }
        }

		root_->color_ = BLACK; // 根节点必须是黑色
        return true;
    }
private:
    TreeNode<K, V>* root_;
};

#endif
