#define _CRT_SECURE_NO_WARNINGS
#include"Template.h"


template<class T>
void f(const T& a)
{
	cout << "f(T a) " << endl;
}
//1.��ʾʵ����
template
void f<int>(const int& a);

template<class T>
A<T>::A()
	:_a(0)
{}

//��ģ����ʾʵ�������ַ�ʽ������
template
A<int>::A();

//template
//class A<int>;

