
#ifndef CPLUSPLUS_VECTOR_H
#define CPLUSPLUS_VECTOR_H

#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>

namespace max {
    template<class T>
    class vector {
    public:
        typedef T *iterator;
        typedef const T *const_iterator;

        vector() {}

        ~vector() {
            delete[] _first;
            _first = _finish = _end_of_storage = nullptr;
        }

        vector(const vector<T> &v) {
            reserve(v.capacity());
            for (auto e: v) {
                push_back(e);
            }
        }

        template <class InputIterator>
        vector(InputIterator first, InputIterator last) {
            while (first != last) {
                push_back(*first);
                ++first;
            }
        }

        vector(size_t n, const T& val = T()) {
            reserve(n);
            for (size_t i = 0; i < n; i++)
            {
                push_back(val);
            }
        }

        vector(int n, const T& val = T()) {
            reserve(n);
            for (int i = 0; i < n; i++)
            {
                push_back(val);
            }
        }

        void swap(vector<T> &v) {
            std::swap(_first, v._first);
            std::swap(_finish, v._finish);
            std::swap(_end_of_storage, v._end_of_storage);
        }

        vector<T> &operator=(vector<T> tmp) {
            swap(tmp);
            return *this;
        }

        void reserve(size_t n) {
            // 当n大于容量时才需要扩容
            if (n > capacity()) {
                size_t sz = size();
                T *tmp = new T[n];
                if (_first) {
                    for (size_t i = 0; i < sz; ++i) {
                        tmp[i] = _first[i];
                    }
                    delete[] _first;
                }
                _first = tmp;
                _finish = _first + sz;
                _end_of_storage = _first + n;
            }
        }

        void push_back(const T &val) {
//            if (_finish == _end_of_storage) {
//                // 扩容
//                reserve(capacity() == 0 ? 5 : 2 * capacity());
//            }
//            *_finish = val;
//            _finish++;
            insert(_finish, val);
        }

        void pop_back() {
            assert(_finish > _first);
            --_finish;
        }

        T &operator[](size_t pos) {
            assert(pos < size());
            return *(_first + pos);
        }

        const T &operator[](size_t pos) const {
            assert(pos < size());
            return *(_first + pos);
        }

        iterator find(iterator first, iterator finish, const T &val) {
            while (first != finish) {
                if (*first == val) {
                    return first;
                }
                ++first;
            }
            return nullptr;
        }

        iterator insert(iterator pos, const T &val) {
            assert(pos >= _first);
            assert(pos <= _finish);
            if (_finish == _end_of_storage) {
                // 解决迭代器失效问题
                size_t n = pos - _first;
                reserve(capacity() == 0 ? 5 : 2 * capacity());
                pos = _first + n;
            }
            iterator end = _finish;
            while (end >= pos) {
                *end = *(end - 1);
                --end;
            }
            *pos = val;
            ++_finish;
            return pos;
        }

        iterator erase(iterator pos) {
            assert(pos >= _first);
            assert(pos < _finish);
            iterator end = pos + 1;
            while (end < _finish) {
                *(end - 1) = *end;
                ++end;
            }
            --_finish;
            return pos;
        }

        size_t size() const {
            return _finish - _first;
        }

        size_t capacity() const {
            return _end_of_storage - _first;
        }

        iterator begin() {
            return _first;
        }

        iterator end() {
            return _finish;
        }

        const_iterator begin() const {
            return _first;
        }

        const_iterator end() const {
            return _finish;
        }

    private:
        iterator _first = nullptr;
        iterator _finish = nullptr;
        iterator _end_of_storage = nullptr;
    };

    void test_vector1() {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        v.push_back(6);

        for (size_t i = 0; i < v.size(); ++i) {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;

        vector<int>::iterator it = v.begin();
        while (it != v.end()) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;

        for (auto i: v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        vector<std::string> v2;
        v2.push_back("hello");
        v2.push_back("world");
        v2.push_back("nice ");
        v2.push_back("to ");
        v2.push_back("meet ");
        v2.push_back("you!");

        for (auto i: v2) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    void test_vector2() {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        v.push_back(6);
        for (auto i: v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        v.pop_back();
        for (auto i: v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        v.pop_back();
        for (auto i: v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        v.pop_back();
        for (auto i: v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        v.pop_back();
        for (auto i: v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        v.pop_back();
        for (auto i: v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        v.pop_back();
        for (auto i: v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        v.pop_back();
        for (auto i: v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    void test_vector3() {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        for (auto i: v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        auto pos = v.find(v.begin(), v.end(), 3);
        v.insert(pos, 30);
        for (auto i: v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        pos = v.find(v.begin(), v.end(), 1);
        v.insert(pos, 10);
        for (auto i: v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    void test_vector4() {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(2);
        v.push_back(4);
        v.push_back(7);
        v.push_back(5);
        v.push_back(8);

        for (auto i: v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        auto it = v.begin();
        while (it != v.end()) {
            if (*it % 2 == 0) {
                v.erase(it);
            } else {
                ++it;
            }
        }
        for (auto i: v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    void test_vector5() {
        vector<std::string> v1;
        v1.push_back("hello");
        v1.push_back("world");
        v1.push_back("nice");
        v1.push_back("to");
        v1.push_back("meet");
        v1.push_back("you!");

        vector<std::string> v2(v1);
        for (auto i: v2) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        vector<std::string> v3;
        v3.push_back("no");
        v3.push_back("thank you");

        v1 = v3;
        for (auto i: v1) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    void test_vector6() {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(5);
        v1.push_back(6);

        vector<int> v2(v1.begin() + 1, v1.end() - 1);
        for (auto i : v2) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        vector<int> v3(10, 1);
        for (auto i : v3) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}

#endif //CPLUSPLUS_VECTOR_H
