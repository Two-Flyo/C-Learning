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
//		cout << "����Ʊ" << endl;
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
//		cout << "ѧ��Ʊ" << endl;
//	}
//private:
//	int _b;
//};
//
//void Fun(Person& p)
//{
//	p.BuyTicket();//����ʱ��ȥpָ������������ҵ��麯���ĵ�ַ
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
//	//���麯��һ��ֻ������ʵ�֣�ʵ��û�м�ֵ
//	virtual void Drive() = 0;
//	
//};

//override :����������麯���Ƿ���д�˻���ĳ���麯�������û�оͱ��뱨��
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
//C++11ʹ��final
//ʹһ����/�������ܱ��̳�/��д

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

//C++98�в��ܱ��̳е����д��
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
////������ƣ����๹�캯���޷����ø��๹�캯����ʼ����Ա��û�취ʵ��������
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


//��̬
//��̬�Ķ�̬���������أ���������ͬһ�������в�ͬ����Ϊ ��̬������ʱ
//��̬�Ķ�̬��һ����������û�ָ��ȥ����ͬһ�����������ݲ�ͬ�Ķ��󣬻���ò�ͬ�ĺ���
//  ��̬������ʱ
//���ʣ���ͬ����ͬһ������ɲ�ͬ�Ķ���
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
//	void Print()//��������˽�еģ�ʵ���ϼ̳��˸���Print�����ԣ���д�����ٺ���������
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
//		cout << "����Ʊ" << endl;
//	}
//};
//
//class Student :public Person
//{
//
//public:
//	//������������ͬ(������������������ֵ)�麯����������д(����)
//	virtual void BuyTicket()
//	{
//		cout << "ѧ��Ʊ" << endl;
//	}
//};
//
//	
//
//
//void Func(Person& p)
//{
//	p.BuyTicket();//��̬
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