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
	//析构函数名字会被统一处理成destructor()
	//那么子类的析构函数跟父类的析构函数就会构成隐藏
	//学习了多态我们才会理解为什么析构函数名会被统一处理
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


//1.A和B的fun构成函数重载
//2.编译报错
//3.运行报错
//4.A和B的func构成函数隐藏

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
//	b.A::fun();//指明作用域则可以调用
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
//	//赋值兼容 / 切割 / 切片
//	s.print();
//	return 0;
//}