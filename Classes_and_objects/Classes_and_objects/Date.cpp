#include"Date.h"

int Date::GetMouthDay(int year, int mouth)
{
	static int mouthDayArray[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int day = mouthDayArray[mouth];
	//  一年 365天多5h+
	if (mouth == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
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
void Date::Print()
{
	printf("%04d-%02d-%02d\n", _year, _mouth, _day);
}
