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