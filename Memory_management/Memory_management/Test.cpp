#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

int main()
{

	return 0;
}



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