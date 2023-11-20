
#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <iostream>
#include <cstring>
#include <assert.h>
#include <algorithm>

using std::cout;
using std::endl;

namespace mystl {
    template<class T>
    class vector {
    public:
        typedef T* iterator;
        typedef T* const_iterator;

        vector()
            :_start(nullptr)
            ,_finish(nullptr)
            ,_end_of_storage(nullptr)
        {}

        ~vector() {
            delete[] _start;
            _start = _finish = _end_of_storage = nullptr;
        }

        void resize(size_t n, T data = T()) {
            if(n < size()) {
                _finish = _start + n;
            } else {
                if(n > capacity()) {
                    reserve(n);
                }
                while(_finish != _start + n) {
                    *_finish = data;
                    ++_finish;
                }
            }

        }

        void reserve(size_t n) {
            size_t sz = size();
            if(n > capacity()) {
                T* tmp = new T[n];
                if(_start) {
                    memcpy(tmp, _start, sizeof(T) * sz);
                    delete[] _start;
                }

                _start = tmp;
                _finish = _start + sz;
                _end_of_storage = _start + n;
            }
        }
        void push_back(const T& data) {
            if(_finish == _end_of_storage) {
                // 扩容
                reserve(!capacity() ? 4 : 2 * capacity());
            }
            *_finish = data;
            ++_finish;
        }

        void pop_back() {
            assert(!empty());
            --_finish;
        }

        iterator insert(iterator pos, const T& data) {
            assert(pos >= _start);
            assert(pos <= _finish);


            // 判断扩容
            if(_finish == _end_of_storage) {
                // 防止迭代器失效
                size_t n = pos - _start;
                // 扩容
                reserve(!capacity() ? 4 : 2 * capacity());
                pos = _start + n;
            }

            // 移动数据
            iterator end = _finish - 1;
            while(end >= pos) {
                *(end + 1) = *end;
                --end;
            }
            *pos = data;
            ++_finish;
        }

        iterator erase(iterator pos) {
            assert(pos >= _start);
            assert(pos < _finish);

            iterator start = pos + 1;
            while(start != _finish) {
                *(start - 1) = *start;
                ++start;
            }
            --_finish;

            return pos;
        }

        bool empty() {
            return _finish == _start;
        }

        T& operator[](size_t pos) {
            assert(pos < size());
            return _start[pos];
        }

        iterator begin() {
            return _start;
        }
        const_iterator begin() const {
            return _start;
        }

        iterator end() {
            return _finish;
        }
        const_iterator end() const {
            return _finish;
        }

        size_t size() const {
            return _finish - _start;
        }
        size_t capacity() const {
            return _end_of_storage - _start;
        }


    private:
        iterator _start;
        iterator _finish;
        iterator _end_of_storage;
    };

    void testVector1() {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(5);

        for(size_t i = 0; i < v1.size(); ++i) {
            cout << v1[i] << " ";
        }
        cout << endl;

        vector<int>::iterator it = v1.begin();
        while(it != v1.end()) {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
        for(auto n : v1) {
            cout << n << " ";
        }
        cout << endl;
    }

    void fun(const vector<int>& v) {
        vector<int>::iterator it = v.begin();
        while(it != v.end()) {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }
    void testVector2() {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(5);

        for(auto n : v1) {
            cout << n << " ";
        }
        cout << endl;

        v1.pop_back();
        v1.pop_back();

        for(auto n : v1) {
            cout << n << " ";
        }
        cout << endl;

        //fun(v1);
    }

    void testVector3() {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        //v1.push_back(5);

        // 造成迭代器失效
        auto pos = std::find(v1.begin(), v1.end(), 2);
        v1.insert(pos, 30);

        for(auto n : v1) {
            cout << n << " ";
        }
        cout << endl;
    }
    void testVector4() {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);

        auto pos = std::find(v1.begin(), v1.end(), 2);
        v1.erase(pos);

        (*pos)++;

        for(auto n : v1) {
            cout << n << " ";
        }
        cout << endl;
    }

}


#endif //VECTOR_VECTOR_H
