#pragma once
#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;
namespace lrf
{
	//默认大堆 大的优先级高
	template<class T,class Container = vector<T>>
	class priority_queue
	{
	private:
		void adjust_up(size_t child)
		{
			size_t parent = (child - 1) / 2;
			while (child>0)
			{
				if (_con[child] < _con[parent])
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void adjust_down(size_t parent)
		{
			size_t child = 2 * parent + 1;
			while (child<_con.size())
			{
				if (child + 1 < _con.size() && _con[child + 1] < _con[child])
					++child;
				if (_con[child] < _con[parent])
				{	
					swap(_con[child], _con[parent]);
					parent = child;
					child = 2 * parent + 1;
				}
				else
				{
					break;
				}
			}
		}

	public:
		priority_queue()
		{}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:_con(first,last) 
		{
			//建堆
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; i--)
			{
				adjust_down(i);
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}

		void pop()
		{
			assert(!_con.empty());
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}
		
		const T& top()
		{
			return _con[0];
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
		
	};

	void test_priority_queue()
	{
		priority_queue<int,vector<int>> pq;
		pq.push(3);
		pq.push(3);
		pq.push(7);
		pq.push(1);
		pq.push(9);
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}