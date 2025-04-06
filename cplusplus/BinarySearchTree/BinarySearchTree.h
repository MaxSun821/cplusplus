#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

namespace key {
    template <typename K>
    struct TreeNode {
        K key_;
        TreeNode<K>* left_;
        TreeNode<K>* right_;
        TreeNode(const K& key)
            : key_(key), left_(nullptr), right_(nullptr)
        {}
    };

    template <typename K>
    class BinarySearchTree {
    public:
        BinarySearchTree() : root_(nullptr) {}
        ~BinarySearchTree() {
            destroy(root_);
        }
        BinarySearchTree(const BinarySearchTree<K>& rhs) {
            root_ = copy(rhs.root_);
        }
        BinarySearchTree& operator=(const BinarySearchTree<K> rhs) {
            std::swap(root_, rhs.root_);
            return *this;
        }
        bool insert(const K& key) {
            if (root_ == nullptr) {
                root_ = new TreeNode<K>(key);
                return true;
            }

            TreeNode<K>* prev = nullptr;
            TreeNode<K>* cur = root_;
            while (cur != nullptr) {
                prev = cur;
                if (key > cur->key_) {
                    cur = cur->right_;
                }
                else if (key < cur->key_) {
                    cur = cur->left_;
                }
                else {
                    return false;
                }
            }
            cur = new TreeNode<K>(key);
            if (key < prev->key_) {
                prev->left_ = cur;
            }
            else {
                prev->right_ = cur;
            }
            return true;
        }
        bool erase(const K& key) {
            if (root_ == nullptr) {
                return false;
            }

            TreeNode<K>* prev = nullptr;
            TreeNode<K>* cur = root_;

            while (cur != nullptr) {
                if (key < cur->key_) {
                    prev = cur;
                    cur = cur->left_;
                }
                else if (key > cur->key_) {
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
                        TreeNode<K>* tmp = cur->right_;
                        while (tmp->left_ != nullptr) {
                            prev = tmp;
                            tmp = tmp->left_;
                        }
                        std::swap(cur->key_, tmp->key_);
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
        bool find(const K& key) {
            if (root_ == nullptr) {
                return false;
            }
            TreeNode<K>* cur = root_;
            while (cur != nullptr) {
                if (key < cur->key_) {
                    cur = cur->left_;
                }
                else if (key > cur->key_) {
                    cur = cur->right_;
                }
                else {
                    return true;
                }
            }
            return false;
        }
        bool insertR(const K& key) {
            // 使用递归
            return _insertR(root_, key);
        }
        bool eraseR(const K& key) {
            return _eraseR(root_, key);
        }
        bool findR(const K& key) {
            return _findR(root_, key);
        }
        void print() {
            _print(root_);
        }
    private:
        void _print(TreeNode<K>* root) {
            if (root == nullptr) {
                return;
            }
            _print(root->left_);
            std::cout << root->key_ << " ";
            _print(root->right_);
        }
        bool _insertR(TreeNode<K>*& root, const K& key) {
            if (root == nullptr) {
                root = new TreeNode<K>(key);
                return true;
            }
            if (key < root->key_) {
                // 在左子树插入
                return _insertR(root->left_, key);
            }
            if (key > root->key_) {
                // 在右子树插入
                return _insertR(root->right_, key);
            }
            return false;
        }
        bool _eraseR(TreeNode<K>*& root, const K& key) {
            if (root == nullptr) {
                return false;
            }
            if (key < root->key_) {
                return _eraseR(root->left_, key);
            }
            if (key > root->key_) {
                return _eraseR(root->right_, key);
            }
            if (root->left_ == nullptr) {
                // 左子树为空
                TreeNode<K>* del = root;
                root = root->right_;
                delete del;
                return true;
            }
            else if (root->right_ == nullptr) {
                // 右子树为空
                TreeNode<K>* del = root;
                root = root->left_;
                delete del;
                return true;
            }
            else {
                // 左右子树都不为空
                TreeNode<K>* tmp = root->right_;
                while (tmp->left_ != nullptr) {
                    // 找到右子树最小值
                    tmp = tmp->left_;
                }
                std::swap(root->key_, tmp->key_);
                return _eraseR(root->right_, key);
            }
        }
        bool _findR(TreeNode<K>* root, const K& key) {
            if (root == nullptr) {
                return false;
            }
            if (key < root->key_) {
                return _findR(root->left_, key);
            }
            if (key > root->key_) {
                return _findR(root->right_, key);
            }
            return true;
        }
        void destroy(TreeNode<K>*& root) {
            if (root == nullptr) {
                return;
            }
            destroy(root->left_);
            destroy(root->right_);
            delete root;
            root = nullptr;
        }
        TreeNode<K>* copy(TreeNode<K>* root) {
            if (root == nullptr) {
                return nullptr;
            }
            TreeNode<K>* new_root = new TreeNode<K>(root->key_);
            new_root->left_ = copy(root->left_);
            new_root->right_ = copy(root->right_);
            return new_root;
        }
        TreeNode<K>* root_;
    };
}

namespace key_value {
    template <typename K, typename V>
    struct TreeNode {
        K key_;
        V value_;
        TreeNode<K, V>* left_;
        TreeNode<K, V>* right_;
        TreeNode(const K& key, const  V& value)
            : key_(key), value_(value), left_(nullptr), right_(nullptr)
        {}
    };

    template <typename K, typename V>
    class BinarySearchTree {
    public:
        BinarySearchTree() : root_(nullptr) {}
        ~BinarySearchTree() {
            destroy(root_);
        }
        BinarySearchTree(const BinarySearchTree<K, V>& rhs) {
            root_ = copy(rhs.root_);
        }
        BinarySearchTree& operator=(const BinarySearchTree<K, V> rhs) {
            std::swap(root_, rhs.root_);
            return *this;
        }
        bool insert(const K& key, const V& value) {
            if (root_ == nullptr) {
                root_ = new TreeNode<K, V>(key, value);
                return true;
            }

            TreeNode<K, V>* prev = nullptr;
            TreeNode<K, V>* cur = root_;
            while (cur != nullptr) {
                prev = cur;
                if (key > cur->key_) {
                    cur = cur->right_;
                }
                else if (key < cur->key_) {
                    cur = cur->left_;
                }
                else {
                    return false;
                }
            }
            cur = new TreeNode<K, V>(key, value);
            if (key < prev->key_) {
                prev->left_ = cur;
            }
            else {
                prev->right_ = cur;
            }
            return true;
        }
        bool erase(const K& key) {
            if (root_ == nullptr) {
                return false;
            }

            TreeNode<K, V>* prev = nullptr;
            TreeNode<K, V>* cur = root_;

            while (cur != nullptr) {
                if (key < cur->key_) {
                    prev = cur;
                    cur = cur->left_;
                }
                else if (key > cur->key_) {
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
                        TreeNode<K, V>* tmp = cur->right_;
                        while (tmp->left_ != nullptr) {
                            prev = tmp;
                            tmp = tmp->left_;
                        }
                        std::swap(cur->key_, tmp->key_);
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
        TreeNode<K, V>* find(const K& key) {
            if (root_ == nullptr) {
                return nullptr;
            }
            TreeNode<K, V>* cur = root_;
            while (cur != nullptr) {
                if (key < cur->key_) {
                    cur = cur->left_;
                }
                else if (key > cur->key_) {
                    cur = cur->right_;
                }
                else {
                    return cur;
                }
            }
            return nullptr;
        }
        void print() {
            _print(root_);
        }
    private:
        void _print(TreeNode<K, V>* root) {
            if (root == nullptr) {
                return;
            }
            _print(root->left_);
            std::cout << root->key_ << ":" << root->value_ << std::endl;
            _print(root->right_);
        }
        void destroy(TreeNode<K, V>*& root) {
            if (root == nullptr) {
                return;
            }
            destroy(root->left_);
            destroy(root->right_);
            delete root;
            root = nullptr;
        }
        TreeNode<K, V>* copy(TreeNode<K, V>* root) {
            if (root == nullptr) {
                return nullptr;
            }
            TreeNode<K, V>* new_root = new TreeNode<K, V>(root->key_);
            new_root->left_ = copy(root->left_);
            new_root->right_ = copy(root->right_);
            return new_root;
        }
        TreeNode<K, V>* root_;
    };
}

#endif //BINARYSEARCHTREE_H
