#pragma once

#include "RBTree.h"

namespace max {
    template<class K>
    class set {
    public:

        struct KeyOfType {
            const K& operator()(const K& data) {
                return data;
            }
        };

        typedef typename RBTree<K, K, KeyOfType>::const_iterator iterator;
        typedef typename RBTree<K, K, KeyOfType>::const_iterator const_iterator;

        iterator begin() const {
            return _t.begin();
        }

        iterator end() const {
            return _t.end();
        }


        std::pair<iterator, bool> insert(const K& key) {
            return _t.insert(key);
        }

    private:
        RBTree<K, K, KeyOfType> _t;
    };
}