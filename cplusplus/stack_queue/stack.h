#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <deque>
using std::deque;

namespace max {
    template <typename T, typename Container = deque<T>>
    class stack {
    public:
        void push(const T& val) {
            con_.push_back(val);
        }
        void pop() {
            con_.pop_back();
        }
        T& top() {
            return con_.back();
        }
        const T& top() const {
            return con_.back();
        }
        size_t size() const {
            return con_.size();
        }
        bool empty() const {
            return con_.empty();
        }
    private:
        Container con_;
    };

    void stack_test() {
        stack<int> s;
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        s.push(60);
        while (!s.empty()) {
            std::cout << s.top() << std::endl;
            s.pop();
        }
    }
}

#endif //STACK_H
