#include"Date.h"

class A {
public:
	A* operator&()
	{
		return this;
	}
	const A* operator&() const
	{
		return this;
	}
};

//void Date::operator<<(ostream& out)
//{
//	out << _year << "/" << _mouth << "/" << _day << endl;
//}


//int main()
//{
//
//	Date d1(2002, 3, 3);
//	d1.operator<<(cout);//��
//	//cout << d1 << endl;//error
//	d1 << cout;//��  ���ǲ�����ʹ��ϰ��
//	return 0;
//}

int main()
{
	Date d1(2002, 3, 30);
	cout << d1 << endl;
	Date d2;
	while (1)
	{
		cin >> d2;
		cout << d2;
	}
	return 0;
}

//void TestDate2()
//{
//	Date d1 = (2022, 1, 16);
//	Date ret1 = d1++;
//	ret1.Print();
//	Date ret2 = ++d1;
//	ret2.Print();
//}

//void TestDate3()
//{
//	Date d1(2022, 4, 7);
//	d1.PrintWeekDay();
//	//Date d1(1900, 1, 1);
//	////d1.PrintWeekDay();*/
//	//Date d2(2022, 1, 1);
//	//int day = d2 - d1;
//	//cout << day<< endl;
//}
//
//void TestDate1()
//{
//	Date d1(2022,4,5);
//	Date ret = d1 + 100;
//	ret.Print();
//
//	d1 += 100;
//	d1.Print();
//
//	Date ret1 = d1++;//d1.operator(&d1,x)  xռλ
//	ret1.Print();
//	Date ret2 = ++d1;//d1.operator(&d1)
//	ret2.Print();
//
//	Date ret3 = d1;
//	ret3.Print();
//	Date ret4 = ret3 - -1216;
//	ret4.Print();
//}
//
//int main()
//{
//	Date d1;
//	d1.Print();
//	const Date d2;
//	d2.Print();//error
//	return 0;
//}

//int main()
//{
//	//TestDate1();
//	TestDate3();
//	//Date d1;
//	//Date d2(2022, 4, 4);
//	//Date d3(2022, 4, 40);
//	//Date d4(2000, 2, 29);
//	//d1.Print();
//	//d2.Print();
//	return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 0, int mouth = 1, int day = 1)
//	{
//		_year = year;
//		_mouth = mouth;
//		_day = day;
//	}
//	Date& operator=(const Date& d)
//	{
//		if (this != &d) //�жϼ���������Լ����Լ���ֵ
//		{
//			_year = d._year;
//			_mouth = d._mouth;
//			_day = d._day;
//		}
//		return *this;
//	}
//	bool operator>(const Date& d)//���ش��ݵĲ���(thisָ��)
//	{
//		if (this->_year > d._year)
//			return true;
//		else if (this->_year == d._year && this->_mouth > d._mouth)
//			return true;
//		else if (this->_year == d._year && this->_mouth == d._mouth && this->_day > d._day)
//			return true;
//		else
//			return false;
//
//	}
//
//private:
//	int _year;
//	int _mouth;
//	int _day;
//};
//
//// ������ operator������
//// �������� ������������󷵻ص�ֵ��ʲô
//// ���� �������м����������������м�������
//
////int operator-(const Date& d1, const Date& d2)
////{
////
////}
//
//int main()
//{
//	Date d1(2002, 03, 30);
//	Date d2(2022, 04, 04);
//	Date d3;
//	d3 = d1;
//	//cout<<d1.operator>(d2);
//	////Ĭ�������C++�ǲ�֧���Զ������Ͷ���ʹ�������
//	//cout << (d1 > d2) << endl; // =>operator>(d1,d2)
//	//cout << operator>(d1,d2) << endl;
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 0, int mouth = 1, int day = 1)
//	{
//		_year = year;
//		_mouth = mouth;
//		_day = day;
//	}
//	Date(const Date& d)//��������
//	{
//		_year = d._year;
//		_mouth = d._mouth;
//		_day = d._day;
//	}
//	~Date()
//	{
//		//Date��û����Դ��Ҫ����,����Date�಻ʵ����������������
//		cout << "~Date()" << endl;
//	}
//	void Print()
//	{
//		printf("%04d-%02d-%02d\n", _year, _mouth, _day);
//	}
//private:
//	int _year;
//	int _mouth;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2022, 03, 30);
//
//	Date d2(d1);
//	return 0;
//}


//
//int main()
//{
//	Date d1;
//	Date d2(2002,03,30);
//	d1.Print();
//	d2.Print();
//	return 0;
//}

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
//	//��Ա����
//	char _name[10];
//	int _age;
//	int _id;
//public:
//	//��Ա����/����
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


//C++����C�нṹ����÷���ͬʱstruct��C++��Ҳ����������
//struct Student
//{
//	//��Ա����
//	char _name[10];
//	int _age;
//	int _id;
//
//	//��Ա����/����
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
//	struct Student s1;//����C
//	Student s2;//�������࣬Student������Ҳ������
//	s1.Init("lrf", 1, 111);
//	s1.print();
//	return 0;
//}