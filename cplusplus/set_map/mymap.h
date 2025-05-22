
#ifndef MYMAP_H
#define MYMAP_H

#include "RBTree.h"

namespace max {

    template<typename K, typename V>
    class MyMap {
    public:
        struct MapOfValue {
            K& operator()(const pair<K, V>& p) {
                return p.first;
            }
        };
        bool insert(const pair<K, V>& p) {
            return root_.insert(p);
        }
    private:
        RBTree<K, pair<K, V>, MapOfValue>* root_;
    };
}

#endif //MYMAP_H
