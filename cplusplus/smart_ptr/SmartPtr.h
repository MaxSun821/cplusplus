#ifndef SMART_PTR_H
#define SMART_PTR_H

#include <iostream>
#include <functional>

using std::function;

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
	private:
		void release() {
			if (--(*ref_count_) == 0) {
				deleter_(ptr_); // Use custom deleter if provided
				delete ref_count_; // Clean up reference count
			}
		}
	public:
		shared_ptr(T* p = nullptr) : ptr_(p), ref_count_(new int(1)) {}

		template<typename D>
		shared_ptr(T* p, D deleter)
			: ptr_(p), ref_count_(new int(1)), deleter_(deleter) {  }

		~shared_ptr() {
			release();
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
		shared_ptr<T>& operator=(const shared_ptr<T>& p) {
			if (ptr_ != p.ptr_) {
				release(); // Release current resource
				ptr_ = p.ptr_;
				ref_count_ = p.ref_count_; // Share the reference count
				++(*ref_count_); // Increment reference count
			}
			return *this;
		}
		T* get() const {
			return ptr_;
		}
		int use_count() const {
			return *ref_count_;
		}
	private:
		T* ptr_;
		int* ref_count_; // Reference count for shared_ptr
		function<void(T*)> deleter_ = [](T* ptr) {delete ptr; };
	};

	template<typename T>
	class weak_ptr {
	public:
		weak_ptr()
			: ptr_(nullptr) { }
		weak_ptr(const shared_ptr<T>& p)
			: ptr_(p.get()) {
		}
		T& operator*() {
			return *ptr_;
		}
		T* operator->() {
			return ptr_;
		}
		weak_ptr<T>& operator=(const shared_ptr<T>& p) {
			ptr_ = p.get();
			return *this;
		}
	private:
		T* ptr_;
	};
}

#endif
