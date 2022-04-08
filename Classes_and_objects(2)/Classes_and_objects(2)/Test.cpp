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
	//static���εĺ�����û��thisָ�룬ֻ�ܷ��ʾ�̬�ĳ�Ա����
	static int GetCount()
	{
		return _sCount;
	}
private:
	int _a;
	//��̬��Ա�������������࣬���ж��������������������������ڼ�
	//����ĳ�Ա�����У�����������
	static int _sCount;
};

int A::_sCount = 0; //�����ʼ��

void f(A a)
{

}

int main()
{
	A a1;
	A a2 = 1;
	A a3(a2);
	f(a3);
	//_sCount ����
	//cout << A::_sCount << endl;
	//cout << a2._sCount << endl;
	
	// _sCount ˽��
	cout << a2.GetCount() << endl;//дһ��Get����
	cout << A::GetCount() << endl;//static���κ����������ͨ����ȥ����


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