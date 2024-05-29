

#ifndef CPLUSPLUS_STRING_H
#define CPLUSPLUS_STRING_H

#include <iostream>
#include <string>
#include <cstring>
#include <cassert>

namespace max {
    class string {
    public:
        string(const char* str = "")
        :_size(strlen(str))
        ,_capacity(_size)
        {
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }
        ~string() {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }
        const char* c_str() const {
            return _str;
        }

        char& operator[](size_t pos) {
            assert(pos < _size);
            return _str[pos];
        }


    private:
        char* _str;
        size_t _size;
        size_t _capacity;
    };

    void test_string1() {
        string s1("hello world");
        std::cout << s1.c_str() << std::endl;
    }
}

#endif //CPLUSPLUS_STRING_H
