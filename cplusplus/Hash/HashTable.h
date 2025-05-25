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

namespace closed_hash {
    enum Status {
        EMPTY,
        DELETED,
        EXISTING
    };

    template<typename K, typename V>
    struct HashNode {
        pair<K, V> kv_;
        Status status_;
    };

    template<typename K, typename V, typename Hash = HashFunc<K>>
    class HashTable {
    public:
        HashTable() {
            data_.resize(10);
        }

        bool insert(const pair<K, V> &p) {
            if (find(p.first) != nullptr) {
                return false;
            }
            if (load_factor * 10 / data_.size() >= 7) {
                // 扩容
                size_t newSize = data_.size() * 2;
                HashTable<K, V> newData;
                newData.data_.resize(newSize);
                for (size_t i = 0; i < data_.size(); i++) {
                    if (data_[i].status_ == EXISTING) {
                        newData.insert(data_[i].kv_);
                    }
                }
                data_.swap(newData.data_);
            }
            Hash hash;
            size_t hashi = hash(p.first) % data_.size(); // 计算hash值
            while (data_[hashi].status_ == EXISTING) {
                ++hashi;
                hashi %= data_.size();
            }
            data_[hashi].kv_ = p;
            data_[hashi].status_ = EXISTING;
            ++load_factor;
            return true;
        }

        HashNode<K, V> *find(const K &key) {
            Hash hash;
            size_t hashi = hash(key) % data_.size();
            while (data_[hashi].status_ != EMPTY) {
                if (data_[hashi].status_ == EXISTING && data_[hashi].kv_.first == key) {
                    return &data_[hashi];
                }
                ++hashi;
                hashi %= data_.size();
            }
            return nullptr;
        }

        bool erase(const K &key) {
            HashNode<K, V> *node = find(key);
            if (node != nullptr) {
                node->status_ = DELETED;
                --load_factor;
                return true;
            }
            return false;
        }

    private:
        vector<HashNode<K, V> > data_;
        size_t load_factor = 0;
    };
}

namespace hash_backet {
    template<typename K, typename V>
    struct HashNode {
        pair<K, V> kv_;
        HashNode<K, V> *next_;

        HashNode(const pair<K, V> &kv)
            : kv_(kv), next_(nullptr) {
        }
    };

    template<typename K, typename V, typename Hash = HashFunc<K>>
    class HashTable {
        typedef HashNode<K, V> Node;
    public:
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
        bool insert(const pair<K, V> &p) {
            if (find(p.first) != nullptr) {
                return false;
            }
            Hash hash;
            if (load_factor == table_.size()) {
                size_t newSize = table_.size() * 2;
                vector<Node *> newData;
                newData.resize(newSize, nullptr);
                for (size_t i = 0; i < table_.size(); i++) {
                    Node *cur = table_[i];
                    while (cur != nullptr) {
                        Node *next = cur->next_;
                        size_t newHashi = hash(cur->kv_.first) % newData.size();
                        cur->next_ = newData[newHashi];
                        newData[newHashi] = cur;
                        cur = next;
                    }
                    table_[i] = nullptr;
                }
                table_.swap(newData);
            }
            size_t hashi = hash(p.first) % table_.size();
            Node *newNode = new Node(p);
            newNode->next_ = table_[hashi];
            table_[hashi] = newNode;
            ++load_factor;
            return true;
        }

        Node *find(const K &key) {
            Hash hash;
            size_t hashi = hash(key) % table_.size();
            Node *node = table_[hashi];
            while (node != nullptr) {
                if (node->kv_.first == key) {
                    return node;
                }
                node = node->next_;
            }
            return nullptr;
        }

        bool erase(const K &key) {
            Hash hash;
            size_t hashi = hash(key) % table_.size();
            Node *cur = table_[hashi];
            Node *prev = nullptr;

            while (cur != nullptr) {
                if (cur->kv_.first == key) {
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
