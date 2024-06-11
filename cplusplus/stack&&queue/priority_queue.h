#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
class Less {
public:
	bool operator()(const T& a, const T& b) {
		return a < b;
	}
};

template<class T>
class Greater {
public:
	bool operator()(const T& a, const T& b) {
		return a > b;
	}
};

namespace max {
	
	template<class T, class Container = std::vector<T>, class Compare = Less<T>>
	class priority_queue {
	public:
		Compare com;
		void adjust_up(size_t child) {
			size_t parent = (child - 1) / 2;
			while (child > 0) {
				if (com(_con[parent], _con[child])) {
					std::swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else {
					break;
				}
			}
		}
		void push(const T& val) {
			_con.push_back(val);
			adjust_up(size() - 1);
		}
		void adjust_down(size_t parent) {
			size_t child = 2 * parent + 1;
			while (child < size()) {
				if (child + 1 < size() && com(_con[child], _con[child + 1])) {
					++child;
				}
				if (com(_con[parent], _con[child])) {
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = 2 * parent + 1;
				}
				else {
					break;
				}
			}
		}
		void pop() {
			std::swap(_con[0], _con[size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}
		T& top() {
			return _con[0];
		}
		bool empty() {
			return _con.empty();
		}
		size_t size() {
			return _con.size();
		}
	private:
		Container _con;
	};
}
