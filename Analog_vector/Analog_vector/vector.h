#pragma once
#include<iostream>
#include<cassert>


namespace lrf
{
	template<class T>
	class vector
	{

	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr),
			 _finish(nullptr),
			 _endofstorage(nullptr)
		{}

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}

		void reserve(size_t n)
		{
			if (n>capacity())
			{
				//À©ÈÝ
				size_t sz = size();
				T* tmp = new T[n];
				if (_start != nullptr)
				{
					memcpy(tmp, _start, sizeof(T) * size());
					delete[] _start;
				}
				_start = tmp;
				_finish = tmp + sz;
				_endofstorage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         		if (n > capacity())
				{
					reserve(n);
				}
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}

			}
		}


		void insert(iterator pos, const T& x);
		void erase(iterator pos);

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		void push_back(const T& x)
		{
			if (_finish==_endofstorage)
			{
				//À©ÈÝ
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}		
		T& operator[](size_t i) const
		{
			assert(i < size());
			return _start[i];
		}


	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
	class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> vv;
			vv.resize(numRows);
			for (int i = 0; i < numRows; i++)
			{
				vv[i].resize(i + 1);
				vv[i][0] = vv[i][vv[i].size() - 1] = 1;
			}
			for (int i = 0; i < vv.size(); i++)
			{
				for (int j = 0; j < vv[i].size(); j++)
				{
					if (vv[i][j] == 0)
						vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
			}

			return vv;
		}
	};
}

void test_vector()
{
	lrf::vector<lrf::vector<int>> vv = lrf::Solution().generate(5);
	for (size_t i = 0; i < vv.size(); i++)
	{
		for (int j = 0; j < vv[i].size(); j++)
		{
			std::cout << vv[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

//void test_vector()
//{
//	lrf::vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//	v.push_back(6);
//	for (int i = 0; i < v.size(); i++)
//	{
//		std::cout << v[i] <<' ';
//	}
//	std::cout << std::endl;
//	lrf::vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		std::cout << *it << ' ';
//		++it;
//	}
//	std::cout << std::endl;
//	for (auto x : v)
//	{
//		std::cout << x << ' ';
//	}
//	std::cout << std::endl;
//}