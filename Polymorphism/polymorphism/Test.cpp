#include <iostream>

using namespace std;

class Person
{
public:
	virtual void BuyTicket() { cout << "����Ʊ" << endl; }
};

class Student :public Person
{
public:
	//����������ͬ(������ ���� ����ֵ)���麯��
	virtual void BuyTicket() { cout << "ѧ��Ʊ" << endl; }
};

void fun(Person& s)
{
	s.BuyTicket();
}

int main()
{
	//��̬��̬:��������,������ͬһ�������в�ͬ����Ϊ
	// ��̬:����ʱ
	//��̬��̬:һ����������û���ָ��ȥ����ͬһ������,���ݲ�ͬ�Ķ���,����ò�ͬ�ĺ���
	//��̬:����ʱ
	Person p;
	Student s;
	p.BuyTicket();
	s.BuyTicket();
	return 0;
}