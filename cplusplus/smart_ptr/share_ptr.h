#pragma once

#include <iostream>

namespace max
{
	template<class T>
	class share_ptr
	{
	 public:
		share_ptr(T* ptr)
			: _ptr(ptr), _pcount(new int(1))
		{}

		void release()
		{
			if (--(*_pcount) == 0)
			{
				std::cout << "~share_ptr()" << std::endl;
				delete _ptr;
				delete _pcount;
			}
		}

		~share_ptr()
		{
			release();
		}

		share_ptr(const share_ptr<T>& sharePtr)
			: _ptr(sharePtr._ptr), _pcount(sharePtr._pcount)
		{
			++(*_pcount);
		}

		share_ptr<T>& operator=(const share_ptr<T>& sharePtr)
		{
			if(_ptr != sharePtr._ptr)
			{
				release();

				_ptr = sharePtr._ptr;
				_pcount = sharePtr._pcount;

				++(*_pcount);
			}
			return *this;
		}

	 private:
		T* _ptr;
		int* _pcount;
	};
}