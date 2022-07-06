#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include<cstring>
#include <iostream>
#include<cassert>

namespace lrf 
{
	class string
	{
	public:

		typedef char* iterator;

		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}		
		const_iterator begin() const
		{
			return _str + _size;
		}

		string(const char* str="")
			:_size(strlen(str))
			,_capacity(_size)
		{
			_str = new char[_capacity + 1];//+1����'\0'��Ϊ�˱����ظ�ʹ��O(N)��strlen�����ڳ�ʼ���б��ʼ��_str
			strcpy(_str, str);
		}
		//s2(s1)��������
		string(const string& s)
			:_size(s._size),
			_capacity(s._capacity)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;//����ռ�ɹ�֮��������ԭ���Ŀռ�
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

			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{

		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;//����'\0'ռ�Ŀռ�
	};
}
void testmystring()
{
	lrf::string s1 = "lrf2333";
	lrf::string::iterator it = s1.begin();
	while (it!=s1.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
}
