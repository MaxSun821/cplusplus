#include "string.h"

namespace max {
    string::string(const char* str)
        : size_(strlen(str)), capacity_(size_) {
        str_ = new char[capacity_ + 1];
        strcpy(str_, str);
    }
    // string::string(const string& str)
    //     : size_(str.size_), capacity_(str.capacity_) {
    //     str_ = new char[capacity_ + 1];
    //     strcpy(str_, str.c_str());
    // }
    string::string(const string& str)
        : str_(nullptr), size_(0), capacity_(0)
    {
        string temp(str.str_);
        swap(temp);
    }
    // string& string::operator=(const string& str) {
    //     if (*this != str) {
    //         char* temp = new char[str.capacity_ + 1];
    //         strcpy(temp, str.c_str());
    //         delete[] str_;
    //         str_ = temp;
    //         capacity_ = str.capacity_;
    //         size_ = str.size_;
    //     }
    //     return *this;
    // }

    string& string::operator=(string str) {
        swap(str);
        return *this;
    }
    string::~string() {
        delete[] str_;
        size_ = capacity_ = 0;
    }

    const char* string::c_str() const {
        return str_;
    }

    void string::swap(string& str) {
        std::swap(str_, str.str_);
        std::swap(capacity_, str.capacity_);
        std::swap(size_, str.size_);
    }

    void string::reserve(size_t capacity) {
        try {
            if (capacity > capacity_) {
                char* temp = new char[capacity + 1];
                strcpy(temp, str_);
                delete[] str_;
                str_ = temp;
                capacity_ = capacity;
            }
        }
        catch (std::exception e) {
            e.what();
        }
    }
    void string::resize(size_t count, char c) {
        if (count < size_) {
            str_[count] = '\0';
            size_ = count;
        }
        else {
            reserve(count);
            while (size_ < count) {
                str_[size_++] = c;
            }
            str_[size_] = '\0';
        }
    }

    void string::push_back(char c) {
        if (size_ == capacity_) {
            size_t new_capacity = capacity_ == 0 ? 5 : capacity_ * 2;
            reserve(new_capacity);
        }
        str_[size_] = c;
        size_++;
        str_[size_] = '\0';
    }
    string& string::append(const char* str) {
        if (size_ + strlen(str) > capacity_) {
            reserve(size_ + strlen(str));
        }
        strcat(str_, str);
        size_ += strlen(str);
        return *this;
    }
    string& string::operator+=(const char* str) {
        append(str);
        return *this;
    }
    string& string::operator+=(char c) {
        push_back(c);
        return *this;
    }

    size_t string::size() const {
        return size_;
    }
    size_t string::capacity() const {
        return capacity_;
    }

    char& string::operator[](size_t index) {
        assert(index < size_);
        return str_[index];
    }

    string::iterator string::begin() {
        return str_;
    }
    string::iterator string::end() {
        return str_ + size_;
    }
    string::const_iterator string::begin() const {
        return str_;
    }
    string::const_iterator string::end() const {
        return str_ + size_;
    }

    void string::insert(size_t pos, size_t count, char c) {
        assert(pos <= size_);
        if (size_ + count > capacity_) {
            reserve(size_ + count);
        }
        size_t end = size_ + count;
        while (end > pos + count - 1) {
            str_[end] = str_[end - count];
            end--;
        }
        memset(str_ + pos, c, count);
        size_ += count;
    }
    void string::insert(size_t pos, const char* str) {
        assert(pos <= size_);
        size_t len = strlen(str);
        if (len == 0) {
            return;
        }
        if (size_ + len > capacity_) {
            reserve(size_ + len);
        }
        size_t end = size_ + len;

        while (end > pos + len - 1) {
            str_[end] = str_[end - len];
            end--;
        }
        memcpy(str_ + pos, str, len);
        size_ += len;
    }
    void string::erase(size_t pos, size_t n) {
        assert(pos < size_);
        if (pos + n > size_ || n == string::npos) {
            str_[pos] = '\0';
            size_ = pos;
            return;
        }
        size_t begin = pos + n;
        while (begin <= size_) {
            str_[begin - n] = str_[begin];
            begin++;
        }
        size_ -= n;
    }

    bool string::operator<(const string& str) const {
        return strcmp(c_str(), str.c_str()) < 0;
    }
    bool string::operator==(const string& str) const {
        return strcmp(c_str(), str.c_str()) == 0;
    }
    bool string::operator!=(const string& str) const {
        return !(*this == str);
    }
    bool string::operator>(const string& str) const {
        return !(*this <= str);
    }
    bool string::operator<=(const string& str) const {
        return (*this < str || *this == str);
    }
    bool string::operator>=(const string& str) const {
        return !(*this < str);
    }

    void string::clear() {
        str_[0] = '\0';
        size_ = 0;
    }

    size_t string::find(char c, size_t pos) const {
        for (size_t i = pos; i < size_; ++i) {
            if (str_[i] == c) {
                return i;
            }
        }
        return string::npos;
    }
    size_t string::find(const char* str, size_t pos) const {
        const char* ret = strstr(str_ + pos, str);
        if (ret) {
            return ret - str_;
        }
        return npos;
    }

    string string::substr(size_t pos, size_t count) {
        string s;
        size_t end = pos + count;
        if (count == string::npos || end > size_) {
            count = size_ - pos;
            end = size_;
        }

        s.reserve(count);
        for (size_t i = pos; i < end; ++i) {
            s += str_[i];
        }
        return s;
    }

    std::ostream& operator<<(std::ostream& os, const string& str) {
        os << str.c_str();
        return os;
    }
    std::istream& operator>>(std::istream& is, string& str) {
        str.clear();
        char buff[128];
        char ch;
        is.get(ch);
        int i = 0;
        while (ch != ' ' && ch != '\n') {
            buff[i++] = ch;
            is.get(ch);
            if (i == 127) {
                buff[i] = '\0';
                str += buff;
                i = 0;
            }
        }

        if (i != 0) {
            buff[i] = '\0';
            str += buff;
        }

        return is;
    }

    void test_string1() {
        string s;
        s.push_back('h');
        s.push_back('e');
        std::cout << s.c_str() << std::endl;
        s.append("llo world");
        std::cout << s.c_str() << std::endl;

        string s2(s);
        std::cout << s2.c_str() << std::endl;
    }

    void test_string2() {
        string s = "hello world";
        auto it = s.begin();
        while (it != s.end()) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;

        for (auto& c : s) {
            std::cout << c << " ";
        }
        std::cout << std::endl;

        s += " Goodbye!!";
        std::cout << s.c_str() << std::endl;
    }

    void test_string3() {
        string s = "hello world";
        s.insert(5, "abc");
        std::cout << s << std::endl;

        s.insert(0, 3, 'x');
        std::cout << s << std::endl;

        s.erase(3, 3);
        std::cout << s << std::endl;
        s.erase(5, 100);
        std::cout << s << std::endl;
        s.erase(2);
        std::cout << s << std::endl;

    }

    void test_string4() {
        string s;
        std::cin >> s;
        std::cout << s << std::endl;
    }

    void test_string5() {
        string s = "hello";
        s.resize(11, 'c');
        std::cout << s << std::endl;
        std::cout << s.size() << std::endl;
    }

    void test_string6() {
        string s = "https://en.cppreference.com/w/cpp/string/basic_string";
        string sub1, sub2, sub3;

        size_t ret1 = s.find(":");
        if (ret1 == string::npos) {
            std::cout << "There's no 1 string!" << std::endl;
        }
        sub1 = s.substr(0, ret1);
        size_t ret2 = s.find("/", ret1 + 3);
        if (ret2 == string::npos) {
            std::cout << "There's no 2 string!" << std::endl;
        }
        sub2 = s.substr(ret1 + 3, ret2 - (ret1 + 3));
        sub3 = s.substr(ret2 + 1);

        std::cout << sub1 << std::endl;
        std::cout << sub2 << std::endl;
        std::cout << sub3 << std::endl;
    }
}