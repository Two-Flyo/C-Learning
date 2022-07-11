#pragma once
#include<iostream>
#include<cassert>
using namespace std;

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
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr),
			 _finish(nullptr),
			 _endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}


		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		vector(const vector<T>& v)
		{
			vector<T> tmp(v.begin(),v.end());
			swap(tmp);
		}

		~vector()
		{
			if (_start != nullptr)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		vector<T>& operator=(vector<T> v)
		{
			swap(v);

			return *this;
		}

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
				//����
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


		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}

		iterator insert(iterator pos, const T& x)  //ͨ������insert�ķ���ֵ���ͣ�һ���̶��ϡ������������ʧЧ����
		{
			assert(pos >= _start && pos <= _finish);  //=_finish�൱��β��
			if (_finish == _endofstorage)
			{
				//����֮�� _start��_finish�����仯���ᵼ�µ�����ʧЧ
				size_t len = pos - _start;
				reserve(capacity() == 0 ?4:capacity() * 2);
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			++_finish;
		}

		iterator erase(iterator pos)  //������ɾ��Ԫ�ص���һ��Ԫ�ص�λ��
		{
			assert(pos >= _start && pos <= _finish);

			iterator begin = pos + 1;
			while (begin < _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			return pos;
		}

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
				//����
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
	
}

void test_vector()
{
	lrf::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;


	// 1 2 3 4 5 ����
	// 1 2 3 4   ����
	// 1 2 4 5   �������
	//lrf::vector<int>::iterator it = find(v1.begin(), v1.end(), 2);	
	lrf::vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		if (*it % 2 == 0)
		{
			v1.erase(it);
		}
		else
		{
			++it;
		}
	}
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	//
	//lrf::vector<int>::iterator pos = find(v1.begin(),v1.end(),2);
	//if (pos != v1.end())
	//{
	//	//insert�з��������ݣ���ô�ᵼ��itָ��Ŀռ䱻�ͷţ�
	//	//it���ʾ���һ��Ұָ�룬�����������Ǿͽ���������ʧЧ
	//	v1.insert(v1.begin(), 20);
	//}
	//for (auto e : v1)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
}

//void test_vector()
//{
//	lrf::vector<lrf::vector<int>> vv = lrf::Solution().generate(5);
//	for (size_t i = 0; i < vv.size(); i++)
//	{
//		for (int j = 0; j < vv[i].size(); j++)
//		{
//			std::cout << vv[i][j] << ' ';
//		}
//		std::cout << std::endl;
//	}
//	std::cout << std::endl;
//}

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