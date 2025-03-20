#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "reverse_iterator.h"


namespace max {
    template <typename T>
    struct list_node {
        T data_;
        list_node<T>* next_;
        list_node<T>* prev_;

        list_node(const T& data = T())
            : data_(data), next_(nullptr), prev_(nullptr)
        {}
    };

    template <typename T, typename Ref, typename Ptr>
    struct __list_iterator {
        typedef list_node<T> node;
        typedef __list_iterator<T, Ref, Ptr> self;
        node* node_;
        __list_iterator(node* node)
            : node_(node)
        {}
        Ref operator*() const {
            return node_->data_;
        }
        self& operator++() {
            node_ = node_->next_;
            return *this;
        }
        self operator++(int) {
            self tmp(*this);
            node_ = node_->next_;
            return tmp;
        }
        self& operator--() {
            node_ = node_->prev_;
            return *this;
        }
        self operator--(int) {
            self tmp(*this);
            node_ = node_->prev_;
            return tmp;
        }
        Ptr operator->() const {
            return &(node_->data_);
        }
        bool operator!=(const self& other) const {
            return node_ != other.node_;
        }
        bool operator==(const self& other) const {
            return node_ == other.node_;
        }
    };

    template <class T>
    class list {
        typedef list_node<T> node;
        void empty_init() {
            head_ = new node;
            head_->next_ = head_;
            head_->prev_ = head_;
            size_ = 0;
        }
    public:
        typedef __list_iterator<T, T&, T*> iterator;
        typedef __list_iterator<T, const T&, const T*> const_iterator;
        typedef ReverseIterator<iterator, T&, T*> reverse_iterator;
        typedef ReverseIterator<const_iterator, const T&, const T*> const_reverse_iterator;

        list() {
            empty_init();
        }
        list(list<T>& other) {
            empty_init();
            for (auto e : other) {
                push_back(e);
            }
        }
        list<T>& operator=(list<T> other) {
            swap(other);
            return *this;
        }
        iterator begin() {
            return iterator(head_->next_);
        }
        iterator end() {
            return iterator(head_);
        }
        const_iterator begin() const {
            return const_iterator(head_->next_);
        }
        const_iterator end() const {
            return const_iterator(head_);
        }
        reverse_iterator rbegin() {
            return reverse_iterator(end());
        }
        reverse_iterator rend() {
            return reverse_iterator(begin());
        }
        const_reverse_iterator rbegin() const {
            return const_reverse_iterator(end());
        }
        const_reverse_iterator rend() const {
            return const_reverse_iterator(begin());
        }
        void push_back(const T& data) {
            insert(end(), data);
        }
        void push_front(const T& data) {
            insert(begin(), data);
        }
        void pop_front() {
            erase(begin());
        }
        void pop_back() {
            erase(--end());
        }
        void insert(iterator pos, const T& data) {
            node* new_node = new node(data);
            node* cur = pos.node_;

            new_node->prev_ = cur->prev_;
            new_node->next_ = cur;

            new_node->prev_->next_ = new_node;
            cur->prev_ = new_node;
            size_++;
        }
        iterator erase(iterator pos) {
            node* cur = pos.node_;
            node* prev = cur->prev_;
            node* next = cur->next_;
            prev->next_ = next;
            next->prev_ = prev;
            delete cur;
            size_--;
            return iterator(next);
        }
        void swap(list<T>& other) {
            std::swap(size_, other.size_);
            std::swap(head_, other.head_);
        }
        void clear() {
            iterator cur = begin();
            while (cur != end()) {
                cur = erase(cur);
            }
        }
        ~list() {
            clear();
            delete head_;
            head_ = nullptr;
        }
    private:
        node* head_;
        size_t size_;
    };

    void test_list1() {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);
        lt.push_front(10);
        lt.push_front(20);
        lt.push_front(30);

        list<int>::iterator it = lt.begin();
        while (it != lt.end()) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;

        list<int> lt2(lt);
        for (int i : lt2) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        lt2.push_back(50);
        lt = lt2;
        for (int i : lt) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    template <typename Container>
    void print_list(const Container& c) {
        typename Container::const_iterator it = c.begin();
        while (it != c.end()) {
            std::cout << *it << " ";
            ++it;
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
        lt.push_front(10);
        lt.push_front(20);
        lt.push_front(30);

        for (int i : lt) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        lt.pop_back();
        for (int i : lt) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        lt.pop_front();
        for (int i : lt) {
            std::cout << i << " ";
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
        lt.push_front(10);
        lt.push_front(20);
        lt.push_front(30);

        print_list(lt);

    }
    void test_list4() {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);
        lt.push_front(10);
        lt.push_front(20);
        lt.push_front(30);

        list<int>::reverse_iterator it = lt.rbegin();
        while (it != lt.rend()) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
    }
}


#endif //LIST_H
