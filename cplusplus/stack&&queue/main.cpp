#include "stack.h"
#include "queue.h"
#include "priority_queue.h"
#include <vector>
#include <list>
#include <queue>

#include "list.h"
#include "vector.h"


void test_stack1() {
    max::stack<int, std::vector<int>> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    std::cout << st.size() << std::endl;

    while(!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;

}

void test_queue() {
    max::queue<int, std::list<int>> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    std::cout << q.back() << std::endl;

    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << std::endl;

}

void test_priority_queue1() {
    std::priority_queue<int> pq;
    pq.push(3);
    pq.push(9);
    pq.push(6);
    pq.push(2);
    pq.push(1);
    pq.push(8);

    std::cout << pq.top() << std::endl;

    while (!pq.empty()) {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }
}
void test_priority_queue2() {
    max::priority_queue<int, std::vector<int>, Greater<int>> pq;
    pq.push(3);
    pq.push(9);
    pq.push(6);
    pq.push(2);
    pq.push(1);
    pq.push(8);

    while (!pq.empty()) {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }
}


void func(const max::list<int>& lt) {
    auto it = lt.rbegin();
    while (it != lt.rend()) {
        std::cout << *it << " ";
        ++it;
    }
}

void test_list1() {
    max::list<int> ls;

    ls.push_back(1);
    ls.push_back(2);
    ls.push_back(3);
    ls.push_back(4);
    ls.push_back(5);

    max::list<int>::reverse_iterator it = ls.rbegin();
    while (it != ls.rend()) {
        std::cout << *it << " ";
        ++it;
    }

    func(ls);

}

void func2(const max::vector<int>& v) {
    auto it = v.rbegin();
    while (it != v.rend()) {
        std::cout << *it << " ";
        ++it;
    }
}

void test_vector1() {
    max::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    max::vector<int>::reverse_iterator it = v.rbegin();
    while (it != v.rend()) {
        std::cout << *it << " ";
        ++it;
    }

    func2(v);
}



int main()
{
    //test_stack1();
    //test_queue();

    //test_priority_queue2();
    test_list1();

    //test_vector1();
    return 0;
}
