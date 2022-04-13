#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

int main()
{
	char* p = new char[2u*1024u * 1024u * 1024u];
	printf("%p\n", p);
	//cout << p << endl;
	return 0;
}

//class A
//{
//public:
//	A()
//	{
//
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	new(p1)A;
//	int* p = NULL;
//	cout<<sizeof(p)<<endl;
//
//}

//class Stack
//{
//public:
//	Stack(int capacity = 4)
//		:_top(0), _capacity(capacity)
//	{
//
//		_a = new int[capacity];
//	}
//	~Stack()
//	{
//		delete[] _a;;
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//
//int main()
//{
//	Stack st;
//
//	
//	//Stack* pst2 = new Stack;//开空间+构造函数初始化
//	////与malloc用法相同
//	//Stack* pstr3 = (Stack*)operator new(sizeof(Stack));
//	////char* p1 = (char*)malloc(0xfffffffffffffff);
//	//
//	//delete pst2; //析构函数(清理对象中的资源)+释放空间
//	return 0;
//}

//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	printf("hello lrf\n");
//	return 0;
//}



//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//private:
//	int _a;
//};

//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = (A*)malloc(sizeof(A)*5);
//
//	A* p3 = new A;
//	A* p4 = new A[5];
//
//	free(p1);
//	free(p2);
//
//	delete(p3);
//	delete[] p4;
//
//	return 0;
//}


//int main()
//{
//	//C
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = (int*)malloc(sizeof(int) * 5);
//	free(p1);
//	free(p2);
//	//C++
//	int* p3 = new int;
//	int* p4 = new int[5];//C++98不支持初始化new的数组
//	int* p5 = new int[5]{ 1,2,3,4,5};//C++11支持使用{}列表初始化
//	delete p3;
//	delete[] p4;
//	delete p5;
//	return 0;
//}

//class StackCPP
//{
//public:
//	StackCPP()
//	{}
//	void Push(int x)
//	{}
//	int Top()
//	{}
//	~StackCPP()
//	{}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//void TestStackCPP()
//{
//	StackCPP st;
//	st.Push(1);
//}
//
//int main()
//{
//
//	return 0;
//}