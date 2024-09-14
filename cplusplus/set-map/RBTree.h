#pragma once

#include <iostream>

enum Color {
    RED,
    BLACK
};

template<class T>
struct RBTreeNode {
    RBTreeNode<T>* _left;
    RBTreeNode<T>* _right;
    RBTreeNode<T>* _parent;

    T _data;
    Color _col;

    RBTreeNode(const T& data)
        : _left(nullptr), _right(nullptr), _parent(nullptr), _data(data), _col(RED) {}
};

template<class T, class Ref, class Ptr>
struct __rb_iterator {
    typedef RBTreeNode<T> node;
    typedef __rb_iterator<T, Ref, Ptr> self;
    node* _node;
    __rb_iterator(node* node)
        : _node(node) {}

    Ref operator*() {
        return _node->_data;
    }

    Ptr operator->() {
        return &(_node->_data);
    }

    self& operator++() {
        if (_node->_right) {
            // 有右子树，找到右子树最左结点
            node* cur = _node->_right;
            while (cur->_left) {
                cur = cur->_left;
            }
            _node = cur;
        }
        else {
            // 没有右子树，向上找孩子是父亲左子树的那个祖先
            node* cur = _node;
            node* parent = cur->_parent;

            while (parent && cur == parent->_right) {
                cur = parent;
                parent = cur->_parent;
            }

            _node = parent;

        }
        return *this;
    }

    bool operator!=(const self& s) {
        return _node != s._node;
    }
};

template<class K, class T, class KOT>
class RBTree {
    typedef RBTreeNode<T> node;
public:
    typedef __rb_iterator<T, T&, T*> iterator;
    typedef __rb_iterator<T, const T&, const T*> const_iterator;
    RBTree()
        : _root(nullptr) {}

    iterator begin() {
        node* cur = _root;
        while (cur && cur->_left) {
            cur = cur->_left;
        }
        return iterator(cur);
    }

    iterator end() {
        return iterator(nullptr);
    }

    const_iterator begin() const {
        node* cur = _root;
        while (cur && cur->_left) {
            cur = cur->_left;
        }
        return const_iterator(cur);
    }

    const_iterator end() const {
        return const_iterator(nullptr);
    }

    std::pair<node*, bool> insert(const T& data) {
        if (_root == nullptr) {
            _root = new node(data);
            _root->_col = BLACK;
            return std::make_pair(_root, true);
        }

        node* cur = _root;
        node* prev = nullptr;
        KOT kot;
        while (cur) {
            if (kot(data) < kot(cur->_data)) {
                prev = cur;
                cur = cur->_left;
            }
            else if (kot(data) > kot(cur->_data)) {
                prev = cur;
                cur = cur->_right;
            }
            else {
                return std::make_pair(cur, false);
            }
        }

        // 插入新结点
        cur = new node(data);
        node* newNode = cur;
        if (kot(cur->_data) < kot(prev->_data)) {
            prev->_left = cur;
        }
        else {
            prev->_right = cur;
        }
        cur->_parent = prev;

        // 判断是否满足红黑树规则
        while (prev && prev->_col == RED) {
            // 父结点是红色才需要调整
            node* grandparent = prev->_parent;
            if (prev == grandparent->_left) {
                node* uncleNode = grandparent->_right;
                if (uncleNode && uncleNode->_col == RED) {
                    // uncleNode结点存在，且和prev结点同为红色
                    prev->_col = uncleNode->_col = BLACK;
                    grandparent->_col = RED;

                    cur = grandparent;
                    prev = cur->_parent;
                }
                else {
                    if (cur == prev->_left) {
                        // uncleNode结点不存在或者为黑
                        //     g
                        //   p   (u)
                        // c
                        // 以grandparent结点进行右旋
                        rotateR(grandparent);
                        prev->_col = BLACK;
                        grandparent->_col = RED;
                    }
                    else {
                        //     g
                        //   p   (u)
                        //     c
                        rotateL(prev);
                        rotateR(grandparent);
                        cur->_col = BLACK;
                        prev->_col = grandparent->_col = RED;
                    }
                    break;
                }
                
            }
            else {
                node* uncleNode = grandparent->_left;
                if (uncleNode && uncleNode->_col == RED) {
                    // uncleNode结点存在，且和prev结点同为红色
                    prev->_col = uncleNode->_col = BLACK;
                    grandparent->_col = RED;

                    cur = grandparent;
                    prev = cur->_parent;
                }
                else {
                    if (cur == prev->_right) {
                        // uncleNode结点不存在或者为黑
                        //     g
                        //  (u)  p
                        //         c 
                        // 以grandparent结点进行右旋
                        rotateL(grandparent);
                        prev->_col = BLACK;
                        grandparent->_col = RED;
                    }
                    else {
                        //     g
                        // (u)   p
                        //     c
                        rotateR(prev);
                        rotateL(grandparent);
                        cur->_col = BLACK;
                        prev->_col = grandparent->_col = RED;
                    }
                    break;
                }
            }
        }
        _root->_col = BLACK;

        return std::make_pair(newNode, true);

    }


    bool isBalance() {
        if (_root == nullptr) {
            return true;
        }
        if (_root->_col == RED) {
            return false;
        }

        node* cur = _root;
        int refVal = 0;
        while (cur) {
            if (cur->_col == BLACK) {
                ++refVal;
            }
            cur = cur->_left;
        }
        int blackNum = 0;

        return check(_root, blackNum, refVal);
    }

    int getHeight() {
        return _height(_root);
    }

    node* find(const K& key) {
        KOT kot;
        node* cur = _root;
        if (key < kot(cur->_data)) {
            cur = cur->_left;
        }
        else if (key > kot(cur->_data)) {
            cur = cur->_right;
        }
        else {
            return cur;
        }
        return nullptr;
    }

    size_t size() {
        if (_root == nullptr) {
            return 0;
        }
        return _size(_root->_left) + _size(_root->_right) + 1;
    }


private:
    void rotateL(node* parent) {
        node* subR = parent->_right;
        node* subRL = subR->_left;

        parent->_right = subRL;
        subR->_left = parent;

        if (subRL) {
            subRL->_parent = parent;
        }

        node* pp_node = parent->_parent;
        parent->_parent = subR;
        if (_root == parent) {
            _root = subR;
            subR->_parent = nullptr;
        }
        else {
            if (pp_node->_left == parent) {
                pp_node->_left = subR;
            }
            else {
                pp_node->_right = subR;
            }
            subR->_parent = pp_node;
        }
    }

    void rotateR(node* parent) {
        node* subL = parent->_left;
        node* subLR = subL->_right;

        parent->_left = subLR;
        if (subLR) {
            subLR->_parent = parent;
        }

        subL->_right = parent;
        node* pp_node = parent->_parent;
        parent->_parent = subL;

        if (_root == parent) {
            _root = subL;
            subL->_parent = nullptr;
        }
        else {
            if (pp_node->_left == parent) {
                pp_node->_left = subL;
            }
            else {
                pp_node->_right = subL;
            }
            subL->_parent = pp_node;
        }

    }


    bool check(node* root, int blackNum, const int refVal) {
        if (root == nullptr) {
            if (blackNum != refVal) {
                std::cout << "出现黑色结点数量不同" << std::endl;
                return false;
            }
            return true;
        }
        if (root->_parent && root->_col == RED && root->_parent->_col == RED) {
            std::cout << "有连续的红色结点" << std::endl;
            return false;
        }
        if (root->_col == BLACK) {
            ++blackNum;
        }

        return check(root->_left, blackNum, refVal) && check(root->_right, blackNum, refVal);
    }

    int _height(node* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftHeight = _height(root->_left);
        int rightHeight = _height(root->_right);
        return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
    }

    size_t _size(node* root) {
        if (root == nullptr) {
            return 0;
        }
        size_t left = _size(root->_left);
        size_t right = _size(root->_right);

        return left + right + 1;
    }

private:
    node* _root;
};