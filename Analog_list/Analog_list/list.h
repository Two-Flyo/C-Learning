#pragma once
#include<iostream>
#include"reverse_iterator.h"
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
		typedef reverse_iterator<const_iterator,const T&,const T*> const_reverse_iterator;
		typedef reverse_iterator<iterator, T&, T*> reverse_iterator;
		
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		//清空链表的所有除哨兵位的元素
		void clear()
		{
			iterator it = begin();
			while (it!=end())
			{
				iterator del = it++;
				delete del._node;
			}
			//恢复哨兵节点的链接关系
			_head->_next = _head;
			_head->_prev = _head;
			//也可以复用erase
			//while(it!=end())
			//{
			//	  erase(it++); //erase会自动恢复链接关系
			//}
		}

		//迭代器构造
		template<class InputIterator>
		list(InputIterator first, InputIterator last)
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

		//n个val构造:会与迭代器构造冲突
		list(size_t n, const T& val = T())
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		~list()
		{
			clear();
			//释放哨兵位头结点
			delete _head;
			_head = nullptr;
		}

		//lt2(lt1)
		//list(const list<T>& lt)
		//{
		//	_head = new Node;
		//	_head->_next = _head;
		//	_head->_prev = _head;
		//	for (auto e : lt)
		//	{
		//		push_back(e);
		//	}
		//}
		//拷贝构造的现代写法
		list(const list<T>& lt)
		{
			//如果不写这3行代码程序就会崩
			//_head = new Node;
			//_head->_next = _head;
			//_head->_prev = _head;
			list<T> tmp(lt.begin(), lt.end());
			swap(_head, tmp._head);
		}
				
		//lt2=lt1
		//list<T>& operator=(const list<T>& lt)
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
			swap(_head, lt._head);
			return *this;
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
			//尾插可以复用insert
			//insert(end(),x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}


		//erase之后，pos指向的节点都被释放了，所以迭代器失效了
		iterator erase(iterator pos) //返回被删除的元素的位置的迭代器
		{
			assert(pos != end());//不能把哨兵位的头结点删除

			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;

			delete pos._node;
			prev->_next = next;
			next->_prev = prev;

			return iterator(next);
		}

		//在pos位置插入元素后，pos位置指向的元素没变，所以insert不失效
		iterator insert(iterator pos,const T& x)
		{
			Node* cur = pos._node;//注意是[.]而不是[->]
			Node* newnode = new Node(x);
			cur->_prev->_next = newnode;
			newnode->_prev = cur->_prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			return iterator(newnode);
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

	//void test_list2()
	//{
	//	list<Date> lt;
	//	lt.push_back(Date(2022,07,18)); 
	//	lt.push_back(Date(2022,8,18)); 
	//	lt.push_back(Date(2022,9,20)); 
	//	lt.push_back(Date(2022,10,21)); 

	//	list<Date>::iterator it = lt.begin();
	//	while (it != lt.end())
	//	{
	//		//本来应该是it-> ->_month,但是这样写可读性太差，所以这里编译器进行优化省略了一个箭头
	//		//所有的类型只要想重载->，都是这样的，都会优化省略箭头
	//		cout << it->_month << endl;
	//		++it;
	//	}
	//}

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::reverse_iterator rit = lt.rbegin();
		while (rit!=lt.rend())
		{
			cout << *rit << endl;
			++rit;
		}
		//list<int>::iterator it = lt.begin();
		//while (it != lt.end())
		//{
		//	*it *= 2;
		//	std::cout << *it << std::endl;
		//	it++; 
		//}
		//list<int> lt2;
		//lt2.push_back(1);
		//lt2.push_back(1);
		//lt2.push_back(1);
		//lt2.push_back(1);
		//lt2.push_back(1);
		//lt2 = lt;

		//lt.print_list(lt2);
		//lt.clear();
	}
}