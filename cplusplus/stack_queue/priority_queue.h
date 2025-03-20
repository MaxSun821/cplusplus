#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <vector>

template <typename T>
struct Less {
    bool operator()(const T& lhs, const T& rhs) const {
        return lhs < rhs;
    }
};
template <typename T>
struct Greater {
    bool operator()(const T& lhs, const T& rhs) const {
        return lhs > rhs;
    }
};

namespace max {
    template <typename T, typename Container = std::vector<T>, typename Compare = Less<T>>
    class priority_queue {
        void adjust_up(size_t child) {
            size_t parent = (child - 1) / 2;
            Compare comp;
            while (child > 0) {
                if (comp(con_[parent], con_[child])) {
                    std::swap(con_[child], con_[parent]);
                }
                else {
                    break;
                }
                child = parent;
                parent = (child - 1) / 2;
            }
        }
        void adjust_down(size_t parent) {
            size_t child = (parent * 2) + 1;
            Compare comp;
            while (child < size()) {
                if (child + 1 < size() && comp(con_[child], con_[child + 1])) {
                    child++;
                }
                if (comp(con_[parent], con_[child])) {
                    std::swap(con_[child], con_[parent]);
                }
                else {
                    break;
                }
                parent = child;
                child = (parent * 2) + 1;
            }
        }
    public:
        void push(const T& val) {
            con_.push_back(val);
            adjust_up(size() - 1); // 传入最后一个结点的下标
        }
        void pop() {
            std::swap(con_[0], con_[size() - 1]);
            con_.pop_back();
            adjust_down(0);
        }
        const T& top() const {
            return con_[0];
        }
        bool empty() {
            return con_.empty();
        }
        size_t size() {
            return con_.size();
        }
    private:
        Container con_;
    };
    void priority_queue_test() {
        priority_queue<int, std::vector<int>, Greater<int>> pq;
        pq.push(7);
        pq.push(9);
        pq.push(4);
        pq.push(2);
        pq.push(3);
        pq.push(5);
        pq.push(8);

        while (!pq.empty()) {
            std::cout << pq.top() << " ";
            pq.pop();
        }
        std::cout << std::endl;
    }
}

#endif //PRIORITY_QUEUE_H
