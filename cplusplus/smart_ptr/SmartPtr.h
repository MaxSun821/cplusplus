#ifndef SMART_PTR_H
#define SMART_PTR_H

#include <iostream>

namespace max {
	template<typename T>
	class auto_ptr {
	public:
		auto_ptr(T* p = nullptr) : ptr_(p) {}
		~auto_ptr() {
			delete ptr_;
			ptr_ = nullptr;
		}
		auto_ptr(auto_ptr<T>& p)
			: ptr_(p.ptr_) {
			p.ptr_ = nullptr;
		}
		T& operator*() {
			return *ptr_;
		}
		T* operator->() {
			return ptr_;
		}
		auto_ptr<T>& operator=(auto_ptr<T>& p) {
			if (this != &p) {
				delete ptr_;
				ptr_ = p.ptr_;
				p.ptr_ = nullptr;
			}
			return *this;
		}
	private:
		T* ptr_;
	};

	template<typename T>
	class unique_ptr {
	public:
		unique_ptr(T* p = nullptr) : ptr_(p) {}
		~unique_ptr() {
			delete ptr_;
			ptr_ = nullptr;
		}
		unique_ptr(unique_ptr<T>& p) = delete; // Prevent copying
		unique_ptr<T>& operator=(unique_ptr<T>& p) = delete; // Prevent assignment

		T& operator*() {
			return *ptr_;
		}
		T* operator->() {
			return ptr_;
		}
	private:
		T* ptr_;
	};

	template<typename T>
	class shared_ptr {
	public:
		shared_ptr(T* p = nullptr) : ptr_(p) {}
		~shared_ptr() {
			ref_count_--;
			if (ref_count_ == 0) {
				delete ptr_;
				ptr_ = nullptr;
				delete ref_count_; // Clean up reference count
				ref_count_ = nullptr;
			}
		}
		shared_ptr(const shared_ptr<T>& p)
			: ptr_(p.ptr_)
			, ref_count_(p.ref_count_) {
			++(*ref_count_); // Increment reference count
		}
		T& operator*() {
			return *ptr_;
		}
		T* operator->() {
			return ptr_;
		}
		shared_ptr& operator=(const shared_ptr<T>& p) {
			if (ptr_ != p.ptr_) {
				(*ref_count_)--;
				if (ref_count_ == 0) {
					delete ptr_;
					ptr_ = nullptr;
					delete ref_count_; // Clean up reference count
					ref_count_ = nullptr;
				}
				ptr_ = p.ptr_;
				ref_count_ = p.ref_count_; // Share the reference count
				++(*ref_count_); // Increment reference count
			}
			return *this;
		}
	private:
		T* ptr_;
		int* ref_count_ = new int(1); // Reference count for shared_ptr
	};
}

#endif
