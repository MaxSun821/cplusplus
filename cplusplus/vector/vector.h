#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cassert>
#include <algorithm>
#include <string>

#include "reverse_iterator.h"

namespace max {
    template<typename T>
    class vector {
    public:
        typedef T *iterator;
        typedef const T *const_iterator;
        typedef ReverseIterator<iterator, T&, T*> reverse_iterator;
        typedef ReverseIterator<const_iterator, const T&, const T*> const_reverse_iterator;

        vector() {}

        vector(size_t count, const T &val = T()) {
            reserve(count);
            for (size_t i = 0; i < count; i++) {
                push_back(val);
            }
        }
        vector(int count, const T &val = T()) {
            reserve(count);
            for (size_t i = 0; i < count; i++) {
                push_back(val);
            }
        }

        template<typename  InputIterator>
        vector(InputIterator first, InputIterator last) {
            while (first != last) {
                push_back(*first);
                ++first;
            }
        }

        vector(const vector<T> &other)
            : start_(nullptr), finish_(nullptr), end_of_storage_(nullptr) {
            reserve(other.capacity());
            for (auto &e: other) {
                push_back(e);
            }
        }

        ~vector() {
            if (start_ != nullptr) {
                delete[] start_;
                start_ = finish_ = end_of_storage_ = nullptr;
            }
        }

        vector<T> &operator=(vector<T> other) {
            swap(other);
            return *this;
        }

        iterator begin() {
            return start_;
        }

        iterator end() {
            return finish_;
        }

        const_iterator begin() const {
            return start_;
        }

        const_iterator end() const {
            return finish_;
        }

        reverse_iterator rbegin() {
            return reverse_iterator(end());
        }
        reverse_iterator rend() {
            return reverse_iterator(begin());
        }
        const_reverse_iterator rbegin() const {
            return const_reverse_iterator(end());
        }
        const_reverse_iterator rend() const {
            return const_reverse_iterator(begin());
        }

        size_t size() const {
            return finish_ - start_;
        }

        size_t capacity() const {
            return end_of_storage_ - start_;
        }

        void clear() {
            finish_ = start_;
        }

        bool empty() {
            return start_ == finish_;
        }

        T &operator[](size_t pos) {
            return start_[pos];
        }

        const T &operator[](size_t pos) const {
            return start_[pos];
        }

        void reserve(size_t new_capacity) {
            size_t sz = size();
            size_t cp = capacity();
            if (cp < new_capacity) {
                T *temp = new T[new_capacity];
                if (start_) {
                    for (size_t i = 0; i < sz; i++) {
                        temp[i] = start_[i];
                    }
                    delete[] start_;
                }
                start_ = temp;
                finish_ = start_ + sz;
                end_of_storage_ = start_ + new_capacity;
            }
        }

        void resize(size_t count, const T &val = T()) {
            size_t sz = size();
            if (count <= sz) {
                finish_ = start_ + count;
            } else {
                reserve(count);
                while (finish_ != start_ + count) {
                    *finish_ = val;
                    ++finish_;
                }
            }
        }

        void push_back(const T &val) {
            if (finish_ == end_of_storage_) {
                // 扩容
                size_t cp = capacity();
                size_t new_capacity = cp == 0 ? 5 : cp * 2;
                reserve(new_capacity);
            }
            *finish_ = val;
            ++finish_;
        }

        void pop_back() {
            if (empty()) {
                std::cout << "There is no element in the vector!" << std::endl;
                return;
            }
            --finish_;
        }

        iterator insert(iterator pos, const T &val) {
            assert(pos >= start_ && pos <= finish_);
            if (finish_ == end_of_storage_) {
                size_t len = pos - start_;
                size_t cp = capacity();
                size_t new_capacity = cp == 0 ? 5 : cp * 2;
                reserve(new_capacity);
                pos = start_ + len;
            }
            iterator end = finish_ - 1;
            while (end >= pos) {
                *(end + 1) = *end;
                --end;
            }
            *pos = val;
            ++finish_;
            return pos;
        }

        iterator erase(iterator pos) {
            assert(pos >= start_ && pos < finish_);
            if (empty()) {
                std::cout << "There is no element in the vector!" << std::endl;
                return nullptr;
            }
            iterator begin = pos;
            while (begin != finish_ - 1) {
                *begin = *(begin + 1);
                ++begin;
            }
            --finish_;
            return pos;
        }

        void swap(vector<T> &other) {
            std::swap(start_, other.start_);
            std::swap(finish_, other.finish_);
            std::swap(end_of_storage_, other.end_of_storage_);
        }

        bool operator==(const vector &other) const {
            if (size() != other.size()) {
                return false;
            }
            for (size_t i = 0; i < size(); ++i) {
                if (start_[i] != other[i]) {
                    return false;
                }
            }
            return true;
        }

        bool operator<(const vector &other) const {
            if (size() > other.size()) {
                return false;
            }
            for (size_t i = 0; i < size(); ++i) {
                if (start_[i] > other[i]) {
                    return false;
                }
            }
            return true;
        }

        bool operator<=(const vector &other) const {
            return (*this < other || *this == other);
        }

        bool operator>(const vector &other) const {
            return !(*this <= other);
        }

        bool operator>=(const vector &other) const {
            return !(*this < other);
        }

        bool operator!=(const vector &other) const {
            return !(*this == other);
        }

    private:
        iterator start_ = nullptr;
        iterator finish_ = nullptr;
        iterator end_of_storage_ = nullptr;
    };

    void vector_test1() {
        vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        vec.push_back(6);
        vec.push_back(7);

        for (size_t i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        vector<int>::iterator it = vec.begin();
        while (it != vec.end()) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;

        for (auto &e: vec) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }

    void vector_test2() {
        vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        vec.push_back(6);
        vec.push_back(7);

        for (auto &e: vec) {
            std::cout << e << " ";
        }
        std::cout << std::endl;

        vec.pop_back();
        vec.pop_back();
        vec.pop_back();
        for (auto &e: vec) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }

    void vector_test3() {
        vector<int> v;
        v.push_back(1);
        v.push_back(1);
        v.push_back(1);
        v.push_back(1);
        v.push_back(1);
        for (auto &v1: v) {
            std::cout << v1 << " ";
        }
        std::cout << std::endl;
        v.insert(v.begin(), 30);
        for (auto &v1: v) {
            std::cout << v1 << " ";
        }
        std::cout << std::endl;
    }

    void vector_test4() {
        vector<int> vec(4);
        for (auto &e: vec) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        std::cout << vec.size() << std::endl;
        std::cout << vec.capacity() << std::endl;
    }

    void vector_test5() {
        vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        vec.push_back(6);
        vec.push_back(7);

        vector<int> v2;
        v2.swap(vec);
        for (auto &e: v2) {
            std::cout << e << " ";
        }
        std::cout << std::endl;

        vector<int> v3;
        v3 = v2;
        for (auto &e: v3) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }

    void vector_test6() {
        vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        vec.push_back(6);
        vec.push_back(7);

        vec.resize(14, 99);
        for (auto &e: vec) {
            std::cout << e << " ";
        }
        std::cout << std::endl;

        vec.resize(2);
        for (auto &e: vec) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }

    void vector_test7() {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(2);
        v.push_back(2);
        v.push_back(2);
        v.push_back(2);
        for (auto &e: v) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        vector<int> v2;
        v2.push_back(1);

        v = v2;
        for (auto &e: v) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }

    void vector_test8() {
        vector<std::string> v1;
        v1.push_back("123");
        v1.push_back("234");
        v1.push_back("345");
        v1.push_back("456");

        vector<std::string> v2(v1.begin() + 1, v1.end());
        for (auto& e : v2) {
            std::cout << e << " ";
        }
        std::cout << std::endl;

    }
    void vector_test9() {
        vector<std::string> v1;
        v1.push_back("123");
        v1.push_back("234");
        v1.push_back("345");
        v1.push_back("456");

        vector<std::string>::reverse_iterator it = v1.rbegin();
        while (it != v1.rend()) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
    }
}

#endif //VECTOR_H
