
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
        typedef T* iterator;
        typedef const T* const_iterator;

        vector()
        :_first(nullptr)
        ,_finish(nullptr)
        ,_end_of_storage(nullptr)
        {}
        ~vector() {
            delete[] _first;
            _first = _finish = _end_of_storage = nullptr;
        }
        void reserve(size_t n) {
            // 当n大于容量时才需要扩容
            if(n > capacity()) {
                T* tmp = new T[n];
                memcpy(tmp, _first, size() * sizeof(T));
                delete[] _first;
                _first = tmp;
                _end_of_storage = _first + n;
            }
        }
        void push_back(const T& val) {
            size_t sz = size();
            if(_finish == _end_of_storage) {
                // 扩容
                size_t cap = capacity() == 0 ? 5 : 2 * capacity();
                reserve(cap);
            }
            _finish = _first + sz;
            *_finish = val;
            _finish++;
        }
        void pop_back() {
            assert(_finish > _first);
            --_finish;
        }
        T& operator[](size_t pos) {
            assert(pos < size());
            return *(_first + pos);
        }
        const T& operator[](size_t pos) const {
            assert(pos < size());
            return *(_first + pos);
        }
        iterator find(iterator first, iterator finish, const T& val) {
            while(first != finish) {
                if(*first == val) {
                    return first;
                }
                ++first;
            }
            return nullptr;
        }
        void insert(iterator pos, const T& val) {
            assert(pos <= _finish);
            if(_finish == _end_of_storage) {
                reserve(2 * capacity());
            }
            iterator end = _finish;
            while(end >= pos) {
                *(end + 1) = *end;
                --end;
            }
            *pos = val;
            ++_finish;
        }
        size_t size() {
            return _finish - _first;
        }
        size_t capacity() {
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
        iterator _first;
        iterator _finish;
        iterator _end_of_storage;
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
        while(it != v.end()) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;

        for(auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        vector<std::string> v2;
        v2.push_back("hello");
        v2.push_back("world");
        for(auto i : v2) {
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
        for(auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        v.pop_back();
        for(auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        v.pop_back();
        for(auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        v.pop_back();
        for(auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        v.pop_back();
        for(auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        v.pop_back();
        for(auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        v.pop_back();
        for(auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        v.pop_back();
        for(auto i : v) {
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
        v.push_back(5);
        v.push_back(6);
        for(auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        auto pos = v.find(v.begin(), v.end(), 3);
        v.insert(pos, 30);
        for(auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        pos = v.find(v.begin(), v.end(), 1);
        v.insert(pos, 10);
        for(auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}

#endif //CPLUSPLUS_VECTOR_H
