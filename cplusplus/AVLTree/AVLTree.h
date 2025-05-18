#ifndef AVLTREE_H
#define AVLTREE_H

#include <cassert>
#include <iostream>
#include <vector>
using std::pair;
using std::cout;
using std::endl;
using std::make_pair;
using std::vector;

template<typename K, typename V>
struct TreeNode {
    TreeNode<K, V> *parent_;
    TreeNode<K, V> *left_;
    TreeNode<K, V> *right_;
    pair<K, V> value_;
    int bf_; // 平衡因子

    TreeNode<K, V>(const pair<K, V> &p)
        : parent_(nullptr), left_(nullptr), right_(nullptr), value_(p), bf_(0) {
    }
};

template<typename K, typename V>
class AVLTree {
public:
    bool insert(const pair<K, V> &p) {
        if (root_ == nullptr) {
            root_ = new TreeNode<K, V>(p);
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
                // 已有重复key
                return false;
            }
        }
        current = new TreeNode<K, V>(p);
        if (p.first < parent->value_.first) {
            parent->left_ = current;
        } else {
            parent->right_ = current;
        }
        current->parent_ = parent;
        // 向上调整平衡因子
        while (parent != nullptr) {
            if (current == parent->left_) {
                --parent->bf_;
            } else {
                ++parent->bf_;
            }
            if (parent->bf_ == 0) {
                // 此刻是平衡的
                break;
            } else if (parent->bf_ == 1 || parent->bf_ == -1) {
                // 向上调整平衡因子
                current = parent;
                parent = parent->parent_;
            } else if (parent->bf_ == -2 || parent->bf_ == 2) {
                // 旋转
                if (parent->bf_ == 2 && current->bf_ == 1) {
                    rotateL(parent);
                } else if (parent->bf_ == -2 && current->bf_ == -1) {
                    rotateR(parent);
                } else if (parent->bf_ == 2 && current->bf_ == -1) {
                    rotateRL(parent);
                } else if (parent->bf_ == -2 && current->bf_ == 1) {
                    rotateLR(parent);
                }
                break;
            } else {
                assert(false);
            }
        }

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

        parent->bf_ = subRight->bf_ = 0;
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
        parent->bf_ = subLeft->bf_ = 0;
    }

    void rotateRL(TreeNode<K, V> *parent) {
        // 右左双旋
        TreeNode<K, V> *subRight = parent->right_;
        TreeNode<K, V> *subRL = subRight->left_;
        int bf = subRL->bf_;
        rotateR(parent->right_);
        rotateL(parent);
        if (bf == 0) {
            // subRL就是新增节点
            parent->bf_ = subRight->bf_ = subRL->bf_ = 0;;
        } else if (bf == 1) {
            subRL->bf_ = subRight->bf_ = 0;
            parent->bf_ = -1;
        } else if (bf == -1) {
            parent->bf_ = subRL->bf_ = 0;
            subRight->bf_ = 1;
        } else {
            assert(false);
        }
    }

    void rotateLR(TreeNode<K, V> *parent) {
        // 左右双旋
        TreeNode<K, V> *subLeft = parent->left_;
        TreeNode<K, V> *subLR = subLeft->right_;
        int bf = subLR->bf_;
        rotateL(parent->left_);
        rotateR(parent);
        if (bf == 0) {
            // subLR就是新增节点
            parent->bf_ = subLeft->bf_ = subLR->bf_ = 0;
        } else if (bf == 1) {
            parent->bf_ = subLR->bf_ = 0;
            subLeft->bf_ = -1;
        } else if (bf == -1) {
            subLeft->bf_ = subLR->bf_ = 0;
            parent->bf_ = 1;
        } else {
            assert(false);
        }
    }

    void inorder() {
        inorder_(root_);
    }

    bool isBalanced() {
        return _isBalanced(root_);
    }

    int height() {
		return _height(root_);
    }

    bool find(const K& key) {
        return _find(root_, key);
    }

private:
    void inorder_(TreeNode<K, V> *root) {
        if (root == nullptr) {
            return;
        }
        inorder_(root->left_);
        std::cout << root->value_.first << ":" << root->value_.second << std::endl;
        inorder_(root->right_);
    }
    bool _isBalanced(TreeNode<K, V> *root) {
        if (root == nullptr) {
            return true;
        }
        int leftHeight = _height(root->left_);
        int rightHeight = _height(root->right_);
        if (rightHeight - leftHeight != root->bf_) {
            // cout << root->value_.first << "平衡因子异常" << endl;
            return false;
        }
        return abs(leftHeight - rightHeight) < 2
        && _isBalanced(root->left_) && _isBalanced(root->right_);
    }
    int _height(TreeNode<K, V> *root) {
        if (root == nullptr) {
            return 0;
        }
        int leftHeight = _height(root->left_);
        int rightHeight = _height(root->right_);
        return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
    }
    bool _find(TreeNode<K, V>* root, const K& key) {
        while (root != nullptr) {
            if (key < root->value_.first) {
                root = root->left_;
            } else if (key > root->value_.first) {
                root = root->right_;
            } else {
                return true;
            }
        }
        return false;
    }

    TreeNode<K, V> *root_ = nullptr;
};

#endif //AVLTREE_H
