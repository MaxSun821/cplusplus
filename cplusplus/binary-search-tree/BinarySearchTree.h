

#ifndef CPLUSPLUS_BINARYSEARCHTREE_H
#define CPLUSPLUS_BINARYSEARCHTREE_H

#include <iostream>

template<class K>
struct TreeNode {
    TreeNode *_left;
    TreeNode *_right;
    K _val;

    TreeNode(const K &val = K())
            : _val(val), _left(nullptr), _right(nullptr) {}

};

template<class K>
class BSTree {
    typedef TreeNode<K> node;
public:
    BSTree()
            : _root(nullptr) {}

    ~BSTree() {
        while (!empty()) {
            erase(_root->_val);
        }
    }

    bool insert(const K &val) {
        if (_root == nullptr) {
            _root = new node(val);
            return true;
        }
        node *cur = _root;
        node *prev = nullptr;
        while (cur != nullptr) {
            prev = cur;
            if (val > cur->_val) {
                cur = cur->_right;
            } else if (val < cur->_val) {
                cur = cur->_left;
            } else {
                return false;
            }
        }
        cur = new node(val);
        if (val > prev->_val) {
            prev->_right = cur;
        } else {
            prev->_left = cur;
        }
        return true;
    }

    bool insertR(const K& val) {
        // 插入递归实现
        return _insertR(_root, val);
    }

    bool erase(const K &val) {
        if (_root == nullptr) {
            return false;
        }
        node *cur = _root;
        node *prev = nullptr;
        while (cur != nullptr) {
            if (val > cur->_val) {
                prev = cur;
                cur = cur->_right;
            } else if (val < cur->_val) {
                prev = cur;
                cur = cur->_left;
            } else {
                if (cur->_left == nullptr) {
                    // 左子树为空
                    if (cur == _root) {
                        _root = cur->_right;
                    } else {
                        if (cur == prev->_left) {
                            // cur是左子树
                            prev->_left = cur->_right;
                        } else {
                            // cur是右子树
                            prev->_right = cur->_right;
                        }
                    }
                    delete cur;
                    return true;
                } else if (cur->_right == nullptr) {
                    // 右子树为空
                    if (cur == _root) {
                        _root = cur->_left;
                    } else {
                        if (cur == prev->_left) {
                            // cur是左子树
                            prev->_left = cur->_left;
                        } else {
                            // cur是右子树
                            prev->_right = cur->_left;
                        }
                    }
                    delete cur;
                    return true;
                } else {
                    // 左右子树都不为空
                    // 找右树最小结点
                    node *subLeft = cur->_right;
                    prev = cur;
                    while (subLeft->_left != nullptr) {
                        prev = subLeft;
                        subLeft = subLeft->_left;
                    }
                    // 交换右树最小结点和删除结点元素
                    std::swap(subLeft->_val, cur->_val);
                    if (subLeft == prev->_left) {
                        prev->_left = subLeft->_left;
                    } else {
                        prev->_right = subLeft->_right;
                    }
                    delete subLeft;
                    return true;
                }
            }
        }
        return false;
    }

    bool eraseR(const K& val) {
        return _eraseR(_root, val);
    }

    bool find(const K &val) {
        if (_root == nullptr) {
            return false;
        }
        node *cur = _root;
        while (cur != nullptr) {
            if (val > cur->_val) {
                cur = cur->_right;
            } else if (val < cur->_val) {
                cur = cur->_left;
            } else {
                return true;
            }
        }
        return false;
    }

    bool findR(const K& val) {
        // 查找递归实现
        return  _findR(_root, val);
    }

    void inorder() {
        _inorder(_root);
        std::cout << std::endl;
    }

    bool empty() {
        return _root == nullptr;
    }

private:
    void _inorder(node *root) {
        if (root == nullptr) {
            return;
        }
        _inorder(root->_left);
        std::cout << root->_val << " ";
        _inorder(root->_right);
    }

    bool _findR(node* root, const K& val) {
        if(root == nullptr) {
            return false;
        }
        if(val > root->_val) {
            return _findR(root->_right, val);
        } else if(val < root->_val) {
            return _findR(root->_left,val);
        } else {
            return true;
        }
    }

    bool _insertR(node*& root, const K& val) {
        if(root == nullptr) {
            root = new node(val);
            return true;
        }
        if(val > root->_val) {
            return _insertR(root->_right, val);
        } else if(val < root->_val) {
            return _insertR(root->_left, val);
        } else {
            return false;
        }
    }

    bool _eraseR(node*& root, const K& val) {
        if(root == nullptr) {
            return false;
        }
        if(val > root->_val) {
            return _eraseR(root->_right, val);
        } else if(val < root->_val) {
            return _eraseR(root->_left, val);
        } else {
            if(root->_left == nullptr) {
                // 左子树为空
                node* del = root;
                root = root->_right;
                delete del;
            } else if(root->_right == nullptr) {
                // 右子树为空
                node* del = root;
                root = root->_left;
                delete del;
            } else {
                // 左右子树都不为空
                // 找右子树最小结点
                node* subLeft = root->_right;
                while(subLeft->_left != nullptr) {
                    subLeft = subLeft->_left;
                }
                // 交换元素
                std::swap(root->_val, subLeft->_val);
                return _eraseR(root->_right, val);
            }
        }
    }

private:
    node *_root;
};

#endif //CPLUSPLUS_BINARYSEARCHTREE_H
