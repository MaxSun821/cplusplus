
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
		typedef typename RBTree<K, pair<const K, V>, MapOfValue>::iterator iterator;
        typedef typename RBTree<K, pair<const K, V>, MapOfValue>::const_iterator const_iterator;
        iterator begin() {
			return tree.begin();
        }
        iterator end() {
            return tree.end();
        }
        V& operator[](const K& p) {
            pair<iterator, bool> ret = insert(make_pair(p, V()));
            return ret.first->second;
        }
        pair<iterator, bool> insert(const pair<K, V>& p) {
            return tree.insert(p);
        }
    private:
        RBTree<K, pair<const K, V>, MapOfValue> tree;
    };
    
}

#endif //MYMAP_H
