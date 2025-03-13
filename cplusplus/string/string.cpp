#include "string.h"

namespace max {
    string::string(const char* str)
        : size_(strlen(str)), capacity_(size_) {
        str_ = new char[capacity_ + 1];
        strcpy(str_, str);
    }
    string::string(const string& str)
        : size_(str.size_), capacity_(str.capacity_) {
        str_ = new char[capacity_ + 1];
        strcpy(str_, str.c_str());
    }
    string::~string() {
        delete[] str_;
        size_ = capacity_ = 0;
    }

    const char* string::c_str() const {
        return str_;
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
            size_t begin = size_;
            while (begin < count) {
                str_[begin++] = c;
            }
            str_[begin] = '\0';
            size_ = count;
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
        if (n > size_) {
            str_[pos] = '\0';
            return;
        }
        size_t end = pos + n;
        while (end <= size_) {
            str_[pos] = str_[end];
            end++;
            pos++;
        }
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
        return -1;
    }

    std::ostream& operator<<(std::ostream& os, const string& str) {
        os << str.c_str();
        return os;
    }
    std::istream& operator>>(std::istream& is, string& str) {
        str.clear();
        char ch;
        is.get(ch);
        str += ch;
        while (ch != ' ' && ch != '\n') {
            is.get(ch);
            str += ch;
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
        string s = "hello";
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
}