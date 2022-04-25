#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
#include<assert.h>
namespace lrf
{
	class string
	{
	public:

		typedef char* iterator;
		typedef const char* const_iterator;

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

		//string()
		//	:_str(new char[1])
		//	,_size(0)
		//	,_capacity(0)
		//{
		//	_str[0] = '\0';
		//}
		string(const char* str="")//常量字符串默认含有\0
			:_size(strlen(str))
			,_capacity(_size)
		{
			_str = new char[_capacity+1];
			strcpy(_str, str);
		}

		//string(const char* str)
		//	:_size(strlen(str))
		//	,_capacity(_size)
		//{
		//	_str = new char[_capacity + 1];
		//	strcpy(_str, str);
		//}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		//s2(s1)
		string(const string& s)
			: _size(s._size)
			,_capacity(s._capacity)
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		//s1=s3;
		string& operator=(const string& s)
		{
			//if (this != &s)
			//{
			//	delete[] _str;
			//	_str = new char[strlen(s._str) + 1];
			//	strcpy(_str, s._str);
			//}
			if (this != &s)
			{
				char* tmp = new char[strlen(s._str) + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;

		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				//扩容
			}
			_str[_size]
		}

		void append(const char* str)
		{

		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;//有效字符空间数(不包含\0)
	};
}