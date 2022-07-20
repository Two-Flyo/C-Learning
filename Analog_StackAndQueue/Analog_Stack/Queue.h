#pragma once
#include <deque>
#include <list>
using namespace std;
namespace lrf
{
	template<class T,class Container = deque<T>>
	class queue
	{
	public:
		bool empty() const
		{
			return _con.empty();
		}

		size_t size() const
		{
			return _con.size();
		}

		const T& front() const
		{
			return _con.front();
		}
		const T& back() const
		{
			return _con.back();
		}


		void push(const T& x) 
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}


	private:
		Container _con;
	};

	void test_queue()
	{
		queue<int, list<int>> q1;
		q1.push(1);
		q1.push(2);
		q1.push(3);
		q1.push(4);
	}
}
