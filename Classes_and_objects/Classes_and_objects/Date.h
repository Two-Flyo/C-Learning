#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

class Date
{
public:
	Date(int year=0, int mouth=1, int day=1);
	void Print();
	int GetMouthDay(int year, int mouth);

	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator>=(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator=(const Date& d);
private:
	int _year;
	int _mouth;
	int _day;
};