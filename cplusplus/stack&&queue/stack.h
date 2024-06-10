

#ifndef CPLUSPLUS_STACK_H
#define CPLUSPLUS_STACK_H

#include <iostream>
#include <deque>

namespace max {
    template <class T, class Container = std::deque<T>>
    class stack {
    public:
        void push(const T& val) {
            _c.push_back(val);
        }
        void pop() {
            _c.pop_back();
        }
        T& top() {
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


#endif //CPLUSPLUS_STACK_H
