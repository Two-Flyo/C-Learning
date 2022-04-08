#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

//using namespace std;
using std::endl;
using std::cout;

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		_sCount++;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		_sCount++;
	}
	//static修饰的函数，没有this指针，只能访问静态的成员变量
	static int GetCount()
	{
		return _sCount;
	}
private:
	int _a;
	//静态成员变量属于整个类，所有对象，生命周期在整个程序运行期间
	//在类的成员函数中，可以随便访问
	static int _sCount;
};

int A::_sCount = 0; //定义初始化

void f(A a)
{

}

int main()
{
	A a1;
	A a2 = 1;
	A a3(a2);
	f(a3);
	//_sCount 公有
	//cout << A::_sCount << endl;
	//cout << a2._sCount << endl;
	
	// _sCount 私有
	cout << a2.GetCount() << endl;//写一个Get函数
	cout << A::GetCount() << endl;//static修饰函数，则可以通过类去访问


	return 0;
}

//class Date
//{
//public:
//	explicit Date(int year)
//		:_year(year)
//	{}
//private:
//	int _year;
//};
//int main()
//{
//	Date d1(2022);
//	Date d2 = 2022;//隐式类型转换 error 
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main() 
//{
//	A aa(1);
//	aa.Print();
//}

//class A
//{
//public:
//	A(int a=0)
//	{
//		_a = a;
//		cout << "A()" << endl;
//	}
//	A(const A & aa)
//	{
//		_a = aa._a;
//		cout << "A(const A& aa)" << endl;
//	}
//	A& operator= (const A & aa)
//	{
//		_a = aa._a;
//	cout << "A& operatpr=(const A & aa)" << endl;
//		return *this;
//	}
//private:
//	int _a;
//};
//
//class Date 
//{
//public:
//	Date(int year, int month, int day, const A& aa)
//	:_a(aa)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	A _a;
//};
//
//int main()
//{
//	A a(11);
//	Date d1(2022, 4, 8, a);
//	return 0;
//}