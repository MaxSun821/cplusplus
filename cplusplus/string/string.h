#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cassert>
#include <cstring>

namespace max {

class string {
    typedef char* iterator;
    typedef const char* const_iterator;
public:
    string(const char* str = "");
    string(const string& str);
    string& operator=(string str);
    ~string();

    void swap(string& str);
    const char* c_str() const;

    void reserve(size_t capacity);
    void resize(size_t count, char c = '\0');

    void push_back(char c);
    string& append(const char* str);
    string& operator+=(const char* str);
    string& operator+=(char c);

    size_t size() const;
    size_t capacity() const;

    char& operator[](size_t index);

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    void insert(size_t pos, size_t count, char c);
    void insert(size_t pos, const char* str);
    void erase(size_t pos, size_t n = npos);

    bool operator<(const string& str) const;
    bool operator==(const string& str) const;
    bool operator!=(const string& str) const;
    bool operator>(const string& str) const;
    bool operator<=(const string& str) const;
    bool operator>=(const string& str) const;

    size_t find(char c, size_t pos = 0) const;
    size_t find(const char* str, size_t pos = 0) const;

    string substr(size_t pos = 0, size_t count = npos);

    void clear();

private:
    char* str_;
    size_t size_;
    size_t capacity_;
public:
    const static size_t npos = -1;
};
    std::ostream& operator<<(std::ostream& os, const string& str);
    std::istream& operator>>(std::istream& is, string& str);
    void test_string1();
    void test_string2();
    void test_string3();
    void test_string4();
    void test_string5();
    void test_string6();
} // max

#endif //STRING_H
