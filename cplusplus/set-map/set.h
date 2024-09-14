#pragma once

#include <iostream>

namespace max {
	template<class K>
	struct TreeNode {
		TreeNode* _left;
		TreeNode* _right;
		K _key;

		TreeNode(const K& key = K())
			: _key(key), _left(nullptr), _right(nullptr) {}
	};

	template<class K>
	class set {
		typedef TreeNode<K> node;
	public:
		set()
			: _root(nullptr) {}
		bool insert(const K& key) {
			node* newNode = new node(key);

			node* cur = _root;
			node* prev = nullptr;
			while (cur) {
				if (key < cur->_key) {
					prev = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key) {
					prev = cur;
					cur = cur->_right;
				}
				else {
					return false;
				}
			}
			if (key < prev->_key) {
				prev->_left = newNode;
			}
			else {
				prev->_right = newNode;
			}
			return true;
		}
	private:
		node* _root;
	};
}