#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<Windows.h>

using namespace std;
using std::endl;
using std::cout;

class A {

	class B {

	};
};

//class Date
//{
//public:
//	Date(int year=0, int mouth=1, int day=1)
//	{
//		_year = year;
//		_mouth = mouth;
//		_day = day;
//	}
//	void Print()
//	{
//		//cout << _year << '-' << _mouth << '-' << _day << endl;
//		printf("%04d-%02d-%02d\n", _year, _mouth, _day);
//	}
//
//private:
//	int _year;
//	int _mouth;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	Date d2(2002, 03, 30);
//	d1.Print();
//	d2.Print();
//	return 0;
//}

//class Date; // 前置声明
//class Time
//{
//	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类员变量
//public:
//	Time(int hour=0, int minute=0, int second=0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//		_t._hour = 0;
//		_t._minute = 0;
//		_t._second = 0;
//	}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//
//	return 0;
//}


//class Time
//{
//	friend class Date;
//};

//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//private:
//	int _b;
//};
//
////C++ 11  
//class A
//{
//public:
//	//初始化列表阶段，没有对成员变量初始化，这里就会使用缺省值初始化
//	A(int a1)
//	{}
//private:
//	int _a1 = 0;//给成员变量缺省值
//	B _bb=10;
//	B _bb2 = B(20);
//	int* p = (int*)malloc(40);
//	int arr[10] = { 1,2,3,4,5 };
//	//静态的不能这样给缺省值，必须在类外面全局定义初始化
//	//static int _sCount = 0;
//
//};
//
//int main()
//{
//	A aa(1);
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		_sCount++;
//	}
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		_sCount++;
//	}
//	int test()
//	{
//		GetCount();
//	}
//	//static修饰的函数，没有this指针，只能访问静态的成员变量
//	static int GetCount()
//	{
//		test();//error
//		return _sCount;
//	}
//private:
//	int _a;
//	//静态成员变量属于整个类，所有对象，生命周期在整个程序运行期间
//	//在类的成员函数中，可以随便访问
//	static int _sCount;
//};
//
//int A::_sCount = 0; //定义初始化
//
//void f(A a)
//{
//
//}
//
//int main()
//{
//	A a1;
//	A a2 = 1;
//	A a3(a2);
//	f(a3);
//	//_sCount 公有
//	//cout << A::_sCount << endl;
//	//cout << a2._sCount << endl;
//	
//	// _sCount 私有
//	cout << a2.GetCount() << endl;//写一个Get函数
//	cout << A::GetCount() << endl;//static修饰函数，则可以通过类去访问
//
//
//	return 0;
//}

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