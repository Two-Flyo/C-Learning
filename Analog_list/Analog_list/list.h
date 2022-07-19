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
		//����Ҫʵ�ֿ�������͸�ֵ��������أ�Ĭ�����ɵļ��� 

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

		//�����������г��ڱ�λ��Ԫ��
		void clear()
		{
			iterator it = begin();
			while (it!=end())
			{
				iterator del = it++;
				delete del._node;
			}
			//�ָ��ڱ��ڵ�����ӹ�ϵ
			_head->_next = _head;
			_head->_prev = _head;
			//Ҳ���Ը���erase
			//while(it!=end())
			//{
			//	  erase(it++); //erase���Զ��ָ����ӹ�ϵ
			//}
		}

		//����������
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

		//n��val����:��������������ͻ
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
			//�ͷ��ڱ�λͷ���
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
		//����������ִ�д��
		list(const list<T>& lt)
		{
			//�����д��3�д������ͻ��
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
		//�ִ�д��
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
			//β����Ը���insert
			//insert(end(),x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}


		//erase֮��posָ��Ľڵ㶼���ͷ��ˣ����Ե�����ʧЧ��
		iterator erase(iterator pos) //���ر�ɾ����Ԫ�ص�λ�õĵ�����
		{
			assert(pos != end());//���ܰ��ڱ�λ��ͷ���ɾ��

			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;

			delete pos._node;
			prev->_next = next;
			next->_prev = prev;

			return iterator(next);
		}

		//��posλ�ò���Ԫ�غ�posλ��ָ���Ԫ��û�䣬����insert��ʧЧ
		iterator insert(iterator pos,const T& x)
		{
			Node* cur = pos._node;//ע����[.]������[->]
			Node* newnode = new Node(x);
			cur->_prev->_next = newnode;
			newnode->_prev = cur->_prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			return iterator(newnode);
		}

		//βɾ
		void pop_back()
		{
			erase(--end());
		}
		//ͷɾ
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
	//		//����Ӧ����it-> ->_month,��������д�ɶ���̫�������������������Ż�ʡ����һ����ͷ
	//		//���е�����ֻҪ������->�����������ģ������Ż�ʡ�Լ�ͷ
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