#pragma once
// #define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>
#include <cstring>

using namespace std;

namespace mystl {
	class string {
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		// 构造函数
		string(const char* str = "")
			: _size(strlen(str))
		{
			_capacity = _size == 0 ? 4 : strlen(str);
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		// 拷贝构造
		string(const string& str)
			: _size(str._size)
			, _capacity(str._capacity)
		{
			_str = new char[str._capacity + 1];
			strcpy(_str, str._str);
		}

		// 返回字符指针
		const char* c_str() const{
			return _str;
		}
		//运算符重载
		char& operator[](size_t pos) {
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const {
			assert(pos < _size);
			return _str[pos];
		}

		string& operator=(const string& str) {
			char* tmp = new char[str._capacity + 1]; // 重新开辟一块空间
			strcpy(tmp, str._str);

			delete[] _str; // 若new空间失败，也不影响原字符串
			_str = tmp;
			_size = str._size;
			_capacity = str._capacity;

			return *this;
		}

		bool operator<(const string& str) const {
			return strcmp(_str, str._str) < 0;
		}
		bool operator==(const string& str) const {
			return strcmp(_str, str._str) == 0;
		}
		bool operator<=(const string& str) const {
			return *this < str || *this == str;
		}
		bool operator>(const string& str) const {
			return !(*this <= str);
		}
		bool operator>=(const string& str) const {
			return !(*this < str);
		}
		bool operator!=(const string& str) const {
			return !(*this == str);
		}

        string& operator+=(const char ch) {
            push_back(ch);
            return *this;
        }
        string& operator+=(const char* str) {
            append(str);
            return *this;
        }
        // 扩容
		void reserve(size_t n) {
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);

			delete[] _str;
			_str = tmp;

			_capacity = n;
		}

        //resize
        void resize(size_t n) {
            if(n < _size) {
                char* tmp = new char[n + 1];
                strncpy(tmp, _str, n);

                _size = n;
                _str = tmp;
            } else {
                _size = n;
                _capacity = n;
            }
        }
        void resize(size_t n, const char ch) {
            if(n < _size) {
                char* tmp = new char[n + 1];
                strncpy(tmp, _str, n);

                _size = n;
                _str = tmp;
            } else if(n > _size) {
                char* tmp = new char[n + 1];
                strcpy(tmp, _str);

                while(_size != n) {
                    tmp[_size++] = ch;
                }
                tmp[_size] = '\0';
                _str = tmp;
                _capacity = n;
            }
        }

		void push_back(char ch) {
			if (_size + 1 > _capacity) {
				reserve(_capacity * 2);
			}

			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		void append(const char* str) {
			size_t len = strlen(str);
			if (_size + len > _capacity) {
				reserve(_size + len);
			}

			strcpy(_str + _size, str);
			_size += len;
		}

		// 迭代器
		iterator begin() {
			return _str;
		}
		iterator end() {
			return _str + _size;
		}
		const_iterator begin() const {
			return _str;
		}
		const_iterator end() const {
			return _str + _size;
		}

		size_t size() const {
			return _size;
		}

        // 任意位置插入
        string& insert(size_t pos, const char ch) {
            assert(pos <= _size);
            reserve( 2 * _capacity);
            size_t end = _size;
            while(end != pos) {
                _str[end] = _str[end - 1];
                --end;
            }
            _str[pos] = ch;
            ++_size;
            return *this;
        }
        string& insert(size_t pos, const char* str) {
            assert(pos <= _size);
            size_t len = strlen(str);

            reserve(_size + len);

            char* tmp = new char[_capacity + 1];
            strncpy(tmp, _str, pos);
            strcpy(tmp + pos, str);
            strcpy(tmp + pos + len, _str + pos);
            _size += len;

            _str = tmp;

            return *this;
        }
        string& erase(size_t pos = 0, size_t len = npos) {

        }


		// 析构函数
		~string() {
			delete[] _str;
			_size = _capacity = 0;
		}


	private:
		char* _str;
		size_t _size;
		size_t _capacity;

        static const size_t npos;
	};

    const size_t string::npos = -1;

	void testString() {
		string s1;
		string s2("hello world");

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		s2[0]++;
		cout << s2.c_str() << endl;
	}

	void testString2() {
		string s1("hello world");
		string s2(s1);

		cout << s1.c_str() << endl;
		s2[0]++;
		cout << s2.c_str() << endl;

		string s3;
		string s4 = "";
		s3 = s2;
		cout << s3.c_str() << endl;
		s4 = s3;
		cout << s4.c_str() << endl;
	}

	void testString3() {
		string s1("hello world");
		
		string::iterator it = s1.begin();
		while (it != s1.end()) {
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto ch : s1) {
			cout << ch << " ";
		}
		cout << endl;
	}

	void testString4() {
		string s1 = "hello";

		s1.append(" world");

		cout << s1.c_str() << endl;

		string s2;

		s2.push_back('n');
		s2.push_back('o');
		cout << s2.c_str() << endl;
	}
    void testString5() {
        string s1 = "hello";

        s1 += " world";

        cout << s1.c_str() << endl;

        string s2;

        s2 += 'n';
        s2 += 'o';
        cout << s2.c_str() << endl;
    }
    void testString6() {
        string s("I like to code in C");
        cout << s.c_str() << endl;

        size_t sz = s.size();

        s.resize(sz + 2, '+');
        cout << s.c_str() << endl;

        s.resize(14);
        cout << s.c_str() << endl;
    }
    void testString7() {
        string s1 = "hello";

        s1.insert(0, " world");
        //s1.insert(6, 'w');
        cout << s1.c_str() << endl;
    }

}