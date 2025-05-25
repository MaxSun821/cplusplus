#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::pair;
using std::make_pair;
using std::string;
using std::cout;
using std::endl;

template<typename T>
struct HashFunc {
    size_t operator()(const T &val) {
        return (size_t)val;
    }
};

template<>
struct HashFunc<string> {
    size_t operator()(const string &s) {
        size_t hash = 0;
        for (auto c : s) {
            hash *= 31;
            hash += c;
        }
        return hash;
    }
};

namespace hash_backet {
    template<typename T>
    struct HashNode {
        T data_;
        HashNode<T> *next_;

        HashNode(const T &data)
            : data_(data), next_(nullptr) {
        }
    };

    template<typename K, typename T, typename KeyOfValue, typename Hash>
    class HashTable;

    template<typename K, typename T, typename Ref, typename Ptr, typename KeyOfValue, typename Hash>
    struct __HTIterator {
        typedef HashNode<T> Node;
        typedef __HTIterator<K, T, Ref, Ptr, KeyOfValue, Hash> Self;
        Node* node_;
        const HashTable<K, T, KeyOfValue, Hash>* ht_;
        size_t hashi_;
        __HTIterator(Node *node, HashTable<K, T, KeyOfValue, Hash>* ht, size_t hashi)
            : node_(node)
			, ht_(ht) 
            , hashi_(hashi) {
		}
        __HTIterator(Node* node, const HashTable<K, T, KeyOfValue, Hash>* ht, size_t hashi)
            : node_(node)
            , ht_(ht)
            , hashi_(hashi) {
        }
        Ref operator*() {
            return node_->data_;
        }
        Ptr operator->() {
            return &node_->data_;
		}
        Self& operator++() {
            if (node_->next_ != nullptr) {
                node_ = node_->next_;
            }
            else {
                ++hashi_;
                while (hashi_ < ht_->table_.size()) {
                    if (ht_->table_[hashi_] != nullptr) {
                        node_ = ht_->table_[hashi_];
                        break;
                    }
                    ++hashi_;
                }
                if (hashi_ == ht_->table_.size()) {
                    node_ = nullptr;
                }
            }
            return *this;
        }
        bool operator!=(const Self& s) {
            return node_ != s.node_;
        }
    };

    template<typename K, typename T, typename KeyOfValue, typename Hash>
    class HashTable {
        typedef HashNode<T> Node;
		

        template<typename K, typename T, typename Ref, typename Ptr, typename KeyOfValue, typename Hash>
		friend struct __HTIterator;

    public:
        typedef __HTIterator<K, T, T&, T*, KeyOfValue, Hash> iterator;
        typedef __HTIterator<K, T, const T&, const T*, KeyOfValue, Hash> const_iterator;

        HashTable() {
            table_.resize(10);
        }
        ~HashTable() {
            for (size_t i = 0; i < table_.size(); i++) {
                Node *cur = table_[i];
                while (cur != nullptr) {
                    Node *next = cur->next_;
                    delete cur;
                    cur = next;
                }
            }
        }
        iterator begin() {
            for (size_t i = 0; i < table_.size(); i++) {
                if (table_[i] != nullptr) {
                    return iterator(table_[i], this, i);
                }
            }
            return end();
        }
        iterator end() {
            return iterator(nullptr, this, -1);
        }
        const_iterator begin() const {
            for (size_t i = 0; i < table_.size(); i++) {
                if (table_[i] != nullptr) {
                    return const_iterator(table_[i], this, i);
                }
            }
            return end();
        }
        const_iterator end() const {
			return const_iterator(nullptr, this, -1);
        }
        
        
        pair<iterator, bool> insert(const T &p) {
            KeyOfValue kov;
            Hash hash;
            iterator it = find(kov(p));
            if (it != end()) {
                return make_pair(it, false);
            }
            
            if (load_factor == table_.size()) {
                size_t newSize = table_.size() * 2;
                vector<Node *> newData;
                newData.resize(newSize, nullptr);
                for (size_t i = 0; i < table_.size(); i++) {
                    Node *cur = table_[i];
                    while (cur != nullptr) {
                        Node *next = cur->next_;
                        size_t newHashi = hash(kov(cur->data_)) % newData.size();
                        cur->next_ = newData[newHashi];
                        newData[newHashi] = cur;
                        cur = next;
                    }
                    table_[i] = nullptr;
                }
                table_.swap(newData);
            }
            size_t hashi = hash(kov(p)) % table_.size();
            Node *newNode = new Node(p);
            newNode->next_ = table_[hashi];
            table_[hashi] = newNode;
            ++load_factor;
            return make_pair(iterator(newNode, this, hashi), true);
        }

        iterator find(const K &key) {
			KeyOfValue kov;
            Hash hash;
            size_t hashi = hash(key) % table_.size();
            Node *node = table_[hashi];
            while (node != nullptr) {
                if (kov(node->data_) == key) {
                    return iterator(node, this, hashi);
                }
                node = node->next_;
            }
            return end();
        }

        bool erase(const K &key) {
            KeyOfValue kov;
            Hash hash;
            size_t hashi = hash(key) % table_.size();
            Node *cur = table_[hashi];
            Node *prev = nullptr;

            while (cur != nullptr) {
                if (kov(cur->data_) == key) {
                    if (prev != nullptr) {
                        prev->next_ = cur->next_;
                    } else {
                        table_[hashi] = cur->next_;
                    }
                    delete cur;
                    return true;
                }
                prev = cur;
                cur = cur->next_;
            }
            return false;
        }
    private:
        vector<Node *> table_;
        size_t load_factor = 0;
    };
}

#endif //HASHTABLE_H
