

#ifndef STRING_STRING_H
#define STRING_STRING_H

#include <iostream>
#include <string.h>
using namespace std;

namespace mystl {
    class string {
    public:
        // 构造函数
        string(const char* s = "")
            :_size(strlen(s))
        {
            _capacity = _size;
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

        string& operator=(const string& s) {
            char* tmp = new char[s._capacity + 1];
            strcpy(tmp, s._str);

            delete[] _str;
            _str = tmp;
            _size = s._size;
            _capacity = s._capacity;
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
            cout << s2.c_str() << endl;
            cout << s3.c_str() << endl;
        }
    private:
        char* _str;
        int _size;
        int _capacity;
    };
}



#endif //STRING_STRING_H
