
#ifndef MYSET_H
#define MYSET_H

#include "RBTree.h"

namespace max {

    template<typename K>
    class set {
    public:
        struct SetOfValue {
            const K& operator()(const K& key) {
                return key;
            }
        };

        typedef typename RBTree<K, K, SetOfValue>::const_iterator iterator;
        typedef typename RBTree<K, K, SetOfValue>::const_iterator const_iterator;

        iterator begin() const {
            return tree.begin();
        }
        iterator end() const {
            return tree.end();
        }
        pair<iterator, bool> insert(const K& key) {
			return tree.insert(key);
        }
    private:
        RBTree<K, K, SetOfValue> tree;
    };
}

#endif //MYSET_H
