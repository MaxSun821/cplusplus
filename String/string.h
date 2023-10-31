

#ifndef STRING_STRING_H
#define STRING_STRING_H

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

namespace mystl {
    class string {
    public:
        // 构造函数
        string(const char* s = "")
            :_size(strlen(s))
        {
            
            _capacity = _size == 0 ? 4 : _size;
            _str = new char[_capacity + 1];
            strcpy(_str, s);
        }

        // 拷贝构造函数
        string(const string& s)
            : _size(s._size)
            , _capacity(s._capacity)
        {
            _str = new char[s._capacity + 1];
            strcpy(_str, s._str);
        }

        const char* c_str() const {
            return _str;
        }

        char& operator[](int pos) {
            assert(pos < _size);
            return _str[pos];
        }

        string& operator=(const string& s) {
            char* tmp = new char[s._capacity + 1];
            strcpy(tmp, s._str);

            delete[] _str;
            _str = tmp;
            _size = s._size;
            _capacity = s._capacity;
        }

        // 返回字符串长度
        size_t size() const {
            return _size;
        }

        // 返回字符串容量
        size_t capacity() const {
            return _capacity;
        }

        // 扩容
        void reserve(size_t n = 0) {
            if (n <= _capacity) {
                return;
            }
            char* tmp = new char[n + 1];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;
            _capacity = n;
        }

        // 析构函数
        ~string() {
            delete[] _str;
            _size = _capacity = 0;
        }

        void stringTest() {
            string s1 = "hello world";
            string s2;
            string s3(s1);

            cout << s1.c_str() << endl;
            // cout << s1[11] << endl;
            cout << s2.c_str() << endl;
            cout << s3.c_str() << endl;

            cout << s1.size() << endl;
        }
    private:
        char* _str;
        size_t _size;
        size_t _capacity;
    };
}



#endif //STRING_STRING_H
