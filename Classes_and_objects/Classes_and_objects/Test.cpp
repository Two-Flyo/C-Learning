#include"Stack.h"
#include<iostream>

using namespace std;

class Date
{
public:
	void Init(int year,int mouth,int day)
	{
		this->_year = year;//Date::_year = year;
		this->_mouth = mouth;
		this->_day = day;
	}
	void Print()
	{
		//cout << _year << '-' << _mouth << '-' << _day << endl;
		printf("%04d-%02d-%02d\n	", _year, _mouth, _day);
	}

private:
	int _year;
	int _mouth;
	int _day;
};

int main()
{
	Date d1;
	Date d2;
	d1.Init(2022, 04, 02);
	d2.Init(2002, 03, 30);
	d1.Print();
	d2.Print();
	return 0;
}

//class A
//{
//public:
//	void show()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->show();
//	return 0;
//}



//class Stack
//{
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//public:
//	void Init()
//	{
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//	void push()
//	{
//
//	}
//	int top()
//	{
//
//	}
//};
//
//int main()
//{
//
//	return 0;
//}

//class Student
//{
//	//成员变量
//	char _name[10];
//	int _age;
//	int _id;
//public:
//	//成员函数/方法
//	void Init(const char* name, int age, int id)
//	{
//		strcpy(_name, name);
//		_age = age;
//		_id = id;
//	}
//
//	void print()
//	{
//		cout << _name << endl;
//		cout << _age << endl;
//		cout << _id << endl;
//	}
//};
//
//int main()
//{
//	Student s1;
//	s1.Init("lrf", 1, 111);
//	s1.print();
//	return 0;
//}


//C++兼容C中结构体的用法，同时struct在C++中也升级成了类
//struct Student
//{
//	//成员变量
//	char _name[10];
//	int _age;
//	int _id;
//
//	//成员函数/方法
//	void Init(const char* name, int age, int id)
//	{
//		strcpy(_name, name);
//		_age = age;
//		_id = id;
//	}
//	void print()
//	{
//		cout << _name << endl;
//		cout << _age << endl;
//		cout << _id << endl;
//	}
//};

//int main()
//{
//	struct Student s1;//兼容C
//	Student s2;//升级到类，Student类名，也是类型
//	s1.Init("lrf", 1, 111);
//	s1.print();
//	return 0;
//}