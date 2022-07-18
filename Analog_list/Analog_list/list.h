#pragma once
#include<iostream>
using namespace std;

namespace lrf
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _prev;
		ListNode<T>* _next;
		T _data;

		ListNode(const T& data = T())
			:_data(data), _prev(nullptr), _next(nullptr)
		{}
	};

	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef __list_iterator<T, Ref,Ptr> self;
		typedef ListNode<T> Node;
		Node* _node;

		__list_iterator(Node* x)
			:_node(x)
		{}


		//++it
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		//it++
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		T* operator->()
		{
			return &_node->_data;
		}


		Ref operator*()
		{
			return _node->_data;
		}

		bool operator==(const self& it) const
		{
			return _node == it._node;
		}

		bool operator!=(const self& it) const
		{
			return _node != it._node;
		}
		//不需要实现拷贝构造和赋值运算符重载，默认生成的即可 

	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef __list_iterator<T,T&,T*> iterator;
		typedef __list_iterator<T, const T&,const T*> const_iterator;
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}

		void push_back(const T& x)
		{
			Node* tail = _head->_prev;
			Node* newnode = new Node(x);
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

		void print_list(const list<T>& lt)
		{
			list<T>::const_iterator it = lt.begin();
			while (it != lt.end())
			{
				cout << *it << " ";
				++it;
			}
			cout << endl;
		}



	private:
		Node* _head;
	};


	struct Date
	{
		int _year;
		int _month;
		int _day;
		Date(int year=2023,int month=7,int day=18)
			:_year(year),_month(month),_day(day)
		{}
	};

	void test_list2()
	{
		list<Date> lt;
		lt.push_back(Date(2022,07,18)); 
		lt.push_back(Date(2022,8,18)); 
		lt.push_back(Date(2022,9,20)); 
		lt.push_back(Date(2022,10,21)); 

		list<Date>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//本来应该是it-> ->_month,但是这样写可读性太差，所以这里编译器进行优化省略了一个箭头
			//所有的类型只要想重载->，都是这样的，都会优化省略箭头
			cout << it->_month << endl;
			++it;
		}
	}

	//void test_list1()
	//{
	//	list<int> lt;
	//	lt.push_back(1);
	//	lt.push_back(2);
	//	lt.push_back(3);
	//	lt.push_back(4);

	//	list<int>::iterator it = lt.begin();
	//	while (it != lt.end())
	//	{
	//		*it *= 2;
	//		std::cout << *it << std::endl;
	//		it++; 
	//	}

	//	lt.print_list(lt);
	//}
}