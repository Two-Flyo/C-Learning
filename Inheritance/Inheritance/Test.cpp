#include <iostream>

using namespace std;




class A
{
public:
	int _a;
};

class B : virtual public A
{
public:
	int _b;
};

class C : virtual public A
{
public:
	int _c;
};

class D :public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	d._a = 0;
	return 0;
}
//class Person
//{
//public:
//	string _name;
//
//};
//
//class Students : virtual public Person
//{
//public:
//	int _num;
//};
//
//class Teacher : virtual public Person
//{
//public:
//	int _id;
//};
//
//class Assistant :public Students, public Teacher
//{
//public:
//	string _majorCourse;
//};
//
//void Test()
//{
//
//}
//int main()
//{
//	Assistant a;
//	a._id=1;
//	a._num = 2;
//	a.Students::_name = "lrf";
//	a.Teacher::_name = "hhh";
//	a._name = "abc";
//	return 0;
//}
//int main()
//{
//
//}

//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//class Person
//{
//protected:
//	int _age;
//	string _name;
//public:
//	Person()
//	{
//		cout << "Person()" << endl;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Students :public Person
//{
//protected:
//	int _grade;
//public:
//	Students()
//	{
//
//	}
//	Students(const Students& s)
//		:Person(s),_grade(s._grade)
//	{
//
//	}
//
//	Students& operator=(const Students& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_grade = s._grade;
//		}
//
//		return *this;
//	}
//	//�����������ֻᱻͳһ�����destructor()
//	//��ô�����������������������������ͻṹ������
//	//ѧϰ�˶�̬���ǲŻ����Ϊʲô�����������ᱻͳһ����
//	~Students()
//	{
//		Person::~Person();
//	}
//};
//
//
//int main()
//{
//	Students s;
//	return 0;
//}


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