
#ifndef MYMAP_H
#define MYMAP_H

#include "RBTree.h"

namespace max {
    template<typename K, typename V>
    class map {
    public:
        struct MapOfValue {
            const K& operator()(const pair<K, V>& p) const {
                return p.first;
			}
        };
		typedef typename RBTree<K, pair<K, V>, MapOfValue>::iterator iterator;
        iterator begin() {
			return tree.begin();
        }
        iterator end() {
            return tree.end();
        }
        bool insert(const pair<K, V>& p) {
            return tree.insert(p);
        }
    private:
        RBTree<K, pair<K, V>, MapOfValue> tree;
    };
    
}

#endif //MYMAP_H
