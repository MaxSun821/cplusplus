
#ifndef CPLUSPLUS_AVLTREE_H
#define CPLUSPLUS_AVLTREE_H

#include <iostream>
#include <vector>

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
                } else if (prev->_bf == 2 && cur->_bf == -1) {
                    rotateRL(prev);
                } else if (prev->_bf == -2 && cur->_bf == 1) {
                    rotateLR(prev);
                }
                break;
            } else {
                assert(false);
            }
        }
        return true;

    }

    void inorder() {
        _inorder(_root);
        std::cout << std::endl;
    }

    bool isBalance() {
        // 验证是否平衡
        return _isBalance(_root);
    }

    int getHeight() {
        return _height(_root);
    }

private:
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
            if (pp_node->_left == parent) {
                pp_node->_left = subL;
            } else {
                pp_node->_right = subL;
            }
            subL->_parent = pp_node;
        }

        parent->_bf = subL->_bf = 0;
    }

    void rotateRL(node *parent) {

        node *sub = parent->_right;
        node *subL = sub->_left;

        int bf = subL->_bf;

        rotateR(parent->_right);
        rotateL(parent);

        if (bf == 0) {
            // subL就是新插入元素
            parent->_bf = sub->_bf = subL->_bf = 0;
        } else if (bf == -1) {
            // 在subL左子树插入新元素
            parent->_bf = subL->_bf = 0;
            sub->_bf = 1;
        } else if (bf == 1) {
            // 在subL右子树插入新元素
            sub->_bf = subL->_bf = 0;
            parent->_bf = -1;
        } else {
            assert(false);
        }
    }

    void rotateLR(node *parent) {
        node *sub = parent->_left;
        node *subR = sub->_right;

        int bf = subR->_bf;

        rotateL(parent->_left);
        rotateR(parent);

        if (bf == 0) {
            // subL就是新插入元素
            parent->_bf = sub->_bf = subR->_bf = 0;
        } else if (bf == -1) {
            // 在subL左子树插入新元素
            subR->_bf = sub->_bf = 0;
            parent->_bf = 1;
        } else if (bf == 1) {
            // 在subL右子树插入新元素
            parent->_bf = subR->_bf = 0;
            sub->_bf = -1;
        } else {
            assert(false);
        }
    }

    void _inorder(node *root) {
        if (root == nullptr) {
            return;
        }
        _inorder(root->_left);
        std::cout << root->_data.first << ":" << root->_data.second << " ";
        _inorder(root->_right);
    }

    bool _isBalance(node *root) {
        if (root == nullptr) {
            return true;
        }
        int leftHeight = _height(root->_left);
        int rightHeight = _height(root->_right);

        if(rightHeight - leftHeight != root->_bf) {
            std::cout << root->_data.first << "平衡因子出现异常" << std::endl;
        }

        return abs(rightHeight - leftHeight) < 2
               && _isBalance(root->_left)
               && _isBalance(root->_right);
    }

    int _height(node *root) {
        if (root == nullptr) {
            return 0;
        }
        int leftHeight = _height(root->_left);
        int rightHeight = _height(root->_right);
        return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
    }

private:
    node *_root;
};

#endif //CPLUSPLUS_AVLTREE_H
