#include"Date.h"

int Date::GetMouthDay(int year, int mouth)
{
	static int mouthDayArray[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int day = mouthDayArray[mouth];
	//  一年 365天多5h+
	if (mouth == 2 && ((year % 4 == 0 && year % 100 != 0)|| (year % 400 == 0)))
		day++;
	return day;
}

Date::Date(int year/*=0*/, int mouth/*=1*/, int day/*=1*/)
{
	_year = year;
	_mouth = mouth;
	_day = day;

	if (!((_year >= 0) && (_mouth > 0 && _mouth < 13) && (_day > 0 && _day <= GetMouthDay(year, mouth))))
	{
		cout << "日期输入有误:";
		Print();
	}
	
}
void Date::Print() const
{
	printf("%04d-%02d-%02d\n", _year, _mouth, _day);
}

Date& Date::operator=(const Date& d)
{
	if (*this != d)
	{
		_year = d._day;
		_mouth = d._mouth;
		_day = d._day;
	}
	return *this;
}

Date& Date::operator+=(int day)//进位：天数->月数->年数
{
	if (day < 0)
	{
		return *this -= (-day);
	}
	_day += day;
	while(_day>GetMouthDay(_year, _mouth))
	{
		_day -= GetMouthDay(_year, _mouth);
		_mouth++;
		if (_mouth == 13)
		{
			_mouth = 1;
			_year++;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date ret(*this);
	ret += day;
	return ret;
}

//d1-=xxx
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}
	_day -= day;
	while (_day <= 0)
	{
		--_mouth;
		if (_mouth == 0)
		{
			--_year; 
			_mouth = 12;
		}
		_day += GetMouthDay(_year, _mouth);
	}
	return *this;
}
//d1-xxx
Date Date::operator-(int day)
{
	Date ret(*this);
	ret -= day;
	return ret;
}

//d2-d1
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	int count = 0;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	while (min != max)
	{
		++min;
		++count;
	}
	return flag*count;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}
//++d1 后置++为了取分前置++，增加一个参数占位
Date Date::operator++(int)
{
	Date ret(*this);
	*this += 1;
	return ret;
}

//d1--;
Date Date::operator--(int day)
{
	Date ret(*this);
	*this -= 1;
	return ret;
}
//--d1;
Date& Date::operator--()
{
	return *this -= 1;
}

bool Date::operator>(const Date& d) const
{
	if (this->_year > d._year)
		return true;
	else if (this->_year == d._year && this->_mouth > d._mouth)
		return true;
	else if (this->_year == d._year && this->_mouth == d._mouth && this->_day > d._day)
		return true;
	else
		return false;
}

bool Date::operator==(const Date& d) const
{
	return _year == d._year && _mouth == d._mouth && _day == d._day;
}

bool Date::operator>=(const Date& d) const
{
	return *this > d || *this == d;
}

bool Date::operator<(const Date& d) const
{
	return !(*this >= d);
}

bool Date::operator<=(const Date& d) const
{
	return !(*this > d);
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}


ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "/" << d._mouth << "/" << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	cout << "请依次输入年月" << endl;
	in >> d._year >> d._mouth >> d._day;
	return in;
}
