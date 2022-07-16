#pragma once
#include<iostream>

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

	template<class T>
	struct __list_iterator
	{
		typedef ListNode<T> Node;
		Node* _node;

		__list_iterator(Node* x)
			:_node(x)
		{}

		//++it
		__list_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		//it++
		__list_iterator<T> operator++(int)
		{
			__list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		T& operator*()
		{
			return _node->_data;
		}

		bool operator==(const __list_iterator<T>& it)
		{
			return _node == it._node;
		}

		bool operator!=(const __list_iterator<T>& it)
		{
			return _node != it._node;
		}

	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef __list_iterator<T> iterator;
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

		void push_back(const T& x)
		{
			Node* tail = _head->_prev;
			Node* newnode = new Node(x);
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

	private:
		Node* _head;
	};

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			std::cout << *it << std::endl;
			it++; 
		}
	}
}