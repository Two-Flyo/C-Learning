#include <iostream>
#include "Date.h"

using namespace std;

bool Date::operator==(const Date& date)
{
	return _year == date._year
		&& _month == date._month
		&& _day == date._day;
}

bool Date::operator!=(const Date& date)
{
	return _year != date._year
		|| _month != date._month
		|| _day != date._day;
}

bool Date::operator>(const Date& date)
{
	if ((_year > date._year)
		|| (_year == date._year && _month > date._month)
		|| (_year == date._year && _month == date._month && _day > date._day))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator>=(const Date& date)
{
	return (*this > date) || (*this == date);
}

bool Date::operator<(const Date& date)
{
	return !(*this >= date);
}

bool Date::operator<=(const Date& date)
{
	return !(*this > date);
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}

Date& Date::operator++() //«∞÷√
{
	return *this += 1;
}

Date Date::operator++(int) //∫Û÷√
{
	Date tmp  = *this;
	*this += 1;
	return tmp;
}

Date& Date::operator-=(int day)
{
}

Date& Date::operator--()
{
	return *this -= 1;
}

Date Date::operator--(int)
{

}

void TestDate1()
{
	Date d1(2004, 2, 17);
	Date d2 = ++d1;
	d2.ShwoDate();
	d1++;
	d1.ShwoDate();
	d2.ShwoDate();
}

int main()
{
	TestDate1();

	return 0;
}