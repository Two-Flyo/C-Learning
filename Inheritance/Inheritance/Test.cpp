#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
};
class Person
{
protected:
	int _age;
	string _name;
public:
	Person()
	{
		cout << "Person()" << endl;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
};

class Students :public Person
{
protected:
	int _grade;
public:
	Students()
	{

	}
	Students(const Students& s)
		:Person(s),_grade(s._grade)
	{

	}

	Students& operator=(const Students& s)
	{
		if (this != &s)
		{
			Person::operator=(s);
			_grade = s._grade;
		}

		return *this;
	}
	//�����������ֻᱻͳһ�����destructor()
	//��ô�����������������������������ͻṹ������
	//ѧϰ�˶�̬���ǲŻ����Ϊʲô�����������ᱻͳһ����
	~Students()
	{
		Person::~Person();
	}
};


int main()
{
	Students s;
	return 0;
}


//1.A��B��fun���ɺ�������
//2.���뱨��
//3.���б���
//4.A��B��func���ɺ�������

//class A 
//{
//public:
//	void fun()
//	{
//		cout << "fun()" << endl;
//	}
//};
//
//class B :public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "fun(int i)" << endl;
//	}
//};
//
//void Test()
//{
//	B b;
//	b.fun();//error
//	b.A::fun();//ָ������������Ե���
//	b.fun(1);
//}
//
//int main()
//{
//
//
//	return 0;
//}


//class Person
//{
//protected:
//	string _name = "111";
//	string _id = "123";
//	int _age = 123;
//	int _height = 174;
//public:
//	void print()
//	{
//		cout << "Name:" << _name << "Id:" << _id << "Age:" << _age;
//	}
//};
//
//class Student :public Person
//{
//private:
//	int _score = 100;
//	int _height = 183;
//public:
//	void print()
//	{
//		cout << "Name:" << _name << "Id:" << _id << "Age:" << _age<<"Score:"<<_score<<"Height:"<<_height;
//	}
//};

//int main()
//{
//	Person p;
//	Student s;
//	//��ֵ���� / �и� / ��Ƭ
//	s.print();
//	return 0;
//}