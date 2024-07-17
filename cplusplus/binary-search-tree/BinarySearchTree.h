

#ifndef CPLUSPLUS_BINARYSEARCHTREE_H
#define CPLUSPLUS_BINARYSEARCHTREE_H

#include <iostream>

namespace key {

    template<class K>
    struct TreeNode {
        TreeNode* _left;
        TreeNode* _right;
        K _key;

        TreeNode(const K& key = K())
            : _key(key), _left(nullptr), _right(nullptr) {}

    };

    template<class K>
    class BSTree {
        typedef TreeNode<K> node;
    public:
        BSTree()
            : _root(nullptr) {}

        /*~BSTree() {
            while (!empty()) {
                erase(_root->_key);
            }
        }*/

        ~BSTree() {
            destroy(_root);
        }

        BSTree(const BSTree<K>& tree) {
            _root = copy(tree._root);
        }

        BSTree<K>& operator=(BSTree<K> tree) {
            std::swap(_root, tree._root);
            return *this;
        }

        bool insert(const K& key) {
            if (_root == nullptr) {
                _root = new node(key);
                return true;
            }
            node* cur = _root;
            node* prev = nullptr;
            while (cur != nullptr) {
                prev = cur;
                if (key > cur->_key) {
                    cur = cur->_right;
                }
                else if (key < cur->_key) {
                    cur = cur->_left;
                }
                else {
                    return false;
                }
            }
            cur = new node(key);
            if (key > prev->_key) {
                prev->_right = cur;
            }
            else {
                prev->_left = cur;
            }
            return true;
        }

        bool insertR(const K& key) {
            // 插入递归实现
            return _insertR(_root, key);
        }

        bool erase(const K& key) {
            if (_root == nullptr) {
                return false;
            }
            node* cur = _root;
            node* prev = nullptr;
            while (cur != nullptr) {
                if (key > cur->_key) {
                    prev = cur;
                    cur = cur->_right;
                }
                else if (key < cur->_key) {
                    prev = cur;
                    cur = cur->_left;
                }
                else {
                    if (cur->_left == nullptr) {
                        // 左子树为空
                        if (cur == _root) {
                            _root = cur->_right;
                        }
                        else {
                            if (cur == prev->_left) {
                                // cur是左子树
                                prev->_left = cur->_right;
                            }
                            else {
                                // cur是右子树
                                prev->_right = cur->_right;
                            }
                        }
                        delete cur;
                        return true;
                    }
                    else if (cur->_right == nullptr) {
                        // 右子树为空
                        if (cur == _root) {
                            _root = cur->_left;
                        }
                        else {
                            if (cur == prev->_left) {
                                // cur是左子树
                                prev->_left = cur->_left;
                            }
                            else {
                                // cur是右子树
                                prev->_right = cur->_left;
                            }
                        }
                        delete cur;
                        return true;
                    }
                    else {
                        // 左右子树都不为空
                        // 找右树最小结点
                        node* subLeft = cur->_right;
                        prev = cur;
                        while (subLeft->_left != nullptr) {
                            prev = subLeft;
                            subLeft = subLeft->_left;
                        }
                        // 交换右树最小结点和删除结点元素
                        std::swap(subLeft->_key, cur->_key);
                        if (subLeft == prev->_left) {
                            prev->_left = subLeft->_left;
                        }
                        else {
                            prev->_right = subLeft->_right;
                        }
                        delete subLeft;
                        return true;
                    }
                }
            }
            return false;
        }

        bool eraseR(const K& key) {
            return _eraseR(_root, key);
        }

        bool find(const K& key) {
            if (_root == nullptr) {
                return false;
            }
            node* cur = _root;
            while (cur != nullptr) {
                if (key > cur->_key) {
                    cur = cur->_right;
                }
                else if (key < cur->_key) {
                    cur = cur->_left;
                }
                else {
                    return true;
                }
            }
            return false;
        }

        bool findR(const K& key) {
            // 查找递归实现
            return  _findR(_root, key);
        }

        void inorder() {
            _inorder(_root);
            std::cout << std::endl;
        }

        bool empty() {
            return _root == nullptr;
        }

    private:
        node* copy(node* root) {
            if (root == nullptr) {
                return nullptr;
            }
            node* newRoot = new node(root->_key);
            newRoot->_left = copy(root->_left);
            newRoot->_right = copy(root->_right);

            return newRoot;
        }

        void destroy(node*& root) {
            if (root == nullptr) {
                return;
            }
            destroy(root->_left);
            destroy(root->_right);
            delete root;
            root = nullptr;
        }

        void _inorder(node* root) {
            if (root == nullptr) {
                return;
            }
            _inorder(root->_left);
            std::cout << root->_key << " ";
            _inorder(root->_right);
        }

        bool _findR(node* root, const K& key) {
            if (root == nullptr) {
                return false;
            }
            if (key > root->_key) {
                return _findR(root->_right, key);
            }
            else if (key < root->_key) {
                return _findR(root->_left, key);
            }
            else {
                return true;
            }
        }

        bool _insertR(node*& root, const K& key) {
            if (root == nullptr) {
                root = new node(key);
                return true;
            }
            if (key > root->_key) {
                return _insertR(root->_right, key);
            }
            else if (key < root->_key) {
                return _insertR(root->_left, key);
            }
            else {
                return false;
            }
        }

        bool _eraseR(node*& root, const K& key) {
            if (root == nullptr) {
                return false;
            }
            if (key > root->_key) {
                return _eraseR(root->_right, key);
            }
            else if (key < root->_key) {
                return _eraseR(root->_left, key);
            }
            else {
                if (root->_left == nullptr) {
                    // 左子树为空
                    node* del = root;
                    root = root->_right;
                    delete del;
                }
                else if (root->_right == nullptr) {
                    // 右子树为空
                    node* del = root;
                    root = root->_left;
                    delete del;
                }
                else {
                    // 左右子树都不为空
                    // 找右子树最小结点
                    node* subLeft = root->_right;
                    while (subLeft->_left != nullptr) {
                        subLeft = subLeft->_left;
                    }
                    // 交换元素
                    std::swap(root->_key, subLeft->_key);
                    return _eraseR(root->_right, key);
                }
            }
        }

    private:
        node* _root;
    };
}

namespace key_value {
	template<class K, class V>
	struct TreeNode {
		TreeNode* _left;
		TreeNode* _right;
		K _key;
		V _value;

		TreeNode(const K& key = K(), const V& value = V())
			: _left(nullptr), _right(nullptr), _key(key), _value(value) {}


	};
    
    template<class K, class V>
    class BSTree {
        typedef TreeNode<K, V> node;
    public:
        BSTree()
            : _root(nullptr) {}

        ~BSTree() {
            destroy(_root);
        }

        bool insert(const K& key, const V& value) {
            if (_root == nullptr) {
                _root = new node(key, value);
                return true;
            }
            node* cur = _root;
            node* prev = nullptr;
            while (cur != nullptr) {
                prev = cur;
                if (key > cur->_key) {
                    cur = cur->_right;
                }
                else if (key < cur->_key) {
                    cur = cur->_left;
                }
                else {
                    return false;
                }
            }
            cur = new node(key, value);
            if (key > prev->_key) {
                prev->_right = cur;
            }
            else {
                prev->_left = cur;
            }
            return true;
        }

        bool erase(const K& key) {
            if (_root == nullptr) {
                return false;
            }
            node* cur = _root;
            node* prev = nullptr;
            while (cur != nullptr) {
                if (key > cur->_key) {
                    prev = cur;
                    cur = cur->_right;
                }
                else if (key < cur->_key) {
                    prev = cur;
                    cur = cur->_left;
                }
                else {
                    if (cur->_left == nullptr) {
                        // 左子树为空
                        if (cur == _root) {
                            _root = cur->_right;
                        }
                        else {
                            if (cur == prev->_left) {
                                // cur是左子树
                                prev->_left = cur->_right;
                            }
                            else {
                                // cur是右子树
                                prev->_right = cur->_right;
                            }
                        }
                        delete cur;
                        return true;
                    }
                    else if (cur->_right == nullptr) {
                        // 右子树为空
                        if (cur == _root) {
                            _root = cur->_left;
                        }
                        else {
                            if (cur == prev->_left) {
                                // cur是左子树
                                prev->_left = cur->_left;
                            }
                            else {
                                // cur是右子树
                                prev->_right = cur->_left;
                            }
                        }
                        delete cur;
                        return true;
                    }
                    else {
                        // 左右子树都不为空
                        // 找右树最小结点
                        node* subLeft = cur->_right;
                        prev = cur;
                        while (subLeft->_left != nullptr) {
                            prev = subLeft;
                            subLeft = subLeft->_left;
                        }
                        // 交换右树最小结点和删除结点元素
                        std::swap(subLeft->_key, cur->_key);
                        if (subLeft == prev->_left) {
                            prev->_left = subLeft->_left;
                        }
                        else {
                            prev->_right = subLeft->_right;
                        }
                        delete subLeft;
                        return true;
                    }
                }
            }
            return false;
        }

        node* find(const K& key) {
            if (_root == nullptr) {
                return nullptr;
            }
            node* cur = _root;
            while (cur != nullptr) {
                if (key > cur->_key) {
                    cur = cur->_right;
                }
                else if (key < cur->_key) {
                    cur = cur->_left;
                }
                else {
                    return cur;
                }
            }
            return nullptr;
        }
        void inorder() {
            _inorder(_root);
            std::cout << std::endl;
        }
    private:
        void destroy(node*& root) {
            if (root == nullptr) {
                return;
            }
            destroy(root->_left);
            destroy(root->_right);
            delete root;
            root = nullptr;
        }
        void _inorder(node* root) {
            if (root == nullptr) {
                return;
            }
            _inorder(root->_left);
            std::cout << root->_key << ": " << root->_value << std::endl;
            _inorder(root->_right);
        }
    private:
        node* _root;
    };
}

#endif //CPLUSPLUS_BINARYSEARCHTREE_H
