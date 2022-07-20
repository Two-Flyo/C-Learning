#pragma once
#include <vector>
#include <list>
#include <deque>
using namespace std;
namespace lrf
{
	template<class T,class Container = deque<T>>
	class stack
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

		const T& top()
		{
			return _con.back();
		}

		

		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}


	private:
		Container _con;
	};


	void test_stack()
	{
		stack<int> s;
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);
		s.push(5);

		s.pop();
	}
}