#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Template.h"
using namespace std;

////��ʾʵ����


int main()
{
	f(1);
	//f(1.1);
	return 0;
}

//template<class T1,class T2>
//class Data
//{
//public:
//	Data()
//	{
//		cout << "Date<T1,T2>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//
////ȫ�ػ�
//template<>
//class Data<int,char>
//{
//public:
//	Data()
//	{
//		cout << "Date<int,char>" << endl;
//	}
//private:
//	int _d1;
//	char _d2;
//};
//
////ƫ�ػ�
//template<class T1>
//class Data<T1,char>
//{
//public:
//	Data()
//	{
//		cout << "Date<T1,char>" << endl;
//	}
//private:
//	T1 _d1;
//	char _d2;
//};
//template<class T1, class T2>
//class Data<T1*,T2*>
//{
//public:
//	Data()
//	{
//		cout << "Date<T1*,T2*>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//template<class T1, class T2>
//class Data<T1&, T2&>
//{
//public:
//	Data()
//	{
//		cout << "Date<T1&,T2&>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//
////������ģ�����Ҳ�����ػ�
//template<size_t N>
//class A
//{
//public:
//	A()
//	{
//		cout << "A<N>" << endl;
//	}
//private:
//};
//template<>
//class A<10>
//{
//public:
//	A()
//	{
//		cout << "A<10>" << endl;
//	}
//private:
//
//};
//int main()
//{
//	A<100> a1;
//	A<10> a2;
//	return 0;
//}

//int main()
//{
//	Data<int, char> d1;
//	Data<char, char> d2;
//	Data<double, char> d3;
//	Data<int, int> d4;
//	Data<int*,int*> d5;
//	Data<int&,int&> d6;
//	A<100> a1;
//	A<10> a2;
//	return 0;
//}

//������ģ�����  -->N:����
//������ģ���������Ϊ���γ���
//template<class T,size_t N=100>
//class MyStack
//{
//public:
//	void push(const T & x)
//	{
//		
//	}
//
//private:
//	T _a[N];
//	size_t _top;
//};
//
//template<class T>
//bool ObjLess(const T& left, const T& right)
//{
//	return left < right;
//}
//
//template<>
//bool ObjLess<int>(const int& left, const int& right)
//{
//	return left < right;
//}
//int main()
//{
//	cout << ObjLess(1, 2) << endl;
//}

//int main()
//{
//
//	MyStack<int,20> stk1;
//	MyStack<int,100> stk2;
//	return 0;
//}