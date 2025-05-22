
#ifndef MYSET_H
#define MYSET_H

#include "RBTree.h"

namespace max {

    template<typename K>
    class MySet {
    public:
        struct SetOfValue {
            const K& operator()(const K& x) {
                return x;
            }
        };
        bool insert(const K& value) {
            return root_.insert(value);
        }
    private:
        RBTree<K, K, SetOfValue>* root_;
    };
}

#endif //MYSET_H
