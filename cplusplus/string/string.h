

#ifndef CPLUSPLUS_STRING_H
#define CPLUSPLUS_STRING_H

namespace max {
    class string {
    public:
        typedef char* iterator;

        iterator begin() {
            return _str;
        }
        iterator end() {
            return _str + _size;
        }

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

        const char& operator[](size_t pos) const {
            assert(pos < _size);
            return _str[pos];
        }

        size_t size() const {
            return _size;
        }
        size_t capacity() const {
            return _capacity;
        }

        void reserve(size_t n = 0) {
            char* tmp = new char[n + 1];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;
            _capacity = n;
        }

        void push_back(char ch) {
            if (_size == _capacity) {
                reserve(_capacity == 0 ? 2 : 2 * _capacity);
            }
            _str[_size] = ch;
            _size++;
            _str[_size] = '\0';
        }

        string& append(const char* str) {
            size_t len = strlen(str);
            if (_size + len > _capacity) {
                reserve(_size + len);
            }
            strcpy(_str + _size, str);
            _size += len;
            return *this;
        }

        string& operator+=(const char* str) {
            (*this).append(str);
            return *this;
        }

        string& operator+=(char ch) {
            (*this).push_back(ch);
            return *this;
        }

        string& insert(size_t pos, char ch) {
            assert(pos <= _size);
            if (_size == _capacity) {
                reserve(_capacity == 0 ? 2 : 2 * _capacity);
            }
            size_t end = _size + 1;
            while (end != pos) {
                _str[end] = _str[end - 1];
                --end;
            }
            _str[pos] = ch;
            _size++;
            _str[_size] = '\0';
            return *this;
        }
        string& insert(size_t pos, const char* str) {
            assert(pos <= _size);
            size_t len = strlen(str);
            if (_size + len > _capacity) {
                reserve(_size + len);
            }
            size_t end = _size + 1;
            while (end != pos) {
                _str[end + len - 1] = _str[end - 1];
                --end;
            }
            for (size_t i = 0; i < len; i++) {
                _str[pos + i] = str[i];
            }
            _size += len;
            return *this;
        }
        string& erase(size_t pos, size_t len = npos) {
            assert(pos < _size);
            if (len >= _size) {
                _str[pos] = '\0';
                _size = pos;
            }
            else {
                size_t end = pos + len;
                while (end <= _size) {
                    _str[end - len] = _str[end];
                    ++end;
                }
                _size -= len;
            }
            return *this;
        }
        bool operator==(const string& s) {
            return strcmp(_str, s._str) == 0;
        }
        bool operator<(const string& s) {
            return strcmp(_str, s._str) < 0;
        }
        bool operator<=(const string& s) {
            return (*this) == s || (*this) < s;
        }
        bool operator>(const string& s) {
            return !((*this) <= s);
        }
        bool operator>=(const string& s) {
            return !((*this) < s);
        }
        bool operator!=(const string& s) {
            return !((*this) == s);
        }

        void clear() {
            _str[0] = '\0';
            _size = 0;
        }


    private:
        char* _str;
        size_t _size;
        size_t _capacity;

        const static size_t npos;
    };
    const size_t string::npos = -1;

    std::ostream& operator<<(std::ostream& out, string& s) {
        out << s.c_str();
        return out;
    }
    std::istream& operator>>(std::istream& in, string& s) {
        s.clear();
        char ch;
        in.get(ch);
        while (ch != ' ' && ch != '\n') {
            s += ch;
            in.get(ch);
        }
        return in;
    }

    void test_string1() {
        string s1("hello world");
        std::cout << s1.c_str() << std::endl;
    }

    void test_string2() {
        string s1("hello world");
        string s2;
        for (size_t i = 0; i < s1.size(); i++) {
            std::cout << s1[i] << " ";
        }
        std::cout << std::endl;
        //std::cout << s2.c_str() << std::endl;

        string::iterator it = s1.begin();
        while (it != s1.end()) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;

        for (auto ch : s1) {
            std::cout << ch << " ";
        }
        std::cout << std::endl;

    }
    void test_string3() {
        string s;
        s.push_back('a');
        s.push_back('b');

        std::cout << s.c_str() << std::endl;

        s.append(" hello world");
        std::cout << s.c_str() << std::endl;
        for (size_t i = 0; i < s.size(); i++) {
            std::cout << s[i] << " ";
        }
        std::cout << std::endl;

        s.push_back('c');
        for (size_t i = 0; i < s.size(); i++) {
            std::cout << s[i] << " ";
        }
        std::cout << std::endl;

        s += " no thank you!!";
        std::cout << s.c_str() << std::endl;

        for (size_t i = 0; i < s.size(); i++) {
            std::cout << s[i] << " ";
        }
        std::cout << std::endl;
    }

    void test_string4() {
        /*string s("h");
        s.insert(0, '1');
        std::cout << s.c_str() << std::endl;
        s.insert(0, 'c');
        std::cout << s.c_str() << std::endl;
        s.insert(s.size(), 'h');
        std::cout << s.c_str() << std::endl;*/

        string s("hello world");
        std::cout << s.size() << std::endl;
        s.erase(5, 6);
        std::cout << s.c_str() << std::endl;
        std::cout << s.size() << std::endl;
        for (size_t i = 0; i < s.size(); i++) {
            std::cout << s[i] << " ";
        }
        std::cout << std::endl;

    }

    void test_string5() {
        string s1("hello c++");
        std::cout << s1 << std::endl;

        std::string s2("hello");
        std::cin >> s2;
        std::cout << s2 << std::endl;
        for (size_t i = 0; i < s2.size(); i++) {
            std::cout << s2[i] << " ";
        }
        std::cout << std::endl;

    }
    void test_string6() {
        string s1("helloy");
        string s2("helloxxxxxxxxxxxx");
        std::cout << (s1 > s2) << std::endl;
    }
}

#endif //CPLUSPLUS_STRING_H
