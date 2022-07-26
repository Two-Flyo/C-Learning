#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//多态
//静态的多态：函数重载，看起来是同一个函数有不同的行为 静态：编译时
//动态的多态：一个对象的引用或指针去调用同一个函数，传递不同的对象，会调用不同的函数
//  动态：运行时
//本质：不同人做同一件事完成不同的动作

class A
{
public:
	virtual void Print()
	{
		cout << "A()" << endl;
	}
};

class B:public A
{
	void Print()//看起来是私有的，实际上继承了父类Print的属性，重写的至少函数的内容
	{
		cout << "B()" << endl;
	}
};

void Fun(A* a)
{
	a->Print();
}

int main()
{
	A* t1 = new A;
	A* t2 = new B;
	Fun(t1);
	Fun(t2);
	t2->Print();
	return 0;
}

//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "成人票" << endl;
//	}
//};
//
//class Student :public Person
//{
//
//public:
//	//子类中满足三同(函数名，参数，返回值)虚函数，叫做重写(覆盖)
//	virtual void BuyTicket()
//	{
//		cout << "学生票" << endl;
//	}
//};
//
//	
//
//
//void Func(Person& p)
//{
//	p.BuyTicket();//多态
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//	return 0;
//}