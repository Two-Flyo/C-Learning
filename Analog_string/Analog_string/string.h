#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
#include<assert.h>
#include<algorithm>

//using std::cout;
//using std::endl;
//using std::swap;

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
		//传统写法
		////s2(s1)
		//string(const string& s)
		//	: _size(s._size)
		//	,_capacity(s._capacity)
		//{
		//	_str = new char[strlen(s._str) + 1];
		//	strcpy(_str, s._str);
		//}
		////s1=s3;
		//string& operator=(const string& s)
		//{
		//	//if (this != &s)
		//	//{
		//	//	delete[] _str;
		//	//	_str = new char[strlen(s._str) + 1];
		//	//	strcpy(_str, s._str);
		//	//}
		//	if (this != &s)
		//	{
		//		char* tmp = new char[strlen(s._str) + 1];
		//		strcpy(tmp, s._str);
		//		delete[] _str;
		//		_str = tmp;
		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}
		//	return *this;

		//}

		//现代写法
		//s2(s1)
		//string(const string& s)
		//	:_str(nullptr)
		//{
		//	string tmp(s._str);
		//	swap(_str, tmp._str);
		//}
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		//s2(s1)
		string(const string& s)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			string tmp(s._str);	
			//this->swap(tmp);
			swap(tmp);
		}



		//s1 = s3;
		//string& operator=(const string& s)
		//{
		//	if(this!=&s)
		//	{
		//		string tmp(s);
		//		swap(_str, tmp._str);
		//	}
		//	return *this;
		//}
		//s1 = s3;
		//string& operator=(string s)
		//{
		//	swap(_str, s._str);
		//	return *this;
		//}
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
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

		void reserve(size_t n)//扩容
		{
			if (n > _capacity)
			{
				char* tmp = new char[n+1];//+1表示\0
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void resize(size_t n,char ch='\0')
		{
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				memset(_str + _size, ch,n-_size);
				_size = n;
				_str[_size] = '\0';
			}
		}

		size_t find(char ch)
		{
			for (size_t i = 0; i < _size; i++)
			{
				if (ch == _str[i])
				{
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* s, size_t pos = 0)
		{
			const char* ptr = strstr(_str + pos, s);
			if (ptr == nullptr)
			{
				return npos;
			}
			else
			{
				return ptr - _str;
			}

		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				//扩容
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size]=ch;
			_size++;
			_str[_size] = '\0';
			//也可以复用insert
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
			//也可以复用insert
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}	

			//无符号整数出现问题！！！
			//size_t end = _size;
			//while (end >= pos)
			//{
			//	_str[end + 1] = _str[end];
			//	end--;  //-1的无符号整数形式是个很大的数
			//}

			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}
			_str[pos] = ch;
			_size++;

		}

		string& erase(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || pos + len >= _size)//pos后面位置全删除完
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}

			return *this;
		}

		string& insert(size_t pos, const char* s)
		 {
			assert(pos <= _size);
			size_t len = strlen(s);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			size_t end = _size + len;
			while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				end--;
			}

			strncpy(_str+pos, s, len);
			return *this;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		
		//写成成员函数，可以访问私有成员，可以使用strcmp
		//bool operator<(const string& s)const
		//{
		//	return strcmp(_str, s._str)<0;
		//}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;//有效字符空间数(不包含\0)
	public:
		static const size_t npos;
	};
	const size_t string::npos = -1;

	//非成员函数，不能访问私有成员变量
	bool operator<(const string& s1, const string& s2)
	{
		//(1)
		//size_t i1 = 0, i2 = 0;
		//while (i1 < s1.size() && i2 < s2.size())
		//{
		//	if (s1[i1] < s2[i2])
		//	{
		//		return true;
		//	}
		//	else if (s1[i1] > s2[i2])
		//	{
		//		return false;
		//	}
		//	else
		//	{
		//		++i1, ++i2;
		//	}
		//}
		//return i2 < s2.size() ? true : false;
		//(2)

		return strcmp(s1.c_str(), s2.c_str())<0;
	}
	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str())==0;
	}	
	bool operator<=(const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}
	bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}
	bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}
	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}

	//cout s1

	ostream& operator<<(ostream& out, const string& s)
	{
		//for (auto ch : s)
		//{
		//	out << ch;
		//}
		for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}
		out << s.c_str();//不能怎么写 对于这种字符串：hello\0world打印会出现问题
		return out;
	}
}