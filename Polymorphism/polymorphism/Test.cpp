#include <iostream>

using namespace std;

class Person
{
public:
	virtual void BuyTicket() { cout << "成人票" << endl; }
};

class Student :public Person
{
public:
	//子类满足三同(函数名 参数 返回值)的虚函数
	virtual void BuyTicket() { cout << "学生票" << endl; }
};

void fun(Person& s)
{
	s.BuyTicket();
}

int main()
{
	//静态多态:函数重载,看起来同一个函数有不同的行为
	// 静态:编译时
	//动态多态:一个父类的引用或者指针去调用同一个函数,传递不同的对象,会调用不同的函数
	//动态:运行时
	Person p;
	Student s;
	p.BuyTicket();
	s.BuyTicket();
	return 0;
}