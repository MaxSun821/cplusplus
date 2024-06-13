
#ifndef CPLUSPLUS_QUEUE_H
#define CPLUSPLUS_QUEUE_H

#include <iostream>
#include <deque>

namespace max {
    template <class T, class Container = std::deque<T>>
    class queue {
    public:
        void push(const T& val) {
            _c.push_back(val);
        }
        void pop() {
            _c.pop_front();
        }
        T& top() {
            return _c.front();
        }
        T& back() {
            return _c.back();
        }
        bool empty() {
            return _c.empty();
        }
        size_t size() {
            return _c.size();
        }
    private:
        Container _c;
    };
}

#endif //CPLUSPLUS_QUEUE_H
