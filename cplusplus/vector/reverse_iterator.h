#ifndef REVERSE_ITERATOR_H
#define REVERSE_ITERATOR_H

#include "vector.h"

namespace max {
    template <typename Iterator, typename Ref, typename Ptr>
    class ReverseIterator {
    public:
        typedef ReverseIterator<Iterator, Ref, Ptr> self;
        ReverseIterator(Iterator it)
            : it_(it)
        {}
        Ref operator*() const {
            Iterator tmp = it_;
            --tmp;
            return *tmp;
        }
        Ptr operator->() {
            return &(operator*());
        }
        self& operator++() {
            --it_;
            return *this;
        }
        bool operator==(const self& it) {
            return it_ = it.it_;
        }
        bool operator!=(const self& it) {
            return it_ != it.it_;
        }
    private:
        Iterator it_;
    };
}


#endif //REVERSE_ITERATOR_H
