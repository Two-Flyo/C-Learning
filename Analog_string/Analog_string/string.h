#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include<cstring>
#include <iostream>
#include<algorithm>
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
		const_iterator end() const
		{
			return _str + _size;
		}

		string(const char* str="")
			:_size(strlen(str))
			,_capacity(_size)
		{
			_str = new char[_capacity + 1];//+1包含'\0'，为了避免重复使用O(N)的strlen，不在初始化列表初始化_str
			strcpy(_str, str);
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		string(const string& s)
			:_str(nullptr),
			_size(0),
			_capacity(0)
		{
			string tmp(s._str);
			swap(tmp);
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		string& operator=(string s)
		{
			std::swap(_str,s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
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

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n+1];//+1表示给'\0'多开一个
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n > _capacity)
			{
				reserve(n);
			}
			else
			{
				_str[n] = '\0';
				_size = n;
			}
			memset(_str + _size, ch, n - _size);
			_size = n;
			_str[_size] = '\0';

		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			//capacity表示可以放的有效字符，本来就已经考虑了'\0'的问题，这里不需要考虑
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		size_t find(char ch)
		{
			for (size_t i = 0; i < _size; i++)
			{
				if (ch == _str[i])
					return i;
			}
			return npos;
		}

		size_t find(const char* s, size_t pos = 0)
		{
			const char* ptr = strstr(_str + pos, s);
			if (ptr == nullptr)
				return npos;
			else
				return ptr - _str;
		}

		string& insert(size_t pos , char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}
			_str[pos] = ch;
			_size++;
			
			return *this;
		}

		string& insert(size_t pos, const char* s)
		{
			assert(pos <= _size);
			size_t len = strlen(s);
			if (len + _size > _capacity)
			{
				reserve(_size + len);
			}
			size_t end = _size + len;
			while (end >= pos+len)
			{
				_str[end] = _str[end-len];
				end--;
			}
			strncpy(_str+pos, s, len);
			_size += len;
			return *this;
		}

		string& erase(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || pos + len >= _size)
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
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;//不算'\0'占的空间
	public:
		static const size_t npos;
	};

	//类外
	const size_t string::npos = -1;


	bool operator<(const string& s1, const string & s2)
	{
		return strcmp(s1.c_str(), s2.c_str())<0;
	}
	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}
	bool operator<=(const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}

	bool operator>(const string& s1, const string &s2)
	{
		return !(s1 <= s2);
	}




	bool operator>=(const string& s1, const string& s2)
	{
		return s1 > s2 || s1 == s2;
	}

	std::ostream& operator<<(std::ostream& out,const string& s)//带返回值的目的是支持连续的使用cout<<a<<b<<c<<endl;
	{
		for (auto ch : s)
		{
			out << ch;
		}
		//out << s.c_str();//不能使用这种方式,会导致带\0的字符串出现问题
		return out;
	}
	std::istream& operator>>(std::istream& in,string& s)
	{
		s.clear();
		char ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}


}



void testmystring()
{  
	lrf::string s1("lrf12345");
	std::cin >> s1;
	std::cout << s1 << std::endl;
	//std::string s2("lrf12345");
	//s2 += '\0';
	//s2 += "abcdefg";
	//std::cout << s2;
	//std::cout << s2.c_str();
	/*

	lrf::string s1("1111111");
	lrf::string s2("222");
	std::cout << (s1 < s2) << std::endl;
	lrf::string s3("131");
	lrf::string s4("122");
	std::cout<<(s3<s4);*/

	//s1.push_back('2');
	//s1.push_back('3');
	//s1.push_back('3');
	//s1.push_back('3');
	//s1.append("hhhhhhhh");
	//lrf::string s2;
	//s1 += '-';
	//s1 += "!!!!!";
	//std::cout << s1.c_str() << std::endl;
}

//void testmystring()
//{
//	lrf::string s1 = "23333";
//	lrf::string s2 = "123";
//	s2 = s1;
//	std::cout << s2.c_str() << std::endl;
//}
