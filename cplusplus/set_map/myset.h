
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

        typedef typename RBTree<K, K, SetOfValue>::iterator iterator;

        iterator begin() {
            return tree.begin();
        }
        iterator end() {
            return tree.end();
        }
        bool insert(const K& key) {
			return tree.insert(key);
        }
    private:
        RBTree<K, K, SetOfValue> tree;
    };
}

#endif //MYSET_H
