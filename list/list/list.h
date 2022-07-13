#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<cassert>
#include<algorithm>
#include<iostream>
using namespace std;

namespace lrf
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;
		ListNode(const T& data = T())
			:_next(nullptr),
			_prev(nullptr),
			_data(data)
		{}
	};


	//Node*原生指针和一个迭代器对象，他们占用的空间是一样大的，都是4Byte,
	//并且存的值也是一样的，但是对他们使用运算符的意义和结果是不一样的
	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef ListNode<T> Node;
		typedef __list_iterator<T, Ref,Ptr> self;
		Node* _node;

		__list_iterator(Node* x)
			:_node(x)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		//在使用时，应该是it->-> ,但是这样的话可读性较差，所以编译器进行了优化，
		//省略了一个->
		Ptr operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const self& it) const
		{
			return _node != it._node;
		}
		bool operator==(const self& it) const
		{
			return _node == it._node;
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

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}		
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}


		//默认生成的拷贝构造和赋值已经足够了
		//析构？迭代器是借助节点的指针访问修改链表，节点属于链表，不属于迭代器
	};

	template<class T>
	class list
	{
	private:
		typedef ListNode<T> Node;
		
	public:
		typedef __list_iterator<T,T&,T*> iterator;
		typedef __list_iterator<T,const T&,const T*> const_iterator;//const在*左边，表示指针指向的空间不能被修改
		//带头双向循环链表
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		iterator  begin()
		{
			return iterator(_head->_next);
		}

		iterator end()  //最后一个元素的下一个位置
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
		//lt2(lt1) 传统写法
		//list(const list<T>& lt)
		//{
		//	_head = new Node();
		//	_head->_next = _head;
		//	_head->_prev = _head;
		//	for (auto e : lt)
		//	{
		//		push_back(e);
		//	}
		//}
		//现代写法
		list(list<T>& lt)
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
			list<T> tmp(lt.begin(),lt.end());
			std::swap(_head,tmp._head);
		}
		

		list(int n, const T& val = T())//n之所以定义为int，是因为定义成size_t类型之后，
			//这样使用list(5,5)，编译器会匹配到template<class InputIterator>
			//list(InputIterator first, InputIterator last)
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		//迭代器构造
		template<class InputIterator>
		list(InputIterator first,InputIterator last)
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
			while (first != last)
			{
				push_back(*first);
				++first;
			}	
		}

		~list() 
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		void  clear()
		{
			iterator it = begin();
			//while (it != end())
			//{
			//	iterator del = it++;
			//	delete del._node;
			//}
			//// 恢复链接关系
			//_head->_next = _head;
			//_head->_prev = _head;
			//复用erase
			while (it != end())
			{
				erase(it++);
			}
		}

		void push_back(const T& x)
		{
			Node* tail = _head->_prev;
			Node* newnode = new Node(x);
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
			//也可复用insert
			//insert(end(),x);
		}

		//头插
		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		//erase之后，迭代器失效了
		iterator erase(iterator pos)
		{
			assert(pos != end());//不能把哨兵位的头给删除
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;
			delete pos._node;
			prev->_next = next;
			next->_prev = prev;
			return iterator(pos._node->_next);
		}

		//lt2=lt1
		//list<T>&operator=(const list<T>&lt)
		//{
		//	if (this != &lt)
		//	{
		//		clear();
		//		for (auto e : lt)
		//		{
		//			push_back(e);
		//		}
		//	}
		//	return *this;
		//}
		//现代写法
		list<T>& operator=(list<T> lt)
		{
			std::swap(_head, lt._head);
			return *this;
		}



		//尾删
		void pop_back()
		{
			erase(--end());
		}
		//头删
		void pop_front()
		{
			erase(begin());
		}


		//这里insert后，pos是不会失效的
		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}


	private:
		Node* _head;
	};

	void print_list(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			std::cout << *it << std::endl;
			it++;
		}
	}

	void test_list()
	{
		list<int> l1;
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		l1.push_back(5);
		l1.push_back(6);

		//list<int> l2(l1);
		//for (auto e : l2)
		//{
		//	cout << e << ' ';
		//}
		//cout << std::endl;

		list<int> l3;
		l3.push_back(1);
		l3.push_back(2);
		l3.push_back(3);
		l3.push_back(4);
		l3.push_back(5);

		l1 = l3;
	}

	//void test_list1()
	//{
	//	list<int> lt;
	//	lt.push_back(1);
	//	lt.push_back(2);
	//	lt.push_back(3);
	//	lt.push_back(4);
	//	lt.push_back(5);
	//	lt.push_back(6);
	//	print_list(lt);
	//}
}