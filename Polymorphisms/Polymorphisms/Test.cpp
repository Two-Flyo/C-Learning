#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//��̬
//��̬�Ķ�̬���������أ���������ͬһ�������в�ͬ����Ϊ ��̬������ʱ
//��̬�Ķ�̬��һ����������û�ָ��ȥ����ͬһ�����������ݲ�ͬ�Ķ��󣬻���ò�ͬ�ĺ���
//  ��̬������ʱ
//���ʣ���ͬ����ͬһ������ɲ�ͬ�Ķ���

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
	void Print()//��������˽�еģ�ʵ���ϼ̳��˸���Print�����ԣ���д�����ٺ���������
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