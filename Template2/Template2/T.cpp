#define _CRT_SECURE_NO_WARNINGS
#include"Template.h"


template<class T>
void f(const T& a)
{
	cout << "f(T a) " << endl;
}
//1.显示实例化
template
void f<int>(const int& a);

template<class T>
A<T>::A()
	:_a(0)
{}

//类模板显示实例化两种方式都可以
template
A<int>::A();

//template
//class A<int>;

