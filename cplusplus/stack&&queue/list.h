
#ifndef CPLUSPLUS_LIST_H
#define CPLUSPLUS_LIST_H

#include <iostream>
#include <string>
#include <vector>
#include "reverse_iterator.h"

namespace max {
    template<class T>
    struct list_node {
        T _val;
        list_node<T> *_prev;
        list_node<T> *_next;

        list_node(const T &val = T())
                : _val(val), _prev(nullptr), _next(nullptr) {}
    };

    template<class T, class Ref, class Ptr>
    struct __list_iterator {
        typedef list_node<T> Node;
        typedef __list_iterator<T, Ref, Ptr> self;

        Node *_node;

        __list_iterator(Node *node)
                : _node(node) {}

        self &operator++() {
            _node = _node->_next;
            return *this;
        }

        self operator++(int) {
            self tmp(*this);
            _node = _node->_next;
            return tmp;
        }

        self &operator--() {
            _node = _node->_prev;
            return *this;
        }

        self operator--(int) {
            self tmp(*this);
            _node = _node->_prev;
            return tmp;
        }

        Ref operator*() {
            return _node->_val;
        }

        Ptr operator->() {
            return &_node->_val;
        }

        bool operator!=(const self &it) {
            return _node != it._node;
        }

        bool operator==(const self& it) {
            return _node == it._node;
        }
    };

    template<class T>
    class list {
        typedef list_node<T> Node;

    public:
        typedef __list_iterator<T, T&, T*> iterator;
        typedef __list_iterator<T, const T&, const T*> const_iterator;
        typedef Reverse_Iterator<iterator, T&, T*> reverse_iterator;
        typedef Reverse_Iterator<const_iterator, const T&, const T*> const_reverse_iterator;

        list() {
            empty_init();
        }

        list(const list<T> &lt) {
            empty_init();
            for (auto e: lt) {
                push_back(e);
            }
        }

        void swap(list<T> &lt) {
            std::swap(_head, lt._head);
            std::swap(_size, lt._size);
        }

        list<T> &operator=(list<T> tmp) {
            swap(tmp);
            return *this;
        }

        void empty_init() {
            _head = new Node;
            _head->_prev = _head;
            _head->_next = _head;
        }

        void push_back(const T &val) {
//            Node *newNode = new Node(val);
//            Node *prev = _head->_prev;
//            prev->_next = newNode;
//            newNode->_prev = prev;
//            newNode->_next = _head;
//            _head->_prev = newNode;
//            ++_size;
            insert(end(), val);
        }

        void push_front(const T &val = T()) {
            insert(begin(), val);
        }

        void pop_front() {
            erase(begin());
        }

        void pop_back() {
            erase(--end());
        }

        iterator insert(iterator pos, const T &val = T()) {
            Node *newNode = new Node(val);
            Node *cur = pos._node;
            Node *prev = cur->_prev;
            prev->_next = newNode;
            newNode->_prev = prev;
            newNode->_next = cur;
            cur->_prev = newNode;
            ++_size;
            return iterator(newNode);
        }

        iterator erase(iterator pos) {
            Node *cur = pos._node;
            Node *next = cur->_next;
            Node *prev = cur->_prev;
            delete cur;
            prev->_next = next;
            next->_prev = prev;
            --_size;
            return iterator(next);
        }

        iterator begin() {
            return _head->_next;
        }

        reverse_iterator rbegin() {
            return end();
        }

        iterator end() {
            return _head;
        }

        reverse_iterator rend() {
            return begin();
        }

        const_iterator begin() const{
            return _head->_next;
        }

        const_reverse_iterator rbegin() const {
            return end();
        }

        const_iterator end() const{
            return _head;
        }

        const_reverse_iterator rend() const {
            return begin();
        }

        ~list() {
            clear();
            delete _head;
            _head = nullptr;
        }

        void clear() {
            iterator it = begin();
            while (it != end()) {
                it = erase(it);
            }
        }

        size_t size() {
            return _size;
        }

    private:
        Node *_head;
        size_t _size;
    };

//    template <class T>
    template <class Container>
    void print_list(const Container& lt) {
        typename Container::const_iterator it = lt.begin();
        while(it != lt.end()) {
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;
    }

    void test_list1() {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);

        list<int>::iterator it = lt.begin();
        while (it != lt.end()) {
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;

        for (auto e: lt) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }

    void test_list2() {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);
        for (auto e: lt) {
            std::cout << e << " ";
        }
        std::cout << std::endl;

        lt.insert(++lt.begin(), 90);
        for (auto e: lt) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        lt.pop_back();
        for (auto e: lt) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        lt.push_front(100);
        for (auto e: lt) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        lt.pop_front();
        for (auto e: lt) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
    void test_list3() {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);
        print_list(lt);

        std::vector<std::string> v;
        v.push_back("abc");
        v.push_back("def");
        print_list(v);

    }
}


#endif
