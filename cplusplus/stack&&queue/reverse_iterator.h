#pragma once
// 反向迭代器


template <class iterator, class Ref, class Ptr>
class Reverse_Iterator {
public:
	typedef Reverse_Iterator<iterator, Ref, Ptr> self;
	Reverse_Iterator(iterator it)
		: _it(it)
	{}

	self& operator++() {
		--_it;
		return *this;
	}
	self& operator--() {
		++_it;
		return *this;
	}
	Ref operator*() {
		//return *_it;
		iterator cur = _it;
		return *(--cur);
	}
	Ptr operator->() {
		return &(_it.operator*());
	}

	bool operator!=(const self& s) {
		return _it != s._it;
	}

	bool operator==(const self& s) {
		return _it == s._it;
	}
private:
	iterator _it;
};