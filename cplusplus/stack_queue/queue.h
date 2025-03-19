#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <deque>

using std::deque;

namespace max {
    template <typename T, typename Container = deque<T>>
    class queue {
    public:
        void push(const T& val) {
            con_.push_back(val);
        }
        void pop() {
            con_.pop_front();
        }
        T& front() {
            return con_.front();
        }
        const T& front() const {
            return con_.front();
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
    void queue_test() {
        queue<int> q;
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);

        while (!q.empty()) {
            std::cout << q.front() << std::endl;
            q.pop();
        }
    }
}

#endif //QUEUE_H
