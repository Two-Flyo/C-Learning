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

//class Date; // ǰ������
//class Time
//{
//	friend class Date; // ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time��Ա����
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
//		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
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
//	//��ʼ���б�׶Σ�û�жԳ�Ա������ʼ��������ͻ�ʹ��ȱʡֵ��ʼ��
//	A(int a1)
//	{}
//private:
//	int _a1 = 0;//����Ա����ȱʡֵ
//	B _bb=10;
//	B _bb2 = B(20);
//	int* p = (int*)malloc(40);
//	int arr[10] = { 1,2,3,4,5 };
//	//��̬�Ĳ���������ȱʡֵ��������������ȫ�ֶ����ʼ��
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
//	//static���εĺ�����û��thisָ�룬ֻ�ܷ��ʾ�̬�ĳ�Ա����
//	static int GetCount()
//	{
//		test();//error
//		return _sCount;
//	}
//private:
//	int _a;
//	//��̬��Ա�������������࣬���ж��������������������������ڼ�
//	//����ĳ�Ա�����У�����������
//	static int _sCount;
//};
//
//int A::_sCount = 0; //�����ʼ��
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
//	//_sCount ����
//	//cout << A::_sCount << endl;
//	//cout << a2._sCount << endl;
//	
//	// _sCount ˽��
//	cout << a2.GetCount() << endl;//дһ��Get����
//	cout << A::GetCount() << endl;//static���κ����������ͨ����ȥ����
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
//	Date d2 = 2022;//��ʽ����ת�� error 
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