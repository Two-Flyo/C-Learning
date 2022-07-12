#pragma once
#define _CRT_SECURE_NO_WARNINGS

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


	//Node*ԭ��ָ���һ����������������ռ�õĿռ���һ����ģ�����4Byte,
	//���Ҵ��ֵҲ��һ���ģ����Ƕ�����ʹ�������������ͽ���ǲ�һ����
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

		//��ʹ��ʱ��Ӧ����it->-> ,���������Ļ��ɶ��Խϲ���Ա������������Ż���
		//ʡ����һ��->
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


		//Ĭ�����ɵĿ�������͸�ֵ�Ѿ��㹻��
		//�������������ǽ����ڵ��ָ������޸������ڵ��������������ڵ�����
	};
	


	template<class T>
	class list
	{
	private:
		typedef ListNode<T> Node;
		
	public:
		typedef __list_iterator<T,T&,T*> iterator;
		typedef __list_iterator<T,const T&,const T*> const_iterator;//const��*��ߣ���ʾָ��ָ��Ŀռ䲻�ܱ��޸�
		//��ͷ˫��ѭ������
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

		iterator end()  //���һ��Ԫ�ص���һ��λ��
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
			newnode->_next = _head;
			_head->_prev = newnode;
		}

		void insert(iterator pos, const T& x);
		void erase(iterator pos);


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

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);
		print_list(lt);
	}
}