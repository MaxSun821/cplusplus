
#ifndef CPLUSPLUS_AVLTREE_H
#define CPLUSPLUS_AVLTREE_H

#include <iostream>

template<class K, class V>
struct AVLTreeNode {
    AVLTreeNode<K, V> *_left;
    AVLTreeNode<K, V> *_right;
    AVLTreeNode<K, V> *_parent;

    std::pair<K, V> _data;
    int _bf;

    AVLTreeNode(const std::pair<K, V> kv)
            : _left(nullptr), _right(nullptr), _parent(nullptr), _data(kv), _bf(0) {}
};

template<class K, class V>
class AVLTree {
    typedef AVLTreeNode<K, V> node;
public:
    AVLTree()
            : _root(nullptr) {}

    bool insert(const std::pair<K, V> &kv) {
        if (_root == nullptr) {
            _root = new node(kv);
            return true;
        }

        node *cur = _root;
        node *prev = nullptr;
        while (cur) {
            if (kv.first < cur->_data.first) {
                prev = cur;
                cur = cur->_left;
            } else if (kv.first > cur->_data.first) {
                prev = cur;
                cur = cur->_right;
            } else {
                return false;
            }
        }
        cur = new node(kv);

        if (kv.first < prev->_data.first) {
            prev->_left = cur;
        } else {
            prev->_right = cur;
        }
        cur->_parent = prev;

        while (prev) {
            if (cur == prev->_left) {
                prev->_bf--;
            } else {
                prev->_bf++;
            }
            if (prev->_bf == 0) {
                break; // 两树高度差一样，不需要旋转
            } else if (prev->_bf == 1 || prev->_bf == -1) {
                // 父结点有变化，需要再向上判断
                cur = prev;
                prev = prev->_parent;
            } else if (prev->_bf == 2 || prev->_bf == -2) {
                // 需要旋转
                if (prev->_bf == 2 && cur->_bf == 1) {
                    // 左旋
                    rotateL(prev);
                } else if (prev->_bf == -2 && cur->_bf == -1) {
                    // 右旋
                    rotateR(prev);
                }
                break;
            } else {
                assert(false);
            }
        }
        return true;

    }

    void rotateL(node *parent) {
        node *subR = parent->_right;
        node *subRL = subR->_left;

        parent->_right = subRL;
        subR->_left = parent;

        if (subRL) {
            subRL->_parent = parent;
        }

        node *pp_node = parent->_parent;
        parent->_parent = subR;
        if (_root == parent) {
            _root = subR;
            subR->_parent = nullptr;
        } else {
            if (pp_node->_left == parent) {
                pp_node->_left = subR;
            } else {
                pp_node->_right = subR;
            }
            subR->_parent = pp_node;
        }

        parent->_bf = subR->_bf = 0;
    }

    void rotateR(node *parent) {
        node *subL = parent->_left;
        node *subLR = subL->_right;

        parent->_left = subLR;
        if (subLR) {
            subLR->_parent = parent;
        }

        subL->_right = parent;
        node *pp_node = parent->_parent;
        parent->_parent = subL;

        if (_root == parent) {
            _root = subL;
            subL->_parent = nullptr;
        } else {
            if (pp_node->_left = parent) {
                pp_node->_left = subL;
            } else {
                pp_node->_right = subL;
            }
            subL->_parent = pp_node;
        }

        parent->_bf = subL->_bf = 0;
    }

private:
    node *_root;
};

#endif //CPLUSPLUS_AVLTREE_H
