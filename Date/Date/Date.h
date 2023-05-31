#pragma once
#include <iostream>

using namespace std;


class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}
		return day;
	}
	
	bool operator==(const Date& date);
	bool operator!=(const Date& date);
	bool operator>(const Date& date);
	bool operator<(const Date& date);
	bool operator>=(const Date& date);
	bool operator<=(const Date& date);

	Date operator+(int day);
	Date& operator+=(int day);
	Date operator-(int day);
	Date& operator-=(int day);

	//使用重载区分前置++和后置++
	Date& operator++(); //前置
	Date operator++(int); //后置

	Date& operator--();
	Date operator--(int);

	//日期-日期
	int operator-(const Date& date);


	void ShwoDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};
