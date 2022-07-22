#pragma once
#include<iostream>

using namespace std;
template<class T>
void f(const T& a);


template<class T>
class A
{
public:
	A();
	cout << "A()" << endl;
private:
	int _a;
};