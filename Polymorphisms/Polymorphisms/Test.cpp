#include <iostream>

using namespace std;

int main()
{

	return 0;
}

//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "成人票" << endl;
//	}
//	void f()
//	{
//		cout << "f()" << endl;
//	}
//private:
//	int _a;
//};
//
//class Student :public Person
//{
//	virtual void BuyTicket()
//	{
//		cout << "学生票" << endl;
//	}
//private:
//	int _b;
//};
//
//void Fun(Person& p)
//{
//	p.BuyTicket();//运行时，去p指向对象的虚表中找到虚函数的地址
//	p.f();//
//}
//
//int main()
//{
//	Person Mike;
//	Fun(Mike);
//	Student Johnson;
//	Fun(Johnson);
//
//	return 0;
//}
//class Base
//{
//public:
//	virtual void Func1()
//	{
//
//	}
//	virtual void Func2()
//	{
//
//	}
//
//private:
//	int _b = 1;
//	char _ch = 'A';
//};
//
//int main()
//{
//	cout << sizeof(Base) << endl;
//	Base b;
//	return 0;
//}


//class Car
//{
//public:
//	//纯虚函数一般只声明不实现，实现没有价值
//	virtual void Drive() = 0;
//	
//};

//override :检查派生类虚函数是否重写了基类某个虚函数，如果没有就编译报错
//class Car
//{
//public:
//	virtual void Drive() 
//	{
//		cout << "Car::Driver()" << endl;
//	}
//};
//
//class Benx :public Car
//{
//public:
//	virtual void Drive() override
//	{
//		cout << "Benx::Driver()" << endl;
//	}
//};
//
//int main()
//{
//	return 0;
//}
//C++11使用final
//使一个类/方法不能被继承/重写

//class A final
//{
//protected:
//	int _a;
//};
//
////class B :public A
////{
////
////};
//
//class C
//{
//public:
//	virtual void f() 
//	{
//		cout << "C::f()" << endl;
//	}
//};
//
//class D :public C
//{
//	virtual void f()
//	{
//		cout << "D::f()" << endl;
//	}
//};
//
//int main()
//{
//	C c;
//	D d;
//	C* aa = &c;
//	aa->f();
//	aa = &d;
//	aa->f();
//
//	return 0;
//}

//C++98中不能被继承的类的写法
//class A 
//{	
//private:
//	A(int a =0)
//		:_a(a)
//	{}
//public:
//	static A CreateOBj(int a = 0)
//	{
//		return A(a);
//	}
//protected:
//	int _a;
//};
//
////间接限制，子类构造函数无法调用父类构造函数初始化成员，没办法实例化对象
//class B :public A
//{
//	
//};


//int main()
//{
//	//A aa = A::CreateOBj(10);
//	B bb;
//
//	return 0;
//}


//多态
//静态的多态：函数重载，看起来是同一个函数有不同的行为 静态：编译时
//动态的多态：一个对象的引用或指针去调用同一个函数，传递不同的对象，会调用不同的函数
//  动态：运行时
//本质：不同人做同一件事完成不同的动作
//
//class A
//{
//public:
//	virtual void Print()
//	{
//		cout << "A()" << endl;
//	}
//};
//
//class B:public A
//{
//	void Print()//看起来是私有的，实际上继承了父类Print的属性，重写的至少函数的内容
//	{
//		cout << "B()" << endl;
//	}
//};
//
//void Fun(A* a)
//{
//	a->Print();
//}
//
//int main()
//{
//	A* t1 = new A;
//	A* t2 = new B;
//	Fun(t1);
//	Fun(t2);
//	t2->Print();
//	return 0;
//}

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