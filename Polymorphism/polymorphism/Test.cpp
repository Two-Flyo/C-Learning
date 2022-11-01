#include <iostream>

using namespace std;


//析构函数是虚函数,是否构成重写? -- 构成!!!
class Person
{
public:
	virtual ~Person() { cout << "~Person()" << endl; }
};

class Student :public Person
{
public:
	virtual ~Student() { cout << "~Student()" << endl; }
};

//class Person
//{
//public:
//	//协变
//	virtual Person* BuyTicket() { cout << "成人票" << endl;  return nullptr; }
//};
//
//class Student :public Person
//{
//public:
//	//子类满足三同(函数名 参数 返回值)的虚函数
//	//协变
//	virtual Student* BuyTicket() { cout << "学生票" << endl; return nullptr; }
//};
//
//void fun(Person& s)
//{
//	s.BuyTicket();
//}
//
//int main()
//{
//	//静态多态:函数重载,看起来同一个函数有不同的行为
//	// 静态:编译时
//	//动态多态:一个父类的引用或者指针去调用同一个函数,传递不同的对象,会调用不同的函数
//	//动态:运行时
//	Person p;
//	Student s;
//	fun(p);
//	fun(s);
//	//p.BuyTicket();
//	//s.BuyTicket();
//	return 0;
//}