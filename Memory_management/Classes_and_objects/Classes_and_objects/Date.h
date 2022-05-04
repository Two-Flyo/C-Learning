#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

class Date
{
	//��Ԫ����
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	Date(int year=0, int mouth=1, int day=1);
	void Print() const;
	int GetMouthDay(int year, int mouth);

	bool operator>(const Date& d) const; 
	bool operator<(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator==(const Date& d) const;
	Date& operator=(const Date& d);
	bool operator!=(const Date& d) const;
	//void operator<<(ostream& o);

	//d1+=xxx
	Date& operator+=(int day);
	//d1+xxx
	Date operator+(int day);
	//d1++
	Date& operator++();
	//++d1 ����++Ϊ��ȡ��ǰ��++������һ������ռλ
	Date operator++(int);
	//d1-=xxx
	Date& operator-=(int day);
	//d1-xxx
	Date operator-(int day);
	//d2-d1
	int operator-(const Date& d);
	//d1--;
	Date operator--(int day);
	//--d1;
	Date& operator--();

	void PrintWeekDay()
	{
		const char* arr[] = { "��һ","�ܶ�","����","����","����","����","����" };
		Date start(1900, 1, 1);
		int count = *this - start;
		cout << arr[count%7] << endl;
	}
private:
	int _year;
	int _mouth;
	int _day;
};