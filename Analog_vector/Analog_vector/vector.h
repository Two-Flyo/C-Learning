#pragma once 
#include<assert.h>
#include<iostream>
#include<algorithm>
using namespace std;

namespace lrf
{
	template<class T>
	class vector
	{
		typedef T* iterator;
	public:
		vector()
			:_start(nullptr),
			_finish(nullptr),
			_endofstorage(nullptr)
		{}

		//һ����ģ��ĳ�Ա�������ֿ�����һ������ģ��
		template<class InputIterator>
		vector(InputIterator first,InputIterator last)
			:_start(nullptr),_finish(nullptr),_endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}


		//vector(const vector<T>& v)
		//{
		//	_start = new T[v.capacity()];
		//	_finish = _start + v.size();
		//	_endofstorage = _start + v.capacity();
		//	memcpy(_start,v._start,v.size()*sizeof(T));
		//}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		vector(const vector<T>& v)
			:_start(nullptr),_finish(nullptr),_endofstorage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		vector<T>& operator=(vector<T>& v) 
		{
			swap(v);
			return *this;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _endofstorage - _start;
		}
			
		T& operator[] (size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		void reserve(size_t n)
		{
			size_t len = size();//����֮���Ӱ��size()�ļ��㣬����ǰ���
			T* tmp = new T[n];
			if (_start)
			{
				//memcpy(tmp, _start, sizeof(T) * n);//��memcpyʹvector�е�string��������ǳ����������ʱ��������
				for (size_t i = 0; i < len; i++)
				{
					//T��int,һ��һ������û���⣬T��string��
					//һ��һ���������õ���T�������ֵ
					tmp[i] = _start[i];
				}
				delete _start;
			}
			_start = tmp;
			_finish = _start + len;
			_endofstorage = _start + n;

		}

		void resize(size_t n, const T& val = T()) //��������const���Σ����ӳ�������������
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
					reserve(n);
			
				while (_finish != _start+n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start&&pos<=_endofstorage);
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + len;  //��ֹ������ʧЧ
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos>=_start&&pos<_finish);
			iterator begin = pos + 1;
			while (begin<_finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			return pos;
		}

		void  push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}

		void pop_back()
		{
			assert(_finish < _start);
			--_finish;
		}

		iterator begin() const
		{
			return _start;
		}
		iterator end() const 
		{
			return _finish;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		v.insert(find(v.begin(), v.end(), 4),233);
		v.insert(find(v.begin(), v.end(), 1),111);
		v.insert(find(v.begin(), v.end(), 5),555);

		vector<int> v2(v);

		for (auto e : v2)
		{
			cout << e << ' ';
		}
		cout << endl;
	}
}
